#!/usr/bin/env python3
"""Deterministic, target-guided .s normalizer for the C build.

Some functions compile to assembly that is semantically identical to the retail
target but differs in a few register-allocation or commutative-operand choices
that modern GNU as does not reproduce the same way the original PSY-Q toolchain
did. For those functions this pass rewrites the cc1 gas ``.s`` (between cc1 and
the assembler) so the emitted words match the retail bytes.

It is NOT a search: every pass is a deterministic rewrite, guided by the
in-repo retail disassembly (``asm/**/nonmatchings/**/<func>.s``). A manifest
(``asm_normalizer_manifest.json`` next to this file) lists, per function, the
ordered pass names to replay. Functions not in the manifest are left byte for
byte verbatim; an empty/absent manifest makes the whole pass a no-op.

The build relies on the final linked SHA-1 as the ground-truth gate: if a
recorded rewrite ever produced the wrong bytes the checksum would fail loudly.

No function names or repository paths are baked into this module. The manifest
supplies the function names; the caller supplies the toolchain paths and the
retail-asm root via a small context object.
"""
import difflib
import glob
import json
import os
import collections
import re
import subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
MANIFEST = os.path.join(HERE, "asm_normalizer_manifest.json")

# --------------------------------------------------------------------------
# MIPS register table (self-contained; O32 ABI order)
# --------------------------------------------------------------------------
NUM2ABI = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
           "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
           "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
           "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]
ABI2NUM = {n: i for i, n in enumerate(NUM2ABI)}
ABI2NUM["s8"] = 30           # fp alias
ABI2NUM["r0"] = 0


def norm_reg(tok):
    """'$a2' / '$4' / 'a2' / '$s8' -> canonical ABI name; a bare number is an
    IMMEDIATE, not a register (objdump prints small shift amounts as bare
    decimals like `sll v0,v0,8`), so only a $-prefixed number names a register."""
    s = tok.strip()
    had_dollar = s.startswith("$")
    t = s.lstrip("$")
    if t in ABI2NUM:
        return NUM2ABI[ABI2NUM[t]]
    if had_dollar and re.fullmatch(r"\d+", t) and int(t) < 32:
        return NUM2ABI[int(t)]
    if re.fullmatch(r"r\d+", t) and int(t[1:]) < 32:
        return NUM2ABI[int(t[1:])]
    return None


# --------------------------------------------------------------------------
# operand parsing on objdump / retail disassembly
# --------------------------------------------------------------------------
def split_ops(opstr):
    out, depth, cur = [], 0, ""
    for ch in opstr:
        if ch == "(":
            depth += 1; cur += ch
        elif ch == ")":
            depth -= 1; cur += ch
        elif ch == "," and depth == 0:
            out.append(cur.strip()); cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


# GTE (coprocessor 2) register operands look like GPRs (`mtc2 $4,$12`, `lwc2 $1,4($2)`) but
# name GTE data/control registers: register maps, liveness and renaming must skip them.
_COP2_MOVE = ("mtc2", "mfc2", "ctc2", "cfc2")
_COP2_MEM = ("lwc2", "swc2")


def _cop2_strip(disasm):
    """`disasm` with its cop2 register operand spelled `c2rN` (not a register token)."""
    p = disasm.split(None, 1)
    if len(p) < 2 or p[0].lower() not in _COP2_MOVE + _COP2_MEM:
        return disasm
    ops = split_ops(p[1])
    k = 1 if p[0].lower() in _COP2_MOVE else 0
    if len(ops) <= k:
        return disasm
    ops[k] = "c2r" + ops[k].strip().lstrip("$")
    return p[0] + " " + ",".join(o.strip() for o in ops)


def insn_parts(disasm):
    """'lw v1,0(a3)' -> ('lw', [regs in order], [non-reg operand skeletons])."""
    disasm = _cop2_strip(disasm)
    p = disasm.split(None, 1)
    mnem = p[0].lower()
    ops = split_ops(p[1]) if len(p) > 1 else []
    regs, skel = [], []
    for op in ops:
        mm = re.fullmatch(r"(.*)\((\$?\w+)\)", op)
        if mm and norm_reg(mm.group(2)) is not None:
            skel.append(mm.group(1).strip() + "(#)")
            regs.append(norm_reg(mm.group(2)))
        else:
            r = norm_reg(op)
            if r is not None:
                regs.append(r)
                skel.append("#")
            else:
                skel.append(op)
    return mnem, regs, skel


# --------------------------------------------------------------------------
# reg-realloc: derive the register correspondence the target's naming implies
# and apply it to the cc1 gas .s
# --------------------------------------------------------------------------
def derive_sigma(our, tgt):
    """From positions whose mnemonic + non-register skeleton already agree, unify
    the register operands to build sigma. Returns (sigma dict, conflicts list)."""
    sigma, conflicts = {}, []
    for (gw, gd), (tw, td) in zip(our, tgt):
        gm, gr, gs = insn_parts(gd)
        tm, tr, ts = insn_parts(td)
        if gm != tm or len(gr) != len(tr):
            continue
        for a, b in zip(gr, tr):
            if a == "zero" or b == "zero":
                if a != b:
                    conflicts.append(("zero-mismatch", gd, td))
                continue
            if a in sigma and sigma[a] != b:
                conflicts.append((a, sigma[a], b))
            else:
                sigma[a] = b
    return sigma, conflicts


# reg_realloc_inj: reg_realloc's sigma keeps the first pairing it sees for each of
# our registers, so two of our registers can land on one target register while
# both are live (`addu a0,a0,a0`). This variant counts every aligned pairing,
# assigns pairs by vote (most first) so no two of our registers share an image,
# and completes the map to a permutation of the registers we use: a register
# that is the image of another keeps its value by moving to a register that
# was freed. Fixed registers stay put. reg_realloc itself is unchanged.
_INJ_FIXED = {"zero", "sp", "gp", "at", "k0", "k1"}


def derive_sigma_inj(our, tgt):
    votes = {}
    used = set()
    for (gw, gd), (tw, td) in zip(our, tgt):
        gm, gr, gs = insn_parts(gd)
        used.update(r for r in gr if r in ABI2NUM)
        tm, tr, ts = insn_parts(td)
        if gm != tm or len(gr) != len(tr):
            continue
        for a, b in zip(gr, tr):
            if a in _INJ_FIXED or b in _INJ_FIXED or a not in ABI2NUM or b not in ABI2NUM:
                continue
            votes[(a, b)] = votes.get((a, b), 0) + 1
    for gw, gd in our[len(tgt):]:
        used.update(r for r in insn_parts(gd)[1] if r in ABI2NUM)
    sigma, img = {}, set()
    for (a, b), n in sorted(votes.items(), key=lambda x: (-x[1], ABI2NUM[x[0][0]], ABI2NUM[x[0][1]])):
        if a in sigma or b in img:
            continue
        sigma[a] = b
        img.add(b)
    # complete to a permutation over the registers we use
    free = sorted((a for a in sigma if a not in img), key=lambda r: ABI2NUM[r])
    for r in sorted(used - _INJ_FIXED, key=lambda r: ABI2NUM[r]):
        if r in sigma or r not in img:
            continue
        if not free:
            return {}
        sigma[r] = free.pop(0)
        img.add(sigma[r])
    return {a: b for a, b in sigma.items() if a != b}


def apply_sigma_to_s(stext, sigma):
    """Rename $N registers in cc1 gas assembly simultaneously per sigma (ABI->ABI)."""
    num = {}
    for a, b in sigma.items():
        if a in ABI2NUM and b in ABI2NUM:
            num[ABI2NUM[a]] = ABI2NUM[b]

    def repl(m):
        n = int(m.group(1))
        return "$%d" % num.get(n, n)

    def line(l):
        return ";".join(seg(x) for x in l.split(";"))

    def seg(l):
        # keep a GTE register operand out of the GPR renaming
        m = re.match(r"(\s*(?:mtc2|mfc2|ctc2|cfc2)\s+\$\w+\s*,\s*)(\$\d+)(.*)$", l) or \
            re.match(r"(\s*(?:lwc2|swc2)\s+)(\$\d+)(.*)$", l)
        if not m:
            return re.sub(r"\$(\d+)\b", repl, l)
        if m.group(1).lstrip().startswith(("lwc2", "swc2")):
            return m.group(1) + m.group(2) + re.sub(r"\$(\d+)\b", repl, m.group(3))
        return re.sub(r"\$(\d+)\b", repl, m.group(1)) + m.group(2) + m.group(3)

    return "\n".join(line(l) for l in stext.split("\n"))


# --------------------------------------------------------------------------
# commutative-operand-swap: transpose the two source operands of a commutative
# insn whose destination already matches the target but whose rs/rt order does
# not (a field order the global register map cannot express)
# --------------------------------------------------------------------------
_COMMUTATIVE_ACC = {"addu", "add", "and", "or", "xor", "nor"}
_ACC_S = re.compile(r"^(\s*)(\w+)\s+(\$\d+)\s*,\s*(\$\d+)\s*,\s*(\$\d+)\s*$")


def _s_is_insn(line):
    s = line.strip()
    if not s or s.startswith((".", "#")) or s.endswith(":"):
        return False
    return True


def _s_insn_lines(lines):
    return [i for i, l in enumerate(lines) if _s_is_insn(l)]


def _abi_to_num(tok):
    r = norm_reg(tok)
    return ("$%d" % ABI2NUM[r]) if r in ABI2NUM else None


def _commutatives_numeric(pairs, to_num):
    """List of (op, dst, rs, rt) commutative 3-register insns with both sources
    real non-zero registers, in order. Excludes the `op rd,rs,zero` move-pseudo
    form so the two sides stay positionally aligned."""
    zero = "$%d" % ABI2NUM["zero"]
    out = []
    for _, dis in pairs:
        m = re.match(r"(\w+)\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*(\$?\w+)\s*$", dis)
        if not m or m.group(1).lower() not in _COMMUTATIVE_ACC:
            continue
        d, s, t = to_num(m.group(2)), to_num(m.group(3)), to_num(m.group(4))
        if d and s and t and s != zero and t != zero:
            out.append((m.group(1).lower(), d, s, t))
    return out


def commutative_swap_s(stext, tgt):
    """Transpose the two source operands of a commutative insn whose destination
    already matches the target but whose rs/rt order does not. stext is
    sigma-applied (numeric register space). Returns new text (unchanged if the
    transform does not fire)."""
    tgt_c = _commutatives_numeric(tgt, _abi_to_num)
    if not tgt_c:
        return stext
    lines = stext.split("\n")
    insn_ix = _s_insn_lines(lines)
    zero = "$%d" % ABI2NUM["zero"]
    our = []
    for i in insn_ix:
        m = _ACC_S.match(lines[i])
        if m and m.group(2).lower() in _COMMUTATIVE_ACC \
                and m.group(4) != zero and m.group(5) != zero:
            our.append((i, m.group(2).lower(), m.group(3), m.group(4), m.group(5)))
    if len(our) != len(tgt_c):
        return stext
    changed = False
    for (li, op, od, os_, ot), (top, td, ts, tt) in zip(our, tgt_c):
        if op != top or od != td:
            continue
        if os_ == ts and ot == tt:
            continue
        if os_ == tt and ot == ts:
            indent = lines[li][:len(lines[li]) - len(lines[li].lstrip())]
            lines[li] = "%s%s\t%s,%s,%s" % (indent, op, od, ts, tt)
            changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# la-form fold: rewrite the split form (`lui $B,%hi(SYM)` + `%lo(SYM)($B)`) into
# the la form (`lui;addiu $B,$B,%lo(SYM)` + `0($B)`). Both compute the same
# address; the original toolchain prefers la-form for some single-symbol
# globals. Target-guided: only fold symbols the target materializes with
# `addiu R,R,%lo(SYM)`.
# --------------------------------------------------------------------------
def target_laform_syms(tgt):
    """Symbols the target builds via an explicit la (lui;addiu %lo) then 0(base)."""
    syms = set()
    pat = re.compile(r"addiu\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*%lo\(([\w.$]+)\)")
    for _, dis in tgt:
        m = pat.search(dis)
        if m and norm_reg(m.group(1)) == norm_reg(m.group(2)):
            syms.add(m.group(3))
    return syms


def laform_fold_s(stext, syms):
    """In the cc1 gas .s, rewrite `lui $B,%hi(SYM)` + `%lo(SYM)($B)` split-form
    into la-form: insert `addiu $B,$B,%lo(SYM)` after the lui and change each
    `%lo(SYM)($B)` operand to `0($B)`. Only fires for SYM in `syms` and only when
    every use of $B in its live range is a `%lo(SYM)($B)` memory operand of that
    same SYM, so materializing the address and zeroing the offsets preserves
    every access. Rewrites one lui/base at a time."""
    lines = stext.split("\n")
    lui_re = re.compile(r"^(\s*)lui\s+(\$\d+)\s*,\s*%hi\(([\w.$]+)\)")
    for sym in syms:
        i = 0
        while i < len(lines):
            m = lui_re.match(lines[i])
            if not m or m.group(3) != sym:
                i += 1; continue
            indent, base = m.group(1), m.group(2)
            reg_re = re.compile(r"(?<![\w$])" + re.escape(base) + r"(?![\w])")
            lo_here = re.compile(r"%lo\(" + re.escape(sym) + r"\)\(" + re.escape(base) + r"\)")
            j = i + 1
            legal = True
            hits = []
            while j < len(lines):
                body = lines[j].split("#", 1)[0]
                mdef = re.match(r"\s*[a-z][\w.]*\s+" + re.escape(base) + r"\s*,", body)
                if mdef:
                    break
                if reg_re.search(body):
                    if lo_here.search(body):
                        hits.append(j)
                    else:
                        legal = False
                        break
                j += 1
            if legal and hits:
                for j in hits:
                    lines[j] = lo_here.sub("0(%s)" % base, lines[j])
                lines.insert(i + 1, "%saddiu\t%s,%s,%%lo(%s)" % (indent, base, base, sym))
                i = j + 2
            else:
                i += 1
    return "\n".join(lines)


def laform_fold_pass(stext, tgt):
    return laform_fold_s(stext, target_laform_syms(tgt))


# --------------------------------------------------------------------------
# la_unfold: retail's cc1 kept a global's address in a register (`la R,S` =
# `lui R,%hi(S); addiu R,R,%lo(S)`) and loaded through it at offset 0, where our
# cc1 folded the address into a symbolic load `op $r,S` (`lui; op %lo(S)`).
# Target-guided: S must appear in the target only in that la form (no %lo(S)
# memory access), with as many la pairs as we have folded loads of S. Each folded
# load becomes `la $r,S; op $r,0($r)` (the loaded register is the address
# temp, so nothing else changes). Count-changing (+1 per load): pre-sigma.
# --------------------------------------------------------------------------
_LU_HI = re.compile(r"^\s*lui\s+(\$\w+)\s*,\s*%hi\(([A-Za-z_]\w*)\)\s*$")
_LU_LO = re.compile(r"^(\s*)(lw|lh|lhu|lb|lbu)(\s+)(\$\w+)\s*,\s*%lo\(([A-Za-z_]\w*)\)\((\$\w+)\)\s*$")
_LU_LOAD = re.compile(r"^(\s*)(lw|lh|lhu|lb|lbu)(\s+)(\$\w+)\s*,\s*([A-Za-z_]\w*)\s*(#.*)?$")


def la_unfold_pass(stext, tgt):
    if not tgt:
        return stext
    lui_re = re.compile(r"lui\s+(\$?\w+)\s*,\s*%hi\(([\w.$]+)\)")
    add_re = re.compile(r"addiu\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*%lo\(([\w.$]+)\)")
    la_n, lo_mem = {}, set()
    for i in range(len(tgt)):
        d = tgt[i][1]
        m = re.search(r"%lo\(([\w.$]+)\)\(", d)
        if m:
            lo_mem.add(m.group(1))
        a = lui_re.search(d)
        b = add_re.search(tgt[i + 1][1]) if a and i + 1 < len(tgt) else None
        if a and b and b.group(3) == a.group(2) and \
                norm_reg(a.group(1)) == norm_reg(b.group(1)) == norm_reg(b.group(2)):
            la_n[a.group(2)] = la_n.get(a.group(2), 0) + 1
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    hits = {}
    for i, l in enumerate(lines):
        if i in nr:
            continue
        m = _LU_LOAD.match(l)
        if m and norm_reg(m.group(4)) not in (None, "zero", "at"):
            hits.setdefault(m.group(5), []).append((i, None))
            continue
        # the expanded form `lui $r,%hi(S); op $r,%lo(S)($r)`
        mh = _LU_HI.match(l.split("#", 1)[0])
        j = _tf_next_insn(lines, i) if mh else None
        mo = _LU_LO.match(lines[j].split("#", 1)[0]) if j is not None and j not in nr else None
        if (mo and mo.group(5) == mh.group(2)
                and norm_reg(mo.group(4)) == norm_reg(mh.group(1)) == norm_reg(mo.group(6))
                and norm_reg(mh.group(1)) not in ("zero", "at")):
            hits.setdefault(mh.group(2), []).append((i, j))
    edits = [x for s, ix in hits.items()
             if s in la_n and s not in lo_mem and la_n[s] == len(ix) for x in ix]
    if not edits:
        return stext
    for i, j in sorted(edits, reverse=True):
        if j is None:
            m = _LU_LOAD.match(lines[i])
            ind, r = m.group(1), m.group(4)
            lines[i:i + 1] = ["%sla\t%s,%s" % (ind, r, m.group(5)),
                              "%s%s%s%s,0(%s)" % (ind, m.group(2), m.group(3), r, r)]
        else:
            mo = _LU_LO.match(lines[j].split("#", 1)[0])
            ind, r, sym = mo.group(1), mo.group(4), mo.group(5)
            lines[j:j + 1] = ["%saddiu\t%s,%s,%%lo(%s)" % (ind, r, r, sym),
                              "%s%s%s%s,0(%s)" % (ind, mo.group(2), mo.group(3), r, r)]
    return "\n".join(lines)


# --------------------------------------------------------------------------
# la_unfold_st: the store form of la_unfold. Retail kept the global's address in
# a register (`la T,S; sw R,k(T)`) where our cc1 folded it into a symbolic store
# (`lui $at,%hi(S+k); sw R,%lo(S+k)($at)`). Target-guided: the target has that
# many `la T,S` pairs each followed (within 4 words) by `op X,k(T)`, and no
# %lo memory access of the address S+k resolves to. T is the target's register;
# it must not be the stored register and must be dead after the store in ours
# (written before read on the straight line). Count-changing (+1): pre-sigma.
# --------------------------------------------------------------------------
_LS_ST = re.compile(r"^(\s*)(sw|sh|sb)(\s+)(\$\w+)\s*,\s*%lo\(([A-Za-z_]\w*)(?:\+(\d+))?\)\(\$(?:1|at)\)\s*$")


def la_unfold_st_pass(stext, tgt):
    if not tgt:
        return stext
    lui_re = re.compile(r"lui\s+(\$?\w+)\s*,\s*%hi\(([\w.$]+)\)")
    add_re = re.compile(r"addiu\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*%lo\(([\w.$]+)\)")
    want, lo_mem = {}, set()
    for i in range(len(tgt)):
        d = tgt[i][1]
        m = re.search(r"%lo\(([\w.$]+)\)\(", d)
        if m:
            lo_mem.add(m.group(1))
        a = lui_re.search(d)
        b = add_re.search(tgt[i + 1][1]) if a and i + 1 < len(tgt) else None
        if not (a and b and b.group(3) == a.group(2)
                and norm_reg(a.group(1)) == norm_reg(b.group(1)) == norm_reg(b.group(2))):
            continue
        t = norm_reg(a.group(1))
        for q in range(i + 2, min(i + 6, len(tgt))):
            mn, regs, sk = insn_parts(tgt[q][1].strip())
            mo = _mem_operand(tgt[q][1].strip())
            if mn in ("sw", "sh", "sb") and mo and mo[0] == t:
                key = (mn, a.group(2), mo[1], t)
                want[key] = want.get(key, 0) + 1
                break
            if t in defs_uses(tgt[q][1].strip())[0]:
                break
    if not want:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    hits = {}
    for j, l in enumerate(lines):
        m = _LS_ST.match(l.split("#", 1)[0])
        if not m or j in nr:
            continue
        k = int(m.group(6) or 0)
        for (mn, sym, off, t), n in want.items():
            if mn == m.group(2) and sym == m.group(5) and off == k:
                hits.setdefault((mn, sym, off, t), []).append(j)
    edits = []
    for key, js in hits.items():
        mn, sym, off, t = key
        if len(js) != want[key] or _sm_sym("%s+%d" % (sym, off)) in lo_mem or (
                off == 0 and sym in lo_mem):
            continue
        mine = []
        for j in js:
            m = _LS_ST.match(lines[j].split("#", 1)[0])
            if norm_reg(m.group(4)) == t or not _us_dead_ft(lines, ins, j, t):
                break
            hi = next((y for y in range(j - 1, -1, -1) if _s_is_insn(lines[y])), None)
            if hi is None or not re.match(r"\s*lui\s+\$(?:1|at)\s*,\s*%hi\(", lines[hi]):
                break
            mine.append((hi, j, m, t, off))
        else:
            edits += mine
    if not edits:
        return stext
    for hi, j, m, t, off in sorted(edits, key=lambda e: -e[0]):
        ind = m.group(1)
        tr = "$%d" % ABI2NUM[t]
        lines[j] = "%s%s%s%s,%d(%s)" % (ind, m.group(2), m.group(3), m.group(4), off, tr)
        lines[hi] = "%sla\t%s,%s" % (ind, tr, m.group(5))
    return "\n".join(lines)


# --------------------------------------------------------------------------
# un-hi-cse (rematerialize): our cc1 hoists a global's `lui %hi` once and shares
# the base across several `%lo` loads; retail's cc1 rematerializes the `lui %hi`
# at EACH use (`lui R,%hi(S); lw R,%lo(S)(R)`, base == dest). This is a COUNT-
# changing pass (adds a lui per use, drops the shared hoist), so it must run
# BEFORE sigma derivation so the register correspondence is built from the
# count-aligned assembly. Target-guided (only symbols the target rematerializes).
# --------------------------------------------------------------------------
_LUI_HI = re.compile(r"^(\s*)lui\s+(\$\d+)\s*,\s*%hi\(([\w.$]+)\)")
_LW_LO = re.compile(r"^(\s*)lw\s+(\$\d+)\s*,\s*%lo\(([\w.$]+)\)\((\$\d+)\)")


def _is_insn_line(line):
    s = line.strip()
    if not s or s.startswith("#") or s.startswith(".") or s.endswith(":"):
        return False
    return bool(re.match(r"[a-z][\w.]*", s))


def _line_mnem(line):
    return line.strip().split(None, 1)[0].lower()


def target_remat_syms(tgt):
    """Symbols the target materializes inline as `lui R,%hi(S); lw R,%lo(S)(R)`
    (base == dest) -- the globals whose %hi retail rematerializes per access."""
    syms = set()
    lui_re = re.compile(r"lui\s+(\$?\w+)\s*,\s*%hi\(([\w.$]+)\)")
    lw_re = re.compile(r"lw\s+(\$?\w+)\s*,\s*%lo\(([\w.$]+)\)\((\$?\w+)\)")
    for i in range(len(tgt) - 1):
        a = lui_re.search(tgt[i][1])
        b = lw_re.search(tgt[i + 1][1])
        if not a or not b:
            continue
        rd, ld, lb = norm_reg(a.group(1)), norm_reg(b.group(1)), norm_reg(b.group(3))
        if a.group(2) == b.group(2) and rd == ld == lb:
            syms.add(a.group(2))
    return syms


def un_hi_cse_s(stext, remat_syms):
    """Un-CSE the %hi base of each `remat_syms` symbol: rematerialize `lui;lw` at
    each use and drop the shared hoist. Returns new text (unchanged if inert)."""
    if not remat_syms:
        return stext
    lines = stext.split("\n")
    # only un-CSE a symbol our cc1 actually HOISTED (`lw $D,%lo(S)($B)`, dest != base);
    # one already in base==dest remat form must not be duplicated.
    hoisted = set()
    for l in lines:
        m = _LW_LO.match(l)
        if m and m.group(3) in remat_syms and m.group(2) != m.group(4):
            hoisted.add(m.group(3))
    remat_syms = hoisted
    if not remat_syms:
        return stext
    region_of, reg, first_insn_line, saw = {}, 0, {}, False
    for idx, ln in enumerate(lines):
        if not _is_insn_line(ln):
            continue
        region_of[idx] = reg
        first_insn_line.setdefault(reg, idx)
        m = _LW_LO.match(ln)
        if m and m.group(3) in remat_syms:
            saw = True
        if _line_mnem(ln) in _STORE_MN:
            reg += 1
    if not saw:
        return stext
    inserts, delete = {}, set()
    for idx, ln in enumerate(lines):
        if idx not in region_of:
            continue
        mlui = _LUI_HI.match(ln)
        if mlui and mlui.group(3) in remat_syms:
            delete.add(idx)
            continue
        mlw = _LW_LO.match(ln)
        if mlw and mlw.group(3) in remat_syms:
            indent, dst, sym = mlw.group(1) or "\t", mlw.group(2), mlw.group(3)
            inserts.setdefault(region_of[idx], []).append(
                ["%slui\t%s,%%hi(%s)" % (indent, dst, sym),
                 "%slw\t%s,%%lo(%s)(%s)" % (indent, dst, sym, dst)])
            delete.add(idx)
    out, emitted = [], set()
    for idx, ln in enumerate(lines):
        r = region_of.get(idx)
        if r is not None and r not in emitted and idx == first_insn_line[r]:
            for pair in inserts.get(r, []):
                out.extend(pair)
            emitted.add(r)
        if idx in delete:
            continue
        out.append(ln)
    return "\n".join(out)


def un_hi_cse_pass(stext, tgt):
    return un_hi_cse_s(stext, target_remat_syms(tgt))


# --------------------------------------------------------------------------
# store-side un_hi_cse: the get/set-via-$at leaf `int f(int a0){ int old=D;
# D=a0; return old; }`. Our cc1 CSEs ONE `lui $B,%hi(D)` and shares $B as the
# base of both the load (`lw $D,%lo(D)($B)`, dest != base) and the store
# (`sw $src,%lo(D)($B)`). Retail instead: (a) materializes the load base==dest
# (`lui $D,%hi(D); lw $D,%lo(D)($D)`) and (b) rematerializes a SEPARATE
# `lui $at,%hi(D)` for the store, `sw $src,%lo(D)($at)`. Plain un_hi_cse handles
# only the load and would leave the store's base ($B) dangling, so this pass does
# both together: fold the load to base==dest, drop the shared hoist, and give the
# store its own `lui $at`. Count-changing (one net extra `lui`) -> PRE_SIGMA.
# --------------------------------------------------------------------------
_SW_LO = re.compile(r"^(\s*)(s[bhw])\s+(\$\d+)\s*,\s*%lo\(([\w.$]+)\)\((\$\d+)\)")


def target_store_remat_syms(tgt):
    """Symbols the target stores through a rematerialized `$at` base: it carries
    a base==dest `lui;lw` for S AND a `s? R,%lo(S)($at)` store of S. $at is $1."""
    loads = target_remat_syms(tgt)
    if not loads:
        return set()
    syms = set()
    sw_re = re.compile(r"s[bhw]\s+\$\w+\s*,\s*%lo\(([\w.$]+)\)\(\$at\)")
    for _w, dis in tgt:
        m = sw_re.search(dis)
        if m and m.group(1) in loads:
            syms.add(m.group(1))
    return syms


def un_hi_cse_store_s(stext, remat_syms):
    """Split a shared %hi base that feeds both a load and a store of the same
    symbol S in `remat_syms`: fold the load to base==dest and give the store its
    own `lui $at`. Fires only when our source has that exact shared shape."""
    if not remat_syms:
        return stext
    lines = stext.split("\n")
    # locate, per symbol, the shared lui base + its lw (dest!=base) + sw uses
    lui_idx = {}                             # sym -> (line idx, base reg)
    for idx, ln in enumerate(lines):
        m = _LUI_HI.match(ln)
        if m and m.group(3) in remat_syms:
            lui_idx.setdefault(m.group(3), (idx, m.group(2)))
    out = list(lines)
    changed = False
    for sym, (li, base) in lui_idx.items():
        lw_i = sw_i = None
        lw_dst = sw_indent = sw_src = None
        for idx, ln in enumerate(lines):
            m = _LW_LO.match(ln)
            if m and m.group(3) == sym and m.group(4) == base and m.group(2) != base:
                lw_i, lw_dst = idx, m.group(2)
            m = _SW_LO.match(ln)
            if m and m.group(4) == sym and m.group(5) == base:
                sw_i, sw_indent, sw_src = idx, m.group(1) or "\t", m.group(3)
        if lw_i is None or sw_i is None:
            continue
        indent = (_LW_LO.match(lines[lw_i]).group(1) or "\t")
        # (a) load base==dest, replacing both the shared lui and the lw
        out[li] = None                       # drop the shared hoist
        out[lw_i] = ("%slui\t%s,%%hi(%s)\n%slw\t%s,%%lo(%s)(%s)"
                     % (indent, lw_dst, sym, indent, lw_dst, sym, lw_dst))
        # (b) store via a fresh $at. cc1 often puts the store in the return's
        # delay slot; the fresh `lui $at` must precede the RETURN, not the sw
        # (which sits in the slot), so scan back over directives/blanks and, if a
        # return leads the store, hoist the lui above it.
        out[sw_i] = "%ssw\t%s,%%lo(%s)($1)" % (sw_indent, sw_src, sym)
        ins_at = sw_i
        j = sw_i - 1
        while j >= 0 and (not _is_insn_line(lines[j])):
            j -= 1
        if j >= 0 and _RET_S.match(lines[j]):
            ins_at = j
        out[ins_at] = "%slui\t$1,%%hi(%s)\n%s" % (sw_indent, sym, out[ins_at])
        changed = True
    if not changed:
        return stext
    return "\n".join(l for l in out if l is not None)


def un_hi_cse_store_pass(stext, tgt):
    return un_hi_cse_store_s(stext, target_store_remat_syms(tgt))


# --------------------------------------------------------------------------
# base-CSE-collapse: our cc1 accesses a global through the split form
# `lui $B,%hi(S); ... sw $x,%lo(S)($B)` and THEN materializes the full address
# `addiu $B,$B,%lo(S)` for a later pointer use (e.g. passing &S to a call), so the
# early accesses use the hi-only base and the later ones the full base. Retail
# materializes the full base ONCE, right after the lui, and every access uses a
# plain `k($B)` offset. laform is the wrong tool here (it would insert a SECOND
# `addiu %lo` because the full base already exists). This pass moves the existing
# `addiu $B,$B,%lo(S)` up to just after its lui and rewrites each intervening
# `%lo(S)($B)` / `%lo(S+k)($B)` operand to `0($B)` / `k($B)`. Semantics-preserving
# when, between the lui and the addiu, $B is never redefined and is only read as
# the base of those %lo(S) memory operands (so after the move every such access
# still computes %hi(S)+%lo(S)+k), and the region is straight-line (no label, no
# branch, no noreorder block). Count-preserving but order-changing, so it runs
# PRE_SIGMA (sigma is then derived from the collapsed, position-aligned words).
# Target-guided: only symbols the target itself materializes as an adjacent
# `lui R,%hi(S); addiu R,R,%lo(S)` pair.
# --------------------------------------------------------------------------
def target_collapse_syms(tgt):
    """Symbols the target materializes as an adjacent `lui R,%hi(S)` +
    `addiu R,R,%lo(S)` full base."""
    syms = set()
    lui_re = re.compile(r"lui\s+(\$?\w+)\s*,\s*%hi\(([\w.$]+)\)")
    add_re = re.compile(r"addiu\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*%lo\(([\w.$]+)\)")
    for i in range(len(tgt) - 1):
        a = lui_re.search(tgt[i][1])
        b = add_re.search(tgt[i + 1][1])
        if not a or not b:
            continue
        r = norm_reg(a.group(1))
        if (a.group(2) == b.group(3) and norm_reg(b.group(1)) == r
                and norm_reg(b.group(2)) == r):
            syms.add(a.group(2))
    return syms


def _label_referenced(lines, name):
    """Some instruction line references label `name` (a real branch target), as
    opposed to cc1's `LMn:` line-marker labels, which nothing branches to."""
    pat = re.compile(r"(?<![\w$.])" + re.escape(name) + r"(?![\w$])")
    return any(_is_insn_line(l) and pat.search(l.split("#", 1)[0]) for l in lines)


def base_cse_collapse_s(stext, syms):
    """Fold split `%lo(S)($B)` accesses onto the full base `addiu $B,$B,%lo(S)` that
    follows them, moving that addiu up to just after the lui. See block comment."""
    if not syms:
        return stext
    lines = stext.split("\n")
    changed = False
    for sym in syms:
        i = 0
        while i < len(lines):
            m = _LUI_HI.match(lines[i])
            if not m or m.group(3) != sym:
                i += 1
                continue
            indent, base = m.group(1) or "\t", m.group(2)
            reg_re = re.compile(r"(?<![\w$])" + re.escape(base) + r"(?![\w])")
            lo_re = re.compile(r"%lo\(" + re.escape(sym) + r"(?:\+(\d+))?\)\("
                               + re.escape(base) + r"\)")
            add_re = re.compile(r"^\s*addiu\s+" + re.escape(base) + r"\s*,\s*"
                                + re.escape(base) + r"\s*,\s*%lo\(" + re.escape(sym)
                                + r"\)\s*(#.*)?$")
            hits, add_i, j = [], None, i + 1
            while j < len(lines):
                s = lines[j].strip()
                if s.startswith(".set") and "noreorder" in s:
                    break
                if s.endswith(":") and not s.startswith(".") and \
                        _label_referenced(lines, s[:-1]):
                    break                       # branch target -> not straight-line
                if not _is_insn_line(lines[j]):
                    j += 1
                    continue
                if add_re.match(lines[j]):
                    add_i = j
                    break
                body = lines[j].split("#", 1)[0]
                mn = _line_mnem(lines[j])
                if _COND_S.match(mn) or mn in ("j", "jr", "jal", "jalr", "b", "bal"):
                    break
                if re.match(r"\s*[a-z][\w.]*\s+" + re.escape(base) + r"\s*,", body) \
                        and mn not in _STORE_MN:
                    break                       # $B redefined
                if reg_re.search(body):
                    if len(lo_re.findall(body)) != 1 or \
                            reg_re.search(lo_re.sub("", body)):
                        break                   # $B read other than as %lo(S) base
                    hits.append(j)
                j += 1
            if add_i is None or not hits:
                i += 1
                continue
            for h in hits:
                lines[h] = lo_re.sub(lambda mm: "%d(%s)" % (int(mm.group(1) or 0), base),
                                     lines[h])
            add_line = lines.pop(add_i)
            lines.insert(i + 1, add_line)
            changed = True
            i = add_i + 1
    return "\n".join(lines) if changed else stext


def base_cse_collapse_pass(stext, tgt):
    return base_cse_collapse_s(stext, target_collapse_syms(tgt))


# --------------------------------------------------------------------------
# shift-const-fold: our cc1's CSE sees a constant K already live in a register
# (`li $r,K`, e.g. a value about to be stored) and substitutes that register for
# the constant shift count, emitting `sll $d,$s,$r` (gas: sllv) where retail keeps
# the immediate form `sll $d,$s,K`. Rewrite the register-count shift back to the
# immediate form when the count register's straight-line reaching definition in
# the span is `li $r,K` (or `addiu/ori $r,$0,K`) with 0 <= K <= 31. Semantics-
# preserving: a variable shift uses the low 5 bits of the count register, which
# equal K. Target-guided: only for (op, K) pairs the target itself emits as an
# immediate shift. Count-preserving; runs PRE_SIGMA so sigma is not derived from a
# sllv/sll opcode-field mismatch.
# --------------------------------------------------------------------------
_SHIFT_REG_S = re.compile(r"^(\s*)(sll|srl|sra)(v?)\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")
_CONST_DEF_S = re.compile(
    r"^\s*(?:li\s+(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))"
    r"|(?:addiu|ori)\s+(\$\w+)\s*,\s*\$(?:0|zero)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+)))\s*(#.*)?$")


def target_imm_shifts(tgt):
    """{(op, K)} immediate shifts the target emits, e.g. ("sll", 16)."""
    out = set()
    pat = re.compile(r"^(sll|srl|sra)\s+\S+\s*,\s*\S+\s*,\s*(0x[0-9a-fA-F]+|\d+)\s*$")
    for _w, dis in tgt:
        m = pat.match(dis.strip())
        if m:
            out.add((m.group(1), int(m.group(2), 0)))
    return out


def shift_const_fold_s(stext, allowed):
    if not allowed:
        return stext
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    changed = False
    for p, (li, l) in enumerate(ins):
        m = _SHIFT_REG_S.match(l)
        if not m:
            continue
        cnt = _src_reg(m.group(6))
        if not cnt:
            continue
        # the constant's straight-line reaching def (also on the fall-through
        # of a conditional branch)
        k = _const_reaching(lines, ins, p, cnt)
        if k is None or not (0 <= k <= 31) or (m.group(2), k) not in allowed:
            continue
        lines[li] = "%s%s\t%s,%s,%d" % (m.group(1), m.group(2), m.group(4), m.group(5), k)
        changed = True
    return "\n".join(lines) if changed else stext


# The same CSE substitutes a live constant register into ALU ops: `addu $d,$s,$r`
# (either operand order) with `li $r,K` reaching it, where retail keeps the
# immediate form `addiu $d,$s,K` (and likewise and/or/xor -> andi/ori/xori,
# slt/sltu -> slti/sltiu). Same reaching-definition rule, target-guided by the
# (op, K) immediates the target emits.
_ALU_REG_S = re.compile(r"^(\s*)(addu|and|or|xor|slt|sltu)\s+(\$\w+)\s*,\s*(\$\w+)\s*,"
                        r"\s*(\$\w+)\s*(#.*)?$")
_ALU_IMM = {"addu": "addiu", "and": "andi", "or": "ori", "xor": "xori",
            "slt": "slti", "sltu": "sltiu"}


def target_imm_alu(tgt):
    """{(immediate op, K)} the target emits, e.g. ("addiu", -1)."""
    out = set()
    pat = re.compile(r"^(addiu|andi|ori|xori|slti|sltiu)\s+\S+\s*,\s*\S+\s*,\s*"
                     r"(-?(?:0x[0-9a-fA-F]+|\d+))\s*$")
    for _w, dis in tgt:
        m = pat.match(dis.strip())
        if m:
            out.add((m.group(1), int(m.group(2), 0)))
    return out


def _const_reaching(lines, ins, p, reg):
    li = ins[p][0]
    for q in range(p - 1, -1, -1):
        qi, ql = ins[q]
        if q == p - 1 and _src_is_branch(ql) and not _src_is_ret(ql):
            continue
        if any(_branch_target_label(lines, ins, x) for x in lines[qi:li]):
            return None                     # a join
        mq = re.match(r"\s*([a-z]+)\b", ql)
        if _src_is_branch(ql) and not (mq and mq.group(1) in _COND_BR_MN):
            return None                     # an unconditional transfer: unreachable
        if mq and mq.group(1) in _COND_BR_MN:
            continue                        # we are on its fall-through path
        d, _u = defs_uses(ql.split("#", 1)[0].strip())
        if reg in d:
            c = _CONST_DEF_S.match(ql)
            if c and _src_reg(c.group(1) or c.group(3)) == reg:
                return int(c.group(2) or c.group(4), 0)
            return None
    return None


def alu_const_fold_s(stext, allowed):
    if not allowed:
        return stext
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    changed = False
    for p, (li, l) in enumerate(ins):
        m = _ALU_REG_S.match(l)
        if not m:
            continue
        op = _ALU_IMM[m.group(2)]
        for src, cnt in ((m.group(4), m.group(5)), (m.group(5), m.group(4))):
            if m.group(2) in ("slt", "sltu") and cnt != m.group(5):
                continue                    # not commutative
            r = _src_reg(cnt)
            if not r or r == _src_reg("$0"):
                continue
            k = _const_reaching(lines, ins, p, r)
            if k is None or (op, k) not in allowed:
                continue
            if op in ("andi", "ori", "xori") and not 0 <= k <= 0xFFFF:
                continue
            if op in ("addiu", "slti", "sltiu") and not -0x8000 <= k < 0x8000:
                continue
            lines[li] = "%s%s\t%s,%s,%d" % (m.group(1), op, m.group(3), src, k)
            changed = True
            break
    return "\n".join(lines) if changed else stext


def shift_const_fold_pass(stext, tgt):
    stext = shift_const_fold_s(stext, target_imm_shifts(tgt))
    return alu_const_fold_s(stext, target_imm_alu(tgt))


# --------------------------------------------------------------------------
# zero-remat: our cc1 copies a register it knows holds zero (`move $d,$s` right
# after `move $s,$0`, e.g. two zero call arguments) where retail materializes the
# zero again (`addu $d,$zero,$zero`). Rewrite the copy to `move $d,$0` when the
# source register's straight-line reaching definition in the span is a zero
# materialization. Semantics-preserving ($s is 0 there). Target-guided: rewrites
# at most as many copies as the target has more zero materializations than ours,
# in source order. Count-preserving; runs PRE_SIGMA with shift_const_fold.
# --------------------------------------------------------------------------
_MOVE_S = re.compile(r"^(\s*)move\s+(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")
_ZERO_DEF_S = re.compile(
    r"^\s*(?:move\s+(\$\w+)\s*,\s*\$(?:0|zero)"
    r"|li\s+(\$\w+)\s*,\s*0"
    r"|(?:addu|or)\s+(\$\w+)\s*,\s*\$(?:0|zero)\s*,\s*\$(?:0|zero)"
    r"|(?:addiu|ori)\s+(\$\w+)\s*,\s*\$(?:0|zero)\s*,\s*0)\s*(#.*)?$")
_ZERO_TGT = re.compile(r"^(?:addu|or)\s+\S+\s*,\s*\$?zero\s*,\s*\$?zero\s*$"
                       r"|^(?:addiu|ori)\s+\S+\s*,\s*\$?zero\s*,\s*0x0*\s*$"
                       r"|^(?:move\s+\S+\s*,\s*\$?zero|li\s+\S+\s*,\s*0)\s*$")


def _noreorder_lines(lines):
    out, on = set(), False
    for x, l in enumerate(lines):
        t = l.strip()
        if t.startswith(".set") and "noreorder" in t:
            on = True
        elif t.startswith(".set") and t.split()[-1] == "reorder":
            on = False
        elif on:
            out.add(x)
    return out


def _zero_reach(lines, ins, p, reg, nr, depth=0):
    """`reg` holds zero on every path reaching insn ins[p]. Walks back on the
    straight line; at a join label every entrant branch must deliver zero too
    (its noreorder slot, else the path before it), and the fall-through only
    counts when the insn before the label is not the slot of a `j`."""
    li = ins[p][0]
    for q in range(p - 1, -1, -1):
        qi, ql = ins[q]
        if q == p - 1 and _src_is_branch(ql):
            continue            # we sit in its delay slot: it has not transferred yet
        labs = [x.strip()[:-1] for x in lines[qi + 1:li]
                if _s_is_label(x) and _branch_target_label(lines, ins, x)]
        if labs:
            if depth >= 4:
                return False
            for lab in labs:
                pat = re.compile(r"[\s,]" + re.escape(lab) + r"\s*$")
                for b, (bi, bl) in enumerate(ins):
                    if not pat.search(bl.split("#", 1)[0]) or not _src_is_branch(bl):
                        continue
                    if bi in nr and b + 1 < len(ins) and ins[b + 1][0] in nr:
                        sb = ins[b + 1][1].split("#", 1)[0].strip()
                        if reg in defs_uses(sb)[0]:
                            z = _ZERO_DEF_S.match(ins[b + 1][1])
                            if not (z and _src_reg(next(g for g in z.groups()[:4] if g)) == reg):
                                return False
                            continue
                    if not _zero_reach(lines, ins, b, reg, nr, depth + 1):
                        return False
            prev = ins[q - 1][1] if q > 0 else ""
            if (q > 0 and qi in nr and re.match(r"\s*(j|b)\s+\$L", prev)
                    and ins[q - 1][0] in nr):
                return True     # ql is the slot of a `j`: no fall-through entrant
        if re.match(r"\s*jal\s+[A-Za-z_]\w*\s*$", ql.split("#", 1)[0]) and \
                re.match(r"s[0-7]$|fp$|s8$", reg or ""):
            li = qi             # a call preserves the callee-saved registers
            continue
        if _src_is_branch(ql):
            # the fall-through of a conditional branch: it was not taken and
            # writes no register (its slot was scanned already): keep walking
            if ql.split("#", 1)[0].split(None, 1)[0].lower() in _COND_BR_MN:
                li = qi
                continue
            return False
        d, _u = defs_uses(ql.split("#", 1)[0].strip())
        if reg in d:
            z = _ZERO_DEF_S.match(ql)
            return bool(z) and _src_reg(next(g for g in z.groups()[:4] if g)) == reg
        li = qi
    return False


def zero_remat_s(stext, budget):
    if budget <= 0:
        return stext
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    changed = False
    for p, (li, l) in enumerate(ins):
        if budget <= 0:
            break
        m = _MOVE_S.match(l)
        if not m:
            continue
        src = _src_reg(m.group(3))
        if not src or src == _src_reg("$0"):
            continue
        if not _zero_reach(lines, ins, p, src, _noreorder_lines(lines)):
            continue
        lines[li] = "%smove\t%s,$0" % (m.group(1), m.group(2))
        budget -= 1
        changed = True
    return "\n".join(lines) if changed else stext


def _tail_count(dis_list, src=False):
    """Words after the `lw $ra` restore that are not frame loads, stack adjusts,
    returns or nops (the work the epilogue still does after reloading $ra).
    src=True: the list is cc1 source insns, weighted by their assembled length."""
    n = 0
    for d in dis_list:
        t = d.split("#", 1)[0].strip() if src else d.strip()
        p = t.split(None, 1)
        if not p:
            continue
        mn = p[0].lower()
        if mn in ("jr", "j") or is_nop(t):
            break
        if _frame_load(t) or _src_sp_delta(t) is not None:
            continue
        n += _src_nwords(t) if src else 1
    return n


# --------------------------------------------------------------------------
# ra-restore-sink: our cc1 (notably in no-split units, where a global store or an
# `la` is one macro insn to the scheduler) reloads `$ra` early in the epilogue,
# ahead of trailing global stores or the return-value setup; retail reloads it
# after them. Sink our `lw $31,K($sp)` past as many trailing words as the target
# still executes after its own `lw $ra`. Semantics-preserving: every insn passed is
# checked not to read or write $31/$sp and not to store into the frame word K;
# control flow and labels stop the move. Count-preserving text pass.
# --------------------------------------------------------------------------
_CALLEE_RS = {"s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp", "ra"}


def _callee_restore(body):
    """Dest reg of a callee-saved restore `lw $sN/$fp/$ra,K($sp)`, else None."""
    if not _frame_load(body):
        return None
    d, _u = defs_uses(body)
    d = set(d) & _CALLEE_RS
    return next(iter(d)) if len(d) == 1 else None


def _unit_permute(lines, blk, order):
    """Rewrite the line range covered by units `blk` [(a, z, body), ...] so unit
    order[k] occupies slot k; non-unit lines between units stay in place."""
    texts = [lines[a:z + 1] for a, z, _b in blk]
    seg = []
    for k, (a, z, _b) in enumerate(blk):
        seg.extend(texts[order[k]])
        nxt = blk[k + 1][0] if k + 1 < len(blk) else z + 1
        seg.extend(lines[z + 1:nxt])
    lines[blk[0][0]:blk[-1][1] + 1] = seg


def _unit_words(body):
    return 2 if re.search(r"%lo\(", body) else _src_nwords(body)


def callee_restore_sink_s(stext, tgt):
    """Second phase of ra_restore_sink: the whole callee-saved restore group.
    Retail can keep all `lw $sN/$ra` restores after trailing work (global stores,
    return setup) where our cc1 interleaves them. Hoist our earliest trailing work
    units above the first restore until the work left after it equals the
    target's. Each hoisted unit must not read/write a register restored by a load
    it passes, touch $sp, or store into the frame; labels/branches stop the move.
    Units are single insns or `.set noat` expanded symbolic accesses (moved whole)."""
    tl = [d for _w, d in tgt]
    rets = [i for i, d in enumerate(tl) if re.match(r"\s*jr\s+\$?ra\s*$", d.strip())]
    if not rets:
        return stext
    j = rets[-1]
    first = None
    for i in range(j - 1, -1, -1):
        mn = tl[i].split(None, 1)[0].lower() if tl[i].strip() else ""
        if mn.startswith("b") or mn in ("j", "jal", "jr", "jalr"):
            break
        if _callee_restore(tl[i].strip()):
            first = i
    if first is None:
        return stext
    want = _tail_count(tl[first + 1:])
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    blocks = _sm_units(lines, ins)
    orets = [i for i, l in ins if _src_is_ret(l)]
    if not orets or not blocks:
        return stext
    # the block that ends right before the return (the `.set noreorder` return
    # group starts the next block)
    before = [b for b in blocks if b[-1][1] < orets[-1]]
    if not before:
        return stext
    blk = before[-1]
    if any(i > blk[-1][1] and i < orets[-1] and not lines[i].strip().startswith(".set")
           for i, _l in ins):
        return stext
    bodies = [_sm_dep_body(b) for _a, _z, b in blk]
    rest = [k for k, b in enumerate(bodies) if _callee_restore(b)]
    if not rest:
        return stext
    k0 = rest[0]
    have = sum(_unit_words(b) for b in bodies[k0 + 1:]
               if not (_frame_load(b) or _src_sp_delta(b) is not None))
    need = have - want
    if need < 0:
        return stext
    hoist, passed = [], set()
    for k in range(k0, len(blk)):
        if need <= 0:
            break
        b = bodies[k]
        r = _callee_restore(b)
        if r:
            passed.add(r)
            continue
        if _src_sp_delta(b) is not None or _frame_load(b):
            return stext
        d, u = defs_uses(b)
        if (set(d) | set(u)) & (passed | {"sp"}):
            return stext
        hoist.append(k)
        need -= _unit_words(b)
    if need != 0:
        return stext
    if hoist:
        order = list(range(k0)) + hoist + [k for k in range(k0, len(blk)) if k not in hoist]
        _unit_permute(lines, blk, order)
    return _restore_group_order("\n".join(lines), tl, first, j)


def _restore_group_order(stext, tl, first, j):
    """When our epilogue ends in a contiguous run of callee-saved restores holding
    the same registers as the target's trailing run, emit them in the target's
    order (loads from distinct frame words into distinct regs commute)."""
    t_regs = [_callee_restore(tl[i].strip()) for i in range(first, j)]
    if not t_regs or None in t_regs:
        return stext
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    orets = [p for p, (_i, l) in enumerate(ins) if _src_is_ret(l)]
    if not orets:
        return stext
    pr = orets[-1]
    grp = []
    for p in range(pr - 1, -1, -1):
        r = _callee_restore(ins[p][1].split("#", 1)[0].strip())
        if not r:
            break
        grp.insert(0, (p, r))
    if len(grp) != len(t_regs) or sorted(r for _p, r in grp) != sorted(t_regs):
        return stext
    if any(_branch_target_label(lines, ins, x)
           for x in lines[ins[grp[0][0]][0] + 1:ins[grp[-1][0]][0]]):
        return stext
    by = {r: lines[ins[p][0]] for p, r in grp}
    for (p, _r), tr in zip(grp, t_regs):
        lines[ins[p][0]] = by[tr]
    return "\n".join(lines)


# --------------------------------------------------------------------------
# sched-match: retail sometimes keeps a straight-line block in source order where
# our sched2 hoists some insns (e.g. global stores of s-regs moved up so the
# restores can issue early). Match every insn of a straight-line source block to a
# target insn by a canonical key (mnemonic, regs, immediate / symbol; symbolic
# macros keyed by their symbol so `lui $at` halves are ignored), then emit the
# block in target order when every transposed pair is independent: no register
# RAW/WAR/WAW, and memory ops only transpose when neither stores or they touch
# provably different places (distinct symbols, or $sp frame vs a symbol, or
# disjoint $sp words). Blocks end at labels that are branch targets, branches,
# calls and `.set noreorder` regions. Count-preserving text pass.
# --------------------------------------------------------------------------
_SYM_RE = re.compile(r"%(?:hi|lo)\(([^)]+)\)")


def _sm_int(t):
    """Integer operand; also splat's `(K >> 16)` / `(K & 0xFFFF)` hi/lo forms."""
    m = re.fullmatch(r"\((-?0x[0-9A-Fa-f]+|-?\d+)\s*(>>\s*16|&\s*0xFFFF)\)", t.strip())
    if m:
        v = int(m.group(1), 0)
        return (v >> 16) & 0xFFFF if ">>" in m.group(2) else v & 0xFFFF
    try:
        return int(t, 0)
    except ValueError:
        return None


def _sm_key(body, target):
    p = body.split(None, 1)
    if not p:
        return None
    mn = p[0].lower()
    ops = [o.strip() for o in split_ops(p[1])] if len(p) > 1 else []
    if target:
        syms = _SYM_RE.findall(body)
        if syms:
            if mn == "lui":
                return "skip"
            reg = norm_reg(ops[0]) if ops else None
            if mn in ("addiu", "ori"):
                return ("la", reg, syms[0])
            return (mn, reg, syms[0])
    else:
        mo = _mem_operand(body)
        if mn in _STORE_MN or mn in ("lw", "lh", "lhu", "lb", "lbu"):
            if len(ops) == 2 and not mo and "(" not in ops[1]:
                return (mn, norm_reg(ops[0]), ops[1])
        if mn == "la" and len(ops) == 2:
            return ("la", norm_reg(ops[0]), ops[1])
        if mn == "move" and len(ops) == 2:
            mn, ops = "addu", [ops[0], ops[1], "$0"]
        elif mn == "li" and len(ops) == 2:
            v = _sm_int(ops[1])
            if v is not None and 0x8000 <= v <= 0xFFFF:
                mn, ops = "ori", [ops[0], "$0", ops[1]]     # the assembler's ori form
            elif v is None or not -0x8000 <= v < 0x8000:
                return None
            else:
                mn, ops = "addiu", [ops[0], "$0", ops[1]]
        elif mn == "subu" and len(ops) == 3 and _sm_int(ops[2]) is not None:
            mn, ops = "addiu", [ops[0], ops[1], str(-_sm_int(ops[2]))]
        elif mn == "addu" and len(ops) == 3 and _sm_int(ops[2]) is not None:
            mn = "addiu"
        elif (mn in ("slt", "sltu", "and", "or", "xor") and len(ops) == 3
              and _sm_int(ops[2]) is not None):
            # immediate operand macro: the assembler emits the -i form
            mn = {"slt": "slti", "sltu": "sltiu", "and": "andi", "or": "ori",
                  "xor": "xori"}[mn]
        elif mn in ("sll", "srl", "sra") and len(ops) == 3 and ops[2].startswith("$"):
            mn += "v"                       # shift by register: the assembler's -v form
    key = [mn]
    for o in ops:
        m = re.fullmatch(r"(-?(?:0x[0-9a-fA-F]+|\d+))\((\$?\w+)\)", o)
        if m:
            key += [int(m.group(1), 0), norm_reg(m.group(2))]
        elif _sm_int(o) is not None:
            key.append(_sm_int(o))
        elif o.startswith("$"):
            r = norm_reg(o)
            key.append("zero" if r in ("zero", "0") else r)
        else:
            return None
    return tuple(key)


def _sm_mem(body):
    """None (no memory), or (is_store, where) with where = ('sym', name) /
    ('sp', off, size) / ('any',)."""
    p = body.split(None, 1)
    mn = p[0].lower() if p else ""
    if not (mn in _STORE_MN or mn in ("lw", "lh", "lhu", "lb", "lbu", "lwl", "lwr")):
        return None
    st = mn in _STORE_MN
    mo = _mem_operand(body)
    if mo:
        return (st, ("sp", mo[1], mo[2]) if mo[0] == "sp" else ("any",))
    ops = split_ops(p[1]) if len(p) > 1 else []
    if len(ops) == 2 and "(" not in ops[1]:
        return (st, ("sym", re.split(r"[+-]", ops[1].strip())[0]))
    # indexed access into a named C object `op r,S+k($b)`: it stays inside S
    # (GCC's own alias rule: accesses based on distinct symbols never overlap)
    mx = re.fullmatch(r"([A-Za-z_]\w*)(?:[+-]\d+)?\(\$\w+\)", ops[1].strip()) if len(ops) == 2 else None
    if mx and norm_reg(mx.group(1)) is None:
        return (st, ("symx", mx.group(1)))
    return (st, ("any",))


def _sm_save_slot(body):
    """A callee-saved register save/restore `sw/lw $sN|$fp|$ra,K($sp)`."""
    mo = _mem_operand(body)
    if not mo or mo[0] != "sp":
        return False
    p = body.split(None, 1)
    if p[0].lower() not in ("sw", "lw"):
        return False
    return norm_reg(split_ops(p[1])[0].strip()) in _CALLEE_RS


def _sm_indep(a, b, stable=frozenset()):
    """`stable`: registers no insn of the block redefines, so two accesses based
    on one of them at disjoint offsets cannot alias."""
    da, ua = defs_uses(a)
    db, ub = defs_uses(b)
    da, ua, db, ub = set(da), set(ua), set(db), set(ub)
    if da & (db | ub) or ua & db:
        return False
    ma, mb = _sm_mem(a), _sm_mem(b)
    if ma and mb and (ma[0] or mb[0]):
        wa, wb = ma[1], mb[1]
        oa, ob = _mem_operand(a), _mem_operand(b)
        if (wa[0] == "any" and wb[0] == "any" and oa and ob and oa[0] == ob[0]
                and oa[0] in stable):
            return oa[1] + oa[2] <= ob[1] or ob[1] + ob[2] <= oa[1]
        if _sm_save_slot(a) or _sm_save_slot(b):
            if wa[0] != "sp" or wb[0] != "sp":
                return True
        if "symx" in (wa[0], wb[0]) and "any" not in (wa[0], wb[0]):
            if wa[0] == "sp" or wb[0] == "sp":
                return True                 # frame vs a named global object
            return wa[1] != wb[1]           # distinct objects (same one: unknown)
        if "any" in (wa[0], wb[0]):
            return False
        if wa[0] == "sym" and wb[0] == "sym":
            return wa[1] != wb[1]
        if wa[0] == "sp" and wb[0] == "sp":
            return wa[1] + wa[2] <= wb[1] or wb[1] + wb[2] <= wa[1]
        return True                         # frame vs global symbol
    return True


def _sm_units(lines, ins, la_tmp=None, reorder_after_br=False):
    """Straight-line blocks of movable units. A unit is one insn line, or an
    explicitly expanded symbolic access `.set noat; lui $1,%hi(S); op ..%lo(S)($1);
    .set at` (keyed and dependency-checked by its %lo insn). Returns
    [[(first_line, last_line, key_body), ...], ...]. With a `la_tmp` dict, a
    split address `lui $t,%hi(S); addiu $d,$t,%lo(S)` is one unit keyed
    `la $d,S` and la_tmp[(first, last)] = $t (the caller must prove $t private)."""
    blocks, cur, noreo, prev_br = [], [], False, False
    ins_at = {i for i, _l in ins}

    def flush():
        if len(cur) > 1:
            blocks.append(list(cur))
        del cur[:]
    i = 0
    while i < len(lines):
        l = lines[i]
        s = l.strip()
        if s.startswith(".set") and s.split()[-1] == "noat" and not noreo:
            j = i + 1
            grp = []
            while j < len(lines) and not (lines[j].strip().startswith(".set")
                                          and lines[j].strip().split()[-1] == "at"):
                if j in ins_at:
                    grp.append(j)
                j += 1
            if (j < len(lines) and len(grp) == 2 and not prev_br
                    and re.match(r"\s*lui\s+\$(?:1|at)\s*,\s*%hi\(", lines[grp[0]])):
                cur.append((i, j, lines[grp[1]].split("#", 1)[0].strip()))
                i = j + 1
                continue
            # indexed form `lui $1,%hi(S); addu $1,$1,$b; op $r,%lo(S)($1)`:
            # one unit keyed / dependency-checked as the macro `op $r,S($b)`
            if (j < len(lines) and len(grp) == 3 and not prev_br
                    and re.match(r"\s*lui\s+\$(?:1|at)\s*,\s*%hi\(", lines[grp[0]])):
                ma = re.match(r"\s*addu\s+\$(?:1|at)\s*,\s*\$(?:1|at)\s*,\s*(\$\w+)\s*$",
                              lines[grp[1]].split("#", 1)[0])
                m3 = re.match(r"\s*(lw|lh|lhu|lb|lbu|sw|sh|sb)\s+(\$\w+)\s*,\s*%lo\(([A-Za-z_]\w*(?:\+\d+)?)\)"
                              r"\(\$(?:1|at)\)\s*$", lines[grp[2]].split("#", 1)[0])
                if ma and m3 and norm_reg(ma.group(1)) not in ("at", None):
                    cur.append((i, j, "%s\t%s,%s(%s)" % (m3.group(1), m3.group(2),
                                                         m3.group(3), ma.group(1))))
                    i = j + 1
                    continue
            flush()
            i = j + 1
            prev_br = False
            continue
        if s.startswith(".set") and "noreorder" in s:
            noreo = True
        elif s.startswith(".set") and s.split()[-1] == "reorder":
            noreo = False
        if i in ins_at:
            br = bool(_src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l))
            if noreo or br or prev_br:
                was_prev = prev_br
                flush()
                prev_br = br
                # (reorder_after_br: in reorder mode the insn after a transfer is
                # not a delay slot, so it starts the next block as a movable unit)
                if not (was_prev and reorder_after_br and not noreo and not br):
                    i += 1
                    continue
            mh = re.match(r"\s*lui\s+(\$\w+)\s*,\s*%hi\(([^)]+)\)\s*$", l.split("#", 1)[0])
            if mh and mh.group(1) not in ("$1", "$at"):
                j = next((x for x, _l in ins if x > i), None)
                if j is not None and not any(_s_is_label(lines[y]) for y in range(i + 1, j)):
                    b2 = lines[j].split("#", 1)[0].strip()
                    # indexed form: `lui $r,%hi(S); addu $r,$r,$b; op $r,%lo(S)($r)`
                    idx = None
                    ma = re.match(r"addu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)$", b2)
                    if (ma and ma.group(1) == mh.group(1) and ma.group(2) == mh.group(1)
                            and ma.group(3) != mh.group(1)):
                        j2 = next((x for x, _l in ins if x > j), None)
                        if j2 is not None and not any(_s_is_label(lines[y])
                                                      for y in range(j + 1, j2)):
                            idx = ma.group(3)
                            j = j2
                            b2 = lines[j].split("#", 1)[0].strip()
                    m3 = re.match(r"addiu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*%lo\(([^)]+)\)$", b2)
                    if (la_tmp is not None and m3 and idx is None
                            and m3.group(2) == mh.group(1) and m3.group(3) == mh.group(2)
                            and m3.group(1) != mh.group(1)):
                        cur.append((i, j, "la\t%s,%s" % (m3.group(1), m3.group(3))))
                        la_tmp[(i, j)] = mh.group(1)
                        prev_br = False
                        i = j + 1
                        continue
                    if (la_tmp is not None and m3 and idx is None
                            and m3.group(2) == mh.group(1) and m3.group(3) == mh.group(2)
                            and m3.group(1) == mh.group(1)):
                        cur.append((i, j, "la\t%s,%s" % (m3.group(1), m3.group(3))))
                        prev_br = False
                        i = j + 1
                        continue
                    m2 = re.match(r"(\w+)\s+(\$\w+)\s*,\s*%lo\(([^)]+)\)\((\$\w+)\)$", b2)
                    if (m2 and m2.group(3) == mh.group(2) and m2.group(4) == mh.group(1)
                            and m2.group(2) == mh.group(1)
                            and m2.group(1).lower() in ("lw", "lh", "lhu", "lb", "lbu")):
                        sym = m2.group(3) + ("(%s)" % idx if idx else "")
                        cur.append((i, j, "%s\t%s,%s" % (m2.group(1), m2.group(2), sym)))
                        prev_br = False
                        i = j + 1
                        continue
            cur.append((i, i, l.split("#", 1)[0].strip()))
            prev_br = br
        elif _branch_target_label(lines, ins, l):
            flush()
        i += 1
    flush()
    return blocks


_SYM_MAP = []


def _sym_map():
    """({name: address}, {address: name}) of the named symbols in the splat symbol file
    (configs/<ver>/sym.*.txt next to tools/), so a renamed data symbol still resolves."""
    if not _SYM_MAP:
        by_name, by_addr = {}, {}
        root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        for p in sorted(glob.glob(os.path.join(root, "configs", "*", "sym.*.txt"))):
            for line in open(p, encoding="utf-8", errors="replace"):
                m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
                if m:
                    by_name[m.group(1)] = int(m.group(2), 16)
                    by_addr.setdefault(int(m.group(2), 16), m.group(1))
        _SYM_MAP.extend([by_name, by_addr])
    return _SYM_MAP[0], _SYM_MAP[1]


def _sym_addr(name):
    """Address of a `D_XXXXXXXX` placeholder or of a named symbol, else None."""
    m = re.fullmatch(r"D_([0-9A-Fa-f]{8})", name)
    if m:
        return int(m.group(1), 16)
    return _sym_map()[0].get(name)


def _sm_sym(s):
    """`SYM+k` -> the splat name of the address it resolves to (the symbol file's name
    for that address when it has one, else `D_XXXXXXXX`)."""
    m = re.fullmatch(r"([A-Za-z_]\w*)\+(\d+)", s)
    a = _sym_addr(m.group(1)) if m else None
    if a is None:
        return s
    a += int(m.group(2))
    return _sym_map()[1].get(a, "D_%08X" % a)


def _sm_srckey(body):
    m = re.match(r"(\w+)\s+(\$\w+)\s*,\s*%lo\(([^)]+)\)\(\$(?:1|at)\)\s*$", body)
    if m:
        return (m.group(1).lower(), norm_reg(m.group(2)), _sm_sym(m.group(3)))
    # indexed symbolic access macro `op $d,S($b)`: gas expands it to
    # `lui $d,%hi(S); addu $d,$d,$b; op $d,%lo(S)($d)` (a store through $at);
    # keyed by its %lo word
    m = re.match(r"(lw|lh|lhu|lb|lbu|sw|sh|sb)\s+(\$\w+)\s*,\s*([A-Za-z_]\w*(?:\+\d+)?)"
                 r"\((\$\w+)\)\s*$", body)
    if m and norm_reg(m.group(2)) not in ("1", "at"):
        return (m.group(1).lower(), norm_reg(m.group(2)), _sm_sym(m.group(3)))
    # a 2-word `li` (lui [+ ori]) is keyed by its lui word
    m = re.match(r"li\s+(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*$", body)
    if m:
        v = int(m.group(2), 0)
        if not (-0x8000 <= v <= 0xFFFF):
            return ("lui", norm_reg(m.group(1)), (v >> 16) & 0xFFFF)
    k = _sm_key(body, False)
    # `la $r,D_X+k` names the same address as the target's `D_(X+k)`
    if isinstance(k, tuple) and k and k[0] == "la":
        k = tuple(_sm_sym(x) if isinstance(x, str) else x for x in k)
    return k


def _sm_dep_body(body):
    """Body for dependency checks: an expanded `op $r,%lo(S)($1)` acts like the
    macro `op $r,S` (the $at temp is private to its unit)."""
    m = re.match(r"(\w+)\s+(\$\w+)\s*,\s*%lo\(([^)]+)\)\(\$(?:1|at)\)\s*$", body)
    return "%s\t%s,%s" % m.groups() if m else body


def _sm_dead_after(lines, last, reg):
    """`reg` is written before it is read on the straight line after line
    `last` (labels are passed through; a transfer or the end gives up)."""
    for j in range(last + 1, len(lines)):
        l = lines[j]
        if not _s_is_insn(l):
            continue
        if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
            return False
        d, u = defs_uses(_sm_dep_body(l.split("#", 1)[0].strip()))
        if reg in u:
            return False
        if reg in d:
            return True
    return False


def _sm_drift(anchors, line):
    """Drift of the nearest anchor unit (by line) or 0."""
    if not anchors:
        return 0
    return min(anchors, key=lambda a: abs(a[0] - line))[1]


def _sm_mask_s(k):
    """A key with callee-saved register names masked (before reg_realloc the
    s-registers may be permuted relative to the target)."""
    if not isinstance(k, tuple):
        return k
    return tuple("S" if isinstance(x, str) and re.match(r"s[0-7]$", x) else x for x in k)


# --------------------------------------------------------------------------
# block_iso: a straight-line block whose dataflow graph equals the target's but
# whose order AND temporaries differ (sched_match keys on registers, so it cannot
# pair the units). Target-guided, count-preserving: find the target window of the
# block's word count, pair every unit with a target unit of the same operation
# whose inputs are the same live-in registers or the paired producers (commutative
# ALU operands in either order), require every register live after the block to
# end with the paired value, and memory units that change relative order to be
# independent. Then emit the target's units: a single-word unit as the target
# insn, a symbolic access as our unit with its register renamed.
# --------------------------------------------------------------------------
_BI_ALU = {"addu", "addiu", "subu", "and", "andi", "or", "ori", "xor", "xori", "nor",
           "sll", "srl", "sra", "sllv", "srlv", "srav", "slt", "slti", "sltu", "sltiu",
           "lui", "lw", "lh", "lhu", "lb", "lbu", "sw", "sh", "sb", "la",
           "mult", "multu", "mfhi", "mflo"}
_BI_COMM = {"addu", "and", "or", "xor", "nor", "mult", "multu"}
_BI_WIDE = [False]      # set while block_iso_wide runs
_BI_TARGS = [set()]     # argument registers the target's block writes
_BI_HL = "hilo"         # the HI/LO pair as one value: mult/multu write it, mfhi/mflo read it
_BI_REGS = set(NUM2ABI) - {"zero"}


def _bi_unit(key):
    """(shape, dest, srcs) of a sched key, or None. Registers other than $zero
    become value slots; the first register is the destination except for stores."""
    if not isinstance(key, tuple) or not key or key[0] not in _BI_ALU:
        return None
    mn = key[0]
    regs = [(k, x) for k, x in enumerate(key) if k and isinstance(x, str) and x in _BI_REGS]
    if any(r == "at" for _k, r in regs):
        return None
    if mn not in _STORE_MN and regs and regs[0][1] in ("sp", "gp"):
        return None                         # the frame/global pointer is never rewritten
    shape = tuple("#" if (k and isinstance(x, str) and x in _BI_REGS) else x
                  for k, x in enumerate(key))
    if mn in ("mult", "multu", "mfhi", "mflo") and not _BI_WIDE[0]:
        return None
    if mn in ("mult", "multu"):
        return (shape, _BI_HL, [r for _k, r in regs]) if len(regs) == 2 else None
    if mn in ("mfhi", "mflo"):
        return (shape, regs[0][1], [_BI_HL]) if len(regs) == 1 else None
    if mn in _STORE_MN:
        return shape, None, [r for _k, r in regs]
    if not regs or regs[0][0] != 1:
        return None
    return shape, regs[0][1], [r for _k, r in regs[1:]]


def _bi_live_after(lines, last, reg):
    """Conservative: may `reg` be read after line `last`?"""
    if reg == _BI_HL:
        # HI/LO: read by a later mfhi/mflo before the next multiply/divide
        for j in range(last + 1, len(lines)):
            l = lines[j]
            if not _s_is_insn(l):
                continue
            mn = l.split("#", 1)[0].split(None, 1)[0].lower()
            if mn in ("mfhi", "mflo"):
                return True
            if mn in ("mult", "multu", "div", "divu", "mthi", "mtlo"):
                return False
            if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
                return True
        return True
    for j in range(last + 1, len(lines)):
        l = lines[j]
        if _s_is_label(l):
            continue                # other entrants do not matter on this path
        if not _s_is_insn(l):
            continue
        body = l.split("#", 1)[0].strip()
        mi = re.match(r"jal\s+\$\w+\s*,\s*(\$\w+)$|jalr\s+(\$\w+)$", body)
        if _BI_WIDE[0] and mi and reg != "at":
            # (block_iso_wide) an indirect call reads its target register and
            # only the argument registers the target's block sets up; it
            # clobbers the other caller-saved registers
            if reg == norm_reg(mi.group(1) or mi.group(2)):
                return True
            if reg in ("a0", "a1", "a2", "a3"):
                return reg in _BI_TARGS[0]
            return reg not in ("v0", "v1") and not re.match(r"t\d$", reg)
        if re.match(r"\s*jal\s+\w+\s*$", body):
            if reg in ("a0", "a1", "a2", "a3"):
                return True
            nb = next((lines[y] for y in range(j + 1, len(lines)) if _s_is_insn(lines[y])), "")
            d, u = defs_uses(_sm_dep_body(nb.split("#", 1)[0].strip())) if nb else (set(), set())
            if reg in u:
                return True             # the call's delay slot reads it
            # the callee clobbers the caller-saved temporaries
            return reg not in ("v0", "v1", "at") and not re.match(r"t\d$", reg)
        if _src_is_ret(l):
            return reg in _FF_RET_LIVE
        if _src_is_branch(l) or re.match(r"\s*jalr\b", l):
            return True
        d, u = defs_uses(_sm_dep_body(body))
        if reg in u:
            return True
        if reg in d:
            return False
    return True


def _bi_key(body):
    """Sched key of one of our units; an indexed symbolic access `op $r,S+k($b)`
    also carries its index register: (op, r, resolved S+k, b)."""
    m = re.match(r"(lw|lh|lhu|lb|lbu|sw|sh|sb)\s+(\$\w+)\s*,\s*([A-Za-z_]\w*(?:\+\d+)?)"
                 r"\((\$\w+)\)\s*$", body)
    if m and norm_reg(m.group(2)) not in ("1", "at") and norm_reg(m.group(4)) is not None:
        return (m.group(1).lower(), norm_reg(m.group(2)), _sm_sym(m.group(3)), norm_reg(m.group(4)))
    return _sm_srckey(body)


def _bi_tgt_units(tgt, a, n):
    """Target units covering n non-nop words from a: [(first_word, nwords, key)] or
    None. The assembler's load-delay nops inside the window are skipped (ours are
    not in the source text)."""
    out, k, end = [], a, a + n
    while k < end:
        if k >= len(tgt):
            return None
        d = tgt[k][1].strip()
        if d == "nop" and out:
            end += 1
            k += 1
            continue
        if is_branch(d) or re.match(r"\s*j", d):
            return None
        key = _sm_key(d, True)
        if key == "skip" and k + 2 < end:
            # indexed symbolic access `lui $at,%hi(S); addu $at,$at,$b; op $r,%lo(S)($at)`
            ma = re.match(r"addu\s+\$at\s*,\s*\$at\s*,\s*(\$\w+)$", tgt[k + 1][1].strip())
            m3 = re.match(r"(\w+)\s+(\$\w+)\s*,\s*%lo\(([\w.$]+)\)\(\$at\)$", tgt[k + 2][1].strip())
            if ma and m3:
                out.append((k, 3, (m3.group(1).lower(), norm_reg(m3.group(2)), m3.group(3),
                                   norm_reg(ma.group(1)))))
                k += 3
                continue
            # (block_iso_wide) the same load expanded through its own destination
            mh = re.match(r"lui\s+(\$\w+)\s*,\s*%hi\(([\w.$]+)\)$", d)
            ma = re.match(r"addu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)$", tgt[k + 1][1].strip())
            m3 = re.match(r"(lw|lh|lhu|lb|lbu)\s+(\$\w+)\s*,\s*%lo\(([\w.$]+)\)\((\$\w+)\)$",
                          tgt[k + 2][1].strip())
            if (_BI_WIDE[0] and mh and ma and m3 and m3.group(3) == mh.group(2)
                    and norm_reg(mh.group(1)) == norm_reg(ma.group(1)) == norm_reg(ma.group(2))
                    == norm_reg(m3.group(2)) == norm_reg(m3.group(4))):
                out.append((k, 3, (m3.group(1).lower(), norm_reg(m3.group(2)), m3.group(3),
                                   norm_reg(ma.group(3)))))
                k += 3
                continue
        if key == "skip":
            if k + 1 >= end:
                return None
            k2 = _sm_key(tgt[k + 1][1].strip(), True)
            if not isinstance(k2, tuple):
                return None
            out.append((k, 2, k2))
            k += 2
            continue
        if not isinstance(key, tuple) or _SYM_RE.findall(d):
            return None
        out.append((k, 1, key))
        k += 1
    return out


def _bi_match(ou, tu):
    """Unit pairing pi (ours -> target) with equal dataflow, or None."""
    n = len(ou)

    def vals(units):
        cur, res = {}, []
        for sh, dst, srcs in units:
            res.append([cur.get(r, ("in", r)) for r in srcs])
            if dst:
                cur[dst] = ("u", len(res) - 1)
        return res, cur
    ov, ofin = vals(ou)
    tv, tfin = vals(tu)
    pi, used = [None] * n, set()
    steps = [0]

    def ok_in(i, t):
        if ou[i][0] != tu[t][0]:
            return False
        a = [x if x[0] == "in" else ("u", pi[x[1]]) for x in ov[i]]
        b = tv[t]
        if a == b:
            return True
        return ou[i][0][0] in _BI_COMM and len(a) == 2 and a == b[::-1]

    def go(i):
        if i == n:
            return True
        steps[0] += 1
        if steps[0] > 20000:
            return False
        for t in range(n):
            if t not in used and ok_in(i, t):
                pi[i] = t
                used.add(t)
                if go(i + 1):
                    return True
                used.discard(t)
        pi[i] = None
        return False
    if not go(0):
        return None
    return pi, ofin, tfin


def _bi_reg_text(tok):
    """cc1's spelling of a register: $sp/$fp/$gp by name, the rest numbered."""
    r = norm_reg(tok)
    if r is None:
        return tok
    return "$" + r if r in ("sp", "fp", "gp") else "$%d" % ABI2NUM[r]


def _bi_op_text(o):
    o = re.sub(r"\$\w+", lambda m: _bi_reg_text(m.group(0)), o.strip())
    return re.sub(r"(?<![\w$])(-?)0x([0-9a-fA-F]+)", lambda m: str(int(m.group(1) + m.group(2), 16)), o)


def _bi_try(lines, blk, tkeys, tgt, wpos, anchors=()):
    """One block_iso attempt on units `blk`: (pi, tw), "same" or None."""
    ou, nw = [], []
    for a, z, b in blk:
        u = _bi_unit(_bi_key(b))
        if u is None:
            break
        dd, uu = defs_uses(_sm_dep_body(b))
        dd, uu = set(dd) - {"at"}, set(uu) - {"at"}
        if dd & {"hi", "lo"}:
            dd = (dd - {"hi", "lo"}) | {_BI_HL}
        if uu & {"hi", "lo"}:
            uu = (uu - {"hi", "lo"}) | {_BI_HL}
        if dd != ({u[1]} if u[1] else set()) or uu != set(u[2]):
            break                       # the key does not carry every register
        ou.append(u)
        nw.append(sum(_src_nwords(lines[y]) for y in range(a, z + 1) if _s_is_insn(lines[y])))
    if len(ou) != len(blk) or len(blk) < 3 or blk[0][0] not in wpos:
        return None
    span = sum(nw)
    starts = set()
    off = 0
    for (a, z, b), k in zip(blk, nw):
        key = _sm_srckey(b)
        qs = [q for q, tk in enumerate(tkeys) if tk == key]
        for q in qs:
            # the key sits on the unit's last word; step back over the words
            # before it, not counting the target's load-delay nops
            st, need = q, off + k - 1
            while need > 0 and st > 0:
                st -= 1
                if tgt[st][1].strip() != "nop":
                    need -= 1
            starts.add(st)
            starts.add(q - off)
        off += k
    est = wpos[blk[0][0]] + _sm_drift(anchors, blk[0][0])
    for st in sorted(starts, key=lambda q: abs(q - est)):
        if st < 0 or st >= len(tgt) or (anchors and abs(st - est) > 8):
            continue                    # another block with the same shape
        tw = _bi_tgt_units(tgt, st, span)
        if tw is None or len(tw) != len(ou):
            continue
        tu = [_bi_unit(k) for _f, _n, k in tw]
        if any(x is None for x in tu):
            continue
        m = _bi_match(ou, tu)
        if m is None:
            continue
        pi, ofin, tfin = m
        if all(pi[i] == i for i in range(len(pi))) and all(
                ou[i][1] == tu[i][1] and ou[i][2] == tu[i][2] for i in range(len(pi))):
            return "same"               # already the target's block
        if any(nw[i] != tw[pi[i]][1] for i in range(len(pi))):
            continue
        last = blk[-1][1]
        bad = False
        _BI_TARGS[0] = {r for r in tfin if r in ("a0", "a1", "a2", "a3")}
        for r in set(ofin) | set(tfin):
            if not _bi_live_after(lines, last, r):
                continue
            if r not in ofin or r not in tfin or pi[ofin[r][1]] != tfin[r][1]:
                bad = True
                break
        if bad:
            continue
        # memory units that change relative order must be independent
        bodies = [_sm_dep_body(b) for _a, _z, b in blk]
        for x in range(len(blk)):
            for y in range(x + 1, len(blk)):
                if pi[x] > pi[y] and _sm_mem(bodies[x]) and _sm_mem(bodies[y]):
                    mx, my = _sm_mem(bodies[x]), _sm_mem(bodies[y])
                    if (mx[0] or my[0]) and not _bi_mem_indep(mx, my, bodies[x], bodies[y]):
                        bad = True
        if bad:
            continue
        # the assembler pads a load directly followed by a reader of its
        # destination: the new order must need exactly the target's nops
        order = sorted(range(len(pi)), key=lambda i: pi[i])
        haz = sum(1 for p, q in zip(order, order[1:])
                  if ou[p][0][0] in ("lw", "lh", "lhu", "lb", "lbu") and ou[p][1]
                  and ou[p][1] in ou[q][2])
        if _BI_WIDE[0]:
            # (block_iso_wide) count by dataflow: the emitted registers are the
            # target's, so q reads p exactly when p produces one of q's inputs
            cur, prod = {}, []
            for u in ou:
                prod.append({cur[r] for r in u[2] if r in cur})
                if u[1]:
                    cur[u[1]] = len(prod) - 1
            haz = sum(1 for p, q in zip(order, order[1:])
                      if ou[p][0][0] in ("lw", "lh", "lhu", "lb", "lbu") and p in prod[q])
        tnops = tw[-1][0] + tw[-1][1] - st - span
        if haz != tnops:
            continue
        return pi, tw
    return None


def _bi_drop_hnops(lines, blk):
    """Units of `blk` minus explicit `nop` units right after a load (cc1 wrote the
    load-delay nop into the text, e.g. after param_copy moved a copy out of it),
    and the line numbers of those nops. The nop is not part of the dataflow; the
    new order must need exactly the target's nops (checked in _bi_try), and the
    assembler pads a hazard, so an edited block drops them."""
    out, drop = [], []
    for u in blk:
        if (re.match(r"\s*nop\s*$", u[2]) and out
                and re.match(r"(lw|lh|lhu|lb|lbu)\s", out[-1][2].strip())):
            drop.extend(y for y in range(u[0], u[1] + 1) if _s_is_insn(lines[y]))
            continue
        out.append(u)
    return out, drop


_BI_NOP = [False]


def block_iso_nop_pass(stext, tgt):
    """block_iso that sees through an explicit load-delay nop unit (see
    _bi_drop_hnops). Separate token: plain block_iso would re-emit a matched
    function's nop as the assembler's pad."""
    _BI_NOP[0] = True
    try:
        return block_iso_pass(stext, tgt)
    finally:
        _BI_NOP[0] = False


def block_iso_wide_pass(stext, tgt):
    """block_iso that also pairs mult/multu/mfhi/mflo units (HI/LO as one value)
    and tries every sub-window of a block of at least 3 units, not only up to 7
    head / 3 tail units trimmed (a block move ahead of the reordered part)."""
    _BI_WIDE[0] = True
    try:
        return block_iso_pass(stext, tgt, wide=True)
    finally:
        _BI_WIDE[0] = False


def block_iso_pass(stext, tgt, wide=False):
    if not tgt:
        return stext
    tkeys = [_sm_key(d.strip(), True) for _w, d in tgt]
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    wpos, w = {}, 0
    for i, l in ins:
        wpos[i] = w
        w += _src_nwords(l)
    blocks = _sm_units(lines, ins, None, reorder_after_br=True)
    # anchors (as sched_match): units whose key occurs once in the target
    anchors = []
    for blk0 in blocks:
        for u in blk0:
            k = _sm_srckey(u[2])
            qs = [q for q, tk in enumerate(tkeys) if k is not None and tk == k]
            if len(qs) == 1 and u[0] in wpos:
                anchors.append((u[0], qs[0] - wpos[u[0]]))
    edits = []
    for blk0 in blocks:
        # the whole block, else with up to 7 units trimmed at the head or 3 at the
        # tail (a block boundary the target has and we lack, or a
        # unit the target moved into a delay slot leaves the window)
        hnops = []
        if _BI_NOP[0]:
            blk0, hnops = _bi_drop_hnops(lines, blk0)
        n0 = len(blk0)
        subs = sorted({(i, j) for i in range(max(1, n0 - 2) if wide else min(8, n0))
                       for j in range(i + 3 if wide else max(i + 3, n0 - 3), n0 + 1)},
                      key=lambda ij: (ij[0] - ij[1], ij[0]))
        for i, j in subs:
            blk = blk0[i:j]
            r = _bi_try(lines, blk, tkeys, tgt, wpos, anchors)
            if r == "same" and (i, j) == (0, n0):
                break
            if r and r != "same":
                edits.append((blk, r[0], r[1],
                              [y for y in hnops if blk[0][0] < y < blk[-1][0]]))
                break
    if not edits:
        return stext
    for blk, pi, tw, hn in sorted(edits, key=lambda e: -e[0][0][0]):
        for y in hn:
            lines[y] = _src_indent(lines[y]) + "#nop"
        for i, (a, z, b) in enumerate(blk):
            f, n, _k = tw[pi[i]]
            if n == 1:
                d = tgt[f][1].strip()
                p = d.split(None, 1)
                ops = ",".join(_bi_op_text(o) for o in split_ops(p[1])) if len(p) > 1 else ""
                insl = [y for y in range(a, z + 1) if _s_is_insn(lines[y])]
                lines[insl[0]] = _src_indent(lines[insl[0]]) + p[0] + ("\t" + ops if ops else "")
            else:
                mp = {}
                okey, tkey = _bi_key(b), tw[pi[i]][2]
                for x, y in zip(okey, tkey):
                    if isinstance(x, str) and x in _BI_REGS and isinstance(y, str):
                        mp[x] = y
                for y in range(a, z + 1):
                    if _s_is_insn(lines[y]) and not re.match(r"\s*lui\s+\$(?:1|at)\s*,", lines[y]):
                        lines[y] = re.sub(r"\$\w+", lambda m: (
                            "$%d" % ABI2NUM[mp[norm_reg(m.group(0))]]
                            if norm_reg(m.group(0)) in mp else m.group(0)), lines[y])
        order = sorted(range(len(blk)), key=lambda i: pi[i])
        _unit_permute(lines, blk, order)
    return "\n".join(lines)


def _bi_mem_indep(mx, my, bx, by):
    wx, wy = mx[1], my[1]
    if wx[0] == "sym" and wy[0] == "sym":
        return wx[1] != wy[1]
    if wx[0] == "sp" and wy[0] == "sp":
        return wx[1] + wx[2] <= wy[1] or wy[1] + wy[2] <= wx[1]
    if "sp" in (wx[0], wy[0]) and ("sym" in (wx[0], wy[0]) or "symx" in (wx[0], wy[0])):
        return True
    if wx[0] in ("sym", "symx") and wy[0] in ("sym", "symx"):
        return wx[1] != wy[1]               # distinct named objects never overlap
    return False


# --------------------------------------------------------------------------
# slot_unsteal: cc1's reorg fills a backward loop branch's slot with the loop
# counter update it takes from the loop's compare entry (`j Lx; INC` enters the
# loop, the body falls into `Lx: C; bc Lbody; INC`). Retail keeps INC at the end
# of the body, right before Lx, and fills the branch slot from the fall-through
# (the next jump's slot insn), leaving that jump with a nop. Target-guided (the
# target's slot is not INC and INC sits right before the target's compare).
# Semantics: Lbody is entered only by this branch (no fall-in, one reference) and
# the body Lbody..Lx neither reads nor writes INC's registers, so INC after the
# body equals INC before it; INC's destination is dead on the fall-through; the
# hoisted slot insn's destination is dead on the taken path.
# --------------------------------------------------------------------------
def _us_dead_ft(lines, ins, j, reg):
    """`reg` is dead on the straight line starting after line j (a return
    reads only $v0 and the callee-saved registers; `j L` follows the label)."""
    k = j
    while True:
        k = _tf_next_insn(lines, k)
        if k is None:
            return False
        body = lines[k].split("#", 1)[0].strip()
        if _src_is_ret(lines[k]):
            sl = _tf_next_insn(lines, k)
            if sl is not None and sl in _noreorder_lines(lines) and \
                    reg in defs_uses(lines[sl].split("#", 1)[0].strip())[1]:
                return False
            return reg not in _FF_RET_LIVE
        mj = re.match(r"j\s+(\$L\w+)\s*$", body)
        if mj:
            sl = _tf_next_insn(lines, k)
            if sl is not None and sl in _noreorder_lines(lines):
                d, u = defs_uses(lines[sl].split("#", 1)[0].strip())
                if reg in u:
                    return False
                if reg in d:
                    return True
            return _ff_dead_on(lines, ins, mj.group(1), reg)
        mc = re.match(r"jal\s+([A-Za-z_]\w*)\s*$", body)
        if mc and reg in ("v0", "v1") or mc and re.match(r"t\d$", reg or ""):
            # a direct call clobbers the caller-saved non-argument registers;
            # only its delay slot (noreorder) can still read the old value
            sl = _tf_next_insn(lines, k)
            if sl is not None and sl in _noreorder_lines(lines) and \
                    reg in defs_uses(lines[sl].split("#", 1)[0].strip())[1]:
                return False
            return True
        if _src_is_branch(lines[k]) or re.match(r"\s*jalr?\b", lines[k]):
            return False
        d, u = defs_uses(_sm_dep_body(body))
        if reg in u:
            return False
        if reg in d:
            return True


def slot_unsteal_pass(stext, tgt):
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    ours = _tf_branches(lines)
    if len(ours) != len(tb):
        return stext
    for k in range(len(ours)):
        ours = _tf_branches(lines)
        bi, nr = ours[k]
        tk = tb[k]
        if not nr or tk + 1 >= len(tgt):
            continue
        mb = re.match(r"\s*\w+\s+.*,\s*(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        si = _tf_next_insn(lines, bi)
        nrs = _noreorder_lines(lines)
        if not mb or si is None or si not in nrs:
            continue
        lbody = mb.group(1)
        inc = _ff_word_form(lines[si].split("#", 1)[0].strip())
        if inc is None:
            continue
        d, u = defs_uses(inc)
        if len(d) != 1:
            continue
        r = next(iter(d))
        ik = _sm_key(inc, False)
        if _sm_key(tgt[tk + 1][1].strip(), True) == ik:
            continue
        if not any(_sm_key(tgt[q][1].strip(), True) == ik for q in range(max(0, tk - 3), tk)):
            continue
        lb = next((y for y in range(bi) if lines[y].strip() == lbody + ":"), None)
        if lb is None:
            continue
        refs = sum(1 for y, l in enumerate(lines) if _s_is_insn(l) and re.search(
            re.escape(lbody) + r"\b", l.split("#", 1)[0]))
        if refs != 1:
            continue
        # no fall-in: the insn before Lbody is the slot of an unconditional jump
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        prev = [i for i, _l in ins if i < lb]
        if len(prev) < 2 or prev[-1] not in nrs or not re.match(
                r"\s*(j|b)\s", lines[prev[-2]]):
            continue
        labs = [y for y in range(lb + 1, bi) if re.match(r"\s*\$L\w+:", lines[y])]
        if len(labs) != 1:
            continue
        lx = labs[0]
        body = [y for y in range(lb + 1, lx) if _s_is_insn(lines[y])]
        regs = set(d) | set(u)
        if not body or any(_src_is_branch(lines[y]) or re.match(r"\s*jalr?\b", lines[y])
                           or regs & (set(defs_uses(_sm_dep_body(
                               lines[y].split("#", 1)[0].strip()))[0])
                               | set(defs_uses(_sm_dep_body(
                                   lines[y].split("#", 1)[0].strip()))[1]))
                           for y in body):
            continue
        if not _us_dead_ft(lines, ins, si, r):
            continue
        new = list(lines)
        new[si] = _src_indent(lines[si]) + "nop"
        # refill from the fall-through: the next jump's slot insn, when the
        # target's slot holds it and its destination is dead on the taken path
        end = si + 1
        while end < len(new) and new[end].strip().startswith(".set"):
            end += 1
        ji = _tf_next_insn(new, si)
        if ji is not None and ji in nrs and re.match(r"\s*j\s", new[ji]):
            js = _tf_next_insn(new, ji)
            if js is not None and js in nrs:
                fx = _ff_word_form(new[js].split("#", 1)[0].strip())
                if fx is not None and _sm_key(tgt[tk + 1][1].strip(), True) == _sm_key(fx, False):
                    dx = defs_uses(fx)[0]
                    ins2 = [(i, l) for i, l in enumerate(new) if _s_is_insn(l)]
                    if len(dx) == 1 and _ff_dead_on(new, ins2, lbody, next(iter(dx))):
                        new[si] = _src_indent(lines[si]) + fx
                        new[js] = _src_indent(new[js]) + "nop"
        new.insert(lx, _src_indent(lines[body[-1]]) + inc)
        lines = new
    return "\n".join(lines)


_SM_LOADS = {"lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr"}


def _sm_symload(k):
    """A sched key `(load, dest, SYMBOL)` of a symbolic (non-frame) load."""
    return (isinstance(k, tuple) and len(k) == 3 and k[0] in _SM_LOADS
            and isinstance(k[2], str) and norm_reg(k[2]) is None
            and re.match(r"[A-Za-z_.]", k[2]) is not None)


def sched_pre_pass(stext, tgt):
    """sched_match before sigma (PRE_SIGMA, count-preserving): units whose exact
    key has no target match are paired by their key with the s-registers masked,
    so a block whose s-registers are permuted can be put in target order first
    and sigma is then derived from aligned code."""
    return sched_match_pass(stext, tgt, mask_s=True)


def sched_match_pass(stext, tgt, mask_s=False):
    tkeys = [_sm_key(d.strip(), True) for _w, d in tgt]
    tmask = [_sm_mask_s(k) for k in tkeys]
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    used = set()
    edits = []
    # a unit with no target match (e.g. `la $r,S+4` that splat names by the
    # address it resolves to) is a barrier: reorder the matched runs around it
    runs = []
    la_tmp = {}
    blocks = _sm_units(lines, ins, la_tmp, reorder_after_br=True)
    wpos, w = {}, 0
    for i, l in ins:
        wpos[i] = w
        w += _src_nwords(l)
    for x in range(len(lines)):             # units may start at a `.set` line
        if x not in wpos:
            nx = next((i for i, _l in ins if i > x), None)
            if nx is not None:
                wpos[x] = wpos[nx]
    # anchors: units whose key occurs exactly once in the target give the drift
    # between our word estimate (no assembler nops) and the target index
    anchors = []
    for blk0 in blocks:
        for u in blk0:
            k = _sm_srckey(u[2])
            qs = [q for q, tk in enumerate(tkeys) if k is not None and tk == k]
            if len(qs) == 1 and u[0] in wpos:
                anchors.append((u[0], qs[0] - wpos[u[0]]))
    for blk0 in blocks:
        # a split-address temp is private when only its own `la` units touch it
        # in the block and it is written before read after the block: then the
        # units depend on each other only through their destinations
        tmps = {la_tmp[(u[0], u[1])] for u in blk0 if (u[0], u[1]) in la_tmp}
        bad = set()
        for t in tmps:
            rt = norm_reg(t)
            for u in blk0:
                if la_tmp.get((u[0], u[1])) == t:
                    continue
                du = defs_uses(_sm_dep_body(u[2]))
                if rt in du[0] or rt in du[1]:
                    bad.add(t)
            if t not in bad and not _sm_dead_after(lines, blk0[-1][1], rt):
                bad.add(t)
        cur = []
        for u in blk0:
            k = _sm_srckey(u[2])
            if la_tmp.get((u[0], u[1])) in bad:
                k = None                    # not private: a barrier
            if u[2].split(None, 1)[0].lower() == "nop":
                k = None                    # an explicit load-delay nop stays put
            # a key can repeat (`move a1,a3` on several paths): take the unused
            # target occurrence nearest to where this unit sits
            cands = [q for q, tk in enumerate(tkeys)
                     if k is not None and tk == k and q not in used]
            if not cands and mask_s and k is not None:
                km = _sm_mask_s(k)
                if km != k:
                    cands = [q for q, tk in enumerate(tmask) if tk == km and q not in used]
            if not cands and mask_s and _sm_symload(k):
                # before sigma a load's destination temporary may differ from
                # the target's: pair by (op, symbol) when that is unique
                cands = [q for q, tk in enumerate(tkeys) if q not in used and _sm_symload(tk)
                         and tk[0] == k[0] and tk[2] == k[2]]
                if len(cands) != 1:
                    cands = []
            est = wpos.get(u[0], 0) + _sm_drift(anchors, u[0])
            t = min(cands, key=lambda q: (abs(q - est), q)) if cands else None
            if t is None:
                if len(cur) > 1:
                    runs.append(cur)
                cur = []
                continue
            used.add(t)
            cur.append((u, t))
        if len(cur) > 1:
            runs.append(cur)
    for run in runs:
        blk = [u for u, _t in run]
        pos = [t for _u, t in run]
        bodies = [_sm_dep_body(b) for _a, _z, b in blk]
        order = sorted(range(len(blk)), key=lambda x: pos[x])
        if order == list(range(len(blk))):
            continue
        # a base register is stable for a pair when no unit between the two (in
        # our order) redefines it: every unit that does keeps its order against
        # both accesses (it writes what they read), so both see one value
        defs_at = [set(defs_uses(b)[0]) for b in bodies]

        def stable_for(y, x):
            s = set(defs_uses(bodies[x])[1]) | set(defs_uses(bodies[y])[1])
            for z in range(y + 1, x):
                s -= defs_at[z]
            return frozenset(s)
        if not all(_sm_indep(bodies[x], bodies[y], stable_for(y, x))
                   for a_, x in enumerate(order) for y in order[a_ + 1:] if y < x):
            continue
        edits.append((blk, order))
    if not edits:
        return stext
    for blk, order in sorted(edits, key=lambda e: -e[0][0][0]):
        _unit_permute(lines, blk, order)
    return "\n".join(lines)


# --------------------------------------------------------------------------
# fallthrough-fill: in units assembled by aspsx with cc1 delay filling off
# (`nosplit_nodb` / `nodb`), a conditional branch's delay slot is filled with the
# FIRST instruction of the fall-through path when that instruction is harmless on
# the taken path (a pure ALU/lui write of a register the taken path redefines
# before reading). cc1 leaves those branches unfilled (the assembler pads a nop).
# Target-guided: the k-th conditional branch of ours is paired with the k-th of
# the target; fire only when the target's slot holds our fall-through insn.
# Semantics: the moved insn now also runs on the taken path, so its destination
# must be dead there (straight-line scan from the target label: written before
# read; a return counts as a read of $v0 and of callee-saved registers; $v1 is
# treated as dead there: no 64-bit returns in this code).
# Count-preserving text pass (the assembler's nop is replaced by the moved word).
# --------------------------------------------------------------------------
_FF_ALU = {"addu", "addiu", "subu", "and", "andi", "or", "ori", "xor", "xori",
           "nor", "sll", "srl", "sra", "sllv", "srlv", "srav", "slt", "slti",
           "sltu", "sltiu", "lui", "li", "move"}
_FF_RET_LIVE = {"v0", "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp",
                "sp", "ra", "gp"}


def _ff_word_form(body):
    """The single-word spelling of a 1-word source insn (`li $r,K` with K = hi<<16
    becomes `lui $r,hi`), or None when it is not a 1-word pure-ALU insn."""
    p = body.split(None, 1)
    if not p or p[0].lower() not in _FF_ALU:
        return None
    if p[0].lower() != "li" and _src_nwords(body) != 1:
        return None
    if p[0].lower() == "li":
        ops = split_ops(p[1])
        v = _sm_int(ops[1].strip()) if len(ops) == 2 else None
        if v is None:
            return None
        if -0x8000 <= v < 0x8000:
            return "addiu\t%s,$0,%d" % (ops[0].strip(), v)
        if 0 <= v <= 0xFFFF:
            return "ori\t%s,$0,%d" % (ops[0].strip(), v)
        if v & 0xFFFF:
            return None
        return "lui\t%s,0x%x" % (ops[0].strip(), (v >> 16) & 0xFFFF)
    return body


_ASM_ROOT = None          # set by normalize_s from ctx["asm_root"]
_UNIT_ROOT = None         # ctx["asm_unit_root"]: searched first by find_target_s
_FN_ADDR = {}


def _fn_addr(name):
    """Start address of function `name`: the hex suffix of a placeholder name
    (the splat placeholder form, hex address after `_`), else the first instruction's address in its retail .s
    (a renamed function), else None."""
    m = re.search(r"_([0-9A-Fa-f]{8})$", name)
    if m:
        return int(m.group(1), 16)
    if name not in _FN_ADDR:
        a = None
        p = find_target_s(_ASM_ROOT, name) if _ASM_ROOT else None
        if p:
            for line in open(p, encoding="utf-8", errors="replace"):
                mm = re.search(r"/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+[0-9A-Fa-f]{8}\s*\*/", line)
                if mm:
                    a = int(mm.group(1), 16)
                    break
        _FN_ADDR[name] = a
    return _FN_ADDR[name]
_CALLEE_S = {}
_CALLEE_RD = {}


def _callee_insns(fn):
    """The retail asm of `fn` as a list of insn texts, with "LABEL" markers."""
    if fn not in _CALLEE_S:
        p = find_target_s(_ASM_ROOT, fn) if _ASM_ROOT else None
        out = []
        if p:
            pat = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+[0-9A-Fa-f]{8}\s*\*/\s+(.*)$")
            for line in open(p, encoding="utf-8", errors="replace"):
                m = pat.search(line)
                if m:
                    out.append(re.sub(r"\s+", " ", m.group(1).strip()))
                elif re.match(r"\s*\.L\w+:", line):
                    out.append("LABEL")
        _CALLEE_S[fn] = out or None
    return _CALLEE_S[fn]


_CALLEE_CFG = {}


def _callee_cfg(fn):
    """The retail asm of `fn` as [(insn, label or None)], or None."""
    if fn not in _CALLEE_CFG:
        p = find_target_s(_ASM_ROOT, fn) if _ASM_ROOT else None
        out, lab = [], []
        if p:
            pat = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+[0-9A-Fa-f]{8}\s*\*/\s+(.*)$")
            pend = []
            for line in open(p, encoding="utf-8", errors="replace"):
                m = pat.search(line)
                if m:
                    out.append(re.sub(r"\s+", " ", m.group(1).strip()))
                    lab.append(pend)
                    pend = []
                else:
                    ml = re.match(r"\s*(\.L\w+):", line)
                    if ml:
                        pend.append(ml.group(1))
        _CALLEE_CFG[fn] = (out, lab) if out else None
    return _CALLEE_CFG[fn]


def _callee_reads_flow(fn, reg, depth):
    """Dataflow form of _callee_reads; None when the CFG cannot be built."""
    cfg = _callee_cfg(fn)
    if cfg is None:
        return None
    body, labs = cfg
    at = {}
    for i, ls in enumerate(labs):
        for l in ls:
            at[l] = i
    nb = len(body)
    xfer = {"j", "b", "jal", "jalr", "jr"} | _COND_BR_MN

    def mnem(i):
        return body[i].split(None, 1)[0].lower()
    succ = [[] for _ in range(nb)]
    call_after = {}                          # slot index -> callee name (or "?")
    for i in range(nb):
        if i > 0 and mnem(i - 1) in xfer:
            continue                         # a delay slot: set by its transfer
        mn = mnem(i)
        if mn not in xfer:
            succ[i] = [i + 1] if i + 1 < nb else []
            continue
        if i + 1 >= nb:
            return None
        succ[i] = [i + 1]
        ops = body[i].split(None, 1)[1] if " " in body[i] else ""
        tgt = re.search(r"(\.L\w+)", ops)
        if mn in ("jal", "jalr"):
            mc = re.match(r"jal (\w+)$", body[i])
            call_after[i + 1] = mc.group(1) if mc else "?"
            succ[i + 1] = [i + 2] if i + 2 < nb else []
        elif mn == "jr":
            if norm_reg(ops.strip()) != "ra":
                return None                  # jump table: give up
            succ[i + 1] = []
        else:
            if not tgt or tgt.group(1) not in at:
                return None
            succ[i + 1] = [at[tgt.group(1)]]
            if mn in _COND_BR_MN and i + 2 < nb:
                succ[i + 1].append(i + 2)
    # forward: nodes where `reg` may still hold the entry value (only True
    # states matter: a read is only a read of the entry value then)
    may = [False] * nb
    may[0] = True
    work = [0]
    while work:
        i = work.pop()
        d, u = defs_uses(body[i])
        if reg in u and mnem(i) != "jal":
            return True
        if reg in d:
            continue
        if i in call_after:
            c = call_after[i]
            if c == "?" or _callee_reads(c, reg, depth + 1):
                return True
            continue                         # the call clobbers a0-a3
        for t in succ[i]:
            if not may[t]:
                may[t] = True
                work.append(t)
    return False


def _callee_reads(fn, reg, depth=0):
    """Conservatively: may function `fn` (retail asm) read argument register `reg`
    before writing it? Dataflow over the callee's CFG (delay slots included): a
    read while `reg` may still hold the entry value counts; a call made then
    recurses into that callee (depth-limited). When the CFG cannot be built, a
    read counts unless `reg` was written earlier in the same basic block or in
    the straight-line entry prefix. Unknown callee or deep chain: assume it
    reads."""
    key = (fn, reg)
    if key in _CALLEE_RD:
        return _CALLEE_RD[key]
    _CALLEE_RD[key] = True                   # recursion guard: assume read
    if depth <= 8:
        fl = _callee_reads_flow(fn, reg, depth)
        if fl is not None:
            _CALLEE_RD[key] = fl
            return fl
    body = _callee_insns(fn)
    if body is None or depth > 8:
        return True
    entry_w, prefix, blk_w, res = False, True, False, False

    def written():
        return entry_w or blk_w
    k = 0
    while k < len(body):
        b = body[k]
        if b == "LABEL":
            prefix, blk_w = False, False
            k += 1
            continue
        mn = b.split(None, 1)[0].lower()
        is_call = mn in ("jal", "jalr")
        is_br = mn in _COND_BR_MN or mn in ("j", "b", "jr")
        d, u = defs_uses(b)
        if reg in u and not written() and not (is_call and mn == "jal"):
            res = True                       # (a direct call's own read is the callee's)
            break
        if is_call or is_br:
            slot = body[k + 1] if k + 1 < len(body) and body[k + 1] != "LABEL" else ""
            sd, su = defs_uses(slot) if slot else (set(), set())
            if reg in su and not written():
                res = True
                break
            if reg in sd:
                blk_w = True
                if prefix:
                    entry_w = True
            if is_call and not written():
                mc = re.match(r"jal (\w+)$", b)
                if not mc or _callee_reads(mc.group(1), reg, depth + 1):
                    res = True
                    break
            if is_call:
                blk_w = True                 # the call clobbers it
                if prefix:
                    entry_w = True           # ... on every path: all go through here
            else:
                prefix, blk_w = False, False
            k += 2
            continue
        if reg in d:
            blk_w = True
            if prefix:
                entry_w = True
        k += 1
    _CALLEE_RD[key] = res
    return res


def _ff_dead_on(lines, ins, label, reg, seen=None, callee_args=True):
    """`reg` is dead at `label`: on every path from it (both sides of conditional
    branches, `j` followed, delay slots included) it is written before it is read.
    A return reads $v0 and the callee-saved registers; calls and indirect
    jumps give up (conservative). callee_args=False trusts the C call arity
    (a call reads only the arguments cc1 set up) instead of the callee asm."""
    seen = set() if seen is None else seen
    if label in seen:
        return True
    seen.add(label)
    at = next((k for k, l in enumerate(lines) if l.strip() == label + ":"), None)
    if at is None:
        return False
    rest = [(i, l) for i, l in ins if i > at]
    nr, on = set(), False
    for x, xl in enumerate(lines):
        s = xl.strip()
        if s.startswith(".set") and "noreorder" in s:
            on = True
        elif s.startswith(".set") and s.split()[-1] == "reorder":
            on = False
        elif on:
            nr.add(x)
    k = 0
    while k < len(rest):
        i, l = rest[k]
        body = l.split("#", 1)[0].strip()
        br = _src_is_branch(l) or _src_is_ret(l)
        if re.match(r"\s*jalr?\b", l):
            # a call kills every caller-saved register that is not an argument;
            # its delay slot (noreorder) and a jalr target register still read
            if reg not in _CALL_CLOBBER:
                # callee-saved (s0-s7, fp): the callee preserves it and does not
                # read the caller's value, so keep scanning after the call
                if not re.match(r"s[0-7]$|fp$|s8$", reg or ""):
                    return False
                if body.split(None, 1)[0].lower() == "jalr" and reg in defs_uses(body)[1]:
                    return False
                if i in nr and k + 1 < len(rest):
                    sd, su = defs_uses(rest[k + 1][1].split("#", 1)[0].strip())
                    if reg in su:
                        return False
                    if reg in sd:
                        return True
                    k += 2
                else:
                    k += 1
                continue
            if reg in ("a0", "a1", "a2", "a3") and callee_args:
                mc = re.match(r"\s*jal\s+(\w+)\s*$", body)
                if not mc or _callee_reads(mc.group(1), reg):
                    return False
            if body.split(None, 1)[0].lower() == "jalr" and reg in defs_uses(body)[1]:
                return False
            if i in nr and k + 1 < len(rest):
                sd, su = defs_uses(rest[k + 1][1].split("#", 1)[0].strip())
                if reg in su:
                    return False
            return True
        d, u = defs_uses(body)
        if reg in u:
            return False
        if br:
            # the delay slot (noreorder only) runs before the transfer
            slot = i in nr and k + 1 < len(rest)
            if slot:
                sb = rest[k + 1][1].split("#", 1)[0].strip()
                sd, su = defs_uses(sb)
                if reg in su:
                    return False
                if reg in sd:
                    return True
            if _src_is_ret(l):
                # a void function's return does not read $v0
                return reg not in _FF_RET_LIVE or (reg == "v0" and _s_void(lines))
            lab = re.search(r"(\$L\w+)\s*$", body)
            if not lab:
                return False
            if not _ff_dead_on(lines, ins, lab.group(1), reg, seen, callee_args):
                return False
            if body.split(None, 1)[0].lower() in ("j", "b"):
                return True
            k += 2 if slot else 1           # fall-through continues after the slot
            continue
        if reg in d:
            return True
        k += 1
    return False


def _ff_nr_swap(stext, tgt):
    """cc1 filled a conditional branch slot (noreorder) with the FIRST fall-through
    insn Y; the target's slot holds a LATER fall-through insn X. Put X in the slot
    and Y back at the head of the fall-through. Needs: X hoistable over the insns
    before it (incl. Y), and both destinations dead on the taken path (X now runs
    there, Y no longer does)."""
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    ours = _tf_branches(lines)
    if len(ours) != len(tb):
        return stext
    for k in range(len(ours)):
        ours = _tf_branches(lines)
        bi, nr = ours[k]
        tk = tb[k]
        if not nr or tk + 1 >= len(tgt):
            continue
        tkey = _sm_key(tgt[tk + 1][1].strip(), True)
        if tkey in (None, "skip", ("nop",), ("sll", "zero", "zero", 0)):
            continue
        slot = _tf_next_insn(lines, bi)
        if slot is None:
            continue
        yform = _ff_word_form(lines[slot].split("#", 1)[0].strip())
        if yform is None or _sm_key(yform, False) == tkey:
            continue
        end = slot + 1
        while end < len(lines) and lines[end].strip().startswith(".set"):
            end += 1
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        pick, seen = None, [yform]
        for fi, fl in ins:
            if fi < end:
                continue
            if any(_branch_target_label(lines, ins, x) for x in lines[end:fi]):
                break
            if _src_is_branch(fl) or _src_is_ret(fl) or re.match(r"\s*jalr?\b", fl):
                break
            fb = fl.split("#", 1)[0].strip()
            form = _ff_word_form(fb)
            if form is not None and _sm_key(form, False) == tkey:
                if all(_sm_indep(form, s) for s in seen):
                    pick = (fi, form)
                break
            seen.append(fb)
        if pick is None:
            continue
        fi, xform = pick
        lab = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        xd, _u = defs_uses(xform)
        yd, _u = defs_uses(yform)
        if not lab or len(xd) != 1 or len(yd) != 1:
            continue
        if not (_ff_dead_on(lines, ins, lab.group(1), next(iter(xd)))
                and _ff_dead_on(lines, ins, lab.group(1), next(iter(yd)))):
            continue
        ind = _src_indent(lines[slot])
        del lines[fi]
        lines[slot] = ind + xform
        lines.insert(end, ind + yform)
    return "\n".join(lines)


def fallthrough_fill_pass(stext, tgt):
    stext = _ff_nr_swap(stext, tgt)
    tb = _tgt_cond_branches(tgt, stext) if tgt else []
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    noreo = False
    ours = []                               # (line index of branch, in noreorder)
    for i, l in enumerate(lines):
        s = l.strip()
        if s.startswith(".set") and "noreorder" in s:
            noreo = True
        elif s.startswith(".set") and s.split()[-1] == "reorder":
            noreo = False
        m = re.match(r"\s*([a-z]+)\b", l)
        if _s_is_insn(l) and m and m.group(1) in _COND_BR_MN:
            ours.append((i, noreo))
    if len(ours) != len(tb):
        return stext
    edits = []
    for (bi, nr), tk in zip(ours, tb):
        if nr or tk + 1 >= len(tgt):
            continue
        tkey = _sm_key(tgt[tk + 1][1].strip(), True)
        if tkey in (None, "skip") or tkey == ("sll", "zero", "zero", 0):
            continue
        # the first fall-through insn with the target's slot key that can be
        # hoisted over every insn before it in the straight-line block
        pick, seen = None, []
        for fi, fl in ins:
            if fi <= bi:
                continue
            if any(_branch_target_label(lines, ins, x) for x in lines[bi + 1:fi]):
                break
            fb = fl.split("#", 1)[0].strip()
            if _src_is_branch(fl) or _src_is_ret(fl) or re.match(r"\s*jalr?\b", fl):
                break
            form = _ff_word_form(fb)
            if form is not None and _sm_key(form, False) == tkey:
                if all(_sm_indep(form, s) for s in seen):
                    pick = (fi, form)
                break
            seen.append(fb)
        if pick is None:
            continue
        fi, form = pick
        d, _u = defs_uses(form)
        lab = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        if len(d) != 1 or not lab or not _ff_dead_on(lines, ins, lab.group(1), next(iter(d))):
            continue
        edits.append((bi, fi, form))
    if not edits:
        return stext
    for bi, fi, form in sorted(edits, reverse=True):
        ind = _src_indent(lines[bi])
        del lines[fi]
        lines[bi:bi + 1] = [ind + ".set\tnoreorder", ind + ".set\tnomacro",
                            lines[bi], ind + form + "\t# ffdup", ind + ".set\tmacro",
                            ind + ".set\treorder"]
    return _ff_skip_dup("\n".join(lines))


def _ff_skip_dup(stext):
    """A branch whose slot got X from the fall-through, while its taken arm starts
    with the same X: retarget it past that copy (X already ran in the slot)."""
    lines = stext.split("\n")
    n = 0
    for x in range(len(lines)):
        if not lines[x].rstrip().endswith("# ffdup"):
            continue
        form = lines[x].split("#", 1)[0].strip()
        lines[x] = lines[x].split("#", 1)[0].rstrip()
        bi = max(y for y in range(x) if _s_is_insn(lines[y]) and not lines[y].strip().startswith("."))
        lab = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        if not lab:
            continue
        at = next((y for y, l in enumerate(lines) if l.strip() == lab.group(1) + ":"), None)
        xi = _tf_next_insn(lines, at) if at is not None else None
        if xi is None or xi in _noreorder_lines(lines) or any(
                _join_label(lines, y) for y in range(at + 1, xi)):
            continue
        if _ff_word_form(lines[xi].split("#", 1)[0].strip()) != form:
            continue
        n += 1
        nl_ = "$Lfd%d_%d" % (bi, n)
        lines[bi] = lines[bi][:lines[bi].rindex(lab.group(1))] + nl_
        lines.insert(xi + 1, nl_ + ":")
    return "\n".join(lines)


# --------------------------------------------------------------------------
# taken-fill: retail's reorg filled a conditional branch's delay slot from the
# TAKEN path (the first insn at the branch target, a pure 1-word ALU insn whose
# destination is dead on the fall-through path) and retargeted the branch past
# that insn; our cc1 left the slot empty. A later branch whose slot then holds
# the same `move d,s` again is redundant (d already equals s on the only path
# that reaches it), and retail leaves that slot a nop.
# Target-guided: the k-th conditional branch of ours is paired with the k-th of
# the target (counts must agree). Op A fires when the target's slot equals the
# first insn of our branch target and our slot is empty/nop; Op B fires when the
# target's slot is a nop and ours holds an insn identical to the most recent
# straight-line def of its destination (no join, no write of its sources since).
# Count-preserving text pass.
# --------------------------------------------------------------------------
def _tf_branches(lines):
    """[(line index, in noreorder)] of every conditional branch."""
    noreo, out = False, []
    for i, l in enumerate(lines):
        s = l.strip()
        if s.startswith(".set") and "noreorder" in s:
            noreo = True
        elif s.startswith(".set") and s.split()[-1] == "reorder":
            noreo = False
        m = re.match(r"\s*([a-z]+)\b", l)
        if _s_is_insn(l) and m and m.group(1) in _COND_BR_MN:
            out.append((i, noreo))
    return out


def _tf_next_insn(lines, i):
    for j in range(i + 1, len(lines)):
        if _s_is_insn(lines[j]):
            return j
    return None


def _tf_is_nop(body):
    return body.split(None, 1)[0].lower() == "nop" if body else False


def _tf_thread(lines, label):
    """(line of the first insn executed at `label`, its 1-word form, thread-to
    label or None). When `label` starts with an unconditional `j/b $L2` whose
    noreorder slot holds S, the first insn is S and the branch may go straight
    to $L2 (jump threading, as retail's reorg does)."""
    at = next((x for x, l in enumerate(lines) if l.strip() == label + ":"), None)
    if at is None:
        return None
    xi = _tf_next_insn(lines, at)
    if xi is None:
        return None
    xb = lines[xi].split("#", 1)[0].strip()
    mj = re.match(r"(?:j|b)\s+(\$L\w+)$", xb)
    if mj:
        si = _tf_next_insn(lines, xi)
        if si is None or not any(lines[y].strip().startswith(".set") and "noreorder" in lines[y]
                                 for y in range(at, xi)):
            return None
        f = _ff_word_form(lines[si].split("#", 1)[0].strip())
        return (si, f, mj.group(1)) if f is not None else None
    f = _ff_word_form(xb)
    return (xi, f, None) if f is not None else None


_TF_INV = {"beq": "bne", "bne": "beq", "beqz": "bnez", "bnez": "beqz",
           "blez": "bgtz", "bgtz": "blez", "bltz": "bgez", "bgez": "bltz"}


def _tf_place(lines, start, form, d, u):
    """Insert the 1-word insn `form` (defs d, uses u) on the straight-line path
    from line `start`: right before the first reader of its destination or the
    first join label, replacing an explicit load-delay `nop` right before that
    spot. Returns False when no spot is found (a write of d/u on the way, or a
    transfer that does not read d)."""
    reg = next(iter(d))
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    dest = None
    for j in range(start, len(lines)):
        l = lines[j]
        if _s_is_label(l) and _branch_target_label(lines, ins, l):
            dest = j
            break
        if not _s_is_insn(l):
            continue
        jd, ju = defs_uses(l.split("#", 1)[0].strip())
        if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
            if reg in ju:
                dest = j
            break
        if reg in ju:
            dest = j
            break
        if set(jd) & (set(d) | set(u)):
            break
    if dest is None:
        return False
    at = dest
    while at > start and (lines[at - 1].strip().startswith(".set")
                          or lines[at - 1].strip() in ("#nop", "")):
        at -= 1
    ind = "\t"
    pi = max((y for y, _l in ins if y < at), default=None)
    if pi is not None and pi >= start and _tf_is_nop(lines[pi].split("#", 1)[0].strip()):
        li_ = max((y for y, _l in ins if y < pi), default=None)
        ld = lines[li_].split("#", 1)[0].strip() if li_ is not None else ""
        if (re.match(r"(lw|lh|lhu|lb|lbu)\s", ld) and li_ >= start
                and not set(defs_uses(ld)[0]) & set(u)):
            lines[pi] = _src_indent(lines[pi]) + form
            return True
    lines.insert(at, ind + form)
    return True


def _tf_hi_key(body):
    """(reg, address) for `lui R,%hi(SYM[+-k])`; SYM named D_<hex> resolves to
    its address, other names stay symbolic. None otherwise."""
    m = re.match(r"lui\s+(\$\w+)\s*,\s*%hi\(([A-Za-z_.$][\w.$]*)\s*([+-]\s*(?:0x[0-9a-fA-F]+|\d+))?\)\s*$",
                 body.strip())
    if not m:
        return None
    off = int(m.group(3).replace(" ", ""), 0) if m.group(3) else 0
    ms = re.fullmatch(r"D_([0-9A-Fa-f]{8})", m.group(2))
    where = int(ms.group(1), 16) + off if ms else (m.group(2), off)
    return norm_reg(m.group(1)), where


def _tf_sole_entrant(lines, label):
    """`label` is referenced exactly once and nothing falls into it (the insn
    before it is an unconditional transfer or that transfer's noreorder slot)."""
    at = next((x for x, l in enumerate(lines) if l.strip() == label + ":"), None)
    if at is None:
        return False
    pat = re.compile(re.escape(label) + r"(?![\w$])")
    refs = sum(len(pat.findall(l.split("#", 1)[0])) for x, l in enumerate(lines) if x != at)
    if refs != 1:
        return False
    nr = _noreorder_lines(lines)
    prev = [x for x in range(at) if _s_is_insn(lines[x]) and not re.match(r"\s*\.", lines[x])]
    if not prev:
        return False
    p = prev[-1]
    if p in nr and len(prev) > 1 and prev[-2] in nr:
        p = prev[-2]
    return bool(re.match(r"\s*(j|b|jr)\s", lines[p]))


def _jnext_drop(stext):
    """Drop a noreorder `j L` whose target label L comes right after its delay
    slot (only labels, directives and blank lines between). The slot insn runs
    on the fall-through either way, so it stays in place. cc1's reorg never
    leaves such a jump; our text passes can, when they empty the block between
    (a return block stolen into a branch slot)."""
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    changed = False
    i = 0
    while i < len(lines):
        m = re.match(r"\s*j\s+(\$L\w+)\s*$", lines[i].split("#", 1)[0])
        if not m or i not in nr:
            i += 1
            continue
        slot = _tf_next_insn(lines, i)
        if slot is None or slot not in nr or _src_is_branch(lines[slot]) \
                or _src_is_ret(lines[slot]) or any(
                    _s_is_label(lines[y]) for y in range(i + 1, slot)):
            i += 1
            continue
        hit = False
        for y in range(slot + 1, len(lines)):
            st = lines[y].strip()
            if st == m.group(1) + ":":
                hit = True
                break
            if _s_is_insn(lines[y]) and not st.startswith("."):
                break
        if hit:
            del lines[i]
            changed = True
            continue
        i += 1
    return "\n".join(lines) if changed else stext


def _join_label(lines, y):
    """Line y is a label some real insn (not a directive) references: a control-flow
    join, unlike cc1's `LMn` line markers and `$Lb/$Le` debug block labels."""
    if not _s_is_label(lines[y]):
        return False
    pat = re.compile(r"(?<![\w$.])" + re.escape(lines[y].strip()[:-1]) + r"(?![\w$])")
    return any(pat.search(l.split("#", 1)[0]) for l in lines
               if _s_is_insn(l) and not l.strip().startswith("."))


def _j_steal(stext, tgt):
    """`j L` (reorder mode, or noreorder with a nop slot) -> `j L'; X` with X the
    first insn of L's block and L' a new label right after X, when the target's
    jump with the same ordinal has X in its slot."""
    if not tgt:
        return stext
    tj = [k for k, (_w, d) in enumerate(tgt) if d.split(None, 1)[0].lower() in ("j", "b")]
    lines = stext.split("\n")
    oj = [x for x, l in enumerate(lines) if re.match(r"\s*j\s+\$L\w+\s*$", l.split("#", 1)[0])]
    if len(oj) != len(tj):
        return stext
    nr = _noreorder_lines(lines)
    changed = False
    for n in range(len(oj) - 1, -1, -1):
        x = oj[n]
        k = tj[n]
        if k + 1 >= len(tgt) or is_nop(tgt[k + 1][1].strip()):
            continue
        slot = None
        if x in nr:
            slot = _tf_next_insn(lines, x)
            if slot is None or not _tf_is_nop(lines[slot].split("#", 1)[0].strip()):
                continue
        lab = re.search(r"(\$L\w+)\s*$", lines[x].split("#", 1)[0]).group(1)
        at = next((y for y, l in enumerate(lines) if l.strip() == lab + ":"), None)
        if at is None:
            continue
        xi = _tf_next_insn(lines, at)
        if xi is None or xi in nr or any(_join_label(lines, y) for y in range(at + 1, xi)):
            continue
        xb = lines[xi].split("#", 1)[0].strip()
        form = _ff_word_form(xb)
        if form is None or _src_is_branch(lines[xi]) or re.match(r"(jalr?|nop)\b", xb):
            continue
        if _sm_key(tgt[k + 1][1].strip(), True) != _sm_key(form, False):
            continue
        n_js = sum(1 for l in lines if l.strip().startswith("$Ljs"))
        nl_ = "$Ljs%d_%d" % (x, n_js)
        ind = _src_indent(lines[xi])
        if xi > x:
            lines.insert(xi + 1, nl_ + ":")
        if slot is not None:
            lines[slot] = ind + form
            lines[x] = lines[x][:lines[x].rindex(lab)] + nl_
        else:
            lines[x:x + 1] = [ind + ".set\tnoreorder", ind + ".set\tnomacro",
                              ind + "j\t" + nl_, ind + form,
                              ind + ".set\tmacro", ind + ".set\treorder"]
        if xi < x:
            lines.insert(xi + 1, nl_ + ":")
        nr = _noreorder_lines(lines)
        oj = [y for y, l in enumerate(lines) if re.match(r"\s*j\s+\$L\w+\s*$", l.split("#", 1)[0])]
        changed = True
    return "\n".join(lines) if changed else stext


def taken_fill_pass(stext, tgt):
    # to a fixed point: an Op F rewrite can create the shape a later Op needs
    out = stext
    for _ in range(3):
        new = _j_steal(_taken_fill_core(out, tgt), tgt)
        if new == out:
            break
        out = new
    return _jnext_drop(out) if out != stext else out


def _taken_fill_core(stext, tgt):
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    ours = _tf_branches(lines)
    if len(ours) != len(tb):
        return stext
    nop_key = ("sll", "zero", "zero", 0)
    n_new = 0
    # Op F: `bc r,L1; S1; j L2; S2; L1:` where retail has `binv r,L2; S2` and S1
    # back on the L1 path: invert the branch over the jump. S2 then also runs on
    # the L1 path (its dest must be dead there); S1 no longer runs on the L2 path
    # (its dest must be dead there) and goes before its first reader.
    for k in range(len(ours)):
        ours = _tf_branches(lines)
        if len(ours) != len(tb) or k >= len(ours):
            break
        bi, nr = ours[k]
        tk = tb[k]
        if not nr or tk + 1 >= len(tgt):
            continue
        mb = re.match(r"(\s*)(\w+)(\s+.*,\s*)(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        tmn = tgt[tk][1].split(None, 1)[0].lower()
        if not mb or _TF_INV.get(mb.group(2)) is None:
            continue
        inv = _TF_INV[mb.group(2)]
        if tmn not in (inv, {"bne": "bnez", "beq": "beqz"}.get(inv, inv)) and not (
                inv in ("bnez", "beqz") and tmn == inv[:3]):
            continue
        s1 = _tf_next_insn(lines, bi)
        ji = _tf_next_insn(lines, s1) if s1 is not None else None
        if ji is None:
            continue
        mj = re.match(r"\s*j\s+(\$L\w+)\s*$", lines[ji].split("#", 1)[0])
        s2 = _tf_next_insn(lines, ji)
        if not mj or s2 is None:
            continue
        l1 = mb.group(4)
        nxt = _tf_next_insn(lines, s2)
        if nxt is None or not any(lines[y].strip() == l1 + ":" for y in range(s2 + 1, nxt)):
            continue
        f1 = _ff_word_form(lines[s1].split("#", 1)[0].strip())
        f2 = _ff_word_form(lines[s2].split("#", 1)[0].strip())
        if f1 is None or f2 is None:
            continue
        if _sm_key(tgt[tk + 1][1].strip(), True) != _sm_key(f2, False):
            continue
        d1, u1 = defs_uses(f1)
        d2, u2 = defs_uses(f2)
        if len(d1) != 1 or len(d2) != 1:
            continue
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        # S1 goes back on the L1 path before the first reader of its dest, so a
        # S2 writing that same register is overwritten there before any read
        same = set(d1) == set(d2) and not (set(d1) & set(u1))
        if not same and not _ff_dead_on(lines, ins, l1, next(iter(d2))):
            continue
        if not _ff_dead_on(lines, ins, mj.group(1), next(iter(d1))):
            continue
        # retail may also keep a copy of S1 right before the inverted branch
        # (dead on the L2 path: checked above)
        keep = tk >= 1 and _sm_key(tgt[tk - 1][1].strip(), True) == _sm_key(f1, False)
        new = list(lines)
        # s2 line and the j group go; the branch becomes binv L2 with S2 in its slot
        grp_end = s2 + 1
        while grp_end < len(new) and new[grp_end].strip().startswith(".set"):
            grp_end += 1
        grp_start = ji
        while grp_start > s1 + 1 and new[grp_start - 1].strip().startswith(".set"):
            grp_start -= 1
        new[bi] = mb.group(1) + inv + mb.group(3) + mj.group(1)
        new[s1] = _src_indent(new[s1]) + f2
        del new[grp_start:grp_end]
        at = grp_start
        if not _tf_place(new, at, f1, d1, u1):
            continue
        if keep:
            b0 = bi
            while b0 > 0 and new[b0 - 1].strip().startswith(".set"):
                b0 -= 1
            new.insert(b0, _src_indent(new[bi]) + f1)
        lines = new
    # Op F2: Op F for a branch cc1 left in reorder mode (the nodb flavors):
    # `bc r,L1; X; j L2; L1:` where the assembler moves X into the jump's slot and
    # leaves the branch slot empty, and retail has `binv r,L2; X`. X then also runs
    # on the L1 path, so its destination must be dead there.
    for k in range(len(ours)):
        ours = _tf_branches(lines)
        if len(ours) != len(tb) or k >= len(ours):
            break
        bi, nr = ours[k]
        tk = tb[k]
        if nr or tk + 1 >= len(tgt):
            continue
        mb = re.match(r"(\s*)(\w+)(\s+.*,\s*)(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        if not mb or _TF_INV.get(mb.group(2)) is None:
            continue
        inv = _TF_INV[mb.group(2)]
        tmn = tgt[tk][1].split(None, 1)[0].lower()
        if tmn not in (inv, {"bne": "bnez", "beq": "beqz"}.get(inv, inv)) and not (
                inv in ("bnez", "beqz") and tmn == inv[:3]):
            continue
        xi = _tf_next_insn(lines, bi)
        ji = _tf_next_insn(lines, xi) if xi is not None else None
        if ji is None or any(_join_label(lines, y) for y in range(bi + 1, ji)):
            continue
        if any(lines[y].strip().startswith(".set") for y in range(bi + 1, ji)):
            continue
        mj = re.match(r"\s*j\s+(\$L\w+)\s*$", lines[ji].split("#", 1)[0])
        if not mj:
            continue
        l1 = mb.group(4)
        nxt = _tf_next_insn(lines, ji)
        if nxt is None or not any(lines[y].strip() == l1 + ":" for y in range(ji + 1, nxt)):
            continue
        fx = _ff_word_form(lines[xi].split("#", 1)[0].strip())
        if fx is None or _sm_key(tgt[tk + 1][1].strip(), True) != _sm_key(fx, False):
            continue
        dx, _ux = defs_uses(fx)
        if len(dx) != 1:
            continue
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        if not _ff_dead_on(lines, ins, l1, next(iter(dx))):
            continue
        ind = mb.group(1)
        lines[bi:ji + 1] = [ind + ".set\tnoreorder", ind + ".set\tnomacro",
                            ind + inv + mb.group(3) + mj.group(1), _src_indent(lines[xi]) + fx,
                            ind + ".set\tmacro", ind + ".set\treorder"]
    # Op F3: a reorder-mode `bc r,L1` followed by cc1's noreorder group
    # `j L2; S2` and then L1: retail has `binv r,L2; S2`. S2 now also runs on the
    # L1 path: its dest must be dead there, or (target-guided: the target has it
    # right after the slot) the straight-line insn R that last set that register
    # before the branch is recomputed on the fall-through, ahead of L1.
    for k in range(len(ours)):
        ours = _tf_branches(lines)
        if len(ours) != len(tb) or k >= len(ours):
            break
        bi, nr = ours[k]
        tk = tb[k]
        if nr or tk + 1 >= len(tgt):
            continue
        mb = re.match(r"(\s*)(\w+)(\s+.*,\s*)(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        if not mb or _TF_INV.get(mb.group(2)) is None:
            continue
        inv = _TF_INV[mb.group(2)]
        tmn = tgt[tk][1].split(None, 1)[0].lower()
        if tmn not in (inv, {"bne": "bnez", "beq": "beqz"}.get(inv, inv)) and not (
                inv in ("bnez", "beqz") and tmn == inv[:3]):
            continue
        ji = _tf_next_insn(lines, bi)
        if ji is None or any(_join_label(lines, y) for y in range(bi + 1, ji)):
            continue
        mj = re.match(r"\s*j\s+(\$L\w+)\s*$", lines[ji].split("#", 1)[0])
        nrs = _noreorder_lines(lines)
        s2 = _tf_next_insn(lines, ji)
        if not mj or ji not in nrs or s2 is None or s2 not in nrs:
            continue
        l1 = mb.group(4)
        nxt = _tf_next_insn(lines, s2)
        if nxt is None or not any(lines[y].strip() == l1 + ":" for y in range(s2 + 1, nxt)):
            continue
        f2 = _ff_word_form(lines[s2].split("#", 1)[0].strip())
        if f2 is None or _sm_key(tgt[tk + 1][1].strip(), True) != _sm_key(f2, False):
            continue
        d2, _u2 = defs_uses(f2)
        if len(d2) != 1:
            continue
        r2 = next(iter(d2))
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        recompute = None
        if not _ff_dead_on(lines, ins, l1, r2):
            if tk + 2 >= len(tgt):
                continue
            # the last straight-line writer of r2 before the branch (slots included)
            ri = None
            for y in range(bi - 1, -1, -1):
                ly = lines[y]
                if _join_label(lines, y):
                    break
                if not _s_is_insn(ly) or ly.strip().startswith("."):
                    continue
                if re.match(r"\s*jalr?\b", ly) or _src_is_ret(ly):
                    break
                dy, uy = defs_uses(ly.split("#", 1)[0].strip())
                if r2 in dy:
                    ri = y
                    break
            if ri is None:
                continue
            fr = _ff_word_form(lines[ri].split("#", 1)[0].strip())
            if fr is None or _sm_key(tgt[tk + 2][1].strip(), True) != _sm_key(fr, False):
                continue
            dr, ur = defs_uses(fr)
            if r2 in ur or any(set(defs_uses(lines[y].split("#", 1)[0].strip())[0]) & set(ur)
                               for y in range(ri + 1, bi) if _s_is_insn(lines[y])
                               and not lines[y].strip().startswith(".")):
                continue
            recompute = fr
        ind = mb.group(1)
        end = s2 + 1
        while end < len(lines) and lines[end].strip().startswith(".set"):
            end += 1
        grp = [ind + ".set\tnoreorder", ind + ".set\tnomacro",
               ind + inv + mb.group(3) + mj.group(1), _src_indent(lines[s2]) + f2,
               ind + ".set\tmacro", ind + ".set\treorder"]
        if recompute:
            grp.append(ind + recompute)
        lines[bi:end] = grp
    # Op C: our slot holds an insn cc1 stole from the fall-through path where the
    # target leaves a nop: put it back on the fall-through, right before the first
    # insn that reads its destination (its destination must be dead on the taken
    # path, nothing on the way may write its destination or its sources, and the
    # way there must be straight-line). Op A may then refill the slot.
    for k in range(len(ours)):
        ours = _tf_branches(lines)
        bi, nr = ours[k]
        tk = tb[k]
        if not nr or tk + 1 >= len(tgt):
            continue
        slot = _tf_next_insn(lines, bi)
        if slot is None:
            continue
        xb = lines[slot].split("#", 1)[0].strip()
        form = _ff_word_form(xb)
        if form is None:
            continue
        tkey = _sm_key(tgt[tk + 1][1].strip(), True)
        if tkey not in (("nop",), nop_key):
            # or the target fills this slot from the TAKEN path (Op A below)
            lab0 = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
            th0 = _tf_thread(lines, lab0.group(1)) if lab0 else None
            f0 = th0[1] if th0 else None
            if (f0 is None or _sm_key(f0, False) != tkey
                    or _sm_key(form, False) == tkey):
                continue
        d, u = defs_uses(form)
        if len(d) != 1:
            continue
        reg = next(iter(d))
        lab = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        if not lab or not _ff_dead_on(lines, ins, lab.group(1), reg):
            continue
        dest = None
        for j in range(slot + 1, len(lines)):
            l = lines[j]
            if _s_is_label(l) and _branch_target_label(lines, ins, l):
                # a join before any use: X goes right before it (still on the
                # fall-through only; other entrants keep their own value)
                dest = j
                break
            if not _s_is_insn(l):
                continue
            if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
                jd, ju = defs_uses(l.split("#", 1)[0].strip())
                if reg in ju:
                    dest = j
                break
            jd, ju = defs_uses(l.split("#", 1)[0].strip())
            if reg in ju:
                dest = j
                break
            if (set(jd) & (set(d) | set(u))):
                break
        if dest is None:
            continue
        # the use may sit inside a `.set noreorder` group: insert before the group
        at = dest
        while at > slot + 1 and (lines[at - 1].strip().startswith(".set")
                                 or lines[at - 1].strip() in ("#nop", "")):
            at -= 1
        ind = _src_indent(lines[slot])
        # an explicit load-delay `nop` right before the spot (the assembler's
        # filler after a load, e.g. before a label) is where X goes: X then
        # fills the load delay, as long as X does not read the loaded register
        pi = max((y for y, _l in ins if y < at), default=None)
        if (pi is not None and pi > slot and _tf_is_nop(lines[pi].split("#", 1)[0].strip())):
            li_ = max((y for y, _l in ins if y < pi), default=None)
            ld = lines[li_].split("#", 1)[0].strip() if li_ is not None else ""
            if (re.match(r"(lw|lh|lhu|lb|lbu)\s", ld) and li_ > slot
                    and not set(defs_uses(ld)[0]) & set(u)):
                lines[pi] = _src_indent(lines[pi]) + form
                lines[slot] = ind + "nop"
                continue
        lines.insert(at, ind + form)
        lines[slot] = ind + "nop"
    # Op A: fill from the taken path
    for k in range(len(ours)):
        ours = _tf_branches(lines)
        bi, nr = ours[k]
        tk = tb[k]
        if tk + 1 >= len(tgt):
            continue
        tkey = _sm_key(tgt[tk + 1][1].strip(), True)
        thi = _tf_hi_key(tgt[tk + 1][1]) if tkey == "skip" else None
        if tkey in (None, ("nop",), nop_key) or (tkey == "skip" and thi is None):
            continue
        slot = None
        if nr:
            slot = _tf_next_insn(lines, bi)
            if slot is None or not _tf_is_nop(lines[slot].split("#", 1)[0].strip()):
                continue
        body = lines[bi].split("#", 1)[0]
        lab = re.search(r"(\$L\w+)\s*$", body)
        if not lab:
            continue
        th = _tf_thread(lines, lab.group(1))
        split_lo = None
        if th is None and thi is not None:
            # a symbolic load macro heads the taken path: retail's slot holds
            # its `lui R,%hi(sym)` half; the `%lo` load stays at the target
            at = next((x for x, l in enumerate(lines) if l.strip() == lab.group(1) + ":"), None)
            xi = _tf_next_insn(lines, at) if at is not None else None
            mm = re.match(r"(lw|lh|lhu|lb|lbu)\s+(\$\w+)\s*,\s*([A-Za-z_.$][\w.$]*(?:[+-]\d+)?)$",
                          lines[xi].split("#", 1)[0].strip()) if xi is not None else None
            if mm:
                hi = "lui\t%s,%%hi(%s)" % (mm.group(2), mm.group(3))
                if _tf_hi_key(hi) == thi:
                    th = (xi, hi, None)
                    split_lo = "%s\t%s,%%lo(%s)(%s)" % (mm.group(1), mm.group(2), mm.group(3),
                                                       mm.group(2))
        if th is None:
            continue
        xi, form, thread_to = th
        if form is None or (_tf_hi_key(form) != thi if thi is not None
                            else _sm_key(form, False) != tkey):
            continue
        d, u = defs_uses(form)
        if len(d) != 1:
            continue
        reg = next(iter(d))
        # both arms start with this insn: retail fills from the fall-through and
        # skips the taken copy (fallthrough_fill does that)
        fh = _tf_next_insn(lines, slot if slot is not None else bi)
        if fh is not None and not any(_join_label(lines, y) for y in range((slot or bi) + 1, fh)) \
                and _ff_word_form(lines[fh].split("#", 1)[0].strip()) == form:
            continue
        # the moved insn now also runs on the fall-through path: its destination
        # must be dead there (probe label right after the branch / its slot)
        probe = list(lines)
        after = slot if slot is not None else bi
        probe.insert(after + 1, "$Ltf_probe:")
        pins = [(i, l) for i, l in enumerate(probe) if _s_is_insn(l)]
        if not _ff_dead_on(probe, pins, "$Ltf_probe", reg):
            continue
        n_new += 1
        own = not thread_to and _tf_sole_entrant(lines, lab.group(1))
        newlab = thread_to or ("%s" % lab.group(1) if own else "$Ltf%d_%d" % (bi, n_new))
        ind = _src_indent(lines[bi])
        nb = lines[bi][:lines[bi].rindex(lab.group(1))] + newlab
        if nr:
            lines[bi] = nb
            lines[slot] = ind + form
        else:
            lines[bi:bi + 1] = [ind + ".set\tnoreorder", ind + ".set\tnomacro", nb,
                                ind + form, ind + ".set\tmacro", ind + ".set\treorder"]
            if xi > bi:
                xi += 5
        if own:
            # own thread: the only way in is this branch, the head moves
            if split_lo:
                lines[xi] = _src_indent(lines[xi]) + split_lo
            else:
                del lines[xi]
            continue
        if split_lo:
            lines[xi] = _src_indent(lines[xi]) + form
        if not thread_to:
            lines.insert(xi + 1, newlab + ":")
        if split_lo:
            lines.insert(xi + 2, _src_indent(lines[xi]) + split_lo)
    # Op G: the reverse of Op A. Our slot S was stolen from the taken path (the
    # branch goes past where S was) but retail fills the slot from the
    # fall-through head X and branches onto its own copy of S. Needs: the target
    # slot == X, the target lands on an insn identical to S, nothing falls into
    # our label from above (a transfer precedes it), S's destination dead on the
    # fall-through, X's destination dead on the taken path and not read by S.
    mfn = re.search(r"^\s*\.ent\s+(\w+)", stext, re.M)
    fna = _fn_addr(mfn.group(1)) if mfn else None
    ours = _tf_branches(lines)
    for k in range(len(ours)):
        if fna is None:
            break
        ours = _tf_branches(lines)
        if len(ours) != len(tb):
            break
        bi, nr = ours[k]
        tk = tb[k]
        if not nr or tk + 1 >= len(tgt):
            continue
        mt = re.search(r"\.L([0-9A-Fa-f]{8})\s*$", tgt[tk][1])
        if not mt:
            continue
        ti = (int(mt.group(1), 16) - fna) // 4
        if not 0 <= ti < len(tgt):
            continue
        slot = _tf_next_insn(lines, bi)
        xi = _tf_next_insn(lines, slot) if slot is not None else None
        if xi is None:
            continue
        sb = lines[slot].split("#", 1)[0].strip()
        xb = lines[xi].split("#", 1)[0].strip()
        sf, xf = _ff_word_form(sb), _ff_word_form(xb)
        if sf is None or xf is None:
            continue
        tsk = _sm_key(tgt[tk + 1][1].strip(), True)
        if _sm_key(xf, False) != tsk or _sm_key(sf, False) == tsk:
            continue
        tkey = _sm_key(tgt[ti][1].strip(), True)
        if tkey == "skip":
            if not sf.startswith("lui") or _SYM_RE.findall(tgt[ti][1]) != _SYM_RE.findall(sf):
                continue
        elif tkey is None or tkey != _sm_key(sf, False):
            continue
        if any(re.match(r"\s*\$L\w*:", lines[y]) for y in range(slot + 1, xi)):
            continue                        # X sits at a join: not the fall-through head
        lab = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        if not lab:
            continue
        at = next((x for x, l in enumerate(lines) if l.strip() == lab.group(1) + ":"), None)
        if at is None:
            continue
        # the label must not be reached by falling through from above
        while at > 0 and lines[at - 1].strip().endswith(":"):
            at -= 1
        pi = max((y for y in range(at) if _s_is_insn(lines[y])), default=None)
        if pi is None:
            continue
        pj = max((y for y in range(pi) if _s_is_insn(lines[y])), default=None)
        pb = lines[pi].split("#", 1)[0].strip()
        jb = lines[pj].split("#", 1)[0].strip() if pj is not None else ""
        uncond = re.match(r"(j|b)\s+\$\w+$|jr\s+\$\w+$", pb)
        if not uncond and not (pj is not None and re.match(r"(j|b)\s+\$\w+$|jr\s+\$\w+$", jb)
                               and pi in _noreorder_lines(lines)):
            continue
        ds, us = defs_uses(sf)
        dx, ux = defs_uses(xf)
        if len(ds) != 1 or len(dx) != 1 or set(dx) & set(us) or set(ds) & set(ux):
            continue
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        if not _ff_dead_on(lines, ins, lab.group(1), next(iter(dx))):
            continue
        probe = list(lines)
        probe.insert(xi + 1, "$Ltg_probe:")
        pins = [(i, l) for i, l in enumerate(probe) if _s_is_insn(l)]
        if not _ff_dead_on(probe, pins, "$Ltg_probe", next(iter(ds))):
            continue
        n_new += 1
        newlab = "$Ltg%d_%d" % (bi, n_new)
        ind = _src_indent(lines[bi])
        lines[bi] = lines[bi][:lines[bi].rindex(lab.group(1))] + newlab
        lines[slot] = _src_indent(lines[slot]) + xf
        del lines[xi]
        if at > xi:
            at -= 1
        lines[at:at] = [newlab + ":", ind + sb]
    # Op B: a slot insn made redundant by an identical earlier def
    ours = _tf_branches(lines)
    if len(ours) != len(tb):
        return "\n".join(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    for (bi, nr), tk in zip(ours, tb):
        if not nr or tk + 1 >= len(tgt):
            continue
        if _sm_key(tgt[tk + 1][1].strip(), True) not in (("nop",), nop_key):
            continue
        slot = _tf_next_insn(lines, bi)
        if slot is None:
            continue
        yb = lines[slot].split("#", 1)[0].strip()
        form = _ff_word_form(yb)
        if form is None:
            continue
        d, u = defs_uses(form)
        if len(d) != 1 or set(d) & set(u):
            continue
        key = _sm_key(form, False)
        ok = False
        for j in range(bi - 1, -1, -1):
            l = lines[j]
            if _s_is_label(l):
                if _branch_target_label(lines, ins, l):
                    break
                continue
            if not _s_is_insn(l):
                continue
            jb = l.split("#", 1)[0].strip()
            if _src_is_ret(l) or re.match(r"\s*(jalr?|j|b)\b", l):
                break
            jf = _ff_word_form(jb)
            if jf is not None and _sm_key(jf, False) == key:
                ok = True
                break
            jd, _ju = defs_uses(jb)
            if (set(d) | set(u)) & set(jd):
                break
        if ok:
            lines[slot] = _src_indent(lines[slot]) + "nop"
    return "\n".join(lines)


# --------------------------------------------------------------------------
# dead-code: after taken_fill retargets branches, a block can lose every entrant
# (retail's jump optimizer then deleted it, and the `j` over it too). Delete the
# instructions between an unconditional transfer (`j`/`b`/`jr`, after its slot)
# and the next label something still references (branches, `.word` jump-table
# entries, anything but the label's own definition); then drop a `j L` whose
# target is the very next instruction (its slot insn, if any, stays in place).
# Semantics-preserving; count-changing.
# --------------------------------------------------------------------------
def _dc_referenced(lines, name):
    pat = re.compile(r"(?<![\w$.])" + re.escape(name) + r"(?![\w$])")
    # `.begin`/`.bend` debug-block markers name `$Lb`/`$Le` labels: not joins
    return any(pat.search(l.split("#", 1)[0]) for l in lines
               if l.strip() != name + ":" and not re.match(r"\s*\.(begin|bend)\b", l))


def dead_code_pass(stext, tgt):
    lines = stext.split("\n")
    changed = True
    while changed:
        changed = False
        noreo, dead, pend = False, False, 0
        out = []
        for l in lines:
            s = l.strip()
            if s.startswith(".set") and "noreorder" in s:
                noreo = True
            elif s.startswith(".set") and s.split()[-1] == "reorder":
                noreo = False
            if _s_is_label(l) and _dc_referenced(lines, s[:-1]):
                dead = False
            if _s_is_insn(l):
                if dead:
                    changed = True
                    continue
                if pend:
                    pend -= 1
                    if pend == 0:
                        dead = True
                elif re.match(r"\s*(j|b|jr)\s", l):
                    if noreo:
                        pend = 1                # its delay slot still runs
                    else:
                        dead = True
            elif s.startswith(".end"):
                dead = False
            out.append(l)
        lines = out
    # `j L` straight to the next instruction
    ins = [i for i, l in enumerate(lines) if _s_is_insn(l)]
    for x in range(len(ins) - 1, -1, -1):
        i = ins[x]
        m = re.match(r"\s*(?:j|b)\s+(\$L\w+)\s*$", lines[i].split("#", 1)[0])
        if not m:
            continue
        noreo = False
        for y in range(i, -1, -1):
            sy = lines[y].strip()
            if sy.startswith(".set") and "noreorder" in sy:
                noreo = True
                break
            if sy.startswith(".set") and sy.split()[-1] == "reorder":
                break
        after = ins[x + 2] if noreo and x + 2 < len(ins) else (ins[x + 1] if not noreo else None)
        if after is None:
            continue
        span = lines[(ins[x + 1] if noreo else i) + 1:after]
        if any(l.strip() == m.group(1) + ":" for l in span) and not any(_s_is_insn(l) for l in span):
            del lines[i]
            changed = True
    return "\n".join(lines)


def ra_restore_sink_pass(stext, tgt):
    stext = callee_restore_sink_s(stext, tgt)
    tl = [d for _w, d in tgt]
    t_ra = [i for i, d in enumerate(tl) if re.match(r"\s*lw\s+\$?ra\s*,", d)]
    if not t_ra:
        return stext
    want = _tail_count(tl[t_ra[-1] + 1:])
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    o_ra = [p for p, (_i, l) in enumerate(ins)
            if re.match(r"\s*lw\s+\$(?:31|ra)\s*,\s*(-?\d+)\(\$(?:sp|29)\)", l)]
    if not o_ra:
        return stext
    p0 = o_ra[-1]
    k = int(re.match(r"\s*lw\s+\S+\s*,\s*(-?\d+)", ins[p0][1]).group(1))
    have = _tail_count([l for _i, l in ins[p0 + 1:]], src=True)
    need = have - want
    if need <= 0:
        return stext
    last = None
    q = p0 + 1
    while need > 0 and q < len(ins):
        qi, ql = ins[q]
        body = ql.split("#", 1)[0].strip()
        if _src_is_branch(ql) or _src_is_ret(ql) or any(
                _branch_target_label(lines, ins, x) for x in lines[ins[q - 1][0] + 1:qi]):
            return stext
        d, u = defs_uses(body)
        if {"ra", "sp"} & (set(d) | set(u)) and not _frame_load(body):
            return stext
        mo = _mem_operand(body)
        if mo and mo[0] == "sp" and body.split()[0].lower() in _STORE_MN \
                and mo[1] < k + 4 and k < mo[1] + mo[2]:
            return stext
        if not (_frame_load(body) or _src_sp_delta(body) is not None):
            need -= _src_nwords(ql)
        last = q
        q += 1
    if need != 0 or last is None:
        return stext
    li = ins[p0][0]
    moved = lines[li]
    at = ins[last][0]
    out = lines[:li] + lines[li + 1:at + 1] + [moved] + lines[at + 1:]
    return "\n".join(out)


# The same for a nonzero 16-bit constant: our cc1 copies a register holding K
# (`move $d,$s` after `li $s,K`), retail re-materializes it (`addiu $d,$zero,K`).
# Budget per K = target's K materializations minus ours.
_KTGT = re.compile(r"^(?:addiu|li)\s+\S+\s*,\s*(?:\$?zero\s*,\s*)?(-?(?:0x[0-9a-fA-F]+|\d+))\s*$")


def const_remat_s(stext, want):
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    have = {}
    for _i, l in ins:
        c = _CONST_DEF_S.match(l)
        if c:
            k = int(c.group(2) or c.group(4), 0)
            have[k] = have.get(k, 0) + 1
    budget = {k: n - have.get(k, 0) for k, n in want.items() if k != 0}
    if not any(v > 0 for v in budget.values()):
        return stext
    changed = False
    for p, (li, l) in enumerate(ins):
        m = _MOVE_S.match(l)
        if not m:
            continue
        src = _src_reg(m.group(3))
        if not src or src == _src_reg("$0"):
            continue
        k = _const_reaching(lines, ins, p, src)
        if k is None or budget.get(k, 0) <= 0 or not (-0x8000 <= k < 0x8000
                                                     or (k & 0xFFFF) == 0):
            continue
        lines[li] = "%sli\t%s,%d" % (m.group(1), m.group(2), k)
        budget[k] -= 1
        changed = True
    return "\n".join(lines) if changed else stext



# --------------------------------------------------------------------------
# load-remat: our cc1 CSEs a second read of the same memory word into a register
# copy (`lb $3,34($16) ... move $4,$3`); retail reads the memory again
# (`lb $4,34($16)`). Where the target carries more loads of an (opcode, offset)
# than we do, a `move rd,rs` whose rs comes from such a load earlier on the same
# straight-line path (no label, store or call in between, base and rs not
# rewritten) becomes the reload. Count may change (a load-delay nop), so it runs
# before sigma.
# --------------------------------------------------------------------------
_LOAD_S = re.compile(r"^(\s*)(lb|lbu|lh|lhu|lw)\s+(\$\w+)\s*,\s*(-?\d+)\((\$\w+)\)\s*(#.*)?$")
_LOAD_T = re.compile(r"(lb|lbu|lh|lhu|lw)\s+\S+\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\(")
_LR_STOP = re.compile(r"(s[bhw]|swl|swr|jal|jalr|j|jr|syscall|break)\b")
_ANDI_S = re.compile(r"^(\s*)andi\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(0xff|255|0xffff|65535)\s*(#.*)?$")
_STORE_S = re.compile(r"^\s*(sb|sh|sw)\s+(\$\w+)\s*,\s*(-?\d+)\((\$\w+)\)\s*(#.*)?$")
# a copy / zero-extend of a register just stored -> the load that re-reads it
_FWD = {("sw", None): "lw", ("sb", 0xff): "lbu", ("sh", 0xffff): "lhu"}


def load_remat_pass(stext, tgt):
    want, tk = {}, []
    for _w, dis in tgt:
        m = _LOAD_T.match(dis.strip())
        k = (m.group(1), int(m.group(2), 0)) if m else None
        tk.append(k)
        if m:
            want[k] = want.get(k, 0) + 1
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    have = {}
    for _i, l in ins:
        m = _LOAD_S.match(l)
        if m:
            k = (m.group(2), int(m.group(4)))
            have[k] = have.get(k, 0) + 1
    nr = _noreorder_lines(lines)
    body = " ".join(l.split("#", 1)[0] for l in lines if _s_is_insn(l)
                    or l.strip().startswith(".word"))
    refd = set(re.findall(r"[$\w.]+", body))
    changed = False
    for p, (li, l) in enumerate(ins):
        m = _MOVE_S.match(l)
        mask = None
        if not m:
            m = _ANDI_S.match(l)
            if m:
                mask = int(m.group(4), 0)
        if not m or li in nr:
            continue
        rd, rs = norm_reg(m.group(2)), norm_reg(m.group(3))
        if rs in (None, "zero") or rd in (None, "zero"):
            continue
        q, hit = p - 1, None
        while q >= 0:
            qi, ql = ins[q]
            if qi in nr or any(_s_is_label(x) and x.strip()[:-1] in refd
                                for x in lines[qi + 1:ins[q + 1][0]]):
                break
            b = ql.split("#", 1)[0].strip()
            ml = _LOAD_S.match(ql)
            d, _u = defs_uses(b)
            if ml and norm_reg(ml.group(3)) == rs and mask is None:
                hit = (q, ml.group(2), int(ml.group(4)), ml.group(5))
                break
            ms = _STORE_S.match(ql)
            if ms and norm_reg(ms.group(2)) == rs and (ms.group(1), mask) in _FWD:
                hit = (q, _FWD[(ms.group(1), mask)], int(ms.group(3)), ms.group(4))
                break
            if rs in d or _LR_STOP.match(b):
                break
            q -= 1
        if not hit:
            continue
        q, op, off, base = hit
        k = (op, off)
        if norm_reg(base) == rs or want.get(k, 0) <= have.get(k, 0):
            continue
        if any(norm_reg(base) in defs_uses(ins[x][1].split("#", 1)[0].strip())[0]
               for x in range(q + 1, p)):
            continue
        new = "%s%s\t%s,%d(%s)" % (m.group(1), op, m.group(2), off, base)
        lines[li] = new
        have[k] = have.get(k, 0) + 1
        changed = True
        # the reload issues where the target has it: above a directly preceding
        # load (same straight line) when the target shows the pair in that order
        pi, pl = ins[p - 1] if p else (None, "")
        mp = _LOAD_S.match(pl)
        if (mp and pi not in nr and not any(_s_is_label(x) for x in lines[pi + 1:li])
                and rd not in defs_uses(pl.split("#", 1)[0].strip())[0]
                and rd != norm_reg(mp.group(5))
                and norm_reg(mp.group(3)) != norm_reg(base)):
            k2 = (mp.group(2), int(mp.group(4)))
            if any(a == k and b == k2 for a, b in zip(tk, tk[1:])):
                lines[pi], lines[li] = new, pl
    return "\n".join(lines) if changed else stext



# --------------------------------------------------------------------------
# nodiv: some retail units were assembled without the divide-by-zero / overflow
# traps (`div $0,$a,$b; mflo $d`, no `bnez; break`), while maspsx --expand-div
# adds them to every 3-operand `div/divu/rem/remu $d,$a,$b` macro. Spell such a
# macro as the bare hardware divide plus its mflo/mfhi, which maspsx leaves
# alone. Only fires when the target has no `break` at all. Count-changing.
# --------------------------------------------------------------------------
_DIV3_S = re.compile(r"^(\s*)(div|divu|rem|remu)\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")


def nodiv_pass(stext, tgt):
    if any(re.match(r"break\b", d.strip()) for _w, d in tgt):
        return stext
    lines = stext.split("\n")
    out, changed = [], False
    for k, l in enumerate(lines):
        m = _DIV3_S.match(l) if _s_is_insn(l) else None
        if not m or norm_reg(m.group(3)) == "zero":
            out.append(l)
            continue
        op = "divu" if m.group(2).endswith("u") else "div"
        mv = "mfhi" if m.group(2).startswith("rem") else "mflo"
        out.append("%s%s\t$0,%s,%s" % (m.group(1), op, m.group(4), m.group(5)))
        out.append("%s%s\t%s" % (m.group(1), mv, m.group(3)))
        # aspsx treats the move like a load: a reader right behind it waits
        nxt = next((x for x in lines[k + 1:] if _s_is_insn(x) or (
            _s_is_label(x) and not x.strip().startswith("LM"))), "")
        if (_s_is_insn(nxt) and not re.match(r"\s*\.set", nxt)
                and norm_reg(m.group(3)) in defs_uses(nxt.split("#", 1)[0].strip())[1]):
            out.append("%snop" % m.group(1))
        changed = True
    return "\n".join(out) if changed else stext



# --------------------------------------------------------------------------
# copy-use: after `move X,Y` both registers hold the same value; our cc1 reads Y
# where retail reads X (copy propagation went the other way). Aligned by
# mnemonic sequence to the target, a use of Y whose target word reads X becomes
# a use of X when the copy `move X,Y` precedes it on the same straight line and
# neither X nor Y is written in between. Sound by value equality.
# --------------------------------------------------------------------------
def _cu_parts(l):
    b = l.split("#", 1)[0].strip()
    m = _MOVE_S.match(l)
    if m:
        return "addu", [norm_reg(m.group(2)), norm_reg(m.group(3)), "zero"], b
    mn, regs, _sk = insn_parts(b)
    return mn, regs, b


def copy_use_pass(stext, tgt):
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)
           and not is_nop(l.split("#", 1)[0].strip())]
    ours = [_cu_parts(l) for _i, l in ins]
    tt = []
    for _w, d in tgt:
        if not is_nop(d.strip()):
            mn, regs, _sk = insn_parts(d.strip())
            tt.append((mn, regs))
    sm = difflib.SequenceMatcher(None, ["%s/%d" % (o[0], len(o[1])) for o in ours],
                                 ["%s/%d" % (t[0], len(t[1])) for t in tt], autojunk=False)
    body = " ".join(l.split("#", 1)[0] for l in lines if _s_is_insn(l)
                    or l.strip().startswith(".word"))
    refd = set(re.findall(r"[$\w.]+", body))
    changed = False
    for a, bb, size in sm.get_matching_blocks():
        for q in range(size):
            p = a + q
            li, l = ins[p]
            mn, regs, b = ours[p]
            tregs = tt[bb + q][1]
            # a return's delay slot is the one noreorder insn handled: the
            # return reads no copy register
            ret_slot = li in nr and p > 0 and _src_is_ret(ins[p - 1][1])
            if (li in nr and not ret_slot) or mn == "addu" and _MOVE_S.match(l):
                continue
            d, u = defs_uses(b)
            diff = [(k, r, t) for k, (r, t) in enumerate(zip(regs, tregs)) if r != t]
            if len(diff) != 1:
                continue
            k, y, x = diff[0]
            if y not in u or y in d or x in d or x in u:
                continue
            # the copy `move x,y` earlier on this straight line
            z, ok = p - 1, False
            while z >= 0:
                zi, zl = ins[z]
                if (zi in nr and not (ret_slot and z == p - 1)) or any(_s_is_label(w) and w.strip()[:-1] in refd
                                   for w in lines[zi + 1:ins[z + 1][0]]):
                    break
                mm = _MOVE_S.match(zl)
                # either direction: after `move x,y` or `move y,x` both hold one value
                if mm and {norm_reg(mm.group(2)), norm_reg(mm.group(3))} == {x, y}:
                    ok = True
                    break
                zd, _zu = defs_uses(zl.split("#", 1)[0].strip())
                if x in zd or y in zd or (_src_is_branch(zl) and not (ret_slot and z == p - 1)) \
                        or re.match(r"\s*jalr?\b", zl):
                    break
                z -= 1
            if not ok:
                continue
            # rewrite the k-th register operand
            mb = re.match(r"^(\s*)(\S+)(\s+)(.*?)(\s*#.*)?$", l)
            ops = split_ops(mb.group(4))
            n = -1
            for j, o in enumerate(ops):
                mo = re.fullmatch(r"(.*)\((\$?\w+)\)", o.strip())
                if mo and norm_reg(mo.group(2)) is not None:
                    n += 1
                    if n == k:
                        ops[j] = "%s(%s)" % (mo.group(1), _src_reg_tok(mo.group(2), x))
                elif norm_reg(o.strip()) is not None:
                    n += 1
                    if n == k:
                        ops[j] = _src_reg_tok(o.strip(), x)
            lines[li] = mb.group(1) + mb.group(2) + mb.group(3) + ",".join(ops) + (mb.group(5) or "")
            changed = True
    return "\n".join(lines) if changed else stext


def _src_reg_tok(like, reg):
    """`reg` (ABI name) spelled like the token `like` ($n numeric or $abi)."""
    if re.fullmatch(r"\$\d+", like.strip()):
        return "$%d" % ABI2NUM[reg]
    return "$" + reg


_SLT_S = re.compile(r"^(\s*)(slt|sltu)\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")
_SLTI0_TGT = re.compile(r"^(slti|sltiu)\s+\$?\w+\s*,\s*\$?\w+\s*,\s*(?:0x0|0)$")
_SLTI0_S = re.compile(r"^\s*(slti|sltiu|slt|sltu)\s+\$\w+\s*,\s*\$\w+\s*,\s*0\s*(#.*)?$")


def zero_cmp_imm_s(stext, budget):
    """`slt/sltu X,Y,R` where R holds zero on every path reaching it becomes
    `slt/sltu X,Y,0` (the assembler's slti/sltiu against 0)."""
    if budget <= 0:
        return stext
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    nr = _noreorder_lines(lines)
    changed = False
    for p, (li, l) in enumerate(ins):
        if budget <= 0:
            break
        m = _SLT_S.match(l)
        if not m:
            continue
        r = _src_reg(m.group(5))
        if not r or r == _src_reg("$0") or not _zero_reach(lines, ins, p, r, nr):
            continue
        lines[li] = "%s%s\t%s,%s,0" % (m.group(1), m.group(2), m.group(3), m.group(4))
        budget -= 1
        changed = True
    return "\n".join(lines) if changed else stext


def zero_remat_pass(stext, tgt):
    want = sum(1 for _w, dis in tgt if _ZERO_TGT.match(dis.strip()))
    have = sum(1 for l in stext.split("\n")
               if _s_is_insn(l) and _ZERO_DEF_S.match(l))
    stext = zero_remat_s(stext, want - have)
    want = sum(1 for _w, dis in tgt if _SLTI0_TGT.match(dis.strip()))
    have = sum(1 for l in stext.split("\n") if _s_is_insn(l) and _SLTI0_S.match(l))
    stext = zero_cmp_imm_s(stext, want - have)
    wk = {}
    for _w, dis in tgt:
        m = _KTGT.match(dis.strip())
        if m:
            k = int(m.group(1), 0)
            wk[k] = wk.get(k, 0) + 1
        mu = re.match(r"lui\s+\S+\s*,\s*(.+)$", dis.strip())
        if mu and "%hi" not in mu.group(1) and _sm_int(mu.group(1)) is not None:
            k = (_sm_int(mu.group(1)) & 0xFFFF) << 16    # a 1-word li of K<<16
            k = k - (1 << 32) if k & 0x80000000 else k
            wk[k] = wk.get(k, 0) + 1
    return const_remat_s(stext, wk)


# --------------------------------------------------------------------------
# exit-merge: cc1 emits each return as its own `j $31` (with the return value in
# the delay slot); retail funnels every return through ONE shared `jr $ra` laid
# last, other paths reaching it by `j <EXIT>`. Rewrite the cc1 source so its
# layout matches. Also unfill any conditional-branch delay the target leaves as a
# nop. Count-changing (adds the exit block), so it runs BEFORE sigma. Fires only
# when target is single-exit and ours is not.
# --------------------------------------------------------------------------
_EXIT_LABEL = "$Lgcce_exit"
_RET_S = re.compile(r"^\s*(?:j\s+\$31|jr\s+\$(?:31|ra))\b")
_COND_S = re.compile(r"^(beq|bne|blez|bgtz|bltz|bgez|beqz|bnez)\b")


def _s_is_label(l):
    s = l.strip()
    return s.endswith(":") and not s.startswith(".")


def _s_mnem(l):
    return l.strip().split(None, 1)[0].lower()


def _s_is_return(l):
    return bool(_RET_S.match(l))


def _count_returns_words(words):
    n = 0
    for _, dis in words:
        p = dis.split(None, 1)
        if p[0].lower() == "jr" and len(p) > 1 and norm_reg(p[1].strip()) == "ra":
            n += 1
    return n


def merge_exits_s(stext):
    """Fold cc1's multiple `j $31` returns into one shared exit. Returns new text."""
    lines = stext.split("\n")
    rets = [i for i, l in enumerate(lines) if _s_is_return(l)]
    if len(rets) < 2:
        return stext
    # one exit label per function: several exit-merged functions share a file
    ent = ENT_RE.search(stext)
    label = _EXIT_LABEL + ("_" + ent.group(1) if ent else "")
    last_i = rets[-1]
    # the last return falls into the shared exit only when nothing executable
    # follows its delay slot; otherwise it stays a jump to the exit
    after = [x for x in range(last_i + 1, len(lines)) if _s_is_insn(lines[x])
             and not lines[x].strip().startswith(".")]
    if len(after) > 1:
        last_i = None
    out = []
    for i, l in enumerate(lines):
        if i == last_i:
            continue                       # drop the last return (keep its delay insn)
        if _s_is_return(l):
            out.append(re.sub(r"(?:j|jr)\s+\$(?:31|ra)\b",
                              "j\t%s" % label, l, count=1))
        else:
            out.append(l)
    ins = len(out)
    for k in range(len(out) - 1, -1, -1):
        if out[k].strip().startswith(".end"):
            ins = k
            break
    exitblk = ["%s:" % label, "\t.set\tnoreorder", "\t.set\tnomacro",
               "\tj\t$31", "\tnop", "\t.set\tmacro", "\t.set\treorder"]
    return "\n".join(out[:ins] + exitblk + out[ins:])


def _target_cond_delay_nop(tgt):
    res = []
    for i, (_, dis) in enumerate(tgt):
        if _COND_S.match(dis.split(None, 1)[0].lower()):
            # the aspsx div-by-zero check (`bnez d,L; nop; break 7`) is not in
            # the cc1 source (maspsx expands it later): skip it so the k-th
            # target branch lines up with our k-th source branch
            if i + 2 < len(tgt) and tgt[i + 2][1].split(None, 1)[0].lower() == "break":
                continue
            nxt = tgt[i + 1][1] if i + 1 < len(tgt) else ""
            res.append(is_nop(nxt))
    return res


def unfill_cond_delay_s(stext, tgt):
    """Where the target's k-th conditional branch has a nop delay but our cc1 filled
    it, move our fill out to just after the branch and restore the nop."""
    want_nop = _target_cond_delay_nop(tgt)
    lines = stext.split("\n")
    result, idx, k = [], 0, -1
    noreorder = False
    while idx < len(lines):
        l = lines[idx]
        st = l.strip()
        if st.startswith(".set"):
            if "noreorder" in st:
                noreorder = True
            elif re.match(r"\.set\s+reorder\b", st):
                noreorder = False
        if _s_is_insn(l) and _COND_S.match(_s_mnem(l)):
            k += 1
            d = idx + 1
            while d < len(lines) and not _s_is_insn(lines[d]):
                if _s_is_label(lines[d]):
                    d = None
                    break
                d += 1
            # only a branch cc1 scheduled itself (inside .set noreorder) has its
            # next insn in the delay slot; in reorder mode the assembler pads it
            filled = noreorder and d is not None and not _src_is_nop(lines[d])
            if filled and k < len(want_nop) and want_nop[k]:
                result.append(l)
                indent = re.match(r"^(\s*)", lines[d]).group(1)
                displaced = lines[d]
                for m in range(idx + 1, d):
                    result.append(lines[m])
                result.append("%snop" % indent)
                m = d + 1
                tail = []
                while m < len(lines) and lines[m].strip() in (
                        ".set\tmacro", ".set macro", ".set\treorder", ".set reorder"):
                    tail.append(lines[m])
                    m += 1
                result.extend(tail)
                result.append(displaced)
                idx = m
                continue
        result.append(l)
        idx += 1
    return "\n".join(result)


def exit_merge_pass(stext, tgt):
    """Combined pre-sigma pass: when the target is single-exit and ours is not,
    unfill any target-nop conditional delay, then funnel our returns to one exit."""
    if _count_returns_words(tgt) != 1:
        return stext
    our_rets = sum(1 for l in stext.split("\n") if _s_is_return(l))
    if our_rets <= 1:
        return stext
    stext = unfill_cond_delay_s(stext, tgt)
    return merge_exits_s(stext)


# --------------------------------------------------------------------------
# operand-recolor: a commutative accumulate our cc1 computes into the INDEX temp
# while the target computes into the BASE temp (`op $I,$I,$B` vs `op $B,$B,$I`).
# The op is commutative so the value and the memory effect are identical and both
# temps are caller-saved (dead at exit); the only difference is which dead temp
# carries the address. sigma cannot express it (the temps keep their identity
# everywhere else), so it is a LOCAL recolor: rewrite the accumulate to the
# target's destination and rename our old destination downstream until it is
# redefined. Target-guided; bail if the base temp is written before the old
# index temp dies (unsafe merge).
# --------------------------------------------------------------------------
def _accs_numeric(pairs, to_num):
    """(op, dst, rs, rt) commutative ACCUMULATES (dst==rs, rt a real non-zero reg)
    in order. The accumulate form keeps both sides aligned (a `op rd,rs,zero`
    renders as `move` in cc1 but `addu` in the target)."""
    zero = "$%d" % ABI2NUM["zero"]
    out = []
    for _, dis in pairs:
        m = re.match(r"(\w+)\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*(\$?\w+)\s*$", dis)
        if not m or m.group(1).lower() not in _COMMUTATIVE_ACC:
            continue
        d, s, t = to_num(m.group(2)), to_num(m.group(3)), to_num(m.group(4))
        if d and s and t and d == s and t != zero:
            out.append((m.group(1).lower(), d, s, t))
    return out


def operand_recolor_s(stext, tgt):
    """Recolor a commutative accumulate our cc1 computes into the index temp but the
    target computes into the base temp (a local dead-temp swap). Returns new text
    (unchanged if it does not fire). stext is sigma-applied (numeric reg space)."""
    tgt_accs = _accs_numeric(tgt, _abi_to_num)
    if not tgt_accs:
        return stext
    lines = stext.split("\n")
    insn_ix = _s_insn_lines(lines)
    zero = "$%d" % ABI2NUM["zero"]
    our_accs = []
    for i in insn_ix:
        m = _ACC_S.match(lines[i])
        if m and m.group(2).lower() in _COMMUTATIVE_ACC \
                and m.group(3) == m.group(4) and m.group(5) != zero:
            our_accs.append((i, m.group(2).lower(), m.group(3), m.group(4), m.group(5)))
    if len(our_accs) != len(tgt_accs):
        return stext
    for (li, op, od, os_, ot), (top, td, ts, tt) in zip(our_accs, tgt_accs):
        if op != top:
            continue
        # target accumulates S into B (`op $B,$B,$S`, td==ts, S==tt); ours is the
        # swapped `op $S,$S,$B` (od==os_==tt, ot==td). Recolor od(=$S) -> $B(td).
        if not (td == ts and od == os_ and od == tt and ot == td):
            continue
        newB, oldI = td, od
        indent = lines[li][:len(lines[li]) - len(lines[li].lstrip())]
        safe, redef_at = True, None
        for j in insn_ix:
            if j <= li:
                continue
            mm = re.match(r"\s*([a-z][\w.]*)\s+(\$\d+)\b", lines[j])
            if not mm:
                continue
            mn, dst = mm.group(1).lower(), mm.group(2)
            is_store = mn in _STORE_MN or mn.startswith(("sb", "sh", "sw"))
            if not is_store and dst == newB:
                safe = False
                break
            if not is_store and dst == oldI:
                redef_at = j
                break
        if not safe:
            continue
        lines[li] = "%s%s\t%s,%s,%s" % (indent, op, newB, newB, oldI)
        reg_re = re.compile(r"(?<![\w$])" + re.escape(oldI) + r"(?![\w])")
        for j in insn_ix:
            if j <= li:
                continue
            if redef_at is not None and j >= redef_at:
                break
            lines[j] = reg_re.sub(newB, lines[j])
        return "\n".join(lines)
    return stext


# --------------------------------------------------------------------------
# web_realloc. reg_realloc renames registers through ONE global sigma, so it
# cannot express "this live range of $a0 is $v1 in the target while the entry
# value stays in $a0" (func_80025114: `lbu $v1,0x46($a0)` where ours reuses the
# dead argument register). This pass splits every register into webs (def-use
# chains joined at shared uses, reaching definitions over the delay-slot aware
# CFG), aligns our instructions with the target words (mnemonic sequence
# match, nops ignored) and renames one web at a time to the register the
# target uses at every aligned occurrence of it. Sound: a web is renamed only
# when it is not pinned (entry value, call argument/clobber, return value,
# $sp/$fp/$ra/$at/$gp) and does not interfere (Chaitin: neither is live where
# the other is defined) with any web currently held in the new register.
# Count-preserving, text pass after sigma.
# --------------------------------------------------------------------------
_WR_USE_ONLY = {"jr", "j", "b", "jal", "jalr", "mult",
                "multu", "div", "divu", "mthi", "mtlo"}
_WR_FIXED = {"zero", "sp", "fp", "gp", "k0", "k1", "ra", "at", "hi", "lo"}
_WR_RET = ("v0", "sp", "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp", "ra")
_WR_VOID = [False]


def web_realloc_void_pass(stext, tgt):
    """web_realloc where a void function's return does not read v0, so a web
    in v0 that reaches the return is not pinned. Separate token: plain
    web_realloc keeps the conservative return (matched functions rely on it)."""
    _WR_VOID[0] = True
    try:
        return web_realloc_pass(stext, tgt)
    finally:
        _WR_VOID[0] = False
_WR_IMM = {"addu": "addiu", "and": "andi", "or": "ori", "xor": "xori",
           "slt": "slti", "sltu": "sltiu", "subu": "addiu"}


def _wr_parse(line):
    """cc1 insn line -> (indent, mnem, ops, comment, regpos) where regpos is
    [(op_index, in_parens, abi_reg)] in operand order."""
    body, _, com = line.partition("#")
    indent = line[:len(line) - len(line.lstrip())]
    p = body.strip().split(None, 1)
    mn = p[0].lower() if p else ""
    ops = split_ops(p[1]) if len(p) > 1 else []
    rp = []
    for k, op in enumerate(ops):
        mm = re.fullmatch(r"(.*)\((\$\w+)\)", op)
        if mm and norm_reg(mm.group(2)) is not None:
            rp.append((k, True, norm_reg(mm.group(2))))
        elif norm_reg(op) is not None:
            rp.append((k, False, norm_reg(op)))
    return indent, mn, ops, com, rp


def _wr_canon(mn, ops, rp):
    """Our line -> [(tgt_mnem, [(reg, ourpos|None)])] word tokens for alignment."""
    regs = [(r, i) for i, (_, _, r) in enumerate(rp)]
    so = _sym_operand("\t%s\t%s" % (mn, ",".join(ops)))
    if so or mn == "la":
        return [("?", [])] * _src_nwords("\t%s\t%s" % (mn, ",".join(ops)))
    if mn == "li":
        n = _src_nwords("\tli\t%s" % ",".join(ops))
        v = int(ops[-1], 0)
        if n != 1 and v & 0xFFFF == 0:
            return [("lui", regs)]
        if n != 1:
            return [("?", [])] * n
        return [("addiu" if v < 0x8000 else "ori", regs + [("zero", None)])]
    if mn == "move":
        return [("addu", regs + [("zero", None)])]
    if mn in ("beq", "bne") and len(regs) == 2 and regs[1][0] == "zero":
        return [(mn + "z", regs[:1])]
    if mn == "j" and regs:
        return [("jr", regs)]
    if mn == "jal" and regs:
        return [("jalr", regs)]
    if mn in _WR_IMM and len(ops) == 3 and len(regs) == 2 and not ops[2].startswith("$"):
        return [(_WR_IMM[mn], regs)]
    return [(mn, regs)]


def _wr_nodes(lines):
    """Build the CFG. Returns (nodes, ok). node = {line, uses:[(reg,pos)],
    defs:[(reg,pos)], succ:[...]}; pos None = implicit (pins the web)."""
    nodes, labels, pend, nr = [], {}, [], False
    jt = []
    for l in lines:
        mj = re.match(r"\s*\.(?:word|gpword)\s+(\$L\w+)\s*$", l)
        if mj and mj.group(1) not in jt:
            jt.append(mj.group(1))
    nodes.append({"line": None, "uses": [], "succ": [1],
                  "defs": [(r, None) for r in ABI2NUM if norm_reg(r) == r
                           and r not in ("zero", "hi", "lo")]})
    ins = []
    for i, l in enumerate(lines):
        s = l.strip()
        if s.startswith(".set"):
            w = s.split()[-1]
            if w == "noreorder":
                nr = True
            elif w == "reorder":
                nr = False
            continue
        m = re.match(r"^([\w.$]+):", s)
        if m:
            ins.append(("L", m.group(1), None))
            continue
        if _s_is_insn(l) and s.split(None, 1)[0].lower() != "nop":
            ins.append(("I", i, nr))
        elif _s_is_insn(l):
            ins.append(("N", i, nr))
    k = 0

    def node(line, uses, defs, fall=True):
        nodes.append({"line": line, "uses": uses, "defs": defs, "succ": [], "fall": fall})
        return len(nodes) - 1

    def ordinary(i):
        ind, mn, ops, com, rp = _wr_parse(lines[i])
        uses, defs = [], []
        for pos, (_, _, r) in enumerate(rp):
            if pos == 0 and mn not in _WR_USE_ONLY and mn not in _STORE_MN \
                    and mn not in _COND_BR_MN:
                defs.append((r, pos))
            else:
                uses.append((r, pos))
        if _sym_operand(lines[i]):
            defs.append(("at", None))
        if mn in ("mult", "multu", "div", "divu"):
            defs += [("hi", None), ("lo", None)]
        return uses, defs

    while k < len(ins):
        kind, a, nrf = ins[k]
        if kind == "L":
            labels[a] = len(nodes)
            k += 1
            continue
        i = a
        ind, mn, ops, com, rp = _wr_parse(lines[i])
        if kind == "N":
            node(i, [], [])
            k += 1
            continue
        xfer = mn in _COND_BR_MN or mn in ("j", "b", "jal", "jalr", "jr")
        if not xfer:
            u, d = ordinary(i)
            node(i, u, d)
            k += 1
            continue
        slot = None
        if nrf and k + 1 < len(ins) and ins[k + 1][0] in ("I", "N"):
            slot = ins[k + 1][1]
        lab = re.search(r"(\$L\w+)\s*$", lines[i].split("#", 1)[0])
        regs = [(r, pos) for pos, (_, _, r) in enumerate(rp)]
        if mn in _COND_BR_MN:
            node(i, regs, [])
        elif mn in ("jal", "jalr") and regs:
            node(i, regs[-1:], [])
        elif mn in ("j", "jr") and regs:
            if regs[0][0] != "ra":
                # switch jump: successors are the entries of the span's jump
                # tables (every table: a superset of the real ones is sound)
                if not jt:
                    return nodes, False
                node(i, regs, [])
            else:
                node(i, [], [])
        else:
            node(i, [], [])
        head = len(nodes) - 1
        if slot is not None:
            u, d = ordinary(slot) if ins[k + 1][0] == "I" else ([], [])
            node(slot, u, d)
        last = len(nodes) - 1
        if mn in ("jal", "jalr"):
            # a direct call reads only the argument registers its callee's
            # retail asm reads (unknown callee: all four)
            mc = re.match(r"\s*jal\s+([A-Za-z_]\w*)\s*$", lines[i].split("#", 1)[0])
            node(None, [(r, None) for r in ("a0", "a1", "a2", "a3")
                        if not mc or _callee_reads(mc.group(1), r)],
                 [(r, None) for r in _CALL_CLOBBER if r not in ("hi", "lo")])
        elif mn in ("j", "jr") and regs and regs[0][0] != "ra":
            nodes[last]["jumps"] = jt
            nodes[last]["fall"] = False
        elif mn in ("j", "jr") and regs:
            node(None, [(r, None) for r in _WR_RET
                        if not (r == "v0" and _WR_VOID[0] and _s_void(lines))], [], fall=False)
        elif mn in ("j", "b"):
            nodes[last]["jump"] = lab.group(1) if lab else None
            nodes[last]["fall"] = False
            if not lab:
                return nodes, False
        if mn in _COND_BR_MN:
            if not lab:
                return nodes, False
            nodes[last]["jump"] = lab.group(1)
        k += 2 if slot is not None else 1
    for n, nd in enumerate(nodes):
        if n == 0:
            continue
        if nd.get("fall", True) and n + 1 < len(nodes):
            nd["succ"].append(n + 1)
        for jl in ([nd["jump"]] if nd.get("jump") else []) + nd.get("jumps", []):
            t = labels.get(jl)
            if t is None:
                return nodes, False
            if t < len(nodes) and t not in nd["succ"]:
                nd["succ"].append(t)
    return nodes, True


def _wr_webs(nodes):
    """Reaching defs -> webs. Returns (occ, pinned, live_out, defs_at) keyed by
    web root: occ[(node,reg,pos)] = root; defs_at[node] = [roots defined]."""
    dids = []                                   # (node, reg, pos)
    gen = []
    for n, nd in enumerate(nodes):
        g = {}
        for r, pos in nd["defs"]:
            g[r] = len(dids)
            dids.append((n, r, pos))
        gen.append(g)
    pred = [[] for _ in nodes]
    for n, nd in enumerate(nodes):
        for s in nd["succ"]:
            pred[s].append(n)
    IN = [dict() for _ in nodes]
    OUT = [dict() for _ in nodes]
    ch = True
    while ch:
        ch = False
        for n in range(len(nodes)):
            new = {}
            for p in pred[n]:
                for r, ds in OUT[p].items():
                    new.setdefault(r, set()).update(ds)
            IN[n] = new
            o = {r: set(ds) for r, ds in new.items()}
            for r, d in gen[n].items():
                o[r] = {d}
            if o != OUT[n]:
                OUT[n] = o
                ch = True
    par = list(range(len(dids)))

    def f(x):
        while par[x] != x:
            par[x] = par[par[x]]
            x = par[x]
        return x
    useocc = []
    for n, nd in enumerate(nodes):
        for r, pos in nd["uses"]:
            ds = sorted(IN[n].get(r, ()))
            if not ds:
                continue
            for d in ds[1:]:
                par[f(d)] = f(ds[0])
            useocc.append((n, r, pos, ds[0]))
    occ, pinned = {}, set()
    for d, (n, r, pos) in enumerate(dids):
        occ[(n, r, pos, "d")] = f(d)
        if pos is None:
            pinned.add(f(d))
    for n, r, pos, d in useocc:
        occ[(n, r, pos, "u")] = f(d)
        if pos is None:
            pinned.add(f(d))
    reg_of = {f(d): r for d, (n, r, pos) in enumerate(dids)}
    # web liveness (backward)
    use_w = [set() for _ in nodes]
    def_w = [set() for _ in nodes]
    for (n, r, pos, kd), w in occ.items():
        (use_w if kd == "u" else def_w)[n].add(w)
    LI = [set() for _ in nodes]
    LO = [set() for _ in nodes]
    ch = True
    while ch:
        ch = False
        for n in range(len(nodes) - 1, -1, -1):
            lo = set()
            for s in nodes[n]["succ"]:
                lo |= LI[s]
            li = use_w[n] | (lo - def_w[n])
            if lo != LO[n] or li != LI[n]:
                LO[n], LI[n] = lo, li
                ch = True
    return occ, pinned, reg_of, LO, def_w


def _wr_rename(lines, nodes, occ, mapping):
    """Rewrite every explicit occurrence of each web in `mapping` to its new
    register (simultaneously)."""
    edits = {}
    for (n, rr, pos, kd), w in occ.items():
        if w in mapping and pos is not None:
            edits.setdefault(nodes[n]["line"], {})[pos] = "$%d" % ABI2NUM[mapping[w]]
    for li, poss in edits.items():
        ind, mn, ops, com, rp = _wr_parse(lines[li])
        ops = list(ops)
        for pos, num in poss.items():
            k, par_, _r = rp[pos]
            if par_:
                ops[k] = re.sub(r"\(\$\w+\)$", "(%s)" % num, ops[k])
            else:
                ops[k] = num
        body = lines[li].split("#", 1)[0].strip().split(None, 1)[0]
        lines[li] = "%s%s\t%s%s" % (ind, body, ",".join(ops),
                                    ("\t#" + com) if com else "")


def _wr_imms(items):
    """Integer operands (immediates, memory offsets) of an operand list; labels
    and %hi/%lo operands are skipped."""
    out = []
    for it in items:
        it = it.strip()
        mm = re.fullmatch(r"(.*)\((\S+)\)", it)
        if mm and (mm.group(2) == "#" or norm_reg(mm.group(2)) is not None):
            it = mm.group(1).strip()
        if norm_reg(it) is not None or it == "#":
            continue
        v = _sm_int(it) if it else 0
        if v is not None:
            out.append(str(v))
    return out


def _wr_tok(mn, regs, sym, imms):
    """Alignment token: mnemonic, %hi/%lo symbol, zero-register pattern, ints."""
    return "%s|%s|%s|%s" % (mn, sym or "", "".join("Z" if r == "zero" else "R" for r in regs),
                            ",".join(imms))


def web_realloc_pass(stext, tgt):
    lines = stext.split("\n")
    tk = []
    for _, d in tgt:
        mn, regs, sk = insn_parts(d)
        if mn != "nop":
            sy = _SYM_RE.findall(d)
            tk.append((_wr_tok(mn, regs, sy[0] if sy else "", _wr_imms(sk)), regs))
    for _ in range(12):
        nodes, ok = _wr_nodes(lines)
        if not ok:
            return stext if _ == 0 else "\n".join(lines)
        occ, pinned, reg_of, LO, def_w = _wr_webs(nodes)
        ours = []                                  # (node, [(reg,pos)], mnem)
        for n, nd in enumerate(nodes):
            if nd["line"] is None or n == 0:
                continue
            ind, mn, ops, com, rp = _wr_parse(lines[nd["line"]])
            if mn == "nop" or not mn:
                continue
            sy = _SYM_RE.findall(lines[nd["line"]].split("#", 1)[0])
            im = _wr_imms(ops)
            if mn == "subu" and len(im) == 1:
                im = [str(-int(im[0]))]
            for cm, cr in _wr_canon(mn, ops, rp):
                if mn == "li" and cm == "lui":
                    im = [str((int(ops[-1], 0) >> 16) & 0xFFFF)]
                ours.append((n, cr, "?" if cm == "?" else
                             _wr_tok(cm, [r for r, _p in cr], sy[0] if sy else "", im)))
        sm = difflib.SequenceMatcher(None, [o[2] for o in ours], [t[0] for t in tk],
                                     autojunk=False)
        want, comm_ops = {}, []

        def vote(w, t):
            if w is not None:
                cnt = want.setdefault(w, {})
                cnt[t] = cnt.get(t, 0) + 1
        for a, b, size in sm.get_matching_blocks():
            for q in range(size):
                n, cr, cm = ours[a + q]
                treg = tk[b + q][1]
                if len(treg) != len(cr):
                    continue
                comm = cm.split("|", 1)[0] in _COMMUTATIVE_ACC | {"mult", "multu"}
                # a pinned web (entry value, call argument, ...) keeps its register:
                # an aligned pair that disagrees there is a misalignment
                if not comm and any(
                        occ.get((n, r, pos, kd)) in pinned and r != t
                        for (r, pos), t in zip(cr, treg) if pos is not None
                        for kd in ("d", "u")):
                    continue
                uses = []
                for k, ((r, pos), t) in enumerate(zip(cr, treg)):
                    if pos is None:
                        continue
                    vote(occ.get((n, r, pos, "d")), t)
                    if comm and (k > 0 or cm.startswith("mult")):
                        uses.append((occ.get((n, r, pos, "u")), t))
                    else:
                        vote(occ.get((n, r, pos, "u")), t)
                if len(uses) == 2:
                    comm_ops.append(uses)
                else:
                    for w, t in uses:
                        vote(w, t)
        # commutative operands: pair them straight or crossed, whichever agrees
        # better with the votes from everything else (straight on a tie)
        base = {w: max(c.items(), key=lambda x: x[1])[0] for w, c in want.items()}
        for (w1, t1), (w2, t2) in comm_ops:
            st = (base.get(w1) == t1) + (base.get(w2) == t2)
            cr_ = (base.get(w1) == t2) + (base.get(w2) == t1)
            if cr_ > st:
                t1, t2 = t2, t1
            vote(w1, t1)
            vote(w2, t2)
        # all wanted webs at once first (resolves swaps and cycles), then one
        # at a time
        cand = {}
        pick = {}
        for w, cnt in want.items():
            # plurality of the aligned occurrences (identical-looking insns can
            # pair up crosswise; any pick is sound, the gate decides)
            top = sorted(cnt.items(), key=lambda x: -x[1])
            if len(top) == 1 or top[0][1] > top[1][1]:
                pick[w] = top[0][0]
        for w, t in pick.items():
            if w in pinned:
                continue
            if t != reg_of[w] and t not in _WR_FIXED and reg_of[w] not in _WR_FIXED:
                cand[w] = t
        if len(cand) > 1:
            fin = dict(reg_of)
            fin.update(cand)
            clash = any(fin[x] == fin[y] for n in range(len(nodes))
                        for x in def_w[n] for y in LO[n] if x != y)
            if not clash:
                _wr_rename(lines, nodes, occ, cand)
                continue
        done = False
        for w, t in sorted(pick.items()):
            if w in pinned:
                continue
            r = reg_of[w]
            if t == r or t in _WR_FIXED or r in _WR_FIXED:
                continue
            others = [x for x, rr in reg_of.items() if rr == t]
            bad = False
            for n in range(len(nodes)):
                if w in def_w[n] and any(x in LO[n] for x in others):
                    bad = True
                    break
                if w in LO[n] and any(x in def_w[n] for x in others):
                    bad = True
                    break
            if bad:
                continue
            _wr_rename(lines, nodes, occ, {w: t})
            done = True
            break
        if not done:
            break
    return "\n".join(lines)


def _wr_pick(lines, tk):
    """Shared web-realloc vote step: build the CFG/webs, align our token stream to
    the target and return (nodes, occ, pinned, reg_of, LO, def_w, pick) where
    pick[web] = the register the target uses for that web at a plurality of aligned
    occurrences. `pick` is the raw wanted mapping BEFORE any interference filtering.
    Returns None if the CFG could not be built."""
    nodes, ok = _wr_nodes(lines)
    if not ok:
        return None
    occ, pinned, reg_of, LO, def_w = _wr_webs(nodes)
    ours = []
    for n, nd in enumerate(nodes):
        if nd["line"] is None or n == 0:
            continue
        ind, mn, ops, com, rp = _wr_parse(lines[nd["line"]])
        if mn == "nop" or not mn:
            continue
        sy = _SYM_RE.findall(lines[nd["line"]].split("#", 1)[0])
        im = _wr_imms(ops)
        if mn == "subu" and len(im) == 1:
            im = [str(-int(im[0]))]
        for cm, cr in _wr_canon(mn, ops, rp):
            if mn == "li" and cm == "lui":
                im = [str((int(ops[-1], 0) >> 16) & 0xFFFF)]
            ours.append((n, cr, "?" if cm == "?" else
                         _wr_tok(cm, [r for r, _p in cr], sy[0] if sy else "", im)))
    sm = difflib.SequenceMatcher(None, [o[2] for o in ours], [t[0] for t in tk],
                                 autojunk=False)
    want, comm_ops = {}, []

    def vote(w, t):
        if w is not None:
            cnt = want.setdefault(w, {})
            cnt[t] = cnt.get(t, 0) + 1
    for a, b, size in sm.get_matching_blocks():
        for q in range(size):
            n, cr, cm = ours[a + q]
            treg = tk[b + q][1]
            if len(treg) != len(cr):
                continue
            comm = cm.split("|", 1)[0] in _COMMUTATIVE_ACC | {"mult", "multu"}
            if not comm and any(
                    occ.get((n, r, pos, kd)) in pinned and r != t
                    for (r, pos), t in zip(cr, treg) if pos is not None
                    for kd in ("d", "u")):
                continue
            uses = []
            for k, ((r, pos), t) in enumerate(zip(cr, treg)):
                if pos is None:
                    continue
                vote(occ.get((n, r, pos, "d")), t)
                if comm and (k > 0 or cm.startswith("mult")):
                    uses.append((occ.get((n, r, pos, "u")), t))
                else:
                    vote(occ.get((n, r, pos, "u")), t)
            if len(uses) == 2:
                comm_ops.append(uses)
            else:
                for w, t in uses:
                    vote(w, t)
    base = {w: max(c.items(), key=lambda x: x[1])[0] for w, c in want.items()}
    for (w1, t1), (w2, t2) in comm_ops:
        st = (base.get(w1) == t1) + (base.get(w2) == t2)
        cr_ = (base.get(w1) == t2) + (base.get(w2) == t1)
        if cr_ > st:
            t1, t2 = t2, t1
        vote(w1, t1)
        vote(w2, t2)
    pick = {}
    for w, cnt in want.items():
        top = sorted(cnt.items(), key=lambda x: -x[1])
        if len(top) == 1 or top[0][1] > top[1][1]:
            pick[w] = top[0][0]
    return nodes, occ, pinned, reg_of, LO, def_w, pick, want


def web_cycle_pass(stext, tgt):
    """Resolve a PERMUTATION CYCLE of webs that web_realloc's global all-or-nothing
    batch cannot, because that batch aborts on any single interference anywhere in
    the function (registers like $v0 are reused for dozens of unrelated values, so a
    global `fin[x]==fin[y]` clash is almost always present). This pass finds the
    webs whose target register is held by ANOTHER moving web, decomposes them into
    closed cycles (w1 wants reg_of[w2], w2 wants reg_of[w3], ..., wk wants reg_of[w1]),
    and applies each cycle SIMULTANEOUSLY when the interference check restricted to
    that cycle's members passes. Renaming a set of webs onto a permutation of the
    registers they already occupy is semantics-preserving iff no cycle member is live
    where another web that keeps one of those registers is defined; the check below
    enforces exactly that (Chaitin interference over the delay-slot-aware CFG). A pure
    cycle only reshuffles registers among the cycle's own webs, so it never collides
    with the cycle members themselves. Count-preserving, opt-in (no committed recipe
    names it, so zero regression), text pass after sigma. Handles func_800678D8's
    v1->v0->a0->v1 first-block 3-cycle that web_realloc leaves at bad 5."""
    lines = stext.split("\n")
    tk = []
    for _, d in tgt:
        mn, regs, sk = insn_parts(d)
        if mn != "nop":
            sy = _SYM_RE.findall(d)
            tk.append((_wr_tok(mn, regs, sy[0] if sy else "", _wr_imms(sk)), regs))
    for _ in range(12):
        got = _wr_pick(lines, tk)
        if got is None:
            return "\n".join(lines)
        nodes, occ, pinned, reg_of, LO, def_w, pick, want = got
        # candidate movers: the strongest voted register that is NOT the web's
        # current one, as long as it is at least as strongly voted as staying put.
        # (pick drops ties, which hides a cycle member whose target reg ties with
        # its current reg -- func_800678D8 web 36 votes v1:2/a0:2. A cycle is only
        # ever APPLIED when it closes and passes interference, so admitting tie
        # candidates here is safe; non-closing ones are dropped below.)
        move = {}
        for w, cnt in want.items():
            if w in pinned:
                continue
            r = reg_of.get(w)
            if r is None or r in _WR_FIXED:
                continue
            alts = [(v, t) for t, v in cnt.items() if t != r and t not in _WR_FIXED]
            if not alts:
                continue
            v, t = max(alts)
            if v >= cnt.get(r, 0):
                move[w] = t
        if not move:
            return "\n".join(lines)
        holder = {}                                # register -> the moving web in it
        for w in move:
            holder[reg_of[w]] = w
        applied = False
        seen = set()
        for w0 in list(move):
            if w0 in seen:
                continue
            cyc, cur = [], w0
            while cur is not None and cur not in seen:
                seen.add(cur)
                cyc.append(cur)
                cur = holder.get(move[cur])        # who currently holds our target reg
            # closed cycle: last member's target register is held by the first member
            if not cyc or holder.get(move[cyc[-1]]) != cyc[0]:
                continue
            cycset = set(cyc)
            cmap = {x: move[x] for x in cyc}
            fin = dict(reg_of)
            fin.update(cmap)
            clash = False
            for n in range(len(nodes)):
                for x in def_w[n]:
                    for y in LO[n]:
                        if x != y and (x in cycset or y in cycset) \
                                and fin.get(x) == fin.get(y):
                            clash = True
                            break
                    if clash:
                        break
                if clash:
                    break
            if clash:
                continue
            _wr_rename(lines, nodes, occ, cmap)
            applied = True
            break                                  # webs changed: rebuild and repeat
        if not applied:
            break
    return "\n".join(lines)


# --------------------------------------------------------------------------
# const_fold: `li $t,K ... addu $r,$b,$t` where retail folded the constant into
# the add (`addiu $r,$b,K`; the li stays for $t's other uses). Our cc1 keeps the
# register form when $t is a loop counter initialised to K (a giv init from a
# biv). Target-guided: fires only while the target has more `addiu x,y,K` (y
# not $zero/$sp) than we do. Straight line only; $t and $b not written in
# between. Count-preserving.
# --------------------------------------------------------------------------
_CF_LI = re.compile(r"^(\s*)li\s+(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*(#.*)?$")
_CF_ADDU = re.compile(r"^(\s*)addu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")


def _cf_count(bodies, k):
    n = 0
    for b in bodies:
        mn, regs, sk = insn_parts(b)
        if mn == "addiu" and len(regs) == 2 and regs[1] not in ("zero", "sp") \
                and _sm_int(sk[-1]) == k:
            n += 1
    return n


def const_fold_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    tb = [d.strip() for _w, d in tgt]
    changed = False
    for i, l in enumerate(lines):
        m = _CF_LI.match(l)
        if not m or i in nr:
            continue
        t, k = norm_reg(m.group(2)), int(m.group(3), 0)
        if not (-0x8000 <= k < 0x8000) or t in (None, "zero", "at"):
            continue
        for j in range(i + 1, len(lines)):
            lj = lines[j]
            if _join_label(lines, j):
                break
            if not _s_is_insn(lj) or lj.strip().startswith("."):
                continue
            body = lj.split("#", 1)[0].strip()
            ma = _CF_ADDU.match(lj)
            if ma and j not in nr and t in (norm_reg(ma.group(3)), norm_reg(ma.group(4))) \
                    and norm_reg(ma.group(3)) != norm_reg(ma.group(4)):
                b = ma.group(4) if norm_reg(ma.group(3)) == t else ma.group(3)
                if norm_reg(b) in ("zero", "sp"):
                    break
                ours = [x.split("#", 1)[0].strip() for x in lines if _s_is_insn(x)
                        and not x.strip().startswith(".")]
                if _cf_count(tb, k) <= _cf_count(ours, k):
                    break
                lines[j] = "%saddiu\t%s,%s,%d" % (ma.group(1), ma.group(2), b, k)
                changed = True
                break
            if _src_is_branch(lj) or _src_is_ret(lj) or re.match(r"\s*jalr?\b", lj):
                break
            if t in defs_uses(body)[0]:
                break
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# arg_unprop: our sched1 hoisted a call's argument copy `move $aN,$S` above other
# work, and cse then fed that work from the copy ($aN) instead of $S. Retail keeps
# the copies right before the call and the work reads $S. Rewrite each non-call
# reader of $aN between the copy and its call to read $S (same value: neither is
# written in between), so sched_match can sink the copy. Target-guided: fires only
# when the target has no insn other than a copy that reads $aN in a
# straight-line call setup, i.e. the target's reader of that value reads an
# s-register. Count-preserving.
# --------------------------------------------------------------------------
_AU_MOVE = re.compile(r"^(\s*)move\s+(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")


def _au_tgt_arg_reads(tgt):
    """Number of target insns that read an argument register and are not a copy,
    a call, a store of it, or a branch."""
    n = 0
    for _w, d in tgt:
        mn, regs, _sk = insn_parts(d.strip())
        if mn in ("jal", "jalr", "addu", "or") and (mn in ("jal", "jalr") or "zero" in regs[1:]):
            continue
        if mn in _STORE_MN or mn in _COND_BR_MN:
            continue
        _d, u = defs_uses(d.strip())
        if any(r in ("a0", "a1", "a2", "a3") for r in u):
            n += 1
    return n


def arg_unprop_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ours = [l.split("#", 1)[0].strip() for l in lines if _s_is_insn(l) and not l.strip().startswith(".")]
    budget = _au_tgt_arg_reads(tgt) - _au_tgt_arg_reads([(0, b) for b in ours])
    if budget >= 0:
        return stext
    changed = False
    for i, l in enumerate(lines):
        m = _AU_MOVE.match(l)
        if not m or i in nr:
            continue
        a, src = norm_reg(m.group(2)), norm_reg(m.group(3))
        if a not in ("a0", "a1", "a2", "a3") or not re.match(r"s[0-7]$", src or ""):
            continue
        hits, ok = [], False
        for j in range(i + 1, len(lines)):
            lj = lines[j]
            if _join_label(lines, j):
                break
            if not _s_is_insn(lj) or lj.strip().startswith("."):
                continue
            body = lj.split("#", 1)[0].strip()
            if re.match(r"jal\s", body):
                ok = True
                break
            if _src_is_branch(lj) or _src_is_ret(lj):
                break
            d, u = defs_uses(body)
            if a in d or src in d:
                break
            if a in u and j not in nr:
                hits.append(j)
        if not ok or not hits:
            continue
        for j in hits:
            body, com = (lines[j].split("#", 1) + [""])[:2]
            nb = re.sub(r"(?<![\w$])%s(?![\w])" % re.escape(m.group(2)), m.group(3), body)
            if nb != body:
                lines[j] = nb + ("#" + com if com else "")
                changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# sreg_perm: our allocator gave the callee-saved pseudos the s-registers in a
# different order than retail (e.g. param copy in s2, a global's address in s0,
# retail the other way round) while everything else lines up. Renaming the
# s-registers consistently over the whole function (saves and restores
# included) preserves its meaning. Try every permutation of the s-registers we
# use (up to 5) and keep the one whose insn sequence matches the target best,
# only when it beats the identity. save_slot then re-lays the save area.
# Count-preserving.
# --------------------------------------------------------------------------
_SR_NUM = {"s%d" % k: "$%d" % (16 + k) for k in range(8)}
_SR_NUM["fp"] = "$30"


def _sr_used(lines):
    """Callee-saved registers the body uses as plain registers: s0-s7, plus $fp
    when it is not a frame pointer (never set from $sp or copied into it)."""
    used, fp_frame = set(), False
    for l in lines:
        if _s_is_insn(l) and not l.strip().startswith("."):
            d, u = defs_uses(l.split("#", 1)[0].strip())
            regs = set(d) | set(u)
            used |= {r for r in regs if re.match(r"s[0-7]$|fp$", r or "")}
            mn = l.split("#", 1)[0].split(None, 1)[0].lower()
            if mn not in _SM_LOADS and mn not in _STORE_MN and (
                    ("fp" in d and "sp" in u) or ("sp" in d and "fp" in u)):
                fp_frame = True
    if fp_frame:
        used.discard("fp")
    return used


def _sr_rename(lines, perm):
    pat = re.compile(r"\$(1[6-9]|2[0-3]|30|s[0-8]|fp)(?![\w])")

    def sub(m):
        r = norm_reg(m.group(0))
        n = perm.get(r, r)
        if n == r:
            return m.group(0)
        return _SR_NUM[n] if m.group(1).isdigit() else "$" + n
    out = []
    for l in lines:
        if _s_is_insn(l) and not l.strip().startswith("."):
            body, sep, com = l.partition("#")
            out.append(pat.sub(sub, body) + sep + com)
        else:
            out.append(l)
    return out


def sreg_perm_pass(stext, tgt):
    if not tgt:
        return stext
    import itertools
    lines = stext.split("\n")
    used = sorted(_sr_used(lines))
    if len(used) < 2:
        return stext
    tk = [_sm_key(d.strip(), True) for _w, d in tgt]
    tk = [k for k in tk if k not in (None, "skip")]

    def score(ls):
        ok = [_sm_srckey(l.split("#", 1)[0].strip()) for l in ls
              if _s_is_insn(l) and not l.strip().startswith(".")]
        ok = [k for k in ok if k is not None]
        sm = difflib.SequenceMatcher(None, ok, tk, autojunk=False)
        return sum(b.size for b in sm.get_matching_blocks())
    base = score(lines)
    best, best_s = None, base
    if len(used) <= 5:
        for pm in itertools.permutations(used):
            perm = dict(zip(used, pm))
            if all(k == v for k, v in perm.items()):
                continue
            sc = score(_sr_rename(lines, perm))
            if sc > best_s:
                best, best_s = perm, sc
    else:
        # too many for every permutation: greedy transpositions, best first
        cur = {r: r for r in used}
        while True:
            step = None
            for x, y in itertools.combinations(used, 2):
                perm = dict(cur)
                perm[x], perm[y] = cur[y], cur[x]
                sc = score(_sr_rename(lines, perm))
                if sc > best_s:
                    step, best_s = perm, sc
            if step is None:
                # no single swap helps: try 3-cycles (a rotation of three
                # registers needs two swaps, neither of which helps alone)
                for x, y, z in itertools.permutations(used, 3):
                    if x > y or x > z:
                        continue
                    perm = dict(cur)
                    perm[x], perm[y], perm[z] = cur[y], cur[z], cur[x]
                    sc = score(_sr_rename(lines, perm))
                    if sc > best_s:
                        step, best_s = perm, sc
            if step is None:
                break
            cur = best = step
    if best is None:
        return stext
    return "\n".join(_sr_rename(lines, best))


# --------------------------------------------------------------------------
# sreg_swap: an s-register can host two webs (a parameter copy early, a loop
# accumulator late) while retail swapped only the early ones between two
# s-registers. sreg_perm's whole-function rename then fixes the early webs and
# breaks the late ones, so it never wins. Try each transposition of two
# s-registers over the whole function followed by web_realloc (which moves the
# late webs back where the target wants them, soundly: interference checked);
# keep the best when it beats web_realloc alone. Count-preserving.
# --------------------------------------------------------------------------
def sreg_swap_pass(stext, tgt):
    if not tgt:
        return stext
    import itertools
    lines = stext.split("\n")
    used = sorted(_sr_used(lines))
    if len(used) < 2:
        return stext
    tk = [_sm_key(d.strip(), True) for _w, d in tgt]
    tk = [k for k in tk if k not in (None, "skip")]

    def score(txt):
        ok = [_sm_srckey(l.split("#", 1)[0].strip()) for l in txt.split("\n")
              if _s_is_insn(l) and not l.strip().startswith(".")]
        ok = [k for k in ok if k is not None]
        sm = difflib.SequenceMatcher(None, ok, tk, autojunk=False)
        return sum(b.size for b in sm.get_matching_blocks())
    best = web_realloc_pass(stext, tgt)
    best_s = score(best)
    base_s = best_s
    for x, y in itertools.combinations(used, 2):
        cand = web_realloc_pass("\n".join(_sr_rename(lines, {x: y, y: x})), tgt)
        sc = score(cand)
        if sc > best_s:
            best, best_s = cand, sc
    return best if best_s > base_s else stext


# --------------------------------------------------------------------------
# licm_li: our loop head re-materializes a constant (`L: li R,K` with the back
# branches jumping to L) where retail's loop.c hoisted it into the preheader.
# Move the li above L (the preheader falls into L). Sound when every branch to L
# lies in the loop region (L .. the last branch to L), nothing else in the region
# writes R (no call either when R is caller-saved), and no label inside the
# region is a branch target from outside it. Target-guided: the target has the
# same li, and the insn after our li (the loop's first insn) does not follow it
# directly in the target. Count-preserving; sched_match then places the li.
# --------------------------------------------------------------------------
def licm_li_pass(stext, tgt):
    if not tgt:
        return stext
    tkeys = [_sm_key(d.strip(), True) for _w, d in tgt]
    lines = stext.split("\n")
    changed = False
    i = 0
    while i < len(lines):
        m = re.match(r"^\s*(\$L\w+):\s*$", lines[i])
        if not m:
            i += 1
            continue
        lab = m.group(1)
        li = _tf_next_insn(lines, i)
        if li is None or any(re.match(r"^\s*\$L\w+:", lines[y]) for y in range(i + 1, li)):
            i += 1
            continue
        body = lines[li].split("#", 1)[0].strip()
        mli = re.match(r"li\s+(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))$", body)
        if not mli or li in _noreorder_lines(lines):
            i += 1
            continue
        r = norm_reg(mli.group(1))
        refs = [y for y, l in enumerate(lines) if _s_is_insn(l) and re.search(
            r"[\s,]" + re.escape(lab) + r"\s*$", l.split("#", 1)[0])]
        if not refs or min(refs) < i:
            i += 1
            continue
        end = max(refs)
        nx = _tf_next_insn(lines, li)
        k_li = _sm_srckey(body)
        k_nx = _sm_srckey(lines[nx].split("#", 1)[0].strip()) if nx is not None else None
        ql = [q for q, k in enumerate(tkeys) if k == k_li]
        if nx is not None and (k_nx is None or _src_is_branch(lines[nx])):
            # a branch has no key (label operand): compare mnemonics
            mn = lines[nx].split(None, 1)[0].lower()
            qn = [q for q, (_w, d) in enumerate(tgt) if d.split(None, 1)[0].lower() == mn]
        else:
            qn = [q for q, k in enumerate(tkeys) if k == k_nx]
        if not ql or not qn or any(b - a == 1 for a in ql for b in qn):
            i += 1
            continue
        ok = True
        inner = set()
        for y in range(li + 1, end + 2):
            if y >= len(lines):
                break
            l = lines[y]
            ml = re.match(r"^\s*(\$L\w+):\s*$", l)
            if ml:
                inner.add(ml.group(1))
                continue
            if not _s_is_insn(l) or l.strip().startswith("."):
                continue
            b = l.split("#", 1)[0].strip()
            if re.match(r"jalr?\b", b) and (r in ("v0", "v1", "at") or re.match(r"[at]\d$", r)):
                ok = False
                break
            if r in defs_uses(_sm_dep_body(b))[0]:
                ok = False
                break
        if ok:
            for y, l in enumerate(lines):
                if (y < i or y > end + 1) and _s_is_insn(l):
                    t = re.search(r"[\s,](\$L\w+)\s*$", l.split("#", 1)[0])
                    if t and t.group(1) in inner:
                        ok = False
                        break
        if not ok:
            i += 1
            continue
        line = lines.pop(li)
        lines.insert(i, line)
        changed = True
        i = li + 1
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# web_resched: web_realloc then sched_match again, run after sched_match. A load
# the target hoists above a store can be stuck twice over: its destination is the
# register the store's base lives in (a true dependence), and the target's
# destination is only free once sched_match has moved an earlier copy out of it.
# After the first sched_match the web can take the target register, and the
# second sched_match can then hoist the load. Count-preserving.
# --------------------------------------------------------------------------
def web_resched_pass(stext, tgt):
    return sched_match_pass(web_realloc_pass(stext, tgt), tgt)


# --------------------------------------------------------------------------
# save_slot. After reg_realloc renames callee-saved registers, each one still
# lives in the stack slot its OLD number was given (cc1 lays the save area out by
# register number), so `sw $s1,0x14($sp)` can come out as `sw $s1,0x20($sp)`
# while every other insn matches. Re-lay the save area to the target's
# register -> slot map: target-guided (same saved set, same slot set), and sound
# only when those slots are touched by nothing but the saves and restores of
# their own register (checked over the whole function).
# --------------------------------------------------------------------------
_SS_RE = re.compile(r"^(\s*)(sw|lw)(\s+)(\$\w+)(\s*,\s*)(-?(?:0x[0-9a-fA-F]+|\d+))\((\$\w+)\)(.*)$")


def _ss_map(pairs):
    """{reg: offset} of callee-saved `sw reg,off($sp)` in (mnem, reg, off) list."""
    m = {}
    for mn, r, off in pairs:
        if mn == "sw" and r in _CALLEE_RS and r not in m:
            m[r] = off
    return m


def save_slot_pass(stext, tgt):
    tp = []
    for _w, d in tgt:
        mn, regs, skel = insn_parts(d)
        if mn == "sw" and len(regs) == 2 and regs[1] == "sp":
            off = _sm_int(skel[1].replace("(#)", ""))
            if off is not None:
                tp.append(("sw", regs[0], off))
    tmap = _ss_map(tp)
    lines = stext.split("\n")
    acc = []                                   # (line, mnem, reg, off)
    for i, l in enumerate(lines):
        m = _SS_RE.match(l.split("#", 1)[0])
        if m and norm_reg(m.group(7)) == "sp":
            acc.append((i, m.group(2), norm_reg(m.group(4)), int(m.group(6), 0)))
        elif _s_is_insn(l) and re.search(r"\(\$(?:sp|29)\)", l):
            mo = _mem_operand(l.split("#", 1)[0].strip())
            if mo and mo[0] == "sp":
                acc.append((i, "other", None, mo[1]))
    omap = _ss_map([(mn, r, off) for _i, mn, r, off in acc])
    if not omap or set(omap) != set(tmap) or omap == tmap \
            or sorted(omap.values()) != sorted(tmap.values()):
        return stext
    slot_reg = {off: r for r, off in omap.items()}
    for _i, mn, r, off in acc:
        if off in slot_reg and (mn == "other" or r != slot_reg[off]):
            return stext                       # slot used for something else
    for i, mn, r, off in acc:
        if off in slot_reg:
            m = _SS_RE.match(lines[i].split("#", 1)[0])
            lines[i] = "%s%s%s%s%s%d(%s)%s" % (m.group(1), m.group(2), m.group(3),
                                               m.group(4), m.group(5), tmap[r],
                                               m.group(7), m.group(8))
    return "\n".join(lines)


# --------------------------------------------------------------------------
# label_nop. aspsx_label_nops spells a load-delay nop right after a load that a
# label separates from its consumer (`lw; nop; L: use`). Usually retail has it
# there, but some retail branches land ON that nop (`lw; L: nop; use`), one
# word earlier. Target-guided: list the target's load/nop sites next to a
# branch-target label (label before or after the nop) and our `load; nop; L:`
# sites in order; when the counts agree, move each label the target has
# before its nop. Count-preserving: only which word a branch lands on changes,
# and the nop is a no-op on every path.
# --------------------------------------------------------------------------
def label_nop_pass(stext, tgt):
    m = re.search(r"^\s*\.ent\s+(\w+)", stext, re.M)
    fa = _fn_addr(m.group(1)) if m else None
    if fa is None or not tgt:
        return stext
    base = fa
    targets = set()
    for _w, d in tgt:
        mt = re.search(r"\.L([0-9A-Fa-f]{8})\s*$", d)
        if mt:
            targets.add((int(mt.group(1), 16) - base) // 4)
    flags = []
    for i in range(1, len(tgt) - 1):
        if is_nop(tgt[i][1]) and _is_load(tgt[i - 1][1]) and (i in targets or i + 1 in targets):
            flags.append(i in targets)
    if not any(flags):
        return stext
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    nr = _noreorder_lines(lines)
    sites = []
    for k in range(len(ins) - 1):
        li, ll = ins[k]
        ni, nl = ins[k + 1]
        if li in nr or ni in nr or not _is_load(ll.split("#", 1)[0].strip()):
            continue
        if not _tf_is_nop(nl.split("#", 1)[0].strip()):
            continue
        nxt = ins[k + 2][0] if k + 2 < len(ins) else len(lines)
        labs = [y for y in range(ni + 1, nxt) if re.match(r"\s*\$L\w*:", lines[y])
                and _branch_target_label(lines, ins, lines[y])]
        if labs:
            sites.append((ni, labs))
    if len(sites) != len(flags):
        return stext
    for (ni, labs), before in sorted(zip(sites, flags), key=lambda x: -x[0][0]):
        if not before:
            continue
        moved = [lines[y] for y in labs]
        for y in reversed(labs):
            del lines[y]
        lines[ni:ni] = moved
    return "\n".join(lines)

# --------------------------------------------------------------------------
# offset-unfold: our cc1 folds a constant member offset into the index before
# the base add (`addu $K,$I,K; addu $Y,$B,$K; sb $r,0($Y)`) where retail keeps
# the plain element address and carries the offset in every access
# (`addu $Y,$B,$I; sb $r,K($Y)`). Applies when the folded temp dies at the base
# add and every later access through $Y is a memory base use. One insn fewer.
# --------------------------------------------------------------------------
_ADDI_S = re.compile(r"^(\s*)addi?u\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(-?\d+|-?0x[0-9a-fA-F]+)\s*(#.*)?$")
_ADD3_S = re.compile(r"^(\s*)addu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")
_MEMB_S = re.compile(r"^(\s*)(lb|lbu|lh|lhu|lw|lwl|lwr|sb|sh|sw|swl|swr)\s+(\$\w+)\s*,\s*(-?\d+)\((\$\w+)\)\s*(#.*)?$")


def _ou_reads_after(lines, start, reg):
    """[(line, is_mem_base)] for every instruction after `start` that reads
    `reg`; None when `reg` is written after `start`."""
    out = []
    for j in range(start + 1, len(lines)):
        l = lines[j]
        if not _s_is_insn(l):
            continue
        body = l.split("#", 1)[0].strip()
        d, u = defs_uses(body)
        if reg in u:
            m = _MEMB_S.match(l)
            out.append((j, bool(m and norm_reg(m.group(5)) == reg
                                and (m.group(2) in ("lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr")
                                     or norm_reg(m.group(3)) != reg))))
        if reg in d:
            return None
    return out


def _ou_live(lines, start, reg):
    """`reg` is read by some instruction after `start` before a write of it
    (textual order; conservative for the forward-only shapes this pass takes)."""
    for j in range(start + 1, len(lines)):
        if not _s_is_insn(lines[j]):
            continue
        d, u = defs_uses(lines[j].split("#", 1)[0].strip())
        if reg in u:
            return True
        if reg in d:
            return False
    return False


def offset_unfold_pass(stext, tgt):
    lines = stext.split("\n")
    changed = True
    any_change = False
    while changed:
        changed = False
        for a, la in enumerate(lines):
            ma = _ADDI_S.match(la) if _s_is_insn(la) else None
            if not ma:
                continue
            k, i = norm_reg(ma.group(2)), norm_reg(ma.group(3))
            imm = int(ma.group(4), 0)
            if k in (None, "zero", "sp", "gp") or i in (None, "zero", "sp", "gp") or not imm:
                continue
            # the base add on the same straight line, k and i unchanged between
            b, slot = None, False
            for j in range(a + 1, len(lines)):
                l = lines[j]
                if _s_is_label(l) and not l.strip().startswith("LM"):
                    break
                if not _s_is_insn(l) or re.match(r"\s*\.", l):
                    continue
                mb = _ADD3_S.match(l)
                body = l.split("#", 1)[0].strip()
                d, u = defs_uses(body)
                if mb and k in (norm_reg(mb.group(3)), norm_reg(mb.group(4))):
                    b = j
                    break
                if slot or k in u or k in d or i in d:
                    break
                # a conditional branch's delay slot (noreorder) runs on both paths
                if _src_is_branch(l) and j in _noreorder_lines(lines) and \
                        re.match(r"\s*(beq|bne|blez|bgtz|bltz|bgez|beqz|bnez)\b", l):
                    slot = True
                    continue
                if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
                    break
            if b is None:
                continue
            mb = _ADD3_S.match(lines[b])
            y = norm_reg(mb.group(2))
            o1, o2 = norm_reg(mb.group(3)), norm_reg(mb.group(4))
            base = o2 if o1 == k else o1
            if base == k or y in (None, "zero"):
                continue
            # k dies at the base add (unless the add rewrites it)
            if y != k and _ou_live(lines, b, k):
                continue
            ry = _ou_reads_after(lines, b, y)
            if not ry or not all(mem for _j, mem in ry):
                continue
            if any(not -0x8000 <= int(_MEMB_S.match(lines[j]).group(4)) + imm < 0x8000
                   for j, _m in ry):
                continue
            for j, _m in ry:
                m = _MEMB_S.match(lines[j])
                lines[j] = "%s%s\t%s,%d(%s)%s" % (m.group(1), m.group(2), m.group(3),
                                                  int(m.group(4)) + imm, m.group(5),
                                                  (" " + m.group(6)) if m.group(6) else "")
            src_i = ma.group(3)
            lines[b] = "%saddu\t%s,%s,%s%s" % (mb.group(1), mb.group(2),
                                                mb.group(3) if o1 != k else src_i,
                                                mb.group(4) if o2 != k else src_i,
                                                (" " + mb.group(5)) if mb.group(5) else "")
            del lines[a]
            changed = any_change = True
            break
    return "\n".join(lines) if any_change else stext

# --------------------------------------------------------------------------
# slot-unfill: our reorg fills a conditional branch's delay slot with a
# constant load from before the branch where retail leaves that slot empty and
# keeps the constant at the head of the block (retail's reorg later steals it
# into the slots of the branches ENTERING that block: taken_fill /
# fallthrough_fill redo that part). Target-guided by conditional-branch
# ordinal: only a slot the target leaves as a nop. The constant moves up to
# just after the block's label when nothing in between touches its register.
# --------------------------------------------------------------------------
_SU_CONST = re.compile(r"^\s*(li|lui)\s+(\$\w+)\s*,\s*[-\w()%>< ]+\s*(#.*)?$")


def _su_shape(key):
    """An insn key with its registers masked (register names differ before
    realloc)."""
    if not isinstance(key, tuple):
        return key
    return tuple(k if i == 0 or not isinstance(k, str) else "r" for i, k in enumerate(key))


# normalize_s records whether the span it is running text passes on is a void
# function (its COFF `.def` sits before the span, out of the passes' sight)
_SPAN_INFO = {}


def _s_void(lines):
    """cc1 marks a void function `.type 0x21` in its COFF `.def`."""
    return bool(_SPAN_INFO.get("void")) or any(
        re.search(r"\.def\s+\w+;\s*\.val\s+\w+;\s*\.scl\s+2;\s*\.type\s+0x21;", l)
        for l in lines)


def _su_rehome(lines, j, s, pb, pc, tl, label, ob, tb, nr):
    """Branch j (slot s) and the branch pb before label L (slot pc) both carry a
    copy X of L's thread head, and L has no other entrant: when the target leaves
    both slots empty, X goes back to the head of L. X must be one word and not
    read what it writes; its destination must be dead where X no longer runs
    (j's fall-through, pb's taken target). The span has no COFF `.def`, so a
    return counts as reading $v0 unless X is a `lui %hi` half."""
    if pb not in ob or not tb[ob.index(pb)] or pb not in nr:
        return False
    pat = re.compile(re.escape(label) + r"(?![\w$])")
    if sum(len(pat.findall(l.split("#", 1)[0])) for x, l in enumerate(lines) if x != tl) != 1:
        return False
    body = lines[s].split("#", 1)[0].strip()
    if _ff_word_form(body) is None and not _SU_CONST.match(lines[s]):
        return False
    d, u = defs_uses(body)
    if len(d) != 1 or set(d) & set(u):
        return False
    x = next(iter(d))
    lb = re.search(r"(\$L\w+)\s*$", lines[pb].split("#", 1)[0])
    if not lb:
        return False
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    global _FF_RET_LIVE
    keep = _FF_RET_LIVE
    try:
        # a lone `lui R,%hi(S)` is an address half, never a return value
        if _s_void(lines) or re.match(r"lui\s+\$\w+\s*,\s*%hi\(", body):
            _FF_RET_LIVE = keep - {x}
        if not _zc_dead_after(lines, ins, s, x) or not _ff_dead_on(lines, ins, lb.group(1), x):
            return False
    finally:
        _FF_RET_LIVE = keep
    ind = lines[s][:len(lines[s]) - len(lines[s].lstrip())]
    xl = lines[s]
    lines[s] = ind + "nop"
    lines[pc] = ind + "nop"
    lines.insert(tl + 1, xl)
    return True


def _tgt_cond_branches(tgt, stext):
    """Indices of the target's conditional branches that pair with our source's.
    A 3-operand divide macro in our source assembles its check branches itself,
    so while our text has no explicit `break`, the target's div/rem check
    branches are left out of the pairing."""
    tb = [k for k, (_w, d) in enumerate(tgt) if d.split(None, 1)[0].lower() in _COND_BR_MN]
    if re.search(r"^\s*break\b", stext, re.M):
        return tb
    return [k for k in tb if not _tgt_div_check(tgt, k)]


def _tgt_div_check(tgt, k):
    """Target word k is a branch of an aspsx div/rem check expansion (`bnez d,L;
    nop; break 7` and the signed `bne d,$at,L` / `bne s,$at,L` overflow checks),
    which the cc1 source does not contain."""
    d = tgt[k][1].strip()
    if re.search(r"[\s,]\$?at\b", d.split(None, 1)[1] if len(d.split(None, 1)) > 1 else ""):
        return True
    return any(k + x < len(tgt) and tgt[k + x][1].split(None, 1)[0].lower() == "break"
               for x in (2,))


def slot_unfill_pass(stext, tgt):
    lines = stext.split("\n")
    tb, tfall, thead = [], [], []
    for k, (_w, d) in enumerate(tgt):
        mn = d.strip().split(None, 1)[0] if d.strip() else ""
        if mn in _COND_BR_MN and not _tgt_div_check(tgt, k):
            tb.append(is_nop(tgt[k + 1][1].strip()) if k + 1 < len(tgt) else False)
            # key of the first insn at the branch target (16-bit word offset)
            try:
                off = int(_w, 16) if isinstance(_w, str) else int(_w)
                off = (off & 0xFFFF) - ((off & 0x8000) << 1)
                ti = k + 1 + off
                thead.append(_sm_key(tgt[ti][1].strip(), True) if 0 <= ti < len(tgt) else None)
            except (TypeError, ValueError):
                thead.append(None)
            # keys of the target's straight-line fall-through after the slot
            keys = set()
            for _w2, d2 in tgt[k + 2:]:
                if is_branch(d2.strip()):
                    break
                keys.add(_su_shape(_sm_key(d2.strip(), True)))
            tfall.append(keys)
    ob = [j for j, l in enumerate(lines) if _s_is_insn(l)
          and not re.match(r"\s*\.", l) and _src_is_branch(l)
          and re.match(r"\s*(beq|bne|blez|bgtz|bltz|bgez|beqz|bnez)\b", l)]
    if len(ob) != len(tb):
        return stext
    nr = _noreorder_lines(lines)
    changed = False
    for n in range(len(ob) - 1, -1, -1):
        j = ob[n]
        if not tb[n] or j not in nr:
            continue
        s = next((x for x in range(j + 1, len(lines)) if _s_is_insn(lines[x])
                  and not re.match(r"\s*\.", lines[x])), None)
        if s is None or s not in nr:
            continue
        m = _SU_CONST.match(lines[s])
        body = lines[s].split("#", 1)[0].strip()
        d, u = defs_uses(body)
        # stolen from the taken path: our target label sits right after a copy
        # of the slot insn (possibly the delay slot of the branch before it).
        # Retail branches onto that copy and leaves its own slot empty.
        lab = re.search(r"(\$L\w+)\s*$", lines[j].split("#", 1)[0])
        tl = next((x for x, l in enumerate(lines) if lab and l.strip() == lab.group(1) + ":"), None)
        # stolen and deleted from a sole-entrant taken block whose head the
        # target keeps: X goes back to the head of that block
        if (tl is not None and thead[n] is not None and len(d) == 1
                and _ff_word_form(body) is not None
                and _sm_key(_ff_word_form(body), False) == thead[n]
                and _tf_sole_entrant(lines, lab.group(1))):
            xi = _tf_next_insn(lines, tl)
            xb = lines[xi].split("#", 1)[0].strip() if xi is not None else ""
            ins_ = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
            if xb.split() != body.split() and _zc_dead_after(lines, ins_, s, next(iter(d))):
                ind = lines[s][:len(lines[s]) - len(lines[s].lstrip())]
                xl = lines[s]
                lines[s] = ind + "nop"
                lines.insert(tl + 1, xl)
                changed = True
                continue
        if tl is not None:
            pc = next((x for x in range(tl - 1, -1, -1) if _s_is_insn(lines[x])
                       or (_s_is_label(lines[x]) and not lines[x].strip().startswith("LM"))), None)
            if (pc is not None and _s_is_insn(lines[pc]) and pc != s
                    and lines[pc].split("#", 1)[0].split() == body.split()):
                n_su = sum(1 for l in lines if l.strip().startswith("$Lsu"))
                nl_ = "$Lsu%d_%d" % (j, n_su)
                ind = lines[s][:len(lines[s]) - len(lines[s].lstrip())]
                # a copy in the delay slot of a branch with our operands and the
                # inverse sense (never taken when we arrive): retail threads
                # onto that branch
                pb = next((x for x in range(pc - 1, -1, -1) if _s_is_insn(lines[x])
                           and not re.match(r"\s*\.", lines[x])), None)
                in_slot = (pb is not None and pc in nr and _src_is_branch(lines[pb]))
                if in_slot:
                    mo = re.match(r"\s*(\w+)\s+(.*),\s*\S+\s*$", lines[j].split("#", 1)[0])
                    mp = re.match(r"\s*(\w+)\s+(.*),\s*\S+\s*$", lines[pb].split("#", 1)[0])
                    if not (mo and mp and _TF_INV.get(mo.group(1)) == mp.group(1)
                            and sorted(norm_reg(r) for r in split_ops(mo.group(2)))
                            == sorted(norm_reg(r) for r in split_ops(mp.group(2)))):
                        if _su_rehome(lines, j, s, pb, pc, tl, lab.group(1), ob, tb, nr):
                            changed = True
                        continue
                lines[s] = ind + "nop"
                lines[j] = lines[j][:lines[j].rindex(lab.group(1))] + nl_
                lines.insert(pb if in_slot else pc, nl_ + ":")
                changed = True
                continue
        if not m:
            # any other 1-word insn our reorg took from before the branch goes
            # back right before it (the branch must not read what it writes)
            bd, bu = defs_uses(lines[j].split("#", 1)[0].strip())
            if (len(d) != 1 or set(d) & set(bu) or _src_is_branch(lines[s])
                    or re.match(r"\s*(jalr?|nop)\b", lines[s]) or _ff_word_form(body) is None):
                continue
            ind = lines[s][:len(lines[s]) - len(lines[s].lstrip())]
            ins_ = lines[s]
            if _su_shape(_sm_key(body, False)) in tfall[n]:
                # retail runs it on the fall-through path: stolen from there.
                # It goes back to the head of that path (sched_match orders it)
                at = s + 1
                while at < len(lines) and lines[at].strip().startswith(".set"):
                    at += 1
                if at < len(lines) and _s_is_label(lines[at]) and \
                        not lines[at].strip().startswith("LM"):
                    continue
                lines[s] = ind + "nop"
                lines.insert(at, ins_)
                changed = True
                continue
            at = j
            while at > 0 and lines[at - 1].strip().startswith(".set"):
                at -= 1
            lines[s] = ind + "nop"
            lines.insert(at, ins_)
            changed = True
            continue
        if u or len(d) != 1:
            continue
        x = next(iter(d))
        # walk back to the block label
        head, ok = None, True
        for q in range(j - 1, -1, -1):
            l = lines[q]
            if _s_is_label(l) and not l.strip().startswith("LM"):
                head = q
                break
            if not _s_is_insn(l) or re.match(r"\s*\.", l):
                continue
            if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
                ok = False
                break
            dd, uu = defs_uses(l.split("#", 1)[0].strip())
            if x in dd or x in uu:
                ok = False
                break
        if not ok or head is None:
            continue
        ind = lines[s][:len(lines[s]) - len(lines[s].lstrip())]
        const = lines[s]
        lines[s] = ind + "nop"
        lines.insert(head + 1, const)
        changed = True
    return "\n".join(lines) if changed else stext

# --------------------------------------------------------------------------
# cross-jump: `bc X,L; nop; j L; S` where the function already has a block
# `M: j L; S` (same jump, same slot insn). Retail's jump optimizer shares that
# block: `binv X,M; nop; j L; nop`. Target-guided: the target's conditional
# branch of the same ordinal has the inverse sense of ours.
# --------------------------------------------------------------------------
def _cj_slot(lines, j):
    """(slot line, slot text) of the noreorder branch/jump at line j, or None."""
    s = next((x for x in range(j + 1, len(lines)) if _s_is_insn(lines[x])
              and not re.match(r"\s*\.", lines[x])), None)
    return s


def cross_jump_pass(stext, tgt):
    lines = stext.split("\n")
    tmn = [d.strip().split(None, 1)[0].lower() for _w, d in tgt
           if d.strip() and d.strip().split(None, 1)[0].lower() in _COND_BR_MN]
    nr = _noreorder_lines(lines)
    changed = False
    k = 0
    while True:
        ob = [j for j, l in enumerate(lines) if _s_is_insn(l) and not re.match(r"\s*\.", l)
              and re.match(r"\s*(beq|bne|blez|bgtz|bltz|bgez|beqz|bnez)\b", l)]
        if len(ob) != len(tmn) or k >= len(ob):
            break
        j = ob[k]
        k += 1
        mo = re.match(r"(\s*)(\w+)(\s+.*,\s*)(\$L\w+)\s*$", lines[j].split("#", 1)[0])
        zf = {"beqz": "beq", "bnez": "bne"}
        if not mo or zf.get(_TF_INV.get(mo.group(2)), _TF_INV.get(mo.group(2))) != zf.get(tmn[k - 1], tmn[k - 1]):
            continue
        s1 = _cj_slot(lines, j)
        if s1 is None or (j in nr and not is_nop(lines[s1].split("#", 1)[0].strip())):
            continue
        jn = s1 if j in nr else j
        jj = next((x for x in range(jn + 1, len(lines)) if _s_is_insn(lines[x])
                   and not re.match(r"\s*\.", lines[x])), None)
        if jj is None or jj not in nr:
            continue
        mj = re.match(r"\s*j\s+(\$L\w+)\s*$", lines[jj].split("#", 1)[0])
        if not mj or mj.group(1) != mo.group(4):
            continue
        s2 = _cj_slot(lines, jj)
        if s2 is None or s2 not in nr:
            continue
        slot = lines[s2].split("#", 1)[0].split()
        if not slot or slot == ["nop"]:
            continue
        # jump.c cross-jumping: the same insn S right before label L (falling
        # into L, not itself a delay slot) becomes the shared tail
        m_lab, ins_at = None, None
        lx = next((x for x, l in enumerate(lines) if l.strip() == mj.group(1) + ":"), None)
        py = next((z for z in range(lx - 1, -1, -1) if _s_is_insn(lines[z])
                   and not re.match(r"\s*\.", lines[z])), None) if lx is not None else None
        if py is not None and py != s2 and lines[py].split("#", 1)[0].split() == slot:
            pz = next((z for z in range(py - 1, -1, -1) if _s_is_insn(lines[z])
                       and not re.match(r"\s*\.", lines[z])), None)
            if not (pz is not None and py in nr and _src_is_branch(lines[pz])) and not any(
                    _s_is_label(lines[z]) and not lines[z].strip().startswith("LM")
                    for z in range(py + 1, lx)):
                h = py
                while h > 0 and (lines[h - 1].strip().startswith((".set", ".loc", "LM"))
                                 or not lines[h - 1].strip()):
                    h -= 1
                if h > 0 and _s_is_label(lines[h - 1]) and not lines[h - 1].strip().startswith("LM"):
                    m_lab = lines[h - 1].strip()[:-1]
                else:
                    m_lab, ins_at = "$Lcj%d" % py, h
        if not m_lab:
            continue
        lines[j] = mo.group(1) + _TF_INV[mo.group(2)] + mo.group(3) + m_lab
        ind = lines[s2][:len(lines[s2]) - len(lines[s2].lstrip())]
        lines[s2] = ind + "nop"
        if ins_at is not None:
            lines.insert(ins_at, m_lab + ":")
        changed = True
    return "\n".join(lines) if changed else stext

# --------------------------------------------------------------------------
# zext-keep: retail keeps a redundant zero-extend `andi R,R,0xff` (0xffff)
# of a value just loaded with lbu (lhu); our combine drops it. Target-guided by
# load ordinal: the k-th lbu/lhu of the target whose register is next read by
# such an andi gets one in ours, right before our first reader of it. The andi
# is a no-op on a zero-extended load. Count-changing (PRE_SIGMA).
# --------------------------------------------------------------------------
_ZX_LOAD = re.compile(r"^\s*(lbu|lhu)\s+(\$\w+)\s*,")


def _zx_target(tgt):
    out = []
    for k, (_w, d) in enumerate(tgt):
        p = d.strip().split(None, 1)
        if not p or p[0].lower() not in ("lbu", "lhu"):
            continue
        r = norm_reg(split_ops(p[1])[0])
        mask = 0xff if p[0].lower() == "lbu" else 0xffff
        hit = False
        for _w2, d2 in tgt[k + 1:k + 6]:
            dd, uu = defs_uses(d2.strip())
            q = d2.strip().split(None, 1)
            if q and q[0].lower() == "andi":
                ops = split_ops(q[1])
                if (len(ops) == 3 and norm_reg(ops[1]) == r and _sm_int(ops[2]) == mask):
                    # "other": the zero-extend lands in another register
                    hit = True if norm_reg(ops[0]) == r else "other"
                    break
            if r in uu or r in dd or is_branch(d2.strip()):
                break
        out.append(hit)
    return out


def zext_keep_pass(stext, tgt):
    want = _zx_target(tgt)
    if not any(want):
        return stext
    lines = stext.split("\n")
    loads = [j for j, l in enumerate(lines) if _s_is_insn(l) and _ZX_LOAD.match(l)]
    if len(loads) != len(want):
        return stext
    changed = False
    for n in range(len(loads) - 1, -1, -1):
        if not want[n]:
            continue
        j = loads[n]
        m = _ZX_LOAD.match(lines[j])
        r = norm_reg(m.group(2))
        mask = "0x00ff" if m.group(1) == "lbu" else "0xffff"
        at = None
        for x in range(j + 1, len(lines)):
            l = lines[x]
            if _s_is_label(l) and not l.strip().startswith("LM"):
                break
            if not _s_is_insn(l) or re.match(r"\s*\.", l):
                continue
            dd, uu = defs_uses(l.split("#", 1)[0].strip())
            if r in uu:
                at = x
                break
            if r in dd or _src_is_branch(l) or re.match(r"\s*jalr?\b", l):
                break
        if at is None:
            continue
        mm = re.match(r"\s*andi\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\w+)", lines[at])
        if mm and norm_reg(mm.group(1)) == r and norm_reg(mm.group(2)) == r and \
                _sm_int(mm.group(3)) == int(mask, 16):
            continue
        dst = m.group(2)
        if want[n] == "other":
            # into the reader's destination: the reader must read only R
            rd, ru = defs_uses(lines[at].split("#", 1)[0].strip())
            if len(rd) != 1 or set(ru) != {r} or next(iter(rd)) == r:
                continue
            mr = re.match(r"^(\s*\w+\s+)(\$\w+)(\s*,\s*)(\$\w+)(.*)$", lines[at])
            if not mr or norm_reg(mr.group(4)) != r:
                continue
            dst = mr.group(2)
            lines[at] = mr.group(1) + mr.group(2) + mr.group(3) + dst + mr.group(5)
        while at > j + 1 and lines[at - 1].strip() in ("#nop", ""):
            at -= 1
        ind = lines[j][:len(lines[j]) - len(lines[j].lstrip())]
        lines.insert(at, "%sandi\t%s,%s,%s" % (ind, dst, m.group(2), mask))
        changed = True
    return "\n".join(lines) if changed else stext



# --------------------------------------------------------------------------
# self_move: cc1 coalesced a value into the register of the giv/copy it seeds,
# leaving a literal `move R,R` (e.g. `lw $6,0($4); sh x,288($6); ... move $4,$16;
# move $6,$6`), where retail kept the value in T and copies it (`lw $4,0($4);
# sh x,288($4); ... move $6,$4; move $4,$16`). When the target has a `move R,T`
# and the straight-line web of R that reaches our self-move can live in T (T not
# read or written inside it apart from its defining insn, dead on every branch
# leaving it, no call), rename that web to T and hoist the move above the
# preceding insns that do not touch R or read T.
# --------------------------------------------------------------------------
_SMV_RE = re.compile(r"^(\s*)move\s+(\$\w+)\s*,\s*(\$\w+)\s*$")


def _smv_target(tgt):
    out = []
    for _w, d in tgt:
        p = d.strip().split(None, 1)
        if len(p) < 2 or p[0].lower() not in ("addu", "or", "move"):
            continue
        ops = split_ops(p[1])
        if p[0].lower() == "move" and len(ops) == 2:
            ops = ops + ["$zero"]
        if len(ops) == 3 and norm_reg(ops[2]) == "zero":
            r, t = norm_reg(ops[0]), norm_reg(ops[1])
            if r and t and r != t and t != "zero":
                out.append((r, t))
    return out


def _smv_branch_label(lines, name):
    for l in lines:
        if _s_is_insn(l) and re.search(r"(?<![\w$])%s\s*$" % re.escape(name),
                                       l.split("#", 1)[0].rstrip()):
            return True
    return False


def _smv_rename(line, r, t):
    rn, tn = _abi_to_num("$" + r), _abi_to_num("$" + t)
    body, sep, com = line.partition("#")

    def sub(m):
        return tn if norm_reg(m.group(0)) == r else m.group(0)
    return re.sub(r"\$\w+", sub, body) + sep + com


def self_move_pass(stext, tgt):
    tm = _smv_target(tgt)
    if not tm:
        return stext
    lines = stext.split("\n")
    changed = False
    for j in range(len(lines)):
        m = _SMV_RE.match(lines[j].split("#", 1)[0].rstrip())
        if not m or norm_reg(m.group(2)) != norm_reg(m.group(3)):
            continue
        R = norm_reg(m.group(2))
        # which target `move R,T`: the same ordinal among moves into R, else the only T
        ours = [x for x in range(len(lines)) if (lambda mo: mo and norm_reg(mo.group(2)) == R)(
            _SMV_RE.match(lines[x].split("#", 1)[0].rstrip()))]
        ts = [t for r, t in tm if r == R]
        if len(ts) == len(ours):
            T = ts[ours.index(j)]
        elif len(set(ts)) == 1:
            T = ts[0]
        else:
            continue
        if T == R:
            continue
        # hop back over plain insns (reorder mode) that neither touch R nor read T
        p, x = j, j - 1
        while x >= 0:
            st = lines[x].strip()
            if not st or st.startswith(".loc") or (st.endswith(":") and st.startswith("LM")):
                x -= 1
                continue
            if not _s_is_insn(lines[x]) or _src_is_branch(lines[x]) or \
                    re.match(r"\s*jalr?\b", lines[x]):
                break
            d, u = defs_uses(lines[x].split("#", 1)[0].strip())
            if R in d or R in u or T in u:
                break
            p = x
            x -= 1
        if p == j:
            continue
        # web of R reaching p: straight line back to its def
        ren, labs, dfn, x, ok = [], [], None, p - 1, True
        while x >= 0:
            l = lines[x]
            st = l.strip()
            if _s_is_label(l):
                if not st.startswith("LM") and _smv_branch_label(lines, st[:-1]):
                    ok = False
                    break
                x -= 1
                continue
            if not _s_is_insn(l):
                x -= 1
                continue
            body = l.split("#", 1)[0].strip()
            if re.match(r"\s*jalr?\b", l) or _src_is_ret(l):
                ok = False
                break
            if _src_is_branch(l):
                lab = re.search(r"(\$L\w+)\s*$", body)
                if not lab or body.split(None, 1)[0].lower() in ("j", "b"):
                    ok = False
                    break
                labs.append(lab.group(1))
            d, u = defs_uses(body)
            if R in d:
                if R in u or T in d:
                    ok = False
                    break
                dfn = x
                break
            if T in d or T in u:
                ok = False
                break
            if R in u:
                ren.append(x)
            x -= 1
        if not ok or dfn is None:
            continue
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        if not all(_ff_dead_on(lines, ins, lb, R, None, False) and _ff_dead_on(lines, ins, lb, T)
                   for lb in labs):
            continue
        dl = lines[dfn]
        body, sep, com = dl.partition("#")
        mm = re.match(r"^(\s*\w+\s+)(\$\w+)(.*)$", body)
        if not mm or norm_reg(mm.group(2)) != R:
            continue
        lines[dfn] = mm.group(1) + _abi_to_num("$" + T) + mm.group(3) + sep + com
        for x in ren:
            lines[x] = _smv_rename(lines[x], R, T)
        ind = m.group(1)
        mv = "%smove\t%s,%s" % (ind, m.group(2), _abi_to_num("$" + T))
        del lines[j]
        lines.insert(p, mv)
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# mask_reuse: combine folded a narrower mask onto the unmasked source. Retail
# `andi M,S,0xffff; ...; andi D,M,0x7e` (reads the zero-extended copy), ours
# `andi M,S,0xffff; ...; andi D,S,0x7e`. Both are S & K when K is a subset of
# the first mask. When the target has a chained andi (source = dest of an
# earlier same-block andi with a superset mask) with immediate K, point our
# same-block `andi D,S,K` at M (M and S not redefined in between, no label,
# branch or call in between). Ordinal per K; count preserving.
# --------------------------------------------------------------------------
_MR_ANDI = re.compile(r"^(\s*)andi\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\S+)\s*$")


def _mr_chains(items):
    """items: list of (kind, mn, ops, dd, uu) with kind in insn/label/branch.
    Return list of (index, K, M) for andi whose source is an earlier andi dest
    with a superset mask (M = that dest)."""
    out = []
    for i, (kind, mn, ops, dd, uu) in enumerate(items):
        if kind != "insn" or mn != "andi" or len(ops) != 3:
            continue
        k = _sm_int(ops[2])
        src = norm_reg(ops[1])
        if k is None:
            continue
        for j in range(i - 1, -1, -1):
            kj, mnj, opsj, ddj, uuj = items[j]
            if kj != "insn":
                break
            if mnj == "andi" and len(opsj) == 3 and norm_reg(opsj[0]) == src and \
                    norm_reg(opsj[1]) != src:
                kk = _sm_int(opsj[2])
                if kk is not None and (k & kk) == k and k != kk:
                    out.append((i, k, src))
                break
            if src in ddj:
                break
    return out


def _mr_items_tgt(tgt):
    items = []
    for _w, d in tgt:
        d = d.strip()
        p = d.split(None, 1)
        mn = p[0].lower() if p else ""
        ops = split_ops(p[1]) if len(p) > 1 else []
        dd, uu = defs_uses(d)
        kind = "branch" if (is_branch(d) or mn in ("jal", "jalr", "jr", "j")) else "insn"
        items.append((kind, mn, ops, dd, uu))
    return items


_MR_TEMPS = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25]


def _mr_free_reg(lines):
    body = "\n".join(l.split("#", 1)[0] for l in lines if _s_is_insn(l))
    used = set(norm_reg(t) for t in re.findall(r"\$\w+", body))
    for n in _MR_TEMPS:
        if norm_reg("$%d" % n) not in used:
            return "$%d" % n
    return None


def _mr_rename_all(line, rn, fr):
    return re.sub(r"\$\w+", lambda t: fr if norm_reg(t.group(0)) == rn else t.group(0), line)


def _mr_rename_dest(line, rn, fr):
    m = re.match(r"^(\s*\S+\s+)(\$\w+)(.*)$", line)
    if m and norm_reg(m.group(2)) == rn:
        return m.group(1) + fr + m.group(3)
    return line


def mask_reuse_pass(stext, tgt):
    want = {}
    titems = _mr_items_tgt(tgt)
    for _i, k, _m in _mr_chains(titems):
        want[k] = want.get(k, 0) + 1
    if not want:
        return stext
    lines = stext.split("\n")
    changed = False
    for x in range(len(lines)):
        m = _MR_ANDI.match(lines[x])
        if not m:
            continue
        k = _sm_int(m.group(4))
        if k is None or not want.get(k):
            continue
        d, sreg = m.group(2), m.group(3)
        sn = norm_reg(sreg)
        hit = None
        for y in range(x - 1, -1, -1):
            l = lines[y]
            if _s_is_label(l) and not l.strip().startswith("LM"):
                break
            if not _s_is_insn(l) or re.match(r"\s*\.", l):
                continue
            body = l.split("#", 1)[0].strip()
            if _src_is_branch(l) or re.match(r"\s*j(al)?r?\b", l):
                break
            mm = _MR_ANDI.match(l)
            if mm and norm_reg(mm.group(3)) == sn and norm_reg(mm.group(2)) != sn:
                kk = _sm_int(mm.group(4))
                if kk is not None and (k & kk) == k and k != kk:
                    hit = (y, mm.group(2))
                break
            dd, _uu = defs_uses(body)
            if sn in dd:
                break
        if hit is None:
            continue
        y, mreg = hit
        mn = norm_reg(mreg)
        wz = None
        for z in range(y + 1, x):
            l = lines[z]
            if not _s_is_insn(l) or re.match(r"\s*\.", l):
                continue
            dd, _uu = defs_uses(l.split("#", 1)[0].strip())
            if sn in dd:
                wz = -1
                break
            if mn in dd and wz is None:
                wz = z
        if wz == -1:
            continue
        if wz is not None:
            # case B: M is overwritten at wz before x. Only when x itself
            # redefines M (D == M): rename M in [wz, x) (wz: dest only) to a
            # register the function never mentions, so M keeps S & K2 up to x.
            if norm_reg(d) != mn:
                continue
            fr = _mr_free_reg(lines)
            if fr is None:
                continue
            for z in range(wz, x):
                l = lines[z]
                if not _s_is_insn(l) or re.match(r"\s*\.", l):
                    continue
                if z == wz:
                    lines[z] = _mr_rename_dest(l, mn, fr)
                else:
                    lines[z] = _mr_rename_all(l, mn, fr)
        lines[x] = "%sandi\t%s,%s,%s" % (m.group(1), d, mreg, m.group(4))
        want[k] -= 1
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# zero_cmp: cse put a register known to hold zero on this path (a switch
# register reached through `beq R,$0,L`) into a compare against zero, so retail
# tests `slt v0,s6,v0; beqz v0,L` where our cc1 folds the constant and emits
# `blez v0,L`. When the target has such `slt X,Z,R; beqz/bnez X` pairs (Z not
# $zero, X == R) and ours has fewer, rewrite our blez/bgtz/bltz/bgez R,L into
# the slt + beqz/bnez form, using the one register proven zero at the branch
# (every entrant of the join label is a `beq Z,$0` / `beqz Z` edge or a
# fall-through that is itself zero) and only when R is dead after the branch
# on both paths. The slt goes before the noreorder block so gas keeps the
# load-delay nop. Count-changing: runs before sigma.
# --------------------------------------------------------------------------
_ZC_FORM = {"blez": ("hi", "beqz"), "bgtz": ("hi", "bnez"),
            "bltz": ("lo", "bnez"), "bgez": ("lo", "beqz")}
_ZC_BR = re.compile(r"^(\s*)(blez|bgtz|bltz|bgez)\s+(\$\w+)\s*,\s*(\$L\w+)\s*$")


def _zc_target_count(tgt):
    n = 0
    for k in range(len(tgt) - 1):
        p = tgt[k][1].strip().split(None, 1)
        q = tgt[k + 1][1].strip().split(None, 1)
        if len(p) < 2 or len(q) < 2 or p[0].lower() != "slt" or q[0].lower() not in ("beqz", "bnez"):
            continue
        ops = [norm_reg(x) for x in split_ops(p[1])]
        qo = [norm_reg(x) for x in split_ops(q[1])]
        if len(ops) == 3 and ops[0] == qo[0] and "zero" not in ops[1:] and ops[0] in ops[1:]:
            n += 1
    return n


def _zc_our_count(lines):
    ins = [l.split("#", 1)[0].strip() for l in lines if _s_is_insn(l) and not l.strip().startswith(".")]
    n = 0
    for k in range(len(ins) - 1):
        m = re.match(r"slt\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)$", ins[k])
        q = re.match(r"(beq|bne)z?\s+(\$\w+)", ins[k + 1])
        if m and q and norm_reg(m.group(1)) == norm_reg(q.group(2)) and \
                "zero" not in (norm_reg(m.group(2)), norm_reg(m.group(3))):
            n += 1
    return n


def _zc_zero_at(lines, li, reg, depth=0):
    """reg holds zero at line li: walk back; a def kills (unless `move reg,$0`/li 0);
    at a branch-target label every entrant must be a `beq reg,$0` edge (or beqz)
    or a zero path; a fall-through into the label must be zero too unless the
    line before is an unconditional `j` (reorder mode)."""
    if depth > 4:
        return False
    for x in range(li - 1, -1, -1):
        l = lines[x]
        t = l.strip()
        if _s_is_label(l) and t.startswith("$L"):
            lab = t[:-1]
            pat = re.compile(r"[\s,]" + re.escape(lab) + r"\s*$")
            for y, bl in enumerate(lines):
                if y == x or not _s_is_insn(bl) or not pat.search(bl.split("#", 1)[0]):
                    continue
                b = bl.split("#", 1)[0].strip()
                mm = re.match(r"beq\s+(\$\w+)\s*,\s*(\$\w+)\s*,", b)
                mz = re.match(r"beqz\s+(\$\w+)\s*,", b)
                if mm and ({norm_reg(mm.group(1)), norm_reg(mm.group(2))} == {reg, "zero"}):
                    pass
                elif mz and norm_reg(mz.group(1)) == reg:
                    pass
                elif not _zc_zero_at(lines, y, reg, depth + 1):
                    return False
                # the entrant's delay slot must not write reg
                for z in range(y + 1, min(len(lines), y + 4)):
                    if _s_is_insn(lines[z]) and not lines[z].strip().startswith("."):
                        if reg in defs_uses(lines[z].split("#", 1)[0].strip())[0]:
                            return False
                        break
            # fall-through into the label
            for z in range(x - 1, -1, -1):
                pz = lines[z]
                if _s_is_insn(pz) and not pz.strip().startswith("."):
                    if re.match(r"\s*(j|b)\s+\$L", pz):
                        return True
                    break
                if _s_is_label(pz) and pz.strip().startswith("$L"):
                    break
            continue
        if not _s_is_insn(l) or t.startswith("."):
            continue
        body = l.split("#", 1)[0].strip()
        if re.match(r"jalr?\b", body):
            if reg in _CALL_CLOBBER:
                return False
            continue
        if _src_is_branch(l) or _src_is_ret(l):
            return False
        d, _u = defs_uses(body)
        if reg in d:
            z = re.match(r"(?:move\s+\$\w+\s*,\s*\$0|li\s+\$\w+\s*,\s*0)\s*$", body)
            return bool(z)
    return False


def _zc_dead_after(lines, ins, slot_line, reg):
    """reg dead on the fall-through path after slot_line (index into lines)."""
    for x in range(slot_line + 1, len(lines)):
        l = lines[x]
        if not _s_is_insn(l) or l.strip().startswith("."):
            continue
        body = l.split("#", 1)[0].strip()
        if re.match(r"jalr?\b", body):
            return reg in _CALL_CLOBBER and reg not in ("a0", "a1", "a2", "a3")
        d, u = defs_uses(body)
        if reg in u:
            return False
        if _src_is_ret(l):
            return reg not in _FF_RET_LIVE
        if _src_is_branch(l):
            # a noreorder slot runs before the transfer on both paths
            if x in _noreorder_lines(lines):
                sl = _tf_next_insn(lines, x)
                if sl is not None:
                    sd, su = defs_uses(lines[sl].split("#", 1)[0].strip())
                    if reg in su:
                        return False
                    if reg in sd:
                        return True
            lab = re.search(r"(\$L\w+)\s*$", body)
            if not lab or not _ff_dead_on(lines, ins, lab.group(1), reg):
                return False
            if body.split(None, 1)[0].lower() in ("j", "b"):
                return True
            continue
        if reg in d:
            return True
    return False


def zero_cmp_pass(stext, tgt):
    lines = stext.split("\n")
    if _zc_target_count(tgt) <= 0:
        return stext
    # per mnemonic: our blez/bgtz/bltz/bgez surplus over the target's
    tb = {}
    for _w, d in tgt:
        mn = d.strip().split(None, 1)[0].lower() if d.strip() else ""
        if mn in _ZC_FORM:
            tb[mn] = tb.get(mn, 0) - 1
    for l in lines:
        m = _ZC_BR.match(l.split("#", 1)[0].rstrip())
        if m:
            tb[m.group(2)] = tb.get(m.group(2), 0) + 1
    budget = sum(v for v in tb.values() if v > 0)
    if budget <= 0:
        return stext
    regs = sorted(set(norm_reg(t) for l in lines if _s_is_insn(l)
                      for t in re.findall(r"\$\d+\b", l.split("#", 1)[0])) - {"zero"})
    x = 0
    changed = False
    while x < len(lines) and budget > 0:
        m = _ZC_BR.match(lines[x].split("#", 1)[0].rstrip())
        if not m:
            x += 1
            continue
        ind, br, r, lab = m.groups()
        if tb.get(br, 0) <= 0:
            x += 1
            continue
        rn = norm_reg(r)
        cands = [z for z in regs if z != rn and _zc_zero_at(lines, x, z)]
        if len(cands) != 1:
            x += 1
            continue
        zr = cands[0]
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        slot = None
        nr = _noreorder_lines(lines)
        if x in nr:
            for y in range(x + 1, len(lines)):
                if _s_is_insn(lines[y]) and not lines[y].strip().startswith("."):
                    slot = y
                    break
            if slot is None:
                x += 1
                continue
            sd, su = defs_uses(lines[slot].split("#", 1)[0].strip())
            if rn in sd or rn in su:
                x += 1
                continue
        after = slot if slot is not None else x
        if not _ff_dead_on(lines, ins, lab, rn) or not _zc_dead_after(lines, ins, after, rn):
            x += 1
            continue
        side, nbr = _ZC_FORM[br]
        ztok = next(t for t in re.findall(r"\$\d+\b", "\n".join(lines)) if norm_reg(t) == zr)
        slt = "%sslt\t%s,%s,%s" % (ind, r, ztok, r) if side == "hi" else \
            "%sslt\t%s,%s,%s" % (ind, r, r, ztok)
        lines[x] = "%s%s\t%s,%s" % (ind, nbr, r, lab)
        at = x
        if x in nr:
            while at > 0 and lines[at - 1].strip().startswith(".set"):
                at -= 1
        lines.insert(at, slt)
        x += 2
        budget -= 1
        tb[br] -= 1
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# redundant_skip: reorg (fill_slots_from_thread / redundant_insn) skips a
# target-thread insn that is redundant on the branch path and redirects the
# branch past it: retail `lw v1,36(s4); beqz v1,L+4` where L is `lw v1,36(s4)`
# again. Ours branches to L. When the target has such branches (the insn
# before the branch target equals a load reaching the branch with no def of its
# registers, store or call in between) and ours has fewer, retarget our
# matching branches to a new label after the redundant load. Count preserving.
# --------------------------------------------------------------------------
_RS_BR = re.compile(r"^(\s*)(beq|bne|beqz|bnez|blez|bgtz|bltz|bgez)\s+(.*?)(\$L\w+)\s*$")
_RS_LD = re.compile(r"^(lw|lh|lhu|lb|lbu)\s+(\$\w+)\s*,\s*(-?\w+)\((\$\w+)\)$")
_RS_ST = re.compile(r"^(sw|sh|sb|swl|swr)\b")


def _rs_canon(body):
    return re.sub(r"\s+", " ", body.replace(", ", ",")).strip()


def _rs_reaches(seq, ld):
    """seq: insn bodies (oldest first) on the straight line up to and including
    the branch (and its slot); ld: the load body. True when an identical load
    is in seq with no def of its dest/base, store or call after it."""
    m = _RS_LD.match(ld)
    if not m:
        return False
    rd, rb = norm_reg(m.group(2)), norm_reg(m.group(4))
    for k in range(len(seq) - 1, -1, -1):
        b = seq[k]
        if _rs_canon(b) == _rs_canon(ld) and k < len(seq):
            return True
        if _RS_ST.match(b) or re.match(r"jalr?\b", b):
            return False
        d, _u = defs_uses(b)
        if rd in d or rb in d:
            return False
    return False


def _rs_target_count(tgt):
    dis = [d.strip() for _w, d in tgt]
    words_pc = {}
    n = 0
    for k, d in enumerate(dis):
        p = d.split(None, 1)
        if not p or p[0].lower() not in ("beq", "bne", "beqz", "bnez", "blez", "bgtz", "bltz", "bgez"):
            continue
        w = int(tgt[k][0], 16)
        off = w & 0xFFFF
        off = off - 0x10000 if off & 0x8000 else off
        t = k + 1 + off
        if t < 1 or t > len(dis):
            continue
        prev = dis[t - 1]
        pm = prev.split(None, 1)
        if not pm or pm[0].lower() not in ("lw", "lh", "lhu", "lb", "lbu"):
            continue
        ld = "%s %s" % (pm[0].lower(), ",".join(x.strip() for x in split_ops(pm[1])))
        seq = []
        for q in range(max(0, k - 12), k + 2):
            if q < len(dis) and dis[q].split(None, 1)[0].lower() != "nop":
                qp = dis[q].split(None, 1)
                seq.append("%s %s" % (qp[0].lower(), ",".join(x.strip() for x in split_ops(qp[1])) if len(qp) > 1 else ""))
        if t - 1 != k + 1 and _rs_reaches(seq, ld):
            n += 1
    return n


def redundant_skip_pass(stext, tgt):
    want = _rs_target_count(tgt)
    if want <= 0:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    labidx = {l.strip()[:-1]: i for i, l in enumerate(lines) if _s_is_label(l) and l.strip().startswith("$L")}
    changed = False
    nlab = 0
    for x in range(len(lines)):
        if want <= 0:
            break
        m = _RS_BR.match(lines[x].split("#", 1)[0].rstrip())
        if not m:
            continue
        lab = m.group(4)
        if lab not in labidx:
            continue
        # straight-line insns before the branch (stop at a real label), plus the slot
        seq = []
        for y in range(x - 1, -1, -1):
            l = lines[y]
            if _s_is_label(l) and l.strip().startswith("$L"):
                break
            if _s_is_insn(l) and not l.strip().startswith("."):
                b = l.split("#", 1)[0].strip()
                if _src_is_branch(l) or _src_is_ret(l):
                    break
                seq.insert(0, b)
        seq.append(lines[x].split("#", 1)[0].strip())
        if x in nr:
            for y in range(x + 1, len(lines)):
                if _s_is_insn(lines[y]) and not lines[y].strip().startswith("."):
                    seq.append(lines[y].split("#", 1)[0].strip())
                    break
        seq = [_rs_canon(b) for b in seq[:-1] if b] + [_rs_canon(seq[-1])] if seq else []
        # first insn of the target thread
        li = labidx[lab]
        fi = None
        for y in range(li + 1, len(lines)):
            l = lines[y]
            if _s_is_insn(l) and not l.strip().startswith("."):
                fi = y
                break
        if fi is None or fi in nr:
            continue
        ld = _rs_canon(lines[fi].split("#", 1)[0].strip())
        if not _RS_LD.match(ld.replace(", ", ",")):
            continue
        if not _rs_reaches([b for b in seq if not b.startswith(("beq", "bne", "blez", "bgtz", "bltz", "bgez"))], ld):
            continue
        new = "$Lgcce_rs%d" % nlab
        nlab += 1
        lines.insert(fi + 1, new + ":")
        labidx = {l.strip()[:-1]: i for i, l in enumerate(lines) if _s_is_label(l) and l.strip().startswith("$L")}
        nr = _noreorder_lines(lines)
        lines[x] = lines[x].replace(lab, new)
        want -= 1
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# param_copy: retail copies an incoming argument into another argument
# register at entry (`addiu sp,-40; move a1,a0; ...`, then uses a1 as the
# parameter) where our cc1 keeps using a0. When the target prologue (first 8
# insns) has `move Rn,Ak` (Rn a caller-saved/arg reg, not an s-reg) and ours has
# none, rename our entry web of Ak (every explicit read reached only by the
# incoming value; no implicit read such as a call argument or return) to Rn and
# insert `move Rn,Ak` after the stack adjust. Rn must not be live or defined
# anywhere that web is live, and Rn's own incoming value must be unused.
# Count-changing: runs before sigma.
# --------------------------------------------------------------------------
_PC_ARGS = ("a0", "a1", "a2", "a3")


def _pc_targets(tgt):
    out = []
    for _w, d in tgt[:8]:
        p = d.strip().split(None, 1)
        if len(p) < 2:
            continue
        mn = p[0].lower()
        ops = [norm_reg(x) for x in split_ops(p[1])]
        if mn == "move" and len(ops) == 2:
            ops = ops + ["zero"]
        if mn in ("addu", "or", "move") and len(ops) == 3 and ops[2] == "zero" and \
                ops[1] in _PC_ARGS and ops[0] and ops[0] != ops[1] and \
                ops[0] in ("v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3",
                           "t4", "t5", "t6", "t7", "t8", "t9") and \
                all(ops[0] != x and ops[1] != y for x, y in out):
            out.append((ops[0], ops[1]))
    return out


def _pc_edit(lines, nodes, occ_list, newreg):
    edits = {}
    for n, pos, reg in occ_list:
        edits.setdefault(nodes[n]["line"], {})[pos] = newreg(reg)
    for li, poss in edits.items():
        ind, mn, ops, com, rp = _wr_parse(lines[li])
        ops = list(ops)
        for pos, nr_ in poss.items():
            k, par_, _r = rp[pos]
            num = "$%d" % ABI2NUM[nr_]
            if par_:
                ops[k] = re.sub(r"\(\$\w+\)$", "(%s)" % num, ops[k])
            else:
                ops[k] = num
        body = lines[li].split("#", 1)[0].strip().split(None, 1)[0]
        lines[li] = "%s%s\t%s%s" % (ind, body, ",".join(ops), ("\t#" + com) if com else "")


def _pc_one(lines, rn, ak):
    """Rename Ak's entry web to Rn (rename mode) or swap Ak<->Rn everywhere (swap
    mode, when Rn is busy). Returns True when lines were changed."""
    nodes, ok = _wr_nodes(lines)
    if not ok:
        return False
    occ, pinned, reg_of, LO, def_w = _wr_webs(nodes)
    ent = {}
    for (n, r, pos, kd), w in occ.items():
        if n == 0 and kd == "d":
            ent[r] = w
    aw, rw = ent.get(ak), ent.get(rn)
    if aw is None:
        return False
    uses = [(n, pos) for (n, r, pos, kd), w in occ.items() if w == aw and kd == "u"]
    if not uses or any(pos is None for _n, pos in uses):
        return False
    # Rn's incoming value must be unused (implicit reads by calls are the
    # callee-asm arity over-approximation, not real uses)
    if rw is not None and any(w == rw and kd == "u" and pos is not None
                              for (n, r, pos, kd), w in occ.items()):
        return False
    odefs = [(n, pos) for (n, r, pos, kd), w in occ.items() if w == aw and kd == "d" and n != 0]
    if any(pos is None for _n, pos in odefs):
        return False
    rwebs = set(w for (n, r, pos, kd), w in occ.items() if r == rn and w != rw)
    busy = False
    for n in range(len(nodes)):
        if aw in LO[n] and (rwebs & LO[n] or rwebs & def_w[n]):
            busy = True
            break
    if not busy:
        _pc_edit(lines, nodes, [(n, pos, None) for n, pos in uses + odefs], lambda _r: rn)
        return True
    # swap mode: every explicit Ak/Rn occurrence changes register; no web of
    # either register may have an implicit occurrence besides the entry defs
    for (n, r, pos, kd), w in occ.items():
        if r in (ak, rn) and pos is None and not (n == 0 and kd == "d"):
            if kd == "u" and w == rw:
                continue            # arity over-approximation read of Rn's garbage
            return False
    ol = [(n, pos, r) for (n, r, pos, kd), w in occ.items() if r in (ak, rn) and pos is not None]
    _pc_edit(lines, nodes, ol, lambda r: rn if r == ak else ak)
    return True


def _pc_forward(lines, mv, ak):
    """lines[mv] is `move Y,Ak` at the entry: every other explicit read of Ak's
    entry value that only the move's Y def reaches reads Y instead (retail uses
    the copy everywhere, freeing Ak)."""
    body = lines[mv].split("#", 1)[0].strip()
    m = re.match(r"(?:move\s+(\$\w+)\s*,|addu\s+(\$\w+)\s*,)", body)
    if not m:
        return
    yr = norm_reg(m.group(1) or m.group(2))
    nodes, ok = _wr_nodes(lines)
    if not ok:
        return
    occ, pinned, reg_of, LO, def_w = _wr_webs(nodes)
    aw = next((w for (n, r, pos, kd), w in occ.items() if n == 0 and kd == "d" and r == ak), None)
    mvn = next((n for n, nd in enumerate(nodes) if nd["line"] == mv), None)
    if aw is None or mvn is None:
        return
    # reaching defs of Y (forward dataflow over node ids)
    gen = {n: n for n, nd in enumerate(nodes) if any(r == yr for r, _p in nd["defs"])}
    pred = [[] for _ in nodes]
    for n, nd in enumerate(nodes):
        for sx in nd["succ"]:
            pred[sx].append(n)
    IN = [set() for _ in nodes]
    OUT = [set() for _ in nodes]
    ch = True
    while ch:
        ch = False
        for n in range(len(nodes)):
            i_ = set()
            for p_ in pred[n]:
                i_ |= OUT[p_]
            o_ = {gen[n]} if n in gen else set(i_)
            if i_ != IN[n] or o_ != OUT[n]:
                IN[n], OUT[n] = i_, o_
                ch = True
    ol = []
    for (n, r, pos, kd), w in occ.items():
        if w == aw and kd == "u" and n != mvn:
            if pos is None or IN[n] != {mvn}:
                continue
            ol.append((n, pos, r))
    if ol:
        _pc_edit(lines, nodes, ol, lambda _r: yr)


def param_copy_pass(stext, tgt):
    tps = _pc_targets(tgt)
    if _PC_FRESH[0]:
        tps = [(_PC_FRESH[0], ak) for _rn, ak in tps]
    if not tps:
        return stext
    lines = stext.split("\n")
    ins = [i for i, l in enumerate(lines) if _s_is_insn(l) and not l.strip().startswith(".")]
    if not ins:
        return stext
    for i in ins[:8]:
        b = lines[i].split("#", 1)[0].strip()
        m = re.match(r"move\s+(\$\w+)\s*,\s*(\$\w+)$", b)
        if m and (norm_reg(m.group(1)), norm_reg(m.group(2))) in tps:
            return stext
    at = ins[0]
    for i in ins[:3]:
        if re.match(r"\s*(subu|addu|addiu)\s+\$(sp|29)\s*,\s*\$(sp|29)\s*,", lines[i]):
            at = i + 1
            break
    changed = False
    for rn, ak in tps:
        # ours already copies Ak, later on the entry straight line: hoist that
        # copy to the entry (web_realloc names it afterwards)
        hi = None
        seen = set()
        for y in range(at, len(lines)):
            l = lines[y]
            if _s_is_label(l) and not l.strip().startswith("LM"):
                break
            if not _s_is_insn(l) or l.strip().startswith("."):
                continue
            body = l.split("#", 1)[0].strip()
            if _src_is_branch(l) or _src_is_ret(l) or re.match(r"jalr?\b", body):
                break
            m = re.match(r"(?:move\s+(\$\w+)\s*,\s*(\$\w+)|addu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*\$(?:0|zero))$", body)
            d, u = defs_uses(body)
            if m:
                yr = norm_reg(m.group(1) or m.group(3))
                sr = norm_reg(m.group(2) or m.group(4))
                if sr == ak and yr not in seen and ak not in seen:
                    hi = y
                    break
            seen |= set(d) | set(u) - {ak}
            if ak in d:
                break
        if hi is not None:
            ln = lines.pop(hi)
            lines.insert(at, ln)
            _pc_forward(lines, at, ak)
            at += 1
            changed = True
            continue
        if not _pc_one(lines, rn, ak):
            break
        ref = lines[at] if at < len(lines) and _s_is_insn(lines[at]) else lines[ins[0]]
        ind = ref[:len(ref) - len(ref.lstrip())]
        lines.insert(at, "%smove\t$%d,$%d" % (ind, ABI2NUM[rn], ABI2NUM[ak]))
        at += 1
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# selfmove_nop: a register rename (web_realloc) can leave a literal
# `move R,R` (e.g. the return value copy in a jr slot once the value's web got
# the return register). It does nothing; retail has a nop there. When the
# target has no self-move, turn ours into `nop` (count preserving).
# --------------------------------------------------------------------------
_SMN_RE = re.compile(r"^(\s*)(?:move\s+(\$\w+)\s*,\s*(\$\w+)|addu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*\$(?:0|zero))\s*$")


def selfmove_nop_pass(stext, tgt):
    for _w, d in tgt:
        p = d.strip().split(None, 1)
        if len(p) > 1 and p[0].lower() in ("addu", "or", "move"):
            ops = [norm_reg(x) for x in split_ops(p[1])]
            if len(ops) >= 2 and ops[0] == ops[1] and (len(ops) == 2 or ops[2] == "zero"):
                return stext
    lines = stext.split("\n")
    changed = False
    for x, l in enumerate(lines):
        m = _SMN_RE.match(l.split("#", 1)[0].rstrip())
        if not m:
            continue
        a, b = (m.group(2), m.group(3)) if m.group(2) else (m.group(4), m.group(5))
        if norm_reg(a) == norm_reg(b):
            lines[x] = m.group(1) + "nop"
            changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# slot_swap: our reorg filled a conditional branch slot from the fall-through
# (`P; bc L; S` with S stolen from the fall-through) where retail put the insn
# before the branch into the slot and left S at the fall-through head
# (`bc L; P; S`). Target-guided per conditional branch (same count): the
# target slot is P's word form and the insn after it is S's. P must not write
# a register the branch reads; S's destination must be dead at L (it no longer
# runs on the taken path). Count preserving.
# --------------------------------------------------------------------------
def slot_swap_pass(stext, tgt):
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    if len(_tf_branches(lines)) != len(tb):
        return stext
    changed = False
    for k in range(len(tb)):
        ours = _tf_branches(lines)
        if len(ours) != len(tb):
            break
        bi, nr = ours[k]
        tk = tb[k]
        if not nr or tk + 2 >= len(tgt):
            continue
        si = _tf_next_insn(lines, bi)
        if si is None:
            continue
        # P: the insn right before the branch, same block (no label between)
        pi = None
        for y in range(bi - 1, -1, -1):
            l = lines[y]
            if _s_is_label(l) and not l.strip().startswith("LM"):
                break
            if _s_is_insn(l):
                pi = y
                break
        if pi is None:
            continue
        pb = lines[pi].split("#", 1)[0].strip()
        sb = lines[si].split("#", 1)[0].strip()
        if not pb or not sb or _tf_is_nop(pb) or _tf_is_nop(sb):
            continue
        if _src_is_branch(lines[pi]) or re.match(r"\s*jalr?\b", lines[pi]):
            continue
        fp, fs = _ff_word_form(pb), _ff_word_form(sb)
        if fp is None and re.match(r"(sb|sh|sw|lb|lbu|lh|lhu|lw)\s", pb) and \
                _src_nwords(pb) == 1 and not _sym_operand("\t" + pb):
            fp = pb             # a 1-word store/load may sit in the slot too
        if fp is None or fs is None:
            continue
        if _sm_key(tgt[tk + 1][1].strip(), True) != _sm_key(fp, False):
            continue
        if _sm_key(tgt[tk + 2][1].strip(), True) != _sm_key(fs, False):
            continue
        bd, bu = defs_uses(lines[bi].split("#", 1)[0].strip())
        pd, pu = defs_uses(fp)
        if set(pd) & set(bu):
            continue
        sd, su = defs_uses(fs)
        if len(sd) != 1:
            continue
        lab = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        if not lab or not _ff_dead_on(lines, ins, lab.group(1), next(iter(sd))):
            continue
        # S must not read what P writes out of order (P still runs first) and
        # must not be read by the branch (it ran before the transfer only as slot)
        ind = _src_indent(lines[si])
        new = list(lines)
        new[si] = ind + fp
        # S goes to the fall-through head: after the end of the noreorder group
        at = si + 1
        while at < len(new) and new[at].strip().startswith(".set"):
            at += 1
        new.insert(at, ind + fs)
        del new[pi]
        lines = new
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# slot_retake: both reorgs fill a conditional branch slot from the taken
# thread, but pick a different insn because the block order differs: ours
# `beq v0,$0,L; X` (X was the thread head, L now after it), retail takes a
# later thread insn Y. Put X back at the thread head (L must have no other
# entrant), move Y (pure ALU, independent of the thread insns it passes) into
# the slot. X and Y dests must be dead on the fall-through (X no longer runs
# there, Y now does). sched_match then orders the block. Count preserving.
# --------------------------------------------------------------------------
def slot_retake_pass(stext, tgt):
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    if len(_tf_branches(lines)) != len(tb):
        return stext
    changed = False
    for k in range(len(tb)):
        ours = _tf_branches(lines)
        if len(ours) != len(tb):
            break
        bi, nr = ours[k]
        tk = tb[k]
        if not nr or tk + 1 >= len(tgt):
            continue
        si = _tf_next_insn(lines, bi)
        if si is None:
            continue
        xb = lines[si].split("#", 1)[0].strip()
        fx = _ff_word_form(xb)
        tkey = _sm_key(tgt[tk + 1][1].strip(), True)
        if fx is None or _sm_key(fx, False) == tkey or tkey in (("nop",), ("sll", "zero", "zero", 0)):
            continue
        lab = re.search(r"(\$L\w+)\s*$", lines[bi].split("#", 1)[0])
        if not lab:
            continue
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        if not _tf_sole_entrant(lines, lab.group(1)):
            continue
        at = next((y for y, l in enumerate(lines) if l.strip() == lab.group(1) + ":"), None)
        if at is None:
            continue
        # scan the thread's straight line for Y
        passed, yi = [], None
        for y in range(at + 1, len(lines)):
            l = lines[y]
            if _s_is_label(l) and not l.strip().startswith("LM"):
                break
            if not _s_is_insn(l) or l.strip().startswith("."):
                continue
            if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
                break
            b = l.split("#", 1)[0].strip()
            fy = _ff_word_form(b)
            if fy is not None and _sm_key(fy, False) == tkey:
                yi = y
                break
            passed.append(b)
            if len(passed) > 6:
                break
        if yi is None:
            continue
        fy = _ff_word_form(lines[yi].split("#", 1)[0].strip())
        yd, yu = defs_uses(fy)
        xd, xu = defs_uses(fx)
        if set(yd) & (set(xd) | set(xu)) or set(xd) & set(yu):
            continue
        ok = True
        for b in passed:
            d, u = defs_uses(b)
            if set(yd) & (set(d) | set(u)) or set(yu) & set(d):
                ok = False
                break
        if not ok:
            continue
        if not all(_zc_dead_after(lines, ins, si, r) for r in set(yd) | set(xd)):
            continue
        ind = _src_indent(lines[si])
        new = list(lines)
        del new[yi]
        new[si] = ind + fy
        new.insert(at + 1, ind + fx)
        lines = new
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# undo_drop: reorg fills a conditional branch slot with `addu R,R,k` taken from
# the branch target and, when it thinks R is live on the fall-through, puts
# `addu R,R,-k` right after the slot. Retail's reorg leaves the undo out where R
# is dead (the count of a timeout loop, dead after the loop).
# Drop an undo whose register is dead after it, only while our undo count
# exceeds the target's. Count-changing, so it runs before sigma.
# --------------------------------------------------------------------------
_UD_ADD = re.compile(r"\s*(?:addu|addiu)\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*$")


def _ud_undo_count(tgt):
    n = 0
    for _w, d in tgt:
        m = _UD_ADD.match(d)
        if m and norm_reg(m.group(1)) == norm_reg(m.group(2)) != "sp" and int(m.group(3), 0) < 0:
            n += 1
    return n


def undo_drop_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ours = []
    for x, l in enumerate(lines):
        m = _UD_ADD.match(l.split("#", 1)[0])
        if not m or x in nr or norm_reg(m.group(1)) != norm_reg(m.group(2)):
            continue
        k = int(m.group(3), 0)
        if k >= 0:
            continue
        ins = [y for y in range(x) if _s_is_insn(lines[y]) and not lines[y].strip().startswith(".")]
        if len(ins) < 2:
            continue
        sl, br = ins[-1], ins[-2]
        if sl not in nr or br not in nr or not _COND_S.match(_s_mnem(lines[br])):
            continue
        if any(_s_is_label(lines[y]) for y in range(sl + 1, x)):
            continue
        ms = _UD_ADD.match(lines[sl].split("#", 1)[0])
        if not ms or norm_reg(ms.group(1)) != norm_reg(m.group(1)) \
                or norm_reg(ms.group(2)) != norm_reg(m.group(1)) or int(ms.group(3), 0) != -k:
            continue
        ours.append(x)
    extra = len(ours) - _ud_undo_count(tgt)
    if extra <= 0:
        return stext
    drop = []
    for x in ours:
        reg = norm_reg(_UD_ADD.match(lines[x].split("#", 1)[0]).group(1))
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        if _zc_dead_after(lines, ins, x, reg):
            drop.append(x)
    if not drop:
        return stext
    for x in sorted(drop[:extra], reverse=True):
        del lines[x]
    return "\n".join(lines)


# --------------------------------------------------------------------------
# copy_swap: `move A,$0` ... `move B,A` (straight line, neither A nor B read or
# written in between) holds the same values afterwards as `move B,$0` ...
# `move A,B`; retail's cse kept the constant in the other register
# (s0 = n = 0 and a1 = n for a call argument). Target-guided: fires when
# the target has both swapped insns and fewer of our pair.
# --------------------------------------------------------------------------
_CS_ZERO = re.compile(r"^(\s*)(?:move\s+(\$\w+)\s*,\s*\$(?:0|zero)|li\s+(\$\w+)\s*,\s*0)\s*(?:#.*)?$")


def copy_swap_pass(stext, tgt):
    if not tgt:
        return stext
    tk = collections.Counter(_sm_key(d.strip(), True) for _w, d in tgt)
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    changed = False
    for x in range(len(lines)):
        m = _CS_ZERO.match(lines[x])
        if not m or x in nr:
            continue
        a = m.group(2) or m.group(3)
        ra = norm_reg(a)
        for y in range(x + 1, len(lines)):
            l = lines[y]
            if _join_label(lines, y):
                break
            if not _s_is_insn(l) or l.strip().startswith("."):
                continue
            mm = _MOVE_S.match(l)
            if mm and norm_reg(mm.group(3)) == ra and y not in nr:
                b = mm.group(2)
                rb = norm_reg(b)
                if rb == ra:
                    break
                ours = [_sm_key("move\t%s,$0" % a, False), _sm_key("move\t%s,%s" % (b, a), False)]
                swp = [_sm_key("move\t%s,$0" % b, False), _sm_key("move\t%s,%s" % (a, b), False)]
                # B must not be read or written between the two insns either
                free = all(rb not in set(defs_uses(lines[z].split("#", 1)[0].strip())[0])
                           | set(defs_uses(lines[z].split("#", 1)[0].strip())[1])
                           for z in range(x + 1, y)
                           if _s_is_insn(lines[z]) and not lines[z].strip().startswith("."))
                if free and all(tk.get(k, 0) > 0 for k in swp) and any(tk.get(k, 0) == 0 for k in ours):
                    lines[x] = "%smove\t%s,$0" % (m.group(1), b)
                    lines[y] = "%smove\t%s,%s" % (_src_indent(l), a, b)
                    changed = True
                break
            if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
                break
            d, u = defs_uses(l.split("#", 1)[0].strip())
            if ra in d or ra in u:
                break
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# sra_keep: cc1 combine turns `x >> k` of a value whose sign bit is known zero
# (a zero-extending lbu/lhu load or an andi mask) into srl; retail keeps sra.
# Both give the same value on a nonnegative input. Rewrite `srl R,X,k` to
# `sra R,X,k` when X's reaching def in the same straight-line block is
# lbu/lhu/andi, as long as the target has more `sra *,*,k` and fewer
# `srl *,*,k` than ours (count-guided, first come). Count-preserving.
# --------------------------------------------------------------------------
_SK_SH = re.compile(r"^(\s*)(srl|sra)\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\w+)\s*(#.*)?$")


def _sk_counts(insns):
    c = {}
    for d in insns:
        mn, regs, sk = insn_parts(d)
        if mn in ("srl", "sra") and len(regs) == 2 and sk:
            try:
                k = int(sk[-1], 0)
            except ValueError:
                continue
            c[(mn, k)] = c.get((mn, k), 0) + 1
    return c


def sra_keep_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    ours = [l.split("#", 1)[0].strip() for l in lines if _s_is_insn(l) and not l.strip().startswith(".")]
    tc = _sk_counts([d.strip() for _w, d in tgt])
    oc = _sk_counts(ours)
    changed = False
    for i, l in enumerate(lines):
        m = _SK_SH.match(l)
        if not m or m.group(2) != "srl":
            continue
        try:
            k = int(m.group(5), 0)
        except ValueError:
            continue
        if not (0 < k < 32):
            continue
        if tc.get(("sra", k), 0) <= oc.get(("sra", k), 0) or tc.get(("srl", k), 0) >= oc.get(("srl", k), 0):
            continue
        x = norm_reg(m.group(4))
        ok = False
        for j in range(i - 1, -1, -1):
            lj = lines[j]
            if _join_label(lines, j):
                break
            if not _s_is_insn(lj) or lj.strip().startswith("."):
                continue
            body = lj.split("#", 1)[0].strip()
            if _src_is_branch(body) or _src_is_ret(body) or re.match(r"jalr?\b", body):
                break
            if x in defs_uses(body)[0]:
                mn = body.split(None, 1)[0]
                ok = mn in ("lbu", "lhu", "andi")
                break
        if not ok:
            continue
        lines[i] = "%ssra\t%s,%s,%s" % (m.group(1), m.group(3), m.group(4), m.group(5))
        oc[("srl", k)] -= 1
        oc[("sra", k)] = oc.get(("sra", k), 0) + 1
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# call_slot_sink: our reorg fills a call's delay slot with a 1-word insn X that
# writes a callee-saved register from $0 / callee-saved sources (`jal F;
# move $s5,$0`), and the next unconditional jump in the same straight-line run
# with the insn before it (`Y; j L` -> `j L; Y`). Retail leaves the call slot
# empty and puts X in the jump's slot (`jal F; nop; ...; Y; j L; X`). Sound when
# X's destination and sources are neither read nor written between the call and
# the jump (the call preserves callee-saved registers), and no label lies in
# between. Target-guided: the k-th call of the target has a nop slot while ours
# does not, and the target's next `j` slot holds X. Count-preserving.
# --------------------------------------------------------------------------
_CSS_CALLEE = {"s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp", "zero", "sp"}


def _css_tgt_calls(tgt):
    """For each target call (in order): (slot is nop, key of the next j's slot)."""
    out = []
    ds = [d.strip() for _w, d in tgt]
    for q, d in enumerate(ds):
        mn = d.split(None, 1)[0].lower() if d else ""
        if mn not in ("jal", "jalr") or q + 1 >= len(ds):
            continue
        nop = ds[q + 1].split(None, 1)[0].lower() == "nop"
        jk = None
        for r in range(q + 2, len(ds)):
            m2 = ds[r].split(None, 1)[0].lower() if ds[r] else ""
            if m2 == "j" and r + 1 < len(ds):
                jk = _sm_key(ds[r + 1], True)
                break
            if m2 in ("jal", "jalr", "jr") or m2 in _COND_BR_MN or m2 in ("b", "beqz", "bnez"):
                break
        out.append((nop, jk))
    return out


def call_slot_sink_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    tcalls = _css_tgt_calls(tgt)
    ins = [i for i, l in enumerate(lines) if _s_is_insn(l) and not l.strip().startswith(".")]
    calls = [x for x in range(len(ins)) if re.match(r"\s*jalr?\b", lines[ins[x]])]
    if len(calls) != len(tcalls):
        return stext
    nr = _noreorder_lines(lines)
    changed = False
    for k, x in enumerate(calls):
        tnop, tjk = tcalls[k]
        if not tnop or tjk is None or x + 1 >= len(ins):
            continue
        ci, si = ins[x], ins[x + 1]
        if ci not in nr or si not in nr:
            continue
        sbody = lines[si].split("#", 1)[0].strip()
        if sbody.split(None, 1)[0].lower() == "nop" or _src_nwords(lines[si]) != 1:
            continue
        if _sm_srckey(sbody) != tjk:
            continue
        d, u = defs_uses(sbody)
        d = sorted(d)
        if len(d) != 1 or not re.match(r"s[0-7]$|fp$", d[0] or "") or \
                not all(r in _CSS_CALLEE for r in u):
            continue
        regs = set(d) | set(u)
        # find the next `j` in the same run: no label, branch or call before it
        ok, jx = True, None
        for y in range(si + 1, len(lines)):
            ly = lines[y]
            if re.match(r"^\s*[\$\w.]+:\s*$", ly) and not re.match(r"^\s*LM\w*:\s*$", ly):
                ok = False
                break
            if not _s_is_insn(ly) or ly.strip().startswith("."):
                continue
            body = ly.split("#", 1)[0].strip()
            mn = body.split(None, 1)[0].lower()
            if mn == "j":
                jx = y
                break
            if mn in _COND_BR_MN or mn in ("jal", "jalr", "jr", "b"):
                ok = False
                break
            dy, uy = defs_uses(body)
            if regs & (set(dy) | set(uy)):
                ok = False
                break
        if not ok or jx is None or jx not in nr:
            continue
        yi = next((y for y in range(jx + 1, len(lines)) if _s_is_insn(lines[y])
                   and not lines[y].strip().startswith(".")), None)
        if yi is None or yi not in nr or _src_nwords(lines[yi]) != 1:
            continue
        ybody = lines[yi].split("#", 1)[0].strip()
        if ybody.split(None, 1)[0].lower() == "nop":
            continue
        # Y leaves the j slot for the spot before the jump's noreorder block
        st = jx
        while st > 0 and lines[st - 1].strip().startswith(".set"):
            st -= 1
        ind = re.match(r"^(\s*)", lines[si]).group(1)
        yl = lines[yi]
        lines[yi] = ind + sbody
        lines[si] = ind + "nop"
        lines.insert(st, re.match(r"^(\s*)", yl).group(1) + ybody)
        changed = True
        break
    if changed:
        return call_slot_sink_pass("\n".join(lines), tgt)
    return stext


# --------------------------------------------------------------------------
# giv_rebase: loop strength reduction gives an induction base as `X = A + k`
# where retail derived it from a register it had just set from the same source
# (`B = A + d; X = B + (k - d)`, e.g. q = &r->f1 then q + 5 instead of r + 6).
# Same value when A and B are not written between B's definition and X's.
# Target-guided by keys: the target has more `addiu X,B,k-d` and fewer
# `addiu X,A,k` than ours. Count-preserving; runs after sigma.
# --------------------------------------------------------------------------
_GR_ADD = re.compile(r"^(\s*)(addu|addiu)\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*(#.*)?$")


def giv_rebase_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    tc = {}
    for _w, d in tgt:
        k = _sm_key(d.strip(), True)
        if isinstance(k, tuple):
            tc[k] = tc.get(k, 0) + 1

    def ours_counts():
        c = {}
        for l in lines:
            if _s_is_insn(l) and not l.strip().startswith("."):
                k = _sm_srckey(l.split("#", 1)[0].strip())
                if isinstance(k, tuple):
                    c[k] = c.get(k, 0) + 1
        return c
    changed = False
    for i, l in enumerate(lines):
        m = _GR_ADD.match(l)
        if not m:
            continue
        x, a, k = norm_reg(m.group(3)), norm_reg(m.group(4)), int(m.group(5), 0)
        if x == a or a in ("zero", "sp"):
            continue
        body = l.split("#", 1)[0].strip()
        kx = _sm_srckey(body)
        oc = ours_counts()
        if not isinstance(kx, tuple) or tc.get(kx, 0) >= oc.get(kx, 0):
            continue
        seen = set()
        for j in range(i - 1, -1, -1):
            lj = lines[j]
            if _join_label(lines, j):
                break
            if not _s_is_insn(lj) or lj.strip().startswith("."):
                continue
            bj = lj.split("#", 1)[0].strip()
            if _src_is_branch(bj) or _src_is_ret(bj) or re.match(r"jalr?\b", bj):
                break
            mj = _GR_ADD.match(lj)
            dj = defs_uses(bj)[0]
            if mj and norm_reg(mj.group(4)) == a and norm_reg(mj.group(3)) not in (a, x) and \
                    norm_reg(mj.group(3)) not in seen:
                b, dd = mj.group(3), int(mj.group(5), 0)
                nk = k - dd
                if -0x8000 <= nk < 0x8000:
                    cand = "%saddu\t%s,%s,%d" % (m.group(1), m.group(3), b, nk)
                    ck = _sm_srckey(cand.strip())
                    if isinstance(ck, tuple) and tc.get(ck, 0) > oc.get(ck, 0):
                        lines[i] = cand
                        changed = True
                break
            if a in dj or x in dj:
                break
            seen |= set(dj)
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# ior_add: combine turns `(x << k) + y` into `or` when y's nonzero bits fit below
# bit k (a zero-extended lbu/lhu or an andi mask); retail keeps addu. With
# disjoint bits both give the same value. Rewrite `or R,A,B` -> `addu R,A,B`
# when one operand's reaching def in the block is `sll _,_,k` and the other's is
# lbu (k >= 8) / lhu (k >= 16) / andi with a mask below 1 << k, while the target
# has more addu and fewer or than ours (count-guided). Count-preserving.
# --------------------------------------------------------------------------
_IA_OR = re.compile(r"^(\s*)or\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(\$\w+)\s*(#.*)?$")


def _ia_def(lines, i, reg):
    """The body of reg's reaching def in the straight-line block before line i."""
    for j in range(i - 1, -1, -1):
        lj = lines[j]
        if _join_label(lines, j):
            return None
        if not _s_is_insn(lj) or lj.strip().startswith("."):
            continue
        body = lj.split("#", 1)[0].strip()
        mn = body.split(None, 1)[0].lower()
        if mn in _COND_BR_MN:
            continue
        if _src_is_branch(body) or _src_is_ret(body) or re.match(r"jalr?\b", body):
            return None
        if reg in defs_uses(body)[0]:
            return body
    return None


def _ia_bits(body):
    """Upper bound (exclusive bit index) of body's result, or the sll amount as
    ('sll', k)."""
    mn, regs, sk = insn_parts(body)
    if mn == "lbu":
        return 8
    if mn == "lhu":
        return 16
    if mn == "andi" and sk:
        v = _sm_int(sk[-1])
        return v.bit_length() if v is not None else None
    if mn == "sll" and len(regs) == 2 and sk:
        v = _sm_int(sk[-1])
        return ("sll", v) if v is not None else None
    return None


def ior_add_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    t_add = sum(1 for _w, d in tgt if d.strip().split(None, 1)[0] == "addu")
    t_or = sum(1 for _w, d in tgt if d.strip().split(None, 1)[0] == "or")
    ours = [l.split("#", 1)[0].strip() for l in lines if _s_is_insn(l) and not l.strip().startswith(".")]
    # cc1 writes `addu $d,$s,K` for addiu: count only register-register addu
    o_add = sum(1 for b in ours if b.split(None, 1)[0] == "move" or
                (b.split(None, 1)[0] == "addu" and split_ops(b.split(None, 1)[1])[-1].strip().startswith("$")))
    o_or = sum(1 for b in ours if b.split(None, 1)[0] == "or")
    changed = False
    for i, l in enumerate(lines):
        if not (t_add > o_add and t_or < o_or):
            break
        m = _IA_OR.match(l)
        if not m:
            continue
        a, b = norm_reg(m.group(3)), norm_reg(m.group(4))
        if "zero" in (a, b):
            continue
        da, db = _ia_def(lines, i, a), _ia_def(lines, i, b)
        if not da or not db:
            continue
        ba, bb = _ia_bits(da), _ia_bits(db)
        ok = False
        for x, y in ((ba, bb), (bb, ba)):
            if isinstance(x, tuple) and isinstance(y, int) and x[1] is not None and y <= x[1]:
                ok = True
        if not ok:
            continue
        lines[i] = "%saddu\t%s,%s,%s" % (m.group(1), m.group(2), m.group(3), m.group(4))
        o_add += 1
        o_or -= 1
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# la_copy: retail builds a global's address in a caller-saved temp and copies it
# into the callee-saved register a loop uses (`la vK,S` ... `move sN,vK` in the
# loop preheader, after the guard branches); our cc1 cse'd the copy away and puts
# the la straight into sN. Target-guided: the target has, for S, exactly as many
# `la vK,S` (vK caller-saved) followed within 12 insns by `move sM,vK` (sM
# callee-saved, vK not redefined in between) as we have `la $sN,S`, and no la of
# S straight into a callee-saved register. Our la becomes `la vK,S` and the move
# goes after as many conditional branches as the target has between its lui and
# its move. Sound only when, on the straight line up to the move: no label, sN
# not written (reads of it are renamed to vK), vK not touched, sN and vK dead at
# every taken target, and vK dead after the move. Count-changing (+1): pre-sigma.
# --------------------------------------------------------------------------
_LC_LA = re.compile(r"^(\s*)la\s+(\$\w+)\s*,\s*([A-Za-z_]\w*)\s*$")
_LC_CALLER = {"v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7",
              "t8", "t9"}
_LC_SREG = {"s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp"}


def _lc_target_copies(tgt):
    lui_re = re.compile(r"lui\s+(\$?\w+)\s*,\s*%hi\(([\w.$]+)\)")
    add_re = re.compile(r"addiu\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*%lo\(([\w.$]+)\)")
    cps, direct = {}, set()
    for i in range(len(tgt)):
        a = lui_re.search(tgt[i][1])
        if not a:
            continue
        v, sym = norm_reg(a.group(1)), a.group(2)
        ad = None
        for q in range(i + 1, min(i + 4, len(tgt))):
            b = add_re.search(tgt[q][1])
            if b and b.group(3) == sym and norm_reg(b.group(1)) == norm_reg(b.group(2)) == v:
                ad = q
                break
        if ad is None:
            continue
        if v in _LC_SREG:
            direct.add(sym)
            continue
        if v not in _LC_CALLER:
            continue
        nbr = 0
        for q in range(i + 1, min(i + 13, len(tgt))):
            d = tgt[q][1].strip()
            mn = d.split(None, 1)[0].lower()
            dd, uu = defs_uses(d)
            if q > ad and mn in ("addu", "move", "or"):
                ops = [norm_reg(x.strip()) for x in d.split(None, 1)[1].split(",")] if " " in d else []
                src = [x for x in ops[1:] if x != "zero"]
                if len(ops) >= 2 and ops[0] in _LC_SREG and src == [v] and len(ops) - 1 - len(src) <= 1:
                    cps.setdefault(sym, []).append((v, nbr))
                    break
            if q != ad and v in dd:
                break
            if mn in _COND_BR_MN:
                nbr += 1
            elif mn in ("j", "jr", "jal", "jalr", "b"):
                break
    return cps, direct


def _lc_label(body):
    m = re.search(r",\s*(\$L\w+)\s*$", body)
    return m.group(1) if m else None


def la_copy_pass(stext, tgt):
    if not tgt:
        return stext
    cps, direct = _lc_target_copies(tgt)
    if not cps:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    # the split flavor builds it as `lui $T,%hi(S); addiu $sN,$T,%lo(S)` with T
    # dead after: treat that as `la $sN,S` (restored below when not edited)
    conv = {}
    ins0 = [(y, l) for y, l in enumerate(lines) if _s_is_insn(l)]
    for p in range(len(ins0) - 1):
        h, hl = ins0[p]
        j, jl = ins0[p + 1]
        mh = re.match(r"^(\s*)lui\s+(\$\w+)\s*,\s*%hi\(([A-Za-z_]\w*)\)\s*$", hl.split("#", 1)[0])
        mj = re.match(r"^\s*addiu\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*%lo\(([A-Za-z_]\w*)\)\s*$",
                      jl.split("#", 1)[0])
        if not (mh and mj and mh.group(3) == mj.group(3) and mh.group(3) in cps
                and mj.group(2) == mh.group(2) and mj.group(1) != mh.group(2)
                and norm_reg(mj.group(1)) in _LC_SREG and h not in nr and j not in nr
                and _us_dead_ft(lines, ins0, j, norm_reg(mh.group(2)))):
            continue
        conv[j] = (h, hl, jl)
        lines[h] = "#lc_hi"
        lines[j] = "%sla\t%s,%s" % (mh.group(1), mj.group(1), mh.group(3))
    ours = {}
    for i, l in enumerate(lines):
        m = _LC_LA.match(l.split("#", 1)[0])
        if m and norm_reg(m.group(2)) in _LC_SREG and i not in nr:
            ours.setdefault(m.group(3), []).append(i)
    edits = []
    for sym, ix in ours.items():
        if sym in direct or sym not in cps or len(cps[sym]) != len(ix):
            continue
        for i, (v, nbr) in zip(ix, cps[sym]):
            m = _LC_LA.match(lines[i].split("#", 1)[0])
            sn = norm_reg(m.group(2))
            ins = [(y, l) for y, l in enumerate(lines) if _s_is_insn(l)]
            reads, seen, at, ok = [], 0, None, True
            for y in range(i + 1, len(lines)):
                l = lines[y]
                if _s_is_label(l) and not l.strip().startswith("LM"):
                    ok = nbr == 0
                    break
                if not _s_is_insn(l):
                    continue
                body = l.split("#", 1)[0].strip()
                if y in nr or re.match(r"(jalr?|j|jr|b)\b", body):
                    ok = nbr == 0
                    break
                d, u = defs_uses(body)
                if sn in d or v in d or v in u:
                    ok = False
                    break
                if sn in u:
                    reads.append(y)
                if body.split(None, 1)[0].lower() in _COND_BR_MN and nbr == 0:
                    break
                if body.split(None, 1)[0].lower() in _COND_BR_MN:
                    lab = _lc_label(body)
                    if lab is None or not _ff_dead_on(lines, ins, lab, sn) or \
                            not _ff_dead_on(lines, ins, lab, v):
                        ok = False
                        break
                    seen += 1
                    if seen == nbr:
                        at = y
                        break
            if nbr == 0 and ok and reads:
                # no branch between la and the target's move: copy after the
                # last straight-line read (sched passes place it)
                at = reads[-1]
            if not ok or at is None or not _us_dead_ft(lines, ins, at, v):
                continue
            edits.append((i, at, m, sn, v, reads))
    if not edits:
        return stext
    done = set(e[0] for e in edits)
    for j, (h, hl, jl) in conv.items():
        if j not in done:
            lines[h], lines[j] = hl, jl
    for i, at, m, sn, v, reads in sorted(edits, key=lambda e: -e[0]):
        vr, sr = "$%d" % ABI2NUM[v], m.group(2)
        lines.insert(at + 1, "%smove\t%s,%s" % (m.group(1), sr, vr))
        rr = re.compile(r"(?<![\w$])" + re.escape(sr) + r"(?![\w])")
        for y in reads:
            lines[y] = rr.sub(vr, lines[y])
        lines[i] = "%sla\t%s,%s" % (m.group(1), vr, m.group(3))
    return "\n".join(lines)


# --------------------------------------------------------------------------
# thread_steal: retail's reorg fills a conditional branch's empty slot from its
# fall-through thread when that thread is just `j L`: it copies L's first insn X
# into the slot and retargets the jump past X (`beq a,b,T; X; j L+; nop`). Ours
# keeps `beq a,b,T; nop; j L; nop`. Target-guided by conditional-branch ordinal:
# the target's slot holds X's key and the target's next insn is a jump. Sound
# when X is a plain ALU/constant insn (no memory, no branch), X's destination is
# dead at T (the slot runs on the taken path too), and nothing sits between the
# branch and the jump. L gets a label after X when it has none. Count-preserving.
# --------------------------------------------------------------------------
_TS_ALU = {"move", "addu", "addiu", "subu", "li", "lui", "or", "ori", "and", "andi", "xor", "xori",
           "sll", "srl", "sra", "slt", "sltu", "slti", "sltiu", "nor", "la"}


def _ts_key(body):
    k = _sm_key(body, True)
    if isinstance(k, tuple) and len(k) == 4 and k[0] in ("addu", "or") and k[3] == "zero":
        return ("move", k[1], k[2])
    return k


def thread_steal_pass(stext, tgt):
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ours = [i for i, l in enumerate(lines)
            if _s_is_insn(l) and l.split(None, 1)[0].lower() in _COND_BR_MN]
    if len(ours) != len(tb):
        return stext
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    edits = []
    for bi, tk in zip(ours, tb):
        if bi in nr or tk + 2 >= len(tgt):
            continue
        tn = tgt[tk + 2][1].split(None, 1)[0].lower()
        if tn not in ("j", "b"):
            continue
        ji = _tf_next_insn(lines, bi)
        if ji is None or ji in nr or any(_s_is_label(lines[y]) for y in range(bi + 1, ji)):
            continue
        mj = re.match(r"\s*j\s+(\$L\w+)\s*$", lines[ji].split("#", 1)[0])
        if not mj:
            continue
        lab = mj.group(1)
        at = next((k for k, l in enumerate(lines) if l.strip() == lab + ":"), None)
        xi = _tf_next_insn(lines, at) if at is not None else None
        if xi is None or xi in nr:
            continue
        xb = lines[xi].split("#", 1)[0].strip()
        if xb.split(None, 1)[0].lower() not in _TS_ALU:
            continue
        if _ts_key(xb) != _ts_key(tgt[tk + 1][1].strip()):
            continue
        d, _u = defs_uses(xb)
        tl = _lc_label(lines[bi].split("#", 1)[0].strip())
        if len(d) != 1 or tl is None or not all(_ff_dead_on(lines, ins, tl, r) for r in d):
            continue
        # the label after X (any label line before the next insn), or a new one
        after = None
        for y in range(xi + 1, len(lines)):
            if _s_is_insn(lines[y]):
                break
            m = re.match(r"^\s*(\$L\w+):\s*$", lines[y])
            if m:
                after = m.group(1)
                break
        edits.append((bi, ji, xi, xb, after, lab))
    if not edits:
        return stext
    newlab = {}
    for bi, ji, xi, xb, after, lab in edits:
        if after is None:
            newlab[xi] = lab + "_ts"
    edits = [e[:5] for e in edits]
    return thread_steal_rebuild(lines, edits, newlab)


def thread_steal_rebuild(lines, edits, newlab):
    """Apply edits with new labels: insert labels after X first (highest line first
    so earlier indices stay valid), then rewrite branches/jumps."""
    marks = sorted(set([e[0] for e in edits] + [e[1] for e in edits] + list(newlab)), reverse=True)
    for y in marks:
        if y in newlab:
            lines.insert(y + 1, newlab[y] + ":")
        for bi, ji, xi, xb, after in edits:
            if ji == y:
                ind = lines[ji][:len(lines[ji]) - len(lines[ji].lstrip())]
                lines[ji] = "%sj\t%s" % (ind, after or newlab[xi])
            if bi == y:
                ind = lines[bi][:len(lines[bi]) - len(lines[bi].lstrip())]
                br = lines[bi]
                lines[bi:bi + 1] = [ind + ".set\tnoreorder", ind + ".set\tnomacro", br, ind + xb,
                                    ind + ".set\tmacro", ind + ".set\treorder"]
    return "\n".join(lines)


# --------------------------------------------------------------------------
# slot_sink: our cc1 filled a conditional branch's slot with the first insn X
# of its fall-through; retail left the slot empty and X sits a few insns down
# the fall-through (often in the load-delay spot after two loads). Target-guided
# by conditional-branch ordinal: the target slot is a nop and X's key follows
# after d non-nop insns. X moves there (replacing an explicit nop right there,
# if any) and the slot gets a nop. Sound when X is a plain ALU insn, its
# destination is dead at the branch target (it no longer runs on that path),
# and the d insns it passes neither read nor write its registers. Count-
# preserving.
# --------------------------------------------------------------------------
def slot_sink_pass(stext, tgt):
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ours = [i for i, l in enumerate(lines)
            if _s_is_insn(l) and l.split(None, 1)[0].lower() in _COND_BR_MN]
    if len(ours) != len(tb):
        return stext
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    edits = []
    for bi, tk in zip(ours, tb):
        if bi not in nr or tk + 1 >= len(tgt) or tgt[tk + 1][1].strip() != "nop":
            continue
        si = _tf_next_insn(lines, bi)
        if si is None or si not in nr:
            continue
        xb = lines[si].split("#", 1)[0].strip()
        if xb == "nop" or xb.split(None, 1)[0].lower() not in _TS_ALU:
            continue
        xk = _ts_key(xb)
        d = None
        n = 0
        for q in range(tk + 2, min(tk + 10, len(tgt))):
            td = tgt[q][1].strip()
            if _ts_key(td) == xk:
                d = n
                break
            if is_branch(td) or re.match(r"\s*j", td):
                break
            if td != "nop":
                n += 1
        if not d:
            continue
        xd, xu = defs_uses(xb)
        tl = _lc_label(lines[bi].split("#", 1)[0].strip())
        if len(xd) != 1 or tl is None or not all(_ff_dead_on(lines, ins, tl, r) for r in xd):
            continue
        end = next((y for y in range(si + 1, len(lines))
                    if lines[y].strip().startswith(".set") and lines[y].split()[-1] == "reorder"), None)
        if end is None:
            continue
        seen, at, ok = 0, None, True
        for y in range(end + 1, len(lines)):
            l = lines[y]
            if _s_is_label(l) and not l.strip().startswith("LM"):
                ok = False
                break
            if not _s_is_insn(l) or l.strip().startswith("."):
                continue
            body = l.split("#", 1)[0].strip()
            if body == "nop":
                continue
            if y in nr or _src_is_branch(l) or re.match(r"\s*jalr?\b", l):
                ok = False
                break
            dd, uu = defs_uses(_sm_dep_body(body))
            if (dd | uu) & (xd | xu):
                ok = False
                break
            seen += 1
            if seen == d:
                at = y
                break
        if not ok or at is None:
            continue
        edits.append((si, at, xb))
    if not edits:
        return stext
    for si, at, xb in sorted(edits, key=lambda e: -e[1]):
        ind = lines[at][:len(lines[at]) - len(lines[at].lstrip())]
        nx = _tf_next_insn(lines, at)
        if nx is not None and lines[nx].split("#", 1)[0].strip() == "nop" and \
                not any(_s_is_label(lines[y]) for y in range(at + 1, nx)):
            lines[nx] = ind + xb
        else:
            lines.insert(at + 1, ind + xb)
        sind = lines[si][:len(lines[si]) - len(lines[si].lstrip())]
        lines[si] = sind + "nop"
    return "\n".join(lines)


# --------------------------------------------------------------------------
# selfmove_drop: a register rename (web_realloc) can leave `move R,R`, a no-op
# the target does not have (e.g. an epilogue `move v0,v1` once v1 became v0).
# Drop it when the target has no self-move at all (a no-op either way).
# Count-changing (-1 each).
# --------------------------------------------------------------------------
def selfmove_drop_pass(stext, tgt):
    if not tgt:
        return stext
    if any(re.match(r"(move|addu|or)\s+(\$\w+)\s*,\s*\2\s*(,\s*\$(zero|0))?\s*$", d.strip())
           for _w, d in tgt):
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    out = []
    for i, l in enumerate(lines):
        m = re.match(r"^\s*move\s+(\$\w+)\s*,\s*(\$\w+)\s*$", l.split("#", 1)[0])
        if m and i not in nr and norm_reg(m.group(1)) == norm_reg(m.group(2)):
            continue
        out.append(l)
    return "\n".join(out)


# --------------------------------------------------------------------------
# la_split: our cc1 cse kept a global's address in a register (`la R,S`) and
# shared it between several accesses of the same address (a store and a reload,
# or a range test and a later read across branches); retail's cc1 emitted each
# access as its own symbolic macro (`lui X,%hi(S+k); op Y,%lo(S+k)(X)`, loads
# through their destination, stores through $at). Target-guided: the target has
# as many `la` pairs of that address as ours minus the splittable ones, and a
# %lo access at every address a split use touches. A `la` is splittable when
# every read of R it reaches is the base of a plain load/store (none in a
# noreorder slot, R not the stored value), no branch label sits between the la
# and its last use, and R is dead at every branch target on the way and after
# the last use (a call reads only the arguments cc1 set up on that path). Count-changing: pre-sigma.
# --------------------------------------------------------------------------
_LSP_LA = re.compile(r"^(\s*)la\s+(\$\w+)\s*,\s*([A-Za-z_]\w*)(?:\+(\d+))?\s*$")
_LSP_MEM = re.compile(r"^(\s*)(lw|lh|lhu|lb|lbu|sw|sh|sb)(\s+)(\$\w+)\s*,\s*(-?\d+)\((\$\w+)\)\s*$")
_LSP_SYM = re.compile(r"^D_([0-9A-Fa-f]{8})(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?$")


def _lsp_key(sym, k=0):
    m = _LSP_SYM.match(sym.strip())
    if not m:
        return (sym.strip(), k)
    return int(m.group(1), 16) + (int(m.group(2), 0) if m.group(2) else 0) + k


def _lsp_uses(lines, ins, nr, i, r):
    """Use lines of the `la` at line i (dest r) when it is splittable, else None."""
    uses = []
    pos = next(p for p, (x, _) in enumerate(ins) if x == i)
    for p in range(pos + 1, len(ins)):
        li, l = ins[p]
        # a referenced label between la and here: another path joins
        for y in range(ins[p - 1][0] + 1, li):
            t = lines[y].strip()
            if t.endswith(":") and not t.startswith("LM") and _label_referenced(lines, t[:-1]):
                return None
        body = l.split("#", 1)[0].strip()
        d, u = defs_uses(body)
        mn = body.split(None, 1)[0].lower()
        if r in u:
            m = _LSP_MEM.match(body)
            if li in nr or not m or norm_reg(m.group(6)) != r or \
                    (mn[0] == "s" and norm_reg(m.group(4)) == r):
                return None
            uses.append(li)
            if r in d:
                return uses
            continue
        if r in d:
            return uses
        if mn in _COND_BR_MN:
            lab = _lc_label(body)
            if lab is None or not _ff_dead_on(lines, ins, lab, r, callee_args=False):
                return None
            continue
        if _src_is_branch(l) or _src_is_ret(l) or re.match(r"\s*jalr?\b", l):
            probe = "$Lls_probe"
            l2 = lines[:li] + [probe + ":"] + lines[li:]
            ins2 = [(k, x) for k, x in enumerate(l2) if _s_is_insn(x)]
            return uses if _ff_dead_on(l2, ins2, probe, r, callee_args=False) else None
    return uses


def la_split_pass(stext, tgt):
    if not tgt:
        return stext
    lui_re = re.compile(r"lui\s+(\$?\w+)\s*,\s*%hi\(([^)]+)\)")
    add_re = re.compile(r"addiu\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*%lo\(([^)]+)\)")
    tla, tmem = {}, set()
    for i in range(len(tgt)):
        d = tgt[i][1]
        m = re.search(r"%lo\(([^)]+)\)\(", d)
        if m:
            tmem.add(_lsp_key(m.group(1)))
        a = lui_re.search(d)
        b = add_re.search(tgt[i + 1][1]) if a and i + 1 < len(tgt) else None
        if a and b and b.group(3) == a.group(2) and \
                norm_reg(a.group(1)) == norm_reg(b.group(1)) == norm_reg(b.group(2)):
            k = _lsp_key(a.group(2))
            tla[k] = tla.get(k, 0) + 1
    if not tmem:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    groups = {}
    for i, l in ins:
        m = _LSP_LA.match(l.split("#", 1)[0])
        if not m or i in nr:
            continue
        groups.setdefault(_lsp_key(m.group(3), int(m.group(4) or 0)), []).append((i, m))
    edits = []
    for key, las in groups.items():
        if not isinstance(key, int):
            continue
        cand = []
        for i, m in las:
            r = norm_reg(m.group(2))
            us = _lsp_uses(lines, ins, nr, i, r)
            if not us:
                continue
            k0 = int(m.group(4) or 0)
            if all(key + int(_LSP_MEM.match(lines[u].split("#", 1)[0].strip()).group(5))
                   in tmem for u in us):
                cand.append((i, m, us, k0))
        if cand and len(las) - len(cand) == tla.get(key, 0):
            edits += cand
    if not edits:
        return stext
    rep = {}
    for i, m, us, k0 in edits:
        rep[i] = []
        sym = m.group(3)
        for u in us:
            mm = _LSP_MEM.match(lines[u].split("#", 1)[0].rstrip())
            ind, op, sp, x, off = mm.group(1), mm.group(2), mm.group(3), mm.group(4), int(mm.group(5))
            tot = k0 + off
            e = sym if tot == 0 else ("%s+%d" % (sym, tot) if tot > 0 else "%s%d" % (sym, tot))
            t = "$1" if op[0] == "s" else x
            rep[u] = ["%slui\t%s,%%hi(%s)" % (ind, t, e),
                      "%s%s%s%s,%%lo(%s)(%s)" % (ind, op, sp, x, e, t)]
    out = []
    for i, l in enumerate(lines):
        if i in rep:
            out.extend(rep[i])
        else:
            out.append(l)
    return "\n".join(out)


# --------------------------------------------------------------------------
# const_sink: our loop.c hoisted a constant (`li $sK,C`) out of a loop into a
# callee-saved register; retail left it in the loop body in a caller-saved temp
# (`lui $aX,C>>16` a few insns before its uses) and so saved one s-register
# less. Target-guided: the target saves one s-register fewer than ours, builds
# C in a non-s register, and never holds C in an s-register. Ours: sK is
# written once (the li), every read of it sits in one basic block with no call
# between the first and the last, and the frame size is unchanged by dropping
# one save slot. The li moves to just before the first read into a register
# the function never touches, sK's save/restore go, the s-registers above sK
# slide down one number and the save slots are re-laid out in cc1's order.
# Count-changing: pre-sigma.
# --------------------------------------------------------------------------
_CS_LI = re.compile(r"^(\s*)li\s+\$(1[6-9]|2[0-3])\s*,\s*(-?\d+)")
_CS_FRAME = re.compile(r"\.frame\s+\$sp,(\d+),\$31\s*#\s*vars=\s*(\d+),\s*regs=\s*(\d+)/(\d+),"
                       r"\s*args=\s*(\d+),\s*extra=\s*(\d+)")
_CS_SAVE = re.compile(r"^(\s*)(sw|lw)(\s+)\$(\d+)\s*,\s*(\d+)\(\$sp\)\s*$")
_CS_FREE = (3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 4)


def _cs_tgt(tgt):
    """({const: [regs holding it]}, number of s-registers the target saves)."""
    held, nsave = {}, 0
    for i, (w, d) in enumerate(tgt):
        m = re.match(r"\s*sw\s+\$(s[0-7])\s*,\s*0x[0-9A-Fa-f]+\(\$sp\)", d)
        if m and i < 16:
            nsave += 1
        m = re.match(r"\s*lui\s+\$(\w+)\s*,\s*\((0x[0-9A-Fa-f]+|\d+)\s*>>\s*16\)\s*$", d)
        if m:
            held.setdefault(int(m.group(2), 0) & 0xFFFFFFFF, []).append(norm_reg(m.group(1)))
            continue
        m = re.match(r"\s*addiu\s+\$(\w+)\s*,\s*\$zero\s*,\s*(-?0x[0-9A-Fa-f]+|-?\d+)\s*$", d)
        if m:
            held.setdefault(int(m.group(2), 0) & 0xFFFFFFFF, []).append(norm_reg(m.group(1)))
    return held, nsave


def const_sink_pass(stext, tgt):
    if not tgt:
        return stext
    held, tsave = _cs_tgt(tgt)
    lines = stext.split("\n")
    fr = next(((i, _CS_FRAME.search(l)) for i, l in enumerate(lines) if _CS_FRAME.search(l)), None)
    if fr is None:
        return stext
    fsz, vars_, nregs, nf, args, extra = (int(fr[1].group(k)) for k in range(1, 7))
    newsz = (vars_ + (nregs - 1) * 4 + nf * 8 + args + extra + 7) & ~7
    if newsz != fsz:
        return stext
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    saves = {}
    for i, l in ins[:24]:
        m = _CS_SAVE.match(l)
        if m and m.group(2) == "sw" and (16 <= int(m.group(4)) <= 23 or int(m.group(4)) in (30, 31)):
            saves[int(m.group(4))] = int(m.group(5))
    sregs = sorted(r for r in saves if 16 <= r <= 23)
    if not sregs or sregs != list(range(16, 16 + len(sregs))) or len(sregs) - 1 != tsave:
        return stext
    used = set(int(x) for x in re.findall(r"\$(\d+)\b", "\n".join(l.split("#", 1)[0] for _, l in ins)))
    for i, l in ins:
        m = _CS_LI.match(l.split("#", 1)[0])
        if not m:
            continue
        k, c = int(m.group(2)), int(m.group(3)) & 0xFFFFFFFF
        rk = "$%d" % k
        if k not in saves or c not in held or any(r.startswith("s") or r == "fp" for r in held[c]):
            continue
        pat = re.compile(re.escape(rk) + r"\b")
        refs = [(j, x) for j, x in ins if j != i and pat.search(x.split("#", 1)[0])
                and not _CS_SAVE.match(x)]
        if not refs or any(norm_reg("$%d" % k) in defs_uses(x.split("#", 1)[0].strip())[0]
                           for _, x in refs):
            continue
        a, b = refs[0][0], refs[-1][0]
        mid = [x for j, x in ins if a <= j <= b]
        if any(_src_is_branch(x) or re.match(r"\s*jalr?\b", x) for x in mid) or any(
                re.match(r"\s*[$\w.]+:\s*$", lines[y]) and not lines[y].strip().startswith("LM")
                for y in range(a, b)):
            continue
        if any(y in _noreorder_lines(lines) for y in (i, a)):
            continue
        # a temp the span [a, b] does not mention and that is dead at a
        # (the target's register for C first)
        span = set(int(x) for x in re.findall(r"\$(\d+)\b", "\n".join(
            x.split("#", 1)[0] for j, x in ins if a <= j <= b)))
        l2 = lines[:a] + ["$Lcs_probe:"] + lines[a:]
        ins2 = [(q, x) for q, x in enumerate(l2) if _s_is_insn(x)]
        pref = [ABI2NUM[r] for r in held[c] if r in ABI2NUM]
        t = next((r for r in pref + list(_CS_FREE) if r not in span and r in _CS_FREE
                  and _ff_dead_on(l2, ins2, "$Lcs_probe", norm_reg("$%d" % r))), None)
        if t is None:
            continue
        ind = m.group(1)
        out = []
        for y, l in enumerate(lines):
            if y == i:
                continue
            if y == a:
                out.append("%sli\t$%d,%s" % (ind, t, m.group(3)))
            if a <= y <= b and _s_is_insn(l):
                l = pat.sub("$%d" % t, l)
            ms = _CS_SAVE.match(l)
            if ms and int(ms.group(4)) == k and int(ms.group(5)) == saves[k]:
                continue
            out.append(l)
        order = sorted(saves, key=lambda r: saves[r])
        offs = [saves[r] for r in order]
        new = [r for r in order if r != k]
        ren = {r: (r - 1 if 16 <= r <= 23 and r > k else r) for r in new}
        slot = {ren[r]: offs[x] for x, r in enumerate(new)}
        oldslot = {ren[r]: saves[r] for r in new}

        def rn(mm):
            r = int(mm.group(1))
            return "$%d" % (r - 1 if k < r <= max(sregs) else r)
        res = []
        for l in out:
            if _s_is_insn(l):
                body, sep, cm = l.partition("#")
                body = re.sub(r"\$(\d+)\b", rn, body)
                ms = _CS_SAVE.match(body)
                if ms and int(ms.group(4)) in slot and int(ms.group(5)) == oldslot[int(ms.group(4))]:
                    body = "%s%s%s$%d,%d($sp)" % (ms.group(1), ms.group(2), ms.group(3),
                                                  int(ms.group(4)), slot[int(ms.group(4))])
                l = body + (sep + cm if sep else "")
            res.append(l)
        return "\n".join(res)
    return stext



# --------------------------------------------------------------------------
# ulcopy_rename: an unaligned word copy (movstr of a 4-byte struct) is
# `lwl R,a+3(B); lwr R,a(B); [..] swl R,c+3(D); swr R,c(D)`. Our reload took R
# from the high temporaries; retail's took the lowest free register. Target-
# guided: the target has one copy with the same four offsets and the same base
# registers, through register T. Rename R -> T over the copy when T is not
# mentioned between the lwl and the swr and is dead at the lwl and after the
# swr, and R is dead after the swr (a call reads only the arguments cc1 set
# up). Count-preserving.
# --------------------------------------------------------------------------
_ULC = re.compile(r"^\s*(lwl|lwr|swl|swr)\s+(\$\w+)\s*,\s*(-?(?:0x[0-9A-Fa-f]+|\d+))\((\$\w+)\)\s*$")


def _ulc_quads(items):
    """[(first, last, reg, key)] for items = [(idx, text)] in order."""
    out = []
    for p in range(len(items)):
        m0 = _ULC.match(items[p][1].split("#", 1)[0].strip())
        if not m0 or m0.group(1) != "lwl":
            continue
        r = norm_reg(m0.group(2))
        seq, q = [m0], p + 1
        while q < len(items) and q <= p + 8 and len(seq) < 4:
            m = _ULC.match(items[q][1].split("#", 1)[0].strip())
            if m and norm_reg(m.group(2)) == r and m.group(1) == ("lwr", "swl", "swr")[len(seq) - 1]:
                seq.append(m)
                if len(seq) == 4:
                    break
            q += 1
        if len(seq) != 4:
            continue
        key = tuple((m.group(1), int(m.group(3), 0), norm_reg(m.group(4))) for m in seq)
        out.append((items[p][0], items[q][0], r, key))
    return out


def ulcopy_rename_pass(stext, tgt):
    if not tgt:
        return stext
    tq = _ulc_quads([(i, d) for i, (w, d) in enumerate(tgt)])
    if not tq:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    changed = False
    for a, b, r, key in _ulc_quads(ins):
        hit = [t for _, _, t, k in tq if k == key]
        if len(hit) != 1 or hit[0] == r or hit[0] not in ABI2NUM or a in nr or b in nr:
            continue
        t = hit[0]
        span = [x for y, x in ins if a <= y <= b]
        if any(t in set().union(*defs_uses(x.split("#", 1)[0].strip())) for x in span):
            continue
        if any(y in nr for y, _ in ins if a <= y <= b):
            continue
        l2 = lines[:a] + ["$Lulc_a:"] + lines[a:b + 1] + ["$Lulc_b:"] + lines[b + 1:]
        ins2 = [(q, x) for q, x in enumerate(l2) if _s_is_insn(x)]
        if not (_ff_dead_on(l2, ins2, "$Lulc_a", t, callee_args=False)
                and _ff_dead_on(l2, ins2, "$Lulc_b", t, callee_args=False)
                and _ff_dead_on(l2, ins2, "$Lulc_b", r, callee_args=False)):
            continue
        rn = "$%d" % ABI2NUM[r]
        rr = re.compile(r"(?<![\w$])(" + re.escape(rn) + "|" + re.escape("$" + r) + r")(?![\w])")
        for y in range(a, b + 1):
            if _s_is_insn(lines[y]):
                body, sep, cm = lines[y].partition("#")
                lines[y] = rr.sub("$%d" % ABI2NUM[t], body) + (sep + cm if sep else "")
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# movstr_rename: a block move (movstrsi) is groups of word loads into scratch
# registers, then stores of them in the same order. Our reload took the high
# temporaries (t1..t5); retail's took the lowest free registers (v0/v1/a0/a1).
# Target-guided: the target has exactly one run with the same load/store
# offsets and base registers; our scratch at each slot is renamed to the
# target's when all target scratches are unmentioned in the run (other than
# as our scratches), dead at its start and after it, and ours are dead after
# it. Count-preserving; runs late (after block_iso) when bases agree.
# --------------------------------------------------------------------------
_MVR_LW = re.compile(r"^\s*lw\s+(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)\((\$\w+)\)\s*$")
_MVR_SW = re.compile(r"^\s*sw\s+(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)\((\$\w+)\)\s*$")


def _mvr_runs(items, merge=True):
    """[(first_idx, last_idx, [scratch per slot], key)] over items [(idx, text)].
    merge: adjacent groups with the same width form one run (one scratch set)."""
    runs, p = [], 0
    while p < len(items):
        loads = []
        while p + len(loads) < len(items):
            m = _MVR_LW.match(items[p + len(loads)][1].split("#", 1)[0].strip())
            if not m or norm_reg(m.group(1)) in [x[0] for x in loads] or \
                    norm_reg(m.group(1)) == norm_reg(m.group(3)):
                break
            loads.append((norm_reg(m.group(1)), int(m.group(2), 0), norm_reg(m.group(3))))
        k = len(loads)
        stores = []
        skip = 0
        for x in range(k):
            if p + k + x + skip >= len(items):
                break
            sb = items[p + k + x + skip][1].split("#", 1)[0].strip()
            # (split, target words) the last store sits in a jump's delay slot
            if (not merge and x == k - 1 and not skip and re.match(r"(j|b)\s", sb)
                    and p + k + x + 1 < len(items)):
                skip = 1
                sb = items[p + k + x + skip][1].split("#", 1)[0].strip()
            m = _MVR_SW.match(sb)
            if not m or norm_reg(m.group(1)) != loads[x][0]:
                break
            stores.append((int(m.group(2), 0), norm_reg(m.group(3))))
        if k < 2 or len(stores) != k:
            p += 1
            continue
        regs = [x[0] for x in loads]
        key = tuple((l[1], l[2], st[0], st[1]) for l, st in zip(loads, stores))
        last = items[p + 2 * k - 1 + skip][0]
        if merge and runs and runs[-1][4] == p - 1:
            a, _, rr, kk, _ = runs[-1]
            if len(rr) == len(regs):
                runs[-1] = (a, last, rr, kk + key, p + 2 * k - 1)
                p += 2 * k
                continue
        runs.append((items[p][0], last, regs, key, p + 2 * k - 1 + skip))
        p += 2 * k + skip
    return [(a, b, r, k) for a, b, r, k, _ in runs]


def movstr_rename_split_pass(stext, tgt):
    """movstr_rename over single load/store groups (a 32-byte copy is two
    16-byte groups whose scratches differ after sigma), and duplicate-key
    target runs (the same copy done twice) paired by ordinal when ours has
    the same number of them."""
    return movstr_rename_pass(stext, tgt, split=True)


def movstr_rename_pass(stext, tgt, split=False):
    if not tgt:
        return stext
    truns = _mvr_runs([(i, d) for i, (w, d) in enumerate(tgt)], merge=not split)
    if not truns:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    changed = False
    ours = _mvr_runs(ins, merge=not split)
    seen = {}
    for a, b, regs, key in ours:
        o = seen.get(key, 0)
        seen[key] = o + 1
        hit = [r for _, _, r, k in truns if k == key]
        if split and len(hit) > 1 and len(hit) == sum(1 for x in ours if x[3] == key):
            hit = [hit[o]]
        if len(hit) != 1 or hit[0] == regs:
            continue
        tr = hit[0]
        if any(t not in ABI2NUM for t in tr) or any(y in nr for y, _ in ins if a <= y <= b):
            continue
        span = [x for y, x in ins if a <= y <= b]
        ment = set()
        for x in span:
            d, u = defs_uses(x.split("#", 1)[0].strip())
            ment |= d | u
        if any(t in ment and t not in regs for t in tr):
            continue
        l2 = lines[:a] + ["$Lmvr_a:"] + lines[a:b + 1] + ["$Lmvr_b:"] + lines[b + 1:]
        ins2 = [(q, x) for q, x in enumerate(l2) if _s_is_insn(x)]
        if not all(_ff_dead_on(l2, ins2, "$Lmvr_b", r, callee_args=False) for r in set(regs) | set(tr)):
            continue
        if not all(t in regs or _ff_dead_on(l2, ins2, "$Lmvr_a", t, callee_args=False) for t in tr):
            continue
        mp = {"$%d" % ABI2NUM[r]: "$%d" % ABI2NUM[t] for r, t in zip(regs, tr)}
        for r, t in zip(regs, tr):
            mp["$" + r] = "$%d" % ABI2NUM[t]
        pat = re.compile(r"(?<![\w$])(\$\w+)(?![\w])")
        for y in range(a, b + 1):
            if _s_is_insn(lines[y]):
                body, sep, cm = lines[y].partition("#")
                lines[y] = pat.sub(lambda mm: mp.get(mm.group(1), mm.group(1)), body) + \
                    (sep + cm if sep else "")
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# zext_drop: a volatile byte/halfword read makes our cc1 re-zero-extend the
# loaded value (`lbu R,..; andi R,R,0xff`, or lhu + 0xffff), which is a no-op:
# lbu/lhu already zero-extend. Retail's has no such andi. Target-guided: the
# target has no `andi X,X,M` right after a zero-extending load of X, ours has
# some; each is deleted. Always sound. Count-changing (-1 each): pre-sigma.
# --------------------------------------------------------------------------
_ZXD_LD = re.compile(r"^\s*(lbu|lhu)\s+(\$\w+)\s*,")
_ZXD_AND = re.compile(r"^\s*andi\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*$")


def _zxd_pairs(items):
    """Indexes (into items) of `andi X,X,M` directly after `lbu/lhu X` with M the
    load's full width mask."""
    out = []
    for p in range(len(items) - 1):
        m = _ZXD_LD.match(items[p][1].split("#", 1)[0])
        a = _ZXD_AND.match(items[p + 1][1].split("#", 1)[0].strip())
        if not m or not a:
            continue
        r = norm_reg(m.group(2))
        mask = 0xFF if m.group(1) == "lbu" else 0xFFFF
        if norm_reg(a.group(1)) == norm_reg(a.group(2)) == r and int(a.group(3), 0) == mask:
            out.append(p + 1)
    return out


def zext_drop_pass(stext, tgt):
    if not tgt:
        return stext
    titems = [(i, d) for i, (w, d) in enumerate(tgt) if d.strip() != "nop"]
    if _zxd_pairs(titems):
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    drop = [ins[p][0] for p in _zxd_pairs(ins) if ins[p][0] not in nr]
    if not drop:
        return stext
    return "\n".join(l for i, l in enumerate(lines) if i not in set(drop))


# --------------------------------------------------------------------------
# call_slot_swap: two frame stores before a call, one in the jal's delay slot:
# our sched1/reorg put `sw B,y($sp)` in the slot and `sw A,x($sp)` earlier;
# retail has B earlier and A in the slot. Both still complete before the callee
# runs, so their order only matters to the insns in between. Target-guided: the
# target's call to the same function (same ordinal) has `sw A',x(sp)` in its slot
# and an earlier `sw B',y(sp)` in its straight-line lead-in. Sound when x != y,
# nothing between A and the jal writes A's source or reads/writes either slot,
# and B's source is not written between A and the jal. Count-preserving.
# --------------------------------------------------------------------------
_CSW_SW = re.compile(r"^(\s*)sw\s+(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)\(\$(?:sp|29)\)\s*$")


def _csw_tgt(tgt):
    """[(callee, slot sw offset, set of earlier sw offsets)] per target jal."""
    out = []
    for i, (w, d) in enumerate(tgt):
        m = re.match(r"\s*jal\s+(\w+)\s*$", d.strip())
        if not m or i + 1 >= len(tgt):
            continue
        ms = re.match(r"\s*sw\s+\$\w+\s*,\s*(-?0x[0-9A-Fa-f]+|-?\d+)\(\$sp\)\s*$", tgt[i + 1][1].strip())
        early = set()
        for q in range(i - 1, max(-1, i - 12), -1):
            dq = tgt[q][1].strip()
            if is_branch(dq) or re.match(r"\s*j", dq):
                break
            me = re.match(r"\s*sw\s+\$\w+\s*,\s*(-?0x[0-9A-Fa-f]+|-?\d+)\(\$sp\)\s*$", dq)
            if me:
                early.add(int(me.group(1), 0))
        out.append((m.group(1), int(ms.group(1), 0) if ms else None, early))
    return out


def call_slot_swap_pass(stext, tgt):
    if not tgt:
        return stext
    tj = _csw_tgt(tgt)
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    ours = [(p, re.match(r"\s*jal\s+(\w+)\s*$", l.split("#", 1)[0]).group(1))
            for p, (i, l) in enumerate(ins) if re.match(r"\s*jal\s+\w+\s*$", l.split("#", 1)[0])]
    if len(ours) != len(tj):
        return stext
    changed = False
    for (p, callee), (tc, tslot, tearly) in zip(ours, tj):
        if callee != tc or tslot is None or p + 1 >= len(ins) or ins[p][0] not in nr:
            continue
        si, sl = ins[p + 1]
        mb = _CSW_SW.match(sl.split("#", 1)[0].rstrip())
        if not mb or si not in nr:
            continue
        y = int(mb.group(3), 0)
        if y == tslot or y not in tearly:
            continue
        # our earlier `sw A,tslot($sp)` on the straight line before the jal
        q = p - 1
        found = None
        while q >= 0:
            qi, ql = ins[q]
            if _src_is_branch(ql) or re.match(r"\s*jalr?\b", ql) or any(
                    _s_is_label(x) and not x.strip().startswith("LM") for x in lines[qi + 1:ins[q + 1][0]]):
                break
            ma = _CSW_SW.match(ql.split("#", 1)[0].rstrip())
            if ma and int(ma.group(3), 0) == tslot:
                found = q
                break
            q -= 1
        if found is None or ins[found][0] in nr:
            continue
        ai, al = ins[found]
        ma = _CSW_SW.match(al.split("#", 1)[0].rstrip())
        ra, rb = norm_reg(ma.group(2)), norm_reg(mb.group(2))
        ok = True
        for r in range(found + 1, p):
            body = ins[r][1].split("#", 1)[0].strip()
            d, u = defs_uses(body)
            if ra in d or rb in d:
                ok = False
                break
            mo = _mem_operand(body)
            if mo and norm_reg(mo[0]) == "sp" and (mo[1] in (y, tslot)):
                ok = False
                break
        if not ok:
            continue
        # swap the two stores' bodies (A goes into the slot, B takes A's place)
        a_body = al.split("#", 1)[0].strip()
        b_body = sl.split("#", 1)[0].strip()
        lines[ai] = _src_indent(al) + b_body
        lines[si] = _src_indent(sl) + a_body
        changed = True
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# hi_interleave: two adjacent symbolic loads `lui A,%hi(S1); op A,%lo(S1)(A)`,
# `lui B,%hi(S2); op B,%lo(S2)(B)`; retail's scheduler interleaved the halves:
# `lui A,%hi(S1); lui B,%hi(S2); op B,%lo(S2)(B); op A,%lo(S1)(A)` (ours keeps
# each macro load whole, so sched_match sees two units). Target-guided: the
# target has exactly that 4-word sequence with the same registers and symbols.
# Sound: A != B, each load reads only its own register. Count-preserving.
# --------------------------------------------------------------------------
_HIL_LUI = re.compile(r"^\s*lui\s+(\$\w+)\s*,\s*%hi\(([\w.$+]+)\)\s*$")
_HIL_LD = re.compile(r"^\s*(lw|lh|lhu|lb|lbu)\s+(\$\w+)\s*,\s*%lo\(([\w.$+]+)\)\((\$\w+)\)\s*$")


def _hil_pair(a, b):
    """(reg, sym, op) when a/b are `lui R,%hi(S); op R,%lo(S)(R)`."""
    mh, ml = _HIL_LUI.match(a), _HIL_LD.match(b)
    if not (mh and ml):
        return None
    r = norm_reg(mh.group(1))
    if r in (None, "at") or norm_reg(ml.group(2)) != r or norm_reg(ml.group(4)) != r \
            or _sm_sym(mh.group(2)) != _sm_sym(ml.group(3)):
        return None
    return r, _sm_sym(mh.group(2)), ml.group(1)


def hi_interleave_pass(stext, tgt):
    if not tgt:
        return stext
    want = set()
    for i in range(len(tgt) - 3):
        w = [tgt[i + k][1].strip() for k in range(4)]
        m0, m1 = _HIL_LUI.match(w[0]), _HIL_LUI.match(w[1])
        l2, l3 = _HIL_LD.match(w[2]), _HIL_LD.match(w[3])
        if not (m0 and m1 and l2 and l3):
            continue
        a, b = norm_reg(m0.group(1)), norm_reg(m1.group(1))
        if a == b or norm_reg(l2.group(2)) != b or norm_reg(l2.group(4)) != b \
                or norm_reg(l3.group(2)) != a or norm_reg(l3.group(4)) != a:
            continue
        want.add(((a, _sm_sym(m0.group(2)), l3.group(1)), (b, _sm_sym(m1.group(2)), l2.group(1))))
    if not want:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    changed = False
    p = 0
    while p + 3 < len(ins):
        idx = [ins[p + k][0] for k in range(4)]
        body = [ins[p + k][1].split("#", 1)[0].strip() for k in range(4)]
        # no label between the four lines
        if any(y in nr for y in idx) or any(_s_is_label(x) and not x.strip().startswith("LM")
                                           for x in lines[idx[0] + 1:idx[3]]):
            p += 1
            continue
        x, y = _hil_pair(body[0], body[1]), _hil_pair(body[2], body[3])
        if not (x and y) or x[0] == y[0]:
            p += 1
            continue
        for first, second in ((x, y), (y, x)):
            if (first, second) in want:
                f_lui, f_ld = (body[0], body[1]) if first is x else (body[2], body[3])
                s_lui, s_ld = (body[2], body[3]) if first is x else (body[0], body[1])
                new = [f_lui, s_lui, s_ld, f_ld]
                if new != body:
                    for k in range(4):
                        lines[idx[k]] = _src_indent(lines[idx[k]]) + new[k]
                    changed = True
                break
        p += 4
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# at_dest: cc1 expanded an indexed symbolic load through $at because the index
# register is also the destination (`.set noat; lui $1,%hi(S); addu $1,$1,$X;
# lw $X,%lo(S)($1)`); retail's index lived in another register, so its assembler
# expanded the load through the destination. Rename the index chain (the
# consecutive self-updating defs of X that feed the load) to a temp R that the
# span does not mention and that is dead at the chain start, then write the
# destination form `lui $X,%hi(S); addu $X,$X,$R; lw $X,%lo(S)($X)`.
# Count-preserving; runs before sigma.
# --------------------------------------------------------------------------
_ATD_LUI = re.compile(r"^\s*lui\s+\$(?:1|at)\s*,\s*%hi\(([\w.$+]+)\)\s*$")
_ATD_ADD = re.compile(r"^\s*addu\s+\$(?:1|at)\s*,\s*\$(?:1|at)\s*,\s*(\$\w+)\s*$")
_ATD_LD = re.compile(r"^(\s*)(lw|lh|lhu|lb|lbu)\s+(\$\w+)\s*,\s*%lo\(([\w.$+]+)\)\(\$(?:1|at)\)\s*$")
_ATD_FREE = (3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 2)


def at_dest_pass(stext, tgt):
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    changed = False
    for p in range(len(ins) - 2):
        a, b, c = (ins[p + k][1].split("#", 1)[0].strip() for k in range(3))
        mh, ma, ml = _ATD_LUI.match(a), _ATD_ADD.match(b), _ATD_LD.match(ins[p + 2][1].split("#", 1)[0])
        if not (mh and ma and ml) or mh.group(1) != ml.group(4):
            continue
        x = norm_reg(ma.group(1))
        if norm_reg(ml.group(3)) != x:
            continue
        # chain of defs of x ending before the lui
        q = p - 1
        chain = []
        while q >= 0:
            body = ins[q][1].split("#", 1)[0].strip()
            if _src_is_branch(ins[q][1]) or re.match(r"\s*jalr?\b", ins[q][1]):
                break
            d, u = defs_uses(body)
            if x in d:
                chain.append(q)
                if x not in u:
                    break
            elif x in u:
                chain = []
                break
            q -= 1
        if not chain or q < 0:
            continue
        start = chain[-1]
        span = [ins[k][1].split("#", 1)[0] for k in range(start, p + 3)]
        ment = set(int(v) for v in re.findall(r"\$(\d+)\b", "\n".join(span)))
        l2 = lines[:ins[start][0]] + ["$Latd_a:"] + lines[ins[start][0]:]
        i2 = [(k, v) for k, v in enumerate(l2) if _s_is_insn(v)]
        r = next((f for f in _ATD_FREE if f not in ment and _ff_dead_on(l2, i2, "$Latd_a", NUM2ABI[f], callee_args=False)), None)
        if r is None:
            continue
        xr = "$%d" % ABI2NUM[x]
        pat = re.compile(re.escape(xr) + r"\b")
        for k in range(start, p):
            li = ins[k][0]
            bd, sep, cm = lines[li].partition("#")
            lines[li] = pat.sub("$%d" % r, bd) + (sep + cm if sep else "")
        ind = ml.group(1)
        lines[ins[p][0]] = "%slui\t%s,%%hi(%s)" % (ind, xr, mh.group(1))
        lines[ins[p + 1][0]] = "%saddu\t%s,%s,$%d" % (ind, xr, xr, r)
        lines[ins[p + 2][0]] = "%s%s\t%s,%%lo(%s)(%s)" % (ind, ml.group(2), xr, mh.group(1), xr)
        # the $at bracket is no longer needed (it would split the block)
        for y in list(range(ins[p][0] - 1, max(-1, ins[p][0] - 4), -1)) + \
                list(range(ins[p + 2][0] + 1, min(len(lines), ins[p + 2][0] + 4))):
            if re.match(r"\s*\.set\s+(noat|at)\s*$", lines[y]):
                lines[y] = ""
        changed = True
    return "\n".join(lines) if changed else stext



# --------------------------------------------------------------------------
# slot_redundant: a conditional branch's delay slot holds S (filled from the
# fall-through thread), and the branch target's block recomputes the same S
# before anything changes its inputs or output. Retail's reorg (redundant_insn)
# deleted that copy: the slot already ran on the taken path. Ours keeps it.
# Sound only when the target label has this branch as its only entrant (the
# insn before it is the slot of an unconditional jump, no other reference) and
# nothing between the label and the copy writes S's registers or memory.
# Target-guided: ours has more insns with S's key than the target.
# --------------------------------------------------------------------------
_SRD_COND = re.compile(r"^(beq|bne|blez|bgtz|bltz|bgez|beqz|bnez)$")


def _srd_body(l):
    return l.split("#", 1)[0].strip()


def slot_redundant_pass(stext, tgt):
    if not tgt:
        return stext
    tcount = {}
    for _w, d in tgt:
        k = _sm_key(d.strip(), True)
        if isinstance(k, tuple):
            tcount[k] = tcount.get(k, 0) + 1
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    ocount = {}
    for _i, l in ins:
        k = _sm_srckey(_srd_body(l))
        if isinstance(k, tuple):
            ocount[k] = ocount.get(k, 0) + 1
    nr = _noreorder_lines(lines)
    labdef = {}
    for x, l in enumerate(lines):
        if _s_is_label(l):
            labdef[l.strip()[:-1]] = x
    refs = {}
    for _i, l in ins:
        for tok in re.findall(r"[\w.$]+", _srd_body(l)):
            if tok in labdef:
                refs[tok] = refs.get(tok, 0) + 1
    changed = False
    for p in range(len(ins) - 1):
        bi, bl = ins[p]
        body = _srd_body(bl)
        mn = body.split(None, 1)[0].lower()
        if not _SRD_COND.match(mn) or bi not in nr or ins[p + 1][0] not in nr:
            continue
        lab = split_ops(body.split(None, 1)[1])[-1].strip()
        if lab not in labdef or refs.get(lab) != 1:
            continue
        sbody = _srd_body(ins[p + 1][1])
        sk = _sm_srckey(sbody)
        if not isinstance(sk, tuple) or _sm_mem(_sm_dep_body(sbody)) \
                or ocount.get(sk, 0) <= tcount.get(sk, 0):
            continue
        sd, su = defs_uses(_sm_dep_body(sbody))
        sd, su = set(sd), set(su)
        if not sd or sd & su or "at" in sd | su:
            continue
        li = labdef[lab]
        # the only entrant: the insn before the label is an unconditional jump's slot
        prev = [q for q in range(len(ins)) if ins[q][0] < li]
        if len(prev) < 2:
            continue
        pj = _srd_body(ins[prev[-2]][1]).split(None, 1)[0].lower()
        if pj not in ("j", "b", "jr"):
            continue
        if any(_s_is_label(lines[y]) and refs.get(lines[y].strip()[:-1], 0)
               for y in range(ins[prev[-1]][0] + 1, li)):
            continue
        q = prev[-1] + 1
        while q < len(ins):
            xi, xl = ins[q]
            if xi in nr or any(_s_is_label(lines[y]) and refs.get(lines[y].strip()[:-1], 0)
                               for y in range(li + 1, xi)):
                break
            xb = _srd_body(xl)
            if is_branch(xb):
                break
            if xb == sbody:
                lines[xi] = ""
                ocount[sk] -= 1
                changed = True
                break
            xd, _xu = defs_uses(_sm_dep_body(xb))
            if set(xd) & (sd | su):
                break
            q += 1
    return "\n".join(lines) if changed else stext



# --------------------------------------------------------------------------
# range_unswap: jump.c's "if (foo) bar; else break;" rule swapped two ranges of
# a case tree in our cc1: `bc X,L1 <slot>; RIGHT ... j D; L1: LEFT; <body>`
# (LEFT, a run of range tests, falls into the case body whose label died).
# Retail kept expand's order: `binv X,L1 <slot>; LEFT; j L2; L1: RIGHT ... j D;
# L2: <body>`. The rewrite inverts the branch, moves LEFT up and adds `j L2`
# (+2 words with its nop). Sound: L1 has the branch as its only entrant, RIGHT
# ends in an unconditional jump, the slot runs on both paths as before, LEFT is
# only compares / moves / conditional branches (no fall-through change for the
# body: it is still entered at the same insn). Target-guided: the target has
# the rewritten mnemonic sequence (branch, slot, LEFT, j, RIGHT) and ours not.
# --------------------------------------------------------------------------
_RUS_INV = {"beq": "bne", "bne": "beq", "beqz": "bnez", "bnez": "beqz", "blez": "bgtz",
            "bgtz": "blez", "bltz": "bgez", "bgez": "bltz"}
_RUS_ALU = ("slt", "slti", "sltu", "sltiu", "li", "move", "addu", "addiu", "subu", "andi",
            "ori", "xori", "sll", "srl", "sra")


def _rus_mn(body):
    p = body.split(None, 1)
    if not p:
        return None
    op = p[0].lower()
    ops = [norm_reg(o.strip()) or o.strip() for o in split_ops(p[1])] if len(p) > 1 else []
    if op in ("beq", "bne") and len(ops) == 3 and "zero" in ops[:2]:
        return op + "z"
    if op in ("addiu", "ori") and len(ops) == 3 and ops[1] == "zero":
        return "li"
    if op in ("addu", "or") and len(ops) == 3 and ops[2] == "zero":
        return "move"
    if op == "sll" and ops[:1] == ["zero"]:
        return "nop"
    if op in ("slt", "sltu") and len(ops) == 3 and norm_reg(ops[2]) is None:
        return op + "i"
    return op


def _rus_body(l):
    return l.split("#", 1)[0].strip()


def range_unswap_pass(stext, tgt):
    if not tgt:
        return stext
    tmn = [m for m in (_rus_mn(d.strip()) for _w, d in tgt) if m and m != "nop"]
    tstr = " " + " ".join(tmn) + " "
    lines = stext.split("\n")
    changed = True
    nfix = 0
    while changed and nfix < 8:
        changed = False
        ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
        labdef = {}
        for x, l in enumerate(lines):
            if _s_is_label(l):
                labdef[l.strip()[:-1]] = x
        refs = {}
        for _i, l in ins:
            for tok in re.findall(r"[\w.$]+", _rus_body(l)):
                if tok in labdef:
                    refs[tok] = refs.get(tok, 0) + 1
        nr = _noreorder_lines(lines)
        for p in range(len(ins) - 1):
            bi, bl = ins[p]
            body = _rus_body(bl)
            op = body.split(None, 1)[0].lower()
            if op not in _RUS_INV or bi not in nr or ins[p + 1][0] not in nr:
                continue
            ops = split_ops(body.split(None, 1)[1])
            l1 = ops[-1].strip()
            if l1 not in labdef or refs.get(l1) != 1 or labdef[l1] < bi:
                continue
            li1 = labdef[l1]
            # RIGHT: insns after the slot up to the label, ending in `j`
            right = [q for q in range(p + 2, len(ins)) if ins[q][0] < li1]
            if not right:
                continue
            lastr = right[-1]
            jq = lastr
            if ins[lastr][0] in nr and lastr - 1 in right and \
                    _rus_body(ins[lastr - 1][1]).split(None, 1)[0].lower() == "j":
                jq = lastr - 1
            if _rus_body(ins[jq][1]).split(None, 1)[0].lower() != "j":
                continue
            if any(_s_is_label(lines[y]) and refs.get(lines[y].strip()[:-1], 0)
                   for y in range(ins[p + 1][0] + 1, ins[right[0]][0])):
                continue
            # LEFT: from the label, compares / moves / cond branches, through the
            # last cond branch before the first other insn
            q, lastb = right[-1] + 1, None
            while q < len(ins):
                xi, xl = ins[q]
                if any(_s_is_label(lines[y]) and refs.get(lines[y].strip()[:-1], 0)
                       for y in range(li1 + 1, xi)):
                    break
                xm = _rus_body(xl).split(None, 1)[0].lower()
                if xm in _RUS_INV:
                    lastb = q
                    if xi in nr and q + 1 < len(ins) and ins[q + 1][0] in nr:
                        q += 2
                        lastb = q - 1
                        continue
                elif xm not in _RUS_ALU or xi in nr:
                    break
                q += 1
            if lastb is None:
                continue
            # line span of LEFT: from the label line to the end of its last branch
            # (and slot and the .set lines closing it)
            lz = ins[lastb][0]
            while lz + 1 < len(lines) and lines[lz + 1].strip().startswith(".set") \
                    and not lines[lz + 1].strip().endswith("noreorder"):
                lz += 1
            rz = li1 - 1
            ra = ins[p + 1][0] + 1
            while ra <= rz and lines[ra].strip().startswith(".set") \
                    and not lines[ra].strip().endswith("noreorder"):
                ra += 1
            left_lines = lines[li1 + 1:lz + 1]
            right_lines = lines[ra:rz + 1]
            smn = _rus_mn(_rus_body(ins[p + 1][1]))
            lmn = [_rus_mn(_rus_body(l)) for l in left_lines if _s_is_insn(l)]
            rmn = [_rus_mn(_rus_body(l)) for l in right_lines if _s_is_insn(l)]
            inv = _RUS_INV[op]
            newmn = [_rus_mn(inv + " " + body.split(None, 1)[1]), smn] + lmn + ["j"] + rmn
            oldmn = [_rus_mn(body), smn] + rmn + lmn
            newmn = [m for m in newmn if m != "nop"]
            oldmn = [m for m in oldmn if m != "nop"]
            if (" " + " ".join(newmn) + " ") not in tstr or (" " + " ".join(oldmn) + " ") in tstr:
                continue
            l2 = "$Lrus_%d" % bi
            ind = _src_indent(bl)
            lines[bi] = ind + inv + "\t" + body.split(None, 1)[1]
            new = left_lines + [ind + "j\t" + l2, lines[li1]] + right_lines + [l2 + ":"]
            lines[ra:lz + 1] = new
            changed = True
            nfix += 1
            break
    return "\n".join(lines) if nfix else stext



# --------------------------------------------------------------------------
# slot_rethread: our reorg filled a conditional branch slot with S stolen from
# the taken thread (`bc L; S` / fall-through `F; ...` / `L: ...`), retail filled
# it with the fall-through head F (`bc L; F` / `L: ... S ...`). Rewrite: F into
# the slot, S back into L's block (into the explicit load-delay nop after L's
# first insn when there is one, else at L's head). Sound when L has this branch
# as its only entrant and no fall-through into it; S's destination is dead on
# the fall-through after F (S no longer runs there); F is a plain ALU insn that
# does not write what the branch or S reads, and on the taken path F's
# destination is dead at L or F is `move X,Y` with X == Y already holding at
# the branch. Target-guided by conditional-branch ordinal: the target's slot
# is F's key. Count-preserving when S fills a nop, else +1 (the fall-through
# lost F): only the nop form is applied.
# --------------------------------------------------------------------------
_SRT_ALU = {"move", "addu", "addiu", "subu", "li", "lui", "or", "ori", "and", "andi", "xor", "xori",
            "sll", "srl", "sra", "slt", "sltu", "slti", "sltiu", "nor"}


def _srt_body(l):
    return l.split("#", 1)[0].strip()


def _srt_copy_holds(lines, ins, q, x, y, depth=0):
    """`x == y` holds just before insn ins[q] (straight-line walk back, through a
    label entered only by one unconditional `j`, no fall-through into it)."""
    if depth > 4:
        return False
    labs = {}
    for k, l in enumerate(lines):
        if _s_is_label(l):
            labs[l.strip()[:-1]] = k
    p = q - 1
    while p >= 0:
        xi, xl = ins[p]
        # labels between ins[p] and ins[p + 1]
        top = ins[p + 1][0] if p + 1 < len(ins) else len(lines)
        for y2 in range(xi + 1, top):
            if _s_is_label(lines[y2]):
                name = lines[y2].strip()[:-1]
                srcs = [k for k, (_i, l) in enumerate(ins)
                        if re.search(r"(?<![\w$])" + re.escape(name) + r"(?![\w$])", _srt_body(l))]
                if not srcs:
                    continue
                if len(srcs) != 1 or _srt_body(ins[srcs[0]][1]).split(None, 1)[0].lower() != "j":
                    return False
                # no fall-through: ins[p] is a jump's slot or a reorder-mode j
                pm = _srt_body(xl).split(None, 1)[0].lower()
                pm2 = _srt_body(ins[p - 1][1]).split(None, 1)[0].lower() if p else ""
                if not (pm in ("j", "jr", "b") or pm2 in ("j", "jr", "b")):
                    return False
                return _srt_copy_holds(lines, ins, srcs[0], x, y, depth + 1)
        b = _srt_body(xl)
        d, _u = defs_uses(b)
        if x in d or y in d:
            m = re.match(r"move\s+(\$\w+)\s*,\s*(\$\w+)$", b)
            return bool(m) and {norm_reg(m.group(1)), norm_reg(m.group(2))} == {x, y}
        if is_branch(b) and b.split(None, 1)[0].lower() in ("jal", "jalr"):
            return False
        p -= 1
    return False


def slot_rethread_pass(stext, tgt):
    if not tgt:
        return stext
    tb = _tgt_cond_branches(tgt, stext)
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ours = [i for i, l in enumerate(lines)
            if _s_is_insn(l) and l.split(None, 1)[0].lower() in _COND_BR_MN]
    if len(ours) != len(tb):
        return stext
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    pos = {i: k for k, (i, _l) in enumerate(ins)}
    for bi, tk in zip(ours, tb):
        if bi not in nr or tk + 1 >= len(tgt):
            continue
        p = pos[bi]
        if p + 2 >= len(ins) or ins[p + 1][0] not in nr:
            continue
        sb, fb = _srt_body(ins[p + 1][1]), _srt_body(ins[p + 2][1])
        if ins[p + 2][0] in nr or _ts_key(fb) != _ts_key(tgt[tk + 1][1].strip()) \
                or _ts_key(sb) == _ts_key(fb):
            continue
        if fb.split(None, 1)[0].lower() not in _SRT_ALU or sb.split(None, 1)[0].lower() not in _SRT_ALU:
            continue
        if any(_s_is_label(lines[y]) and not lines[y].strip().startswith("LM")
               for y in range(ins[p + 1][0] + 1, ins[p + 2][0])):
            continue
        lab = _lc_label(_srt_body(lines[bi]))
        at = next((k for k, l in enumerate(lines) if l.strip() == (lab or "?") + ":"), None)
        if at is None:
            continue
        nref = sum(1 for _i, l in ins if re.search(r"(?<![\w$])" + re.escape(lab) + r"(?![\w$])",
                                                   _srt_body(l)))
        if nref != 1:
            continue
        pa = [k for k, (i, _l) in enumerate(ins) if i < at]
        if len(pa) < 2:
            continue
        m1 = _srt_body(ins[pa[-1]][1]).split(None, 1)[0].lower()
        m2 = _srt_body(ins[pa[-2]][1]).split(None, 1)[0].lower()
        if not ((ins[pa[-1]][0] in nr and m2 in ("j", "jr", "b"))
                or (ins[pa[-1]][0] not in nr and m1 in ("j", "jr", "b"))):
            continue
        bd, bu = defs_uses(_srt_body(lines[bi]))
        fd, fu = defs_uses(fb)
        sd, su = defs_uses(sb)
        if len(fd) != 1 or len(sd) != 1 or set(fd) & (set(bu) | set(su)) or set(sd) & set(fu):
            continue
        # S's destination dead on the fall-through after F
        l2 = lines[:ins[p + 2][0] + 1] + ["$Lsrt_f:"] + lines[ins[p + 2][0] + 1:]
        ins2 = [(q, x) for q, x in enumerate(l2) if _s_is_insn(x)]
        if not all(_ff_dead_on(l2, ins2, "$Lsrt_f", r, callee_args=False) for r in sd):
            continue
        # F on the taken path: dead at L, or a copy that already holds
        fr = list(fd)[0]
        if not _ff_dead_on(lines, ins, lab, fr, callee_args=False):
            m = re.match(r"move\s+(\$\w+)\s*,\s*(\$\w+)$", fb)
            if not (m and _srt_copy_holds(lines, ins, p, norm_reg(m.group(1)), norm_reg(m.group(2)))):
                continue
        # where S goes: the explicit nop after L's first insn (a load)
        xs = [k for k, (i, _l) in enumerate(ins) if i > at]
        if len(xs) < 2 or ins[xs[0]][0] in nr or ins[xs[1]][0] in nr:
            continue
        b0 = _srt_body(ins[xs[0]][1])
        if not re.match(r"(lw|lh|lhu|lb|lbu)\s", b0) or _srt_body(ins[xs[1]][1]) != "nop":
            continue
        d0, u0 = defs_uses(b0)
        if set(sd) & (set(d0) | set(u0)) or set(su) & set(d0):
            continue
        ind = _src_indent(ins[p + 1][1])
        lines[ins[xs[1]][0]] = ind + sb
        lines[ins[p + 1][0]] = ind + fb
        lines[ins[p + 2][0]] = ""
        return slot_rethread_pass("\n".join(lines), tgt)
    return stext



# --------------------------------------------------------------------------
# const_uncse: our cse kept a small constant from a compare (`li $sK,C; beq
# x,$sK,L`) live into a later use across a call, so it went to a callee-saved
# register; retail's cse did not (the compare's block ended there) and built
# C again at each use in a temp (`li v0,C; beq x,v0,L` ... `li v0,C; sh v0,..`).
# Rewrite: every use of the web gets its own `li T,C` right before it (before
# its branch when the use sits in a delay slot) with T a caller-saved register
# dead there and unmentioned by the use / branch, and the original li goes.
# Target-guided: the target builds C with `li` at least as often as ours will,
# and never holds C in an s-register. The web must be the li's alone (single
# def, not pinned) and sK must still be used by other webs (frame unchanged).
# Count-changing (+uses-1): pre-sigma.
# --------------------------------------------------------------------------
_CUN_LI = re.compile(r"^\s*li\s+\$(1[6-9]|2[0-3])\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)\s*(?:#.*)?$")
_CUN_T = ("v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9")


def const_uncse_pass(stext, tgt):
    if not tgt:
        return stext
    tli, tsli = {}, set()
    for _w, d in tgt:
        p = d.strip().split(None, 1)
        if len(p) < 2:
            continue
        ops = [o.strip() for o in split_ops(p[1])]
        if p[0].lower() in ("addiu", "ori") and len(ops) == 3 and norm_reg(ops[1]) == "zero":
            try:
                v = int(ops[2], 0)
            except ValueError:
                continue
            tli[v] = tli.get(v, 0) + 1
            if (norm_reg(ops[0]) or "").startswith("s"):
                tsli.add(v)
    lines = stext.split("\n")
    oli = {}
    for l in lines:
        m = re.match(r"^\s*li\s+(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)\s*(?:#.*)?$", l)
        if m:
            v = int(m.group(2), 0)
            oli[v] = oli.get(v, 0) + 1
    cands = [i for i, l in enumerate(lines) if _CUN_LI.match(l)]
    if not cands:
        return stext
    nodes, ok = _wr_nodes(lines)
    if not ok:
        return stext
    occ, pinned, reg_of, LO, def_w = _wr_webs(nodes)
    use_w = [set() for _ in nodes]
    for (n, r, pos, kd), w in occ.items():
        if kd == "u":
            use_w[n].add(w)
    LI = [use_w[n] | (LO[n] - def_w[n]) for n in range(len(nodes))]
    lnode = {nd["line"]: n for n, nd in enumerate(nodes) if nd["line"] is not None}
    nr = _noreorder_lines(lines)
    edits = []
    for i in cands:
        m = _CUN_LI.match(lines[i])
        v = int(m.group(2), 0)
        r = norm_reg("$" + m.group(1))
        n = lnode.get(i)
        if n is None or v in tsli:
            continue
        w = occ.get((n, r, 0, "d"))
        if w is None or w in pinned:
            continue
        defs = [k for k, x in occ.items() if x == w and k[3] == "d"]
        uses = [k for k, x in occ.items() if x == w and k[3] == "u"]
        if len(defs) != 1 or len(uses) < 2 or any(k[2] is None for k in uses):
            continue
        if tli.get(v, 0) < oli.get(v, 0) + len(uses) - 1:
            continue
        # sK still used by another web
        if not any(x != w and reg_of.get(x) == r and k[2] is not None for k, x in occ.items()):
            continue
        plan = []
        for un, _r, pos, _kd in sorted(uses):
            ul = nodes[un]["line"]
            at, bn = ul, un
            if ul in nr:
                prv = [y for y in range(ul - 1, -1, -1) if _s_is_insn(lines[y])]
                if prv and is_branch(lines[prv[0]].split("#", 1)[0].strip()) and prv[0] in nr:
                    bn = lnode.get(prv[0])
                    at = prv[0]
                    while at > 0 and lines[at - 1].strip().startswith(".set"):
                        at -= 1
                elif prv and prv[0] == i:
                    at = ul
                else:
                    plan = None
                    break
            if bn is None:
                plan = None
                break
            ment = set()
            for y in {ul, nodes[bn]["line"]}:
                d, u = defs_uses(lines[y].split("#", 1)[0].strip())
                ment |= set(d) | set(u)
            live = {reg_of.get(x) for x in LI[bn]}
            t = next((c for c in _CUN_T if c not in live and c not in ment and c != r), None)
            if t is None:
                plan = None
                break
            plan.append((at, ul, pos, t))
        if not plan:
            continue
        edits.append((i, r, v, plan))
    if not edits:
        return stext
    ins_at = []
    for i, r, v, plan in edits:
        ind = _src_indent(lines[i])
        lines[i] = ""
        for at, ul, pos, t in plan:
            ind2, mn, ops, com, rp = _wr_parse(lines[ul])
            ops = list(ops)
            k, par_, _r = rp[pos]
            num = "$%d" % ABI2NUM[t]
            ops[k] = re.sub(r"\(\$\w+\)$", "(%s)" % num, ops[k]) if par_ else num
            body = lines[ul].split("#", 1)[0].strip().split(None, 1)[0]
            lines[ul] = "%s%s\t%s%s" % (ind2, body, ",".join(ops), ("\t#" + com) if com else "")
            ins_at.append((at, "%sli\t%s,%d" % (ind, num, v)))
    for at, txt in sorted(ins_at, key=lambda x: -x[0]):
        lines.insert(at, txt)
    return "\n".join(lines)



# --------------------------------------------------------------------------
# la_unhoist: loop.c hoisted `la R,S` (into the prologue) whose only reads are
# load bases `lw X,k(R)`; retail builds S at each read (`lui X,%hi(S+k);
# lw X,%lo(S+k)(X)`) and has no `la` of S. Target-guided: the target loads
# through %lo(S) and never forms S's address. R must be written only by the la
# and read only as a load base by loads whose destination is not R. Deletes the
# la, expands each read. Count-changing: pre-sigma.
# --------------------------------------------------------------------------
_LAU_LD = re.compile(r"^(\s*)(lw|lh|lhu|lb|lbu)(\s+)(\$\w+)\s*,\s*(-?\d+)\((\$\w+)\)\s*$")


def la_unhoist_pass(stext, tgt):
    if not tgt:
        return stext
    tla, tmem = set(), set()
    for _w, d in tgt:
        m = re.search(r"%lo\(([^)]+)\)\(", d)
        if m:
            tmem.add(m.group(1).strip())
        a = re.search(r"addiu\s+\$?\w+\s*,\s*\$?\w+\s*,\s*%lo\(([^)]+)\)", d)
        if a:
            tla.add(a.group(1).strip())
    lines = stext.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    rep, dele = {}, set()
    for i, l in ins:
        m = _LSP_LA.match(l.split("#", 1)[0])
        if not m or m.group(4):
            continue
        r, sym = norm_reg(m.group(2)), m.group(3)
        if sym in tla or sym not in tmem:
            continue
        uses, ok = [], True
        for j, x in ins:
            if j == i:
                continue
            body = x.split("#", 1)[0].strip()
            if re.match(r"jalr?\b", body):
                continue
            d, u = defs_uses(body)
            if r in d or r in u:
                mm = _LAU_LD.match(x.split("#", 1)[0].rstrip())
                if not mm or norm_reg(mm.group(6)) != r or norm_reg(mm.group(4)) == r:
                    ok = False
                    break
                uses.append(j)
        if not ok or not uses:
            continue
        dele.add(i)
        for j in uses:
            mm = _LAU_LD.match(lines[j].split("#", 1)[0].rstrip())
            ind, op, sp, x, off = mm.group(1), mm.group(2), mm.group(3), mm.group(4), int(mm.group(5))
            e = sym if off == 0 else "%s+%d" % (sym, off)
            rep[j] = ["%slui\t%s,%%hi(%s)" % (ind, x, e), "%s%s%s%s,%%lo(%s)(%s)" % (ind, op, sp, x, e, x)]
    if not rep:
        return stext
    out = []
    for i, l in enumerate(lines):
        if i in dele:
            continue
        out.extend(rep.get(i, [l]))
    return "\n".join(out)


# --------------------------------------------------------------------------
# param_copy_fresh: param_copy into a register the function never mentions
# (sigma names it afterwards). For an entry-argument web that spans a loop
# (`p = p->super`), the target's copy register is busy before sigma.
# --------------------------------------------------------------------------
_PC_FRESH = [None]


def param_copy_fresh_pass(stext, tgt):
    used = set()
    for l in stext.split("\n"):
        if _s_is_insn(l):
            for t in re.findall(r"\$\w+", l.split("#", 1)[0]):
                if norm_reg(t):
                    used.add(norm_reg(t))
    fr = next((r for r in ("t6", "t7", "t8", "t9", "t5", "t4", "t3", "t2", "t1", "t0")
               if r not in used), None)
    if fr is None:
        return stext
    _PC_FRESH[0] = fr
    try:
        return param_copy_pass(stext, tgt)
    finally:
        _PC_FRESH[0] = None


# --------------------------------------------------------------------------
# li_uncopy: cse turned `li X,C` into `move X,Y` because Y was set to C earlier
# on the same straight line; retail keeps both li. Target-guided: the target
# builds C with li more often than ours. Count-preserving (li of a 16-bit C).
# --------------------------------------------------------------------------
_LIU_MV = re.compile(r"^(\s*)move\s+(\$\w+)\s*,\s*(\$\w+)\s*$")
_LIU_LI = re.compile(r"^\s*li\s+(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)\s*$")


def li_uncopy_pass(stext, tgt):
    if not tgt:
        return stext
    tli = {}
    for _w, d in tgt:
        m = re.match(r"^\s*(?:li|addiu)\s+\$\w+\s*,\s*(?:\$(?:0|zero)\s*,\s*)?(-?\d+|-?0x[0-9A-Fa-f]+)\s*$",
                     d.strip())
        if m:
            k = int(m.group(1), 0)
            tli[k] = tli.get(k, 0) + 1
    lines = stext.split("\n")
    oli = {}
    for l in lines:
        m = _LIU_LI.match(l.split("#", 1)[0].rstrip())
        if m:
            k = int(m.group(2), 0)
            oli[k] = oli.get(k, 0) + 1
    ch = False
    for i, l in enumerate(lines):
        m = _LIU_MV.match(l.split("#", 1)[0].rstrip())
        if not m:
            continue
        y = norm_reg(m.group(3))
        for j in range(i - 1, -1, -1):
            x = lines[j].split("#", 1)[0].strip()
            if x.endswith(":"):
                if x.startswith("LM"):
                    continue
                break
            if not x or x.startswith("."):
                continue
            if _src_is_branch(lines[j]) or re.match(r"jalr?\b", x):
                break
            ml = _LIU_LI.match(x)
            if ml and norm_reg(ml.group(1)) == y:
                k = int(ml.group(2), 0)
                if -0x8000 <= k < 0x8000 and tli.get(k, 0) > oli.get(k, 0):
                    lines[i] = "%sli\t%s,%s" % (m.group(1), m.group(2), ml.group(2))
                    oli[k] = oli.get(k, 0) + 1
                    ch = True
                break
            d, u = defs_uses(x)
            if y in d:
                break
    return "\n".join(lines) if ch else stext



# --------------------------------------------------------------------------
# zst_place: sched1 hoists a store of $zero into a frame slot (a counter set to
# 0, a const-0 pseudo) or a small `li R,C` to one end of its block; retail
# kept it among the block's loads in source order. Moves each such store (`sw/sh/sb $0,k($sp)`)
# (or `li R,C`, R untouched by what it passes) down or up in its straight-line block to just after the insn the target
# has right before it. Sound: the store reads only $sp; nothing it passes
# touches the frame bytes [k, k+size) or $sp, and no label / branch / call is
# crossed. Target-guided: the target's store nearest our word position and its
# predecessor's key. Count-preserving; post-sigma (keys compare registers).
# --------------------------------------------------------------------------
_ZSP_ST = re.compile(r"^\s*(sw|sh|sb)\s+\$(?:0|zero)\s*,\s*(-?\d+)\(\$(?:sp|29)\)\s*$")


def _zsp_norm(body):
    """Mnemonic + normalized operands (ABI registers, decimal numbers)."""
    p = body.strip().split(None, 1)
    if not p:
        return ""
    ops = []
    for o in (split_ops(p[1]) if len(p) > 1 else []):
        o = re.sub(r"\$\w+", lambda m: norm_reg(m.group(0)) or m.group(0), o.strip())
        o = re.sub(r"(?<![\w$])(-?)0x([0-9A-Fa-f]+)", lambda m: str(int(m.group(1) + m.group(2), 16)), o)
        ops.append(o.replace(" ", ""))
    mn = p[0].lower()
    if mn in ("addiu", "ori") and len(ops) == 3 and ops[1] == "zero":
        mn, ops = "li", [ops[0], ops[2]]
    elif mn in ("addu", "or") and len(ops) == 3 and ops[2] == "zero":
        mn, ops = "move", ops[:2]
    return mn + " " + ",".join(ops)


def zst_place_pass(stext, tgt):
    if not tgt:
        return stext
    tn = [_zsp_norm(d) for _w, d in tgt]
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    changed = False
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    wpos, w = {}, 0
    for i, l in ins:
        wpos[i] = w
        w += _src_nwords(l)
    # drift anchors: our insns whose key occurs once in the target
    cnt = {}
    for x in tn:
        cnt[x] = cnt.get(x, 0) + 1
    anc = []
    for i, l in ins:
        kx = _zsp_norm(l.split("#", 1)[0])
        if cnt.get(kx) == 1:
            anc.append((i, tn.index(kx) - wpos[i]))
    for q in range(len(ins)):
        i, l = ins[q]
        b = l.split("#", 1)[0].strip()
        m = _ZSP_ST.match(b)
        ml = re.match(r"li\s+(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)$", b)
        if not (m or ml) or i in nr:
            continue
        lr = norm_reg(ml.group(1)) if ml else None
        if ml and (lr is None or _src_nwords(l) != 1):
            continue
        k, sz = (int(m.group(2)), {"sw": 4, "sh": 2, "sb": 1}[m.group(1)]) if m else (0, 0)
        key = _zsp_norm(b)
        occ = [t for t, x in enumerate(tn) if x == key]
        if not occ:
            continue
        dr = [dd for ai, dd in anc if ai < i]
        est = wpos[i] + (dr[-1] if dr else 0)
        t = min(occ, key=lambda t: abs(t - est))
        if abs(t - est) > 12:
            continue
        p = t - 1
        while p >= 0 and tn[p] == "nop":
            p -= 1
        if p < 0:
            continue
        pk = tn[p]
        # the insn in ours with key pk, in the same straight line, nearest q
        best = None
        for dirn in (1, -1):
            r = q + dirn
            while 0 <= r < len(ins):
                ri, rl = ins[r]
                lo, hi = (i, ri) if ri > i else (ri, i)
                if any(_s_is_label(lines[y]) and not lines[y].strip().startswith("LM")
                       for y in range(lo + 1, hi + 1 if dirn == 1 else hi)):
                    break
                rb = rl.split("#", 1)[0].strip()
                if ri in nr or is_branch(rb):
                    break
                d, u = defs_uses(rb)
                if "sp" in d or (lr and (lr in d or lr in u)):
                    break
                mm = None if lr else re.search(r"(-?\d+)\(\$(?:sp|29)\)", rb)
                if mm and re.match(r"(lw|lh|lhu|lb|lbu|sw|sh|sb|lwl|lwr|swl|swr)\s", rb):
                    o = int(mm.group(1))
                    osz = 4 if rb.split()[0] in ("lw", "sw", "lwl", "lwr", "swl", "swr") else \
                        2 if rb.split()[0] in ("lh", "lhu", "sh") else 1
                    if rb.split()[0] in ("lwl", "swl"):
                        o -= 3
                    if o < k + sz and k < o + osz:
                        break
                if _zsp_norm(rb) == pk:
                    best = r
                    break
                r += dirn
            if best is not None:
                break
        if best is None or best == q - 1:
            continue
        txt = lines[i]
        bi = ins[best][0]
        if bi > i:
            lines.insert(bi + 1, txt)
            del lines[i]
        else:
            del lines[i]
            lines.insert(bi + 1, txt)
        changed = True
        return zst_place_pass("\n".join(lines), tgt)
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# sreg_const_use: `addu R,X,C` / `addiu R,X,C` where the callee-saved sK is
# known to hold C here (every path reaching the insn last set sK with `li sK,C`,
# e.g. in the branch slot that leads to a single-entrant label); retail's cse
# used the register (`addu R,X,sK`). Target-guided: the target has
# `addu R,X,sK` (either operand order) near our position (the rewrite is
# sound on its own: sK holds C on every path).
# Count-preserving; post-sigma.
# --------------------------------------------------------------------------
_SCU_ADD = re.compile(r"^(\s*)(addu|addiu)\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)\s*$")


def _scu_known(lines, ins, q, reg, refs, nr, depth=0):
    """Value of `reg` just before ins[q] if every reaching def is `li reg,C`."""
    if depth > 4:
        return None
    p = q - 1
    while p >= 0:
        xi, xl = ins[p]
        top = ins[p + 1][0]
        for y in range(xi + 1, top):
            if _s_is_label(lines[y]) and not lines[y].strip().startswith("LM"):
                name = lines[y].strip()[:-1]
                srcs = refs.get(name, [])
                if not srcs:
                    continue
                if len(srcs) != 1:
                    return None
                # no fall-through into the label
                pm = xl.split("#", 1)[0].strip().split(None, 1)[0].lower()
                pm2 = ins[p - 1][1].split("#", 1)[0].strip().split(None, 1)[0].lower() if p else ""
                if not ((xi in nr and pm2 in ("j", "b", "jr")) or (xi not in nr and pm in ("j", "b", "jr"))):
                    return None
                sq = srcs[0]
                # the branch's slot runs on the taken path
                if ins[sq][0] in nr and sq + 1 < len(ins) and ins[sq + 1][0] in nr:
                    return _scu_known(lines, ins, sq + 2, reg, refs, nr, depth + 1)
                return _scu_known(lines, ins, sq + 1, reg, refs, nr, depth + 1)
        b = xl.split("#", 1)[0].strip()
        d, _u = defs_uses(b)
        if reg in d:
            m = re.match(r"li\s+(\$\w+)\s*,\s*(-?\d+|-?0x[0-9A-Fa-f]+)$", b)
            if m and norm_reg(m.group(1)) == reg:
                return int(m.group(2), 0)
            return None
        if re.match(r"jalr?\s", b) and reg not in ("s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp"):
            return None
        p -= 1
    return None


def sreg_const_use_pass(stext, tgt):
    if not tgt:
        return stext
    tadd = []
    for t, (_w, d) in enumerate(tgt):
        pr = d.strip().split(None, 1)
        if len(pr) == 2 and pr[0].lower() == "addu":
            ops = [norm_reg(o.strip()) for o in split_ops(pr[1])]
            if len(ops) == 3 and all(ops) and any(o in ("s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp")
                                                 for o in ops[1:]):
                tadd.append((t, ops))
    if not tadd:
        return stext
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    labs = {l.strip()[:-1] for l in lines if _s_is_label(l)}
    refs = {}
    for k, (_i, l) in enumerate(ins):
        for tok in re.findall(r"[\w.$]+", l.split("#", 1)[0]):
            if tok in labs:
                refs.setdefault(tok, []).append(k)
    wpos, w = {}, 0
    for i, l in ins:
        wpos[i] = w
        w += _src_nwords(l)
    changed = False
    for q, (i, l) in enumerate(ins):
        m = _SCU_ADD.match(l.split("#", 1)[0].rstrip())
        if not m:
            continue
        r, x, c = norm_reg(m.group(3)), norm_reg(m.group(4)), int(m.group(5), 0)
        for t, ops in tadd:
            if abs(t - wpos[i]) > 100 or ops[0] != r:
                continue
            sk = ops[2] if ops[1] == x else ops[1] if ops[2] == x else None
            if sk is None or sk == x or _scu_known(lines, ins, q, sk, refs, nr) != c:
                continue
            lines[i] = "%saddu\t%s,%s,$%d" % (m.group(1), m.group(3), m.group(4), ABI2NUM[sk])
            changed = True
            break
    return "\n".join(lines) if changed else stext


# --------------------------------------------------------------------------
# dead_spill: reload spilled a pseudo whose every reload is dead (a loop
# invariant loop.c hoisted for a test flow later found useless): ours keeps
# `OP T,X,C; ...; sw T,k($sp)` in the preheader and a dead `lw R,k($sp)`,
# retail kept the invariant in a callee-saved register that nothing reads
# (`OP sK,X,C`) and its frame slot k has no insns at all. Rewrites D's dest to
# sK and deletes the store and the dead reloads. Sound: the loaded values are
# dead, the slot has no other reference, T's only reader was the store, sK is
# saved by the prologue and never read after D (no branch after D reaches back
# above it). Target-guided: the target has `OP sK,X,C` near our word position
# and no reference to frame bytes [k, k+4). Post-sigma (keys compare registers).
# --------------------------------------------------------------------------
_DSP_SW = re.compile(r"^\s*sw\s+(\$\w+)\s*,\s*(-?\d+)\(\$(?:sp|29)\)\s*$")
_DSP_LW = re.compile(r"^\s*lw\s+(\$\w+)\s*,\s*(-?\d+)\(\$(?:sp|29)\)\s*$")
_DSP_IMM = {"addu": "addiu", "sltu": "sltiu", "slt": "slti", "and": "andi", "or": "ori", "xor": "xori"}
_DSP_SREGS = ("s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp")
_DSP_MEMSZ = {"lw": 4, "sw": 4, "lwl": 4, "lwr": 4, "swl": 4, "swr": 4,
              "lh": 2, "lhu": 2, "sh": 2, "lb": 1, "lbu": 1, "sb": 1}


def _dsp_key(body):
    k = _zsp_norm(body)
    mn, _, ops = k.partition(" ")
    o = ops.split(",") if ops else []
    if mn in _DSP_IMM and len(o) == 3 and re.match(r"-?\d+$", o[2]):
        mn = _DSP_IMM[mn]
    return mn + " " + ",".join(o)


def _dsp_frame_refs(bodies, k):
    """Indexes of bodies touching frame bytes [k, k+4)."""
    refs = []
    for i, b in bodies:
        m = re.search(r"(-?\d+)\(\$(?:sp|29)\)", b)
        mn = b.split(None, 1)[0].lower()
        if m and mn in _DSP_MEMSZ:
            o = int(m.group(1))
            if mn in ("lwl", "swl"):
                o -= 3
            if o < k + 4 and k < o + _DSP_MEMSZ[mn]:
                refs.append(i)
            continue
    return refs


def _dsp_tgt_refs(tgt, k):
    for _w, d in tgt:
        b = d.strip()
        m = re.search(r"(-?0x[0-9A-Fa-f]+|-?\d+)\(\$(?:sp|29)\)", b)
        mn = b.split(None, 1)[0].lower() if b else ""
        if m and mn in _DSP_MEMSZ:
            o = int(m.group(1), 0)
            if mn in ("lwl", "swl"):
                o -= 3
            if o < k + 4 and k < o + _DSP_MEMSZ[mn]:
                return True
    return False


def dead_spill_pass(stext, tgt):
    if not tgt:
        return stext
    tk = [_dsp_key(d) for _w, d in tgt]
    lines = stext.split("\n")
    nr = _noreorder_lines(lines)
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    bodies = [(i, l.split("#", 1)[0].strip()) for i, l in ins]
    wpos, w = {}, 0
    for i, l in ins:
        wpos[i] = w
        w += _src_nwords(l)
    labpos = {lines[y].strip()[:-1]: y for y in range(len(lines))
              if _s_is_label(lines[y]) and not lines[y].strip().startswith("LM")}
    saved = set()
    for _i, b in bodies:
        m = _DSP_SW.match(b)
        if m:
            saved.add(norm_reg(m.group(1)))
    for q, (si, sb) in enumerate(bodies):
        m = _DSP_SW.match(sb)
        if not m or si in nr:
            continue
        t, k = norm_reg(m.group(1)), int(m.group(2))
        if t in (None, "zero", "sp", "ra") or t in _DSP_SREGS or _dsp_tgt_refs(tgt, k):
            continue
        refs = _dsp_frame_refs(bodies, k)
        if any(r < 0 for r in refs) or refs.count(si) != 1:
            continue
        loads = [r for r in refs if r != si]
        if not loads or not all(_DSP_LW.match(dict(bodies)[r]) and r not in nr for r in loads):
            continue
        if any(_bi_live_after(lines, r, norm_reg(_DSP_LW.match(dict(bodies)[r]).group(1))) for r in loads):
            continue
        # D: the def of T on the same straight line above the store
        d = None
        for p in range(q - 1, -1, -1):
            pi, pb = bodies[p]
            if any(_s_is_label(lines[y]) and not lines[y].strip().startswith("LM") for y in range(pi + 1, si)):
                break
            if pi in nr or _src_is_branch(lines[pi]) or re.match(r"jalr?\s", pb):
                break
            dd, uu = defs_uses(pb)
            if t in dd:
                d = p
                break
            if t in uu:
                break
        if d is None:
            continue
        di, db = bodies[d]
        dd, uu = defs_uses(db)
        md = re.match(r"(\w+)\s+(\$\w+)\s*,(.*)$", db)
        if dd != {t} or not md or norm_reg(md.group(2)) != t or t in uu or _src_nwords(lines[di]) != 1:
            continue
        if any(t in defs_uses(bodies[x][1])[1] for x in range(d + 1, q)):
            continue
        if _bi_live_after(lines, si, t):
            continue
        for sk in _DSP_SREGS:
            if sk not in saved:
                continue
            nb = "%s\t$%d,%s" % (md.group(1), ABI2NUM[sk], md.group(3))
            key = _dsp_key(nb)
            occ = [x for x, y in enumerate(tk) if y == key]
            if not occ or min(abs(x - wpos[di]) for x in occ) > 40:
                continue
            # sK never read after D, no branch after D back above it
            ok = True
            for x in range(d + 1, len(bodies)):
                xi, xb = bodies[x]
                if sk in defs_uses(xb)[1]:
                    ok = False
                    break
                for tok in re.findall(r"[\w.$]+", xb):
                    if tok in labpos and labpos[tok] <= di:
                        ok = False
                if not ok:
                    break
            if not ok:
                continue
            ind = re.match(r"^(\s*)", lines[di]).group(1)
            lines[di] = ind + nb
            for r in sorted(loads + [si], reverse=True):
                del lines[r]
            return dead_spill_pass("\n".join(lines), tgt)
    return stext


# --------------------------------------------------------------------------
# arg_unrename: a global register map (reg_realloc_inj) sends an argument register
# to another register because a LATER web in that argument register pairs with it
# (e.g. a1 holds the incoming arg at entry and an unrelated constant in the loop);
# the entry-block read of the argument then reads a register nothing defined yet
# (`move s3,t9`). In the entry block (straight line from the function label), a
# read of a caller-saved temporary that no earlier insn of the block defined is
# the renamed argument: where the target insn at the same word differs only in
# that operand and names an argument register aK (not redefined before), read aK.
# Post-sigma; sound: only a read of a value that is undefined in our text changes.
# --------------------------------------------------------------------------
_ARGU_TMP = {"v0", "v1", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9"}


def arg_unrename_pass(stext, tgt):
    if not tgt:
        return stext
    lines = stext.split("\n")
    ent = next((i for i, l in enumerate(lines) if re.match(r"\s*\.ent\s", l)), None)
    if ent is None:
        return stext
    nr = _noreorder_lines(lines)
    defined, argdef = set(), set()
    w = 0
    changed = False
    seen_label = False
    for i in range(ent + 1, len(lines)):
        l = lines[i]
        if _s_is_label(l):
            if seen_label and not l.strip().startswith(("LM", "$LM", "$Lb")):
                break
            seen_label = True
            continue
        if not _s_is_insn(l):
            continue
        body = l.split("#", 1)[0].strip()
        if _src_is_branch(l) or _src_is_ret(l) or re.match(r"jalr?\s", body) or i in nr:
            break
        d, u = defs_uses(body)
        for r in sorted(u):
            if r not in _ARGU_TMP or r in defined or w >= len(tgt):
                continue
            tb = tgt[w][1].strip()
            ok = False
            for ak in ("a0", "a1", "a2", "a3"):
                if ak in argdef:
                    continue
                cand = re.sub(r"\$(\w+)", lambda m: "$%d" % ABI2NUM[ak]
                              if norm_reg("$" + m.group(1)) == r else m.group(0), body)
                if _zsp_norm(cand) == _zsp_norm(tb):
                    lines[i] = l.replace(body, cand)
                    body, ok = cand, True
                    break
            if ok:
                changed = True
                d, u = defs_uses(body)
        defined |= set(d)
        argdef |= set(d) & {"a0", "a1", "a2", "a3"}
        w += _src_nwords(l)
    return "\n".join(lines) if changed else stext



# --------------------------------------------------------------------------
# Loop helpers for giv_unreduce / const_unhoist: a loop is a `$L:` label with a
# conditional branch back to it from below; its region runs from the label to
# that branch (plus the delay slot). The loop must be entered only at the label:
# no branch from outside the region may target a label inside it.
# --------------------------------------------------------------------------
_GU_LAB = re.compile(r"^\s*(\$L\w+):\s*$")


def _gu_loops(lines):
    """[(head_line, end_line)] for loops entered only at their head label."""
    labs = {}
    for i, l in enumerate(lines):
        m = _GU_LAB.match(l)
        if m:
            labs[m.group(1)] = i
    refs = {}
    for i, l in enumerate(lines):
        if not _s_is_insn(l):
            continue
        t = re.search(r"[\s,](\$L\w+)\s*$", l.split("#", 1)[0])
        if t:
            refs.setdefault(t.group(1), []).append(i)
    out = []
    for lab, h in labs.items():
        back = [y for y in refs.get(lab, []) if y > h]
        if not back or any(y < h for y in refs.get(lab, [])):
            continue
        e = max(back)
        e2 = e + 1
        while e2 < len(lines) and not _s_is_insn(lines[e2]):
            e2 += 1
        inner = {x for x, y in labs.items() if h < y <= e}
        if any((y < h or y > e2) and _s_is_insn(lines[y]) and re.search(
                r"[\s,](\$L\w+)\s*$", lines[y].split("#", 1)[0]) and re.search(
                r"[\s,](\$L\w+)\s*$", lines[y].split("#", 1)[0]).group(1) in inner
                for y in range(len(lines))):
            continue
        out.append((h, e2))
    return out


def _gu_du(l):
    return defs_uses(l.split("#", 1)[0].strip())


def _gu_tgt_loops(tgt):
    """[(first, last)] index ranges of the target's loops (backward branches)."""
    out = []
    for q, (w, d) in enumerate(tgt):
        mn = d.split(None, 1)[0].lower() if d.strip() else ""
        if not is_branch(mn + " ") or mn in ("j", "jal", "jr", "jalr"):
            continue
        try:
            off = int(w, 16) & 0xFFFF
        except ValueError:
            continue
        if off & 0x8000:
            off -= 0x10000
        if off < 0:
            out.append((q + 1 + off, q + 1))
    return out


def _gu_preheader(lines, h):
    """Line indexes of the insns of the block that falls into loop head h
    (walking back from h to the previous label or branch)."""
    out = []
    y = h - 1
    while y >= 0:
        l = lines[y]
        if _GU_LAB.match(l):
            break
        if _s_is_insn(l):
            if _src_is_branch(l):
                break
            out.append(y)
        y -= 1
    return out[::-1]


def _gu_place(lines, h, tgt, tq, ta):
    """Line after which to insert, in our loop-head block starting at label h, the insn that
    is target insn tq of the target loop starting at ta: after as many of our insns as the
    target has non-nop insns between ta and tq (falls back to the label, stops at a branch)."""
    k = sum(1 for _w, d in tgt[ta:tq] if d.strip() != "nop")
    at, n = h, 0
    y = h + 1
    while n < k and y < len(lines):
        l = lines[y]
        if _GU_LAB.match(l):
            break
        if _s_is_insn(l):
            if _src_is_branch(l):
                break
            n += 1
            at = y
        y += 1
    return at


_GU_ADDK = re.compile(r"^(\s*)addi?u\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*$")


# --------------------------------------------------------------------------
# giv_unreduce: loop.c strength-reduced a combined DEST_ADDR giv G = B + K of the
# biv B (`addu G,B,K` in the preheader, `addu G,G,S` next to the biv's `addu
# B,B,S` in the loop), where retail's loop.c found it not worth reducing and
# recomputes `addiu G,B,K` at the loop top every iteration. Target-guided: the
# target has `addiu X,Y,K` inside one of its loops and fewer `R += S` increments
# than ours. Sound when G has no other definition, is not read after its
# increment inside the loop nor outside the loop (other than by nothing: dead at
# the exits), B is not written between the preheader def and the loop head, and
# the two increments sit in one basic block. -1 insn: pre-sigma.
# --------------------------------------------------------------------------
def giv_unreduce_pass(stext, tgt):
    if not tgt:
        return stext
    tl = _gu_tgt_loops(tgt)
    tk, tinc = {}, {}
    for q, (_w, d) in enumerate(tgt):
        m = re.match(r"^\s*addiu\s+\$(\w+)\s*,\s*\$(\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*$", d.strip())
        if not m:
            continue
        k = int(m.group(3), 0)
        if m.group(1) == m.group(2):
            tinc[k] = tinc.get(k, 0) + 1
        elif m.group(2) not in ("sp", "zero") and any(a <= q < b for a, b in tl):
            tk.setdefault(k, (q, next(a for a, b in tl if a <= q < b)))
    lines = stext.split("\n")
    for h, e in _gu_loops(lines):
        inc = {}
        for y in range(h, e + 1):
            m = _GU_ADDK.match(lines[y].split("#", 1)[0].rstrip())
            if m and norm_reg(m.group(2)) == norm_reg(m.group(3)):
                inc.setdefault(int(m.group(4), 0), []).append(y)
        for y in _gu_preheader(lines, h):
            m = _GU_ADDK.match(lines[y].split("#", 1)[0].rstrip())
            if not m:
                continue
            g, b, k = norm_reg(m.group(2)), norm_reg(m.group(3)), int(m.group(4), 0)
            if g is None or b is None or g == b or k not in tk or b in ("sp", "zero"):
                continue
            # G's increment and B's increment, same step, same block
            gi = [x for s, xs in inc.items() for x in xs
                  if norm_reg(_GU_ADDK.match(lines[x].split("#", 1)[0].rstrip()).group(2)) == g]
            if len(gi) != 1:
                continue
            gi = gi[0]
            s = int(_GU_ADDK.match(lines[gi].split("#", 1)[0].rstrip()).group(4), 0)
            bi = [x for x in inc.get(s, [])
                  if norm_reg(_GU_ADDK.match(lines[x].split("#", 1)[0].rstrip()).group(2)) == b]
            if len(bi) != 1 or len(inc.get(s, [])) <= tinc.get(s, 0):
                continue
            bi = bi[0]
            lo, hi = min(gi, bi), max(gi, bi)
            if any(_GU_LAB.match(lines[x]) or (_s_is_insn(lines[x]) and _src_is_branch(lines[x]))
                   for x in range(lo, hi + 1)):
                continue
            nr = _noreorder_lines(lines)
            if gi in nr or y in nr:
                continue
            ok = True
            for x, l in enumerate(lines):
                if not _s_is_insn(l) or x in (y, gi):
                    continue
                d, u = _gu_du(l)
                if g in d:
                    ok = False          # another definition of G
                    break
                inloop = h <= x <= e
                if g in u and (not inloop or x > gi):
                    ok = False          # read outside the loop or after the increment
                    break
                if inloop and re.match(r"\s*jalr?\b", l):
                    ok = False
                    break
                if y < x < h and b in d:
                    ok = False          # B changes between the preheader def and the head
                    break
            if not ok:
                continue
            ind = m.group(1)
            new = "%saddu\t%s,%s,%d" % (ind, m.group(2), m.group(3), k)
            at = _gu_place(lines, h, tgt, tk[k][0], tk[k][1])
            if at in _noreorder_lines(lines) or any(
                    _s_is_insn(lines[x]) and (g in _gu_du(lines[x])[1] or b in _gu_du(lines[x])[0])
                    for x in range(h + 1, at + 1)):
                at = h
            out = []
            for x, l in enumerate(lines):
                if x in (y, gi):
                    continue
                out.append(l)
                if x == at:
                    out.append(new)
            return giv_unreduce_pass("\n".join(out), tgt)
    return stext


# --------------------------------------------------------------------------
# const_unhoist: loop.c hoisted a constant `li R,C` (C's low half zero: one lui)
# into the preheader, into a callee-saved register, where retail's loop.c left it
# in the loop: the target builds C with `lui T,C>>16` inside its loop. Move the li
# to the loop head (right after the label) into a caller-saved temp nothing in the
# loop mentions and rename R there. R must be written only by the li and read
# only inside the loop, with no call in the loop. R's save/restore stay (retail
# keeps a saved-but-unused s-register). Count-preserving; pre-sigma so sigma sees
# the target's temp.
# --------------------------------------------------------------------------
_GU_LI = re.compile(r"^(\s*)li\s+(\$\w+)\s*,\s*(-?(?:0x[0-9a-fA-F]+|\d+))\s*$")


def const_unhoist_pass(stext, tgt):
    if not tgt:
        return stext
    tl = _gu_tgt_loops(tgt)
    tlui, tpos = {}, {}
    for q, (_w, d) in enumerate(tgt):
        m = re.match(r"^\s*lui\s+\$(\w+)\s*,\s*(?:\((0x[0-9a-fA-F]+|\d+)\s*>>\s*16\)|(0x[0-9a-fA-F]+|\d+))\s*$",
                     d.strip())
        if not m or not any(a <= q < b for a, b in tl):
            continue
        # a lui paired with an ori builds a full constant: only lone luis count
        if any(re.match(r"^\s*ori\s+\$%s\s*," % m.group(1), tgt[z][1].strip())
               for z in range(q + 1, min(q + 4, len(tgt)))):
            continue
        c = (int(m.group(2), 0) & 0xFFFF0000) if m.group(2) else (int(m.group(3), 0) << 16)
        tlui[c & 0xFFFFFFFF] = m.group(1)
        tpos[c & 0xFFFFFFFF] = (q, next(a for a, b in tl if a <= q < b))
    if not tlui:
        return stext
    lines = stext.split("\n")
    used_all = set()
    for l in lines:
        if _s_is_insn(l):
            d, u = _gu_du(l)
            used_all |= d | u
    for h, e in _gu_loops(lines):
        for y in _gu_preheader(lines, h):
            m = _GU_LI.match(lines[y].split("#", 1)[0].rstrip())
            if not m:
                continue
            r, c = norm_reg(m.group(2)), int(m.group(3), 0) & 0xFFFFFFFF
            if c not in tlui or c & 0xFFFF or not r or not (r.startswith("s") or r == "fp"):
                continue
            ok, reads = True, []
            for x, l in enumerate(lines):
                if not _s_is_insn(l) or x == y:
                    continue
                if h <= x <= e and re.match(r"\s*jalr?\b", l):
                    ok = False
                    break
                d, u = _gu_du(l)
                is_save = re.match(r"^\s*(sw|lw)\s+%s\s*,\s*-?\d+\(\$(sp|29)\)" % re.escape(m.group(2)),
                                   l.split("#", 1)[0])
                if is_save:
                    continue
                if r in d:
                    ok = False
                    break
                if r in u:
                    if not h <= x <= e:
                        ok = False
                        break
                    reads.append(x)
            if not ok or not reads or y in _noreorder_lines(lines):
                continue
            inloop = set()
            for x in range(h, e + 1):
                if _s_is_insn(lines[x]):
                    d, u = _gu_du(lines[x])
                    inloop |= d | u
            pref = [tlui[c]] + ["t9", "t8", "t7", "t6", "t5", "t4", "t3", "t2", "t1", "t0",
                                "v1", "a1", "a2", "a3"]
            t = next((z for z in pref if z not in inloop and z not in used_all), None)
            if t is None:
                t = next((z for z in pref if z not in inloop and z in ABI2NUM and not z.startswith("s")
                          and _ff_dead_on(lines, [(q, x) for q, x in enumerate(lines) if _s_is_insn(x)],
                                          lines[h].strip()[:-1], z)), None)
            if t is None and re.match(r"t\d$", tlui[c]) and not any(
                    _s_is_insn(l) and re.match(r"\s*jalr?\b", l) for l in lines):
                # every temp is busy in our loop (ours keeps a loop-invariant web in the
                # target's temp W and the constant in R): exchange W and R over the whole
                # function (R's saves stay), then the constant lives in W. No call in the
                # function, so W may hold any web R held.
                w = "$%d" % ABI2NUM[tlui[c]]
                sw = {m.group(2): w, w: m.group(2)}
                pat2 = re.compile(r"(%s|%s)\b" % (re.escape(m.group(2)), re.escape(w)))
                sw_lines = []
                for x, l in enumerate(lines):
                    body, sep, cm = l.partition("#")
                    if _s_is_insn(l) and not re.match(
                            r"^\s*(sw|lw)\s+%s\s*,\s*-?\d+\(\$(sp|29)\)" % re.escape(m.group(2)), body):
                        l = pat2.sub(lambda q: sw[q.group(1)], body) + sep + cm
                    sw_lines.append(l)
                at = _gu_place(sw_lines, h, tgt, tpos[c][0], tpos[c][1])
                if at in _noreorder_lines(sw_lines) or at == y or any(z <= at for z in reads):
                    at = h
                out = []
                for x, l in enumerate(sw_lines):
                    if x == y:
                        continue
                    out.append(l)
                    if x == at:
                        out.append(sw_lines[y])
                return const_unhoist_pass("\n".join(out), tgt)
            if t is None:
                continue
            tn = "$%d" % ABI2NUM[t]
            pat = re.compile(re.escape(m.group(2)) + r"\b")
            at = _gu_place(lines, h, tgt, tpos[c][0], tpos[c][1])
            if at in _noreorder_lines(lines) or at == y or any(z <= at for z in reads):
                at = h
            out = []
            for x, l in enumerate(lines):
                if x == y:
                    continue
                if x in reads:
                    body, sep, cm = l.partition("#")
                    l = pat.sub(tn, body) + sep + cm
                out.append(l)
                if x == at:
                    out.append("%sli\t%s,%s" % (m.group(1), tn, m.group(3)))
            return const_unhoist_pass("\n".join(out), tgt)
    return stext


PASSES = {
    # reg_realloc is applied specially (it needs sigma from words); the ordered
    # list in the manifest still names it so the recipe is explicit and auditable.
    "reg_realloc": None,
    "reg_realloc_inj": None,
    "un_hi_cse": un_hi_cse_pass,
    "un_hi_cse_store": un_hi_cse_store_pass,
    "exit_merge": exit_merge_pass,
    "commutative_swap": commutative_swap_s,
    "operand_recolor": operand_recolor_s,
    "web_realloc": web_realloc_pass,
    "web_cycle": web_cycle_pass,
    "save_slot": save_slot_pass,
    "label_nop": label_nop_pass,
    "laform": laform_fold_pass,
    "base_cse_collapse": base_cse_collapse_pass,
    "shift_const_fold": shift_const_fold_pass,
    "zero_remat": zero_remat_pass,
    "load_remat": load_remat_pass,
    "nodiv": nodiv_pass,
    "copy_use": copy_use_pass,
    "ra_restore_sink": ra_restore_sink_pass,
    "sched_match": sched_match_pass,
    "sched_pre": sched_pre_pass,
    "web_resched": web_resched_pass,
    "sreg_perm": sreg_perm_pass,
    "sreg_swap": sreg_swap_pass,
    "licm_li": licm_li_pass,
    "la_unfold_st": la_unfold_st_pass,
    "block_iso": block_iso_pass,
    "block_iso_wide": block_iso_wide_pass,
    "block_iso_nop": block_iso_nop_pass,
    "slot_unsteal": slot_unsteal_pass,
    "arg_unprop": arg_unprop_pass,
    "const_fold": const_fold_pass,
    "fallthrough_fill": fallthrough_fill_pass,
    "taken_fill": taken_fill_pass,
    "dead_code": dead_code_pass,
    "offset_unfold": offset_unfold_pass,
    "la_unfold": la_unfold_pass,
    "slot_unfill": slot_unfill_pass,
    "cross_jump": cross_jump_pass,
    "zext_keep": zext_keep_pass,
    "self_move": self_move_pass,
    "mask_reuse": mask_reuse_pass,
    "zero_cmp": zero_cmp_pass,
    "redundant_skip": redundant_skip_pass,
    "param_copy": param_copy_pass,
    "selfmove_nop": selfmove_nop_pass,
    "slot_swap": slot_swap_pass,
    "slot_retake": slot_retake_pass,
    "undo_drop": undo_drop_pass,
    "copy_swap": copy_swap_pass,
    "sra_keep": sra_keep_pass,
    "call_slot_sink": call_slot_sink_pass,
    "giv_rebase": giv_rebase_pass,
    "ior_add": ior_add_pass,
    "la_copy": la_copy_pass,
    "thread_steal": thread_steal_pass,
    "slot_sink": slot_sink_pass,
    "selfmove_drop": selfmove_drop_pass,
    "la_split": la_split_pass,
    "const_sink": const_sink_pass,
    "ulcopy_rename": ulcopy_rename_pass,
    "movstr_rename": movstr_rename_pass,
    "zext_drop": zext_drop_pass,
    "call_slot_swap": call_slot_swap_pass,
    "hi_interleave": hi_interleave_pass,
    "zst_place": zst_place_pass,
    "sreg_const_use": sreg_const_use_pass,
    "la_unhoist": la_unhoist_pass,
    "param_copy_fresh": param_copy_fresh_pass,
    "li_uncopy": li_uncopy_pass,
    "web_realloc_void": web_realloc_void_pass,
    "const_uncse": const_uncse_pass,
    "slot_rethread": slot_rethread_pass,
    "movstr_rename_split": movstr_rename_split_pass,
    "range_unswap": range_unswap_pass,
    "slot_redundant": slot_redundant_pass,
    "at_dest": at_dest_pass,
    "dead_spill": dead_spill_pass,
    "arg_unrename": arg_unrename_pass,
    "giv_unreduce": giv_unreduce_pass,
    "const_unhoist": const_unhoist_pass,
}

# Passes that CHANGE the instruction count and so must run BEFORE sigma is derived
# (the register correspondence has to be built from count-aligned assembly). Any
# such pass listed in a recipe is applied ahead of reg_realloc regardless of the
# manifest order; the rest keep their listed order after sigma.
PRE_SIGMA_PASSES = ("la_unfold_st", "un_hi_cse", "un_hi_cse_store", "exit_merge", "base_cse_collapse",
                    "shift_const_fold", "zero_remat", "load_remat", "nodiv",
                    "offset_unfold", "zext_keep", "zero_cmp", "param_copy",
                    "undo_drop", "la_unfold", "arg_unprop", "sched_pre", "la_copy", "la_split", "const_sink", "zext_drop", "at_dest", "range_unswap", "slot_rethread", "const_uncse", "la_unhoist", "param_copy_fresh", "li_uncopy",
                    "const_unhoist", "giv_unreduce")

# --------------------------------------------------------------------------
# WORD-LEVEL passes. The original PSY-Q assembler (aspsx) scheduled branch and
# load delay slots in ways modern GNU as does not reproduce, so a few classes
# cannot be expressed by a register/operand text rewrite alone: the same source
# assembles to a differently-scheduled word stream. These passes decide the fix
# on the ASSEMBLED words (guided by the retail target) and re-emit the source so
# the assembler keeps the schedule we chose:
#   * padnop           -- append the trailing section-alignment nop(s) the retail
#                         object carried after the function but the C compile omits
#                         (pure text append; the count comes from the target file).
#   * delay_fill       -- move the instruction before a branch/jr into its (nop)
#                         delay slot, matching aspsx's fill (target-guided).
#   * epilogue_unfill  -- move the stack-dealloc out of the jr delay slot to just
#                         before the jr, restoring an empty slot (target-guided).
# delay_fill / epilogue_unfill reorder instructions, so their span is re-emitted
# under `.set noreorder` (one instruction per line, verbatim source) to stop the
# assembler re-scheduling it. padnop needs neither (a trailing nop cannot be
# rescheduled).
WORD_PASSES = ("delay_fill", "epilogue_unfill", "reorder_indep", "reorder_indep_nops",
               "padnop", "prologue_save_hoist", "delay_slot_select", "decouple_reg",
               "delay_decouple", "reorder_deep")

# minimal register def/use for the delay_fill dependency guard (gas `$reg` syntax)
_STORE_MN = {"sb", "sh", "sw", "swl", "swr", "swc1", "swc2", "sd", "sdc1", "sdc2"}
_COND_BR_MN = {"beq", "bne", "blez", "bgtz", "bltz", "bgez", "beqz", "bnez",
               "bgtzl", "blezl", "bltzl", "bgezl", "beql", "bnel"}
_UNCOND_MN = {"b", "j"}
_CALL_CLOBBER = {"v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3",
                 "t4", "t5", "t6", "t7", "t8", "t9", "ra", "at", "hi", "lo"}


def _reg(tok):
    r = norm_reg(tok)
    return r if r and r != "zero" else None


def defs_uses(disasm):
    """(defs, uses) register sets for one instruction's disassembly. Conservative:
    only what delay_fill needs (does the moved insn write a register the branch
    reads). Base register of a `off($b)` memory operand counts as a use."""
    disasm = _cop2_strip(disasm)
    p = disasm.split(None, 1)
    if not p:
        return set(), set()
    op = p[0].lower()
    ops = split_ops(p[1]) if len(p) > 1 else []
    defs, uses = set(), set()
    if op in ("mtc2", "ctc2") and ops:
        r = _reg(ops[0])
        return set(), ({r} if r else set())
    if op in ("mfc2", "cfc2") and ops:
        r = _reg(ops[0])
        return ({r} if r else set()), set()
    if op in ("lwc2", "swc2") and len(ops) > 1:
        mm = re.fullmatch(r"(.*)\((\$?\w+)\)", ops[1].strip())
        r = _reg(mm.group(2)) if mm else None
        return set(), ({r} if r else set())

    def use(tok):
        r = _reg(tok)
        if r:
            uses.add(r)
        mm = re.fullmatch(r"(.*)\((\$?\w+)\)", tok.strip())
        if mm:
            r2 = _reg(mm.group(2))
            if r2:
                uses.add(r2)

    if op in ("lwl", "lwr") and ops:
        # an unaligned half load merges into its destination: it reads it too
        d = _reg(ops[0])
        if d:
            defs.add(d)
            uses.add(d)
        for t in ops[1:]:
            use(t)
        return defs, uses
    if op in ("jal", "bal", "jalr", "bltzal", "bgezal"):
        defs |= set(_CALL_CLOBBER)
        uses |= {"a0", "a1", "a2", "a3"}
        # cc1 spells an indirect call `jal $reg`: the register is read too
        if ops and (op == "jalr" or _reg(ops[-1])):
            use(ops[-1])
        return defs, uses
    if op in ("mult", "multu", "div", "divu"):
        for t in ops:
            use(t)
        defs |= {"hi", "lo"}
        return defs, uses
    if op == "mflo" or op == "mfhi":
        d = _reg(ops[0]) if ops else None
        if d:
            defs.add(d)
        uses.add("lo" if op == "mflo" else "hi")
        return defs, uses
    if op == "mtlo" or op == "mthi":
        if ops:
            use(ops[0])
        defs.add("lo" if op == "mtlo" else "hi")
        return defs, uses
    if op in _STORE_MN:
        for t in ops:
            use(t)
        return defs, uses
    if op in _COND_BR_MN:
        for t in ops[:-1]:
            use(t)
        return defs, uses
    if op in _UNCOND_MN:
        return defs, uses
    if op == "jr":
        if ops:
            use(ops[0])
        return defs, uses
    # default ALU/shift/load/lui/li/la/move: first operand is the destination.
    if ops:
        d = _reg(ops[0])
        if d:
            defs.add(d)
        for t in ops[1:]:
            use(t)
    return defs, uses


_BRANCHY = re.compile(r"^(b|j|jr|jal|beq|bne|blez|bgtz|bltz|bgez|beqz|bnez)")


def is_branch(disasm):
    mn = disasm.split(None, 1)[0].lower() if disasm.strip() else ""
    if mn == "break":
        return False                    # a trap, not a transfer (no delay slot)
    return bool(_BRANCHY.match(mn))


def is_nop(disasm):
    return disasm.strip() in ("nop", "sll zero,zero,0", "sll zero,zero,0x0")


def _target_branch_filled(tgt):
    """For each control-flow instruction in the target (in order), whether its
    delay slot holds a real instruction (True) or a nop (False)."""
    res = []
    for i, (_, dis) in enumerate(tgt):
        if is_branch(dis):
            nxt = tgt[i + 1][1] if i + 1 < len(tgt) else ""
            res.append(bool(nxt.strip()) and not is_nop(nxt))
    return res


def delay_fill(words, tgt):
    """Fill a branch/jr delay slot (currently nop) with the immediately-preceding
    independent instruction, dropping the nop -- the aspsx schedule. Target-guided:
    fill the k-th branch's slot only if the target's k-th branch is filled. Returns
    a new (word,disasm) list (possibly shorter)."""
    want = _target_branch_filled(tgt)
    out = list(words)
    i, k = 0, -1
    while i < len(out) - 1:
        dis = out[i][1]
        if is_branch(dis):
            k += 1
            if is_nop(out[i + 1][1]) and i >= 1 and k < len(want) and want[k]:
                prev = out[i - 1]
                if not is_branch(prev[1]) and not is_nop(prev[1]):
                    pdef = defs_uses(prev[1])[0]
                    bruse = defs_uses(dis)[1]
                    if not (pdef & bruse):
                        out[i - 1], out[i] = out[i], prev
                        del out[i + 1]
                        i += 1
                        continue
        i += 1
    return out


def _sp_delta(dis):
    m = re.match(r"addiu\s+(\$?\w+)\s*,\s*(\$?\w+)\s*,\s*(-?(?:0x)?[0-9a-fA-F]+)\s*$", dis)
    if not m or norm_reg(m.group(1)) != "sp" or norm_reg(m.group(2)) != "sp":
        return None
    try:
        return int(m.group(3), 0)
    except ValueError:
        return None


def _is_ret(dis):
    p = dis.split(None, 1)
    return len(p) > 1 and p[0].lower() == "jr" and norm_reg(p[1].strip()) == "ra"


def _target_wants_sp_before_jr(tgt):
    if len(tgt) < 2 or not _is_ret(tgt[-1][1]):
        return False
    d = _sp_delta(tgt[-2][1])
    return d is not None and d > 0


def epilogue_unfill(words, tgt):
    """Move a positive `addiu $sp` out of the jr delay slot to just before the jr,
    restoring an empty slot -- target-guided. Returns a new word list."""
    if not _target_wants_sp_before_jr(tgt):
        return words
    out = list(words)
    for j in range(len(out) - 1):
        if not _is_ret(out[j][1]):
            continue
        d = _sp_delta(out[j + 1][1])
        if d is None or d <= 0:
            continue
        if j >= 1 and is_nop(out[j - 1][1]):
            out[j - 1], out[j + 1] = out[j + 1], out[j - 1]
        else:
            insn = out.pop(j + 1)
            out.insert(j, insn)
            out.insert(j + 2, ("00000000", "nop"))
        break
    return out


# --------------------------------------------------------------------------
# word-level re-emission: after a reordering word pass, emit the span verbatim
# under `.set noreorder` so the assembler keeps the schedule we chose. The body
# is taken from the ORIGINAL source lines reordered to the new schedule (so
# relocations and symbol operands survive), not from disassembly.
# --------------------------------------------------------------------------
def target_words_full(asm_root, fn):
    """Every word in the target .s file for fn, including the trailing pad after
    endlabel (section-alignment nops). Returns a list of big-endian hex, or None."""
    p = find_target_s(asm_root, fn)
    if not p:
        return None
    pat = re.compile(r'/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+([0-9A-Fa-f]{8})\s+\*/')
    out = []
    for line in open(p, encoding="utf-8", errors="replace"):
        m = pat.search(line)
        if m:
            le = m.group(1)
            out.append((le[6:8] + le[4:6] + le[2:4] + le[0:2]).lower())
    return out


# --- source-line helpers for the reordering passes -------------------------
# The reordering passes rewrite the cc1 gas SOURCE (not the disassembly) so
# relocations and symbol operands survive, then wrap the touched instructions in
# `.set noreorder` / `.set reorder` so the assembler keeps the schedule.
def _src_indent(line):
    return line[:len(line) - len(line.lstrip())]


def _src_reg(tok):
    return norm_reg(tok.strip())


def _src_is_ret(line):
    """Source return: `j $31` / `jr $31` / `jr $ra` (cc1 emits `j $31`)."""
    m = re.match(r"\s*(j|jr)\s+(\$\w+)\s*$", line)
    return bool(m and _src_reg(m.group(2)) == "ra")


def _src_sp_delta(line):
    """`addu/addiu $sp,$sp,IMM` -> signed IMM, else None (cc1 uses addu here)."""
    m = re.match(r"\s*addi?u\s+(\$\w+)\s*,\s*(\$\w+)\s*,\s*(-?(?:0x)?[0-9a-fA-F]+)\s*$",
                 line)
    if not m or _src_reg(m.group(1)) != "sp" or _src_reg(m.group(2)) != "sp":
        return None
    try:
        return int(m.group(3), 0)
    except ValueError:
        return None


def epilogue_unfill_src(span, tgt):
    """Move the stack-dealloc (`addu $sp,$sp,+N`) out of the return's delay slot to
    just before the return, restoring an empty (nop) slot, and wrap the three
    instructions in `.set noreorder`. Target-guided: only when the target ends
    `addiu $sp,$sp,+N ; jr $ra ; (nop)`. Returns (new_span, fired)."""
    if not _target_wants_sp_before_jr(tgt):
        return span, False
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    for k in range(len(ins) - 1):
        li, ll = ins[k]
        if not _src_is_ret(ll):
            continue
        ni, nl = ins[k + 1]
        if _src_sp_delta(nl) is None or _src_sp_delta(nl) <= 0:
            continue
        indent = _src_indent(ll)
        block = [indent + ".set\tnoreorder",
                 indent + nl.strip(),          # dealloc moved before the return
                 ll,                            # the return (jr/j $ra)
                 indent + "nop",                # empty delay slot
                 indent + ".set\treorder"]
        out = []
        for idx, l in enumerate(lines):
            if idx == li:
                out.extend(block)
            elif idx == ni:
                continue                        # dealloc removed from the slot
            else:
                out.append(l)
        return "\n".join(out), True
    return span, False


def _src_is_branch(line):
    m = re.match(r"\s*([a-z]+)\b", line)
    if not m:
        return False
    mn = m.group(1)
    if mn in ("j", "jr") and re.search(r"\$\w+", line):
        return True             # `j $31` / `jr $ra` (register form)
    return is_branch(mn + " ")


def _src_is_nop(line):
    return line.strip() in ("nop", "sll\t$0,$0,0", "sll $0,$0,0")


def delay_fill_src(span, tgt, our_words):
    """Fill a branch/return delay slot (currently a nop after assembly) with the
    immediately-preceding independent instruction -- the aspsx schedule GNU as does
    not reproduce. Target-guided: fill the k-th branch only if the target's k-th
    branch is filled AND our assembled k-th branch slot is a nop. The moved
    instruction and the branch are wrapped in `.set noreorder`. Uses `our_words`
    (assembled) to locate nop slots precisely; the k-th source branch matches the
    k-th assembled branch (branches never macro-expand). Returns (new_span, fired)."""
    want = _target_branch_filled(tgt)
    # our_words: which assembled branch slots are currently nops
    our_slot_nop = []
    for bi, (_, dis) in enumerate(our_words):
        if is_branch(dis):
            nxt = our_words[bi + 1][1] if bi + 1 < len(our_words) else ""
            our_slot_nop.append(is_nop(nxt) or not nxt.strip())
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    nrl = _noreorder_lines(lines)
    drop = set()
    move = {}                   # branch_line_idx -> (prev_line_idx, prev_text)
    keep_nop = set()            # branch line idx whose filler leaves a load-delay nop
    pre_fill = {}               # branch line idx -> macro expansion words kept ahead
    tgt_br = [k for k, (_w, d) in enumerate(tgt) if is_branch(d)]
    kbr = -1
    for p in range(len(ins)):
        i, l = ins[p]
        # a 3-operand divide macro assembles with its own check branches
        # (div/rem: bnez + two bne; divu/remu: bnez): count them so the k-th
        # source branch stays paired with the k-th assembled one
        mdv = re.match(r"\s*(div|divu|rem|remu)\s+(\$\w+)\s*,\s*\$\w+\s*,\s*\$\w+", l)
        if mdv and norm_reg(mdv.group(2)) != "zero":
            kbr += 3 if mdv.group(1) in ("div", "rem") else 1
            continue
        if not _src_is_branch(l):
            continue
        kbr += 1
        if kbr >= len(want) or not want[kbr]:
            continue
        if kbr >= len(our_slot_nop) or not our_slot_nop[kbr]:
            continue            # target fills but our slot already holds a real insn
        if p < 1:
            continue
        pi, pl = ins[p - 1]
        if _src_is_branch(pl) or _src_is_nop(pl):
            continue
        if pi in nrl and p >= 2 and _src_is_branch(ins[p - 2][1]):
            continue            # already another transfer's slot (noreorder group)
        if re.match(r"\s*(div|divu|rem|remu)\s+\$\w+\s*,\s*\$\w+\s*,\s*\$\w+", pl):
            continue            # a divide macro is many words: never a slot filler
        # dependency: prev must not define a register the branch reads
        bmn = re.match(r"\s*([a-z]+)", l).group(1)
        bu = defs_uses(l.strip())[1]
        if bmn in ("jal", "bal"):
            # a call's slot runs before the transfer: an argument set up there still
            # reaches the callee, so $a0-$a3 are not a hazard for the jal itself.
            bu = bu - {"a0", "a1", "a2", "a3"}
        if not (defs_uses(pl.strip())[0] & bu):
            exp = _expand_sym(pl)
            if exp is None:
                exp = _expand_la(pl)
            if exp is not None:
                # aspsx expands the macro first and fills the slot with its LAST
                # word; the address setup stays ahead of the branch.
                pre_fill[i] = exp[:-1]
                move[i] = exp[-1]
                drop.add(pi)
                continue
            move[i] = pl.strip()
            drop.add(pi)
            # aspsx inserts a load-delay nop BEFORE it fills the slot: when the moved
            # insn consumed the load right before it, that nop stays behind in its
            # old place. Keep it explicitly when the target has it.
            if p >= 2 and kbr < len(tgt_br) and tgt_br[kbr] >= 1 \
                    and is_nop(tgt[tgt_br[kbr] - 1][1]):
                ld = ins[p - 2][1].split("#", 1)[0].strip()
                mn = ld.split(None, 1)[0].lower() if ld else ""
                if mn in ("lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr") and \
                        (defs_uses(ld)[0] & (defs_uses(pl.split("#", 1)[0].strip())[1] | bu)):
                    keep_nop.add(ins[p - 2][0])
            # if the source already materialized a nop right after the branch, drop it
            if p + 1 < len(ins) and _src_is_nop(ins[p + 1][1]):
                drop.add(ins[p + 1][0])
    if not move:
        return span, False
    out = []
    for idx, l in enumerate(lines):
        if idx in drop:
            continue
        if idx in keep_nop:
            # the load-delay nop aspsx left stays right after the load, ahead
            # of any label between the load and the branch
            out.append(l)
            out.append(_src_indent(l) + "nop")
            continue
        if idx in move:
            indent = _src_indent(l)
            out.append(indent + ".set\tnoreorder")
            if idx in pre_fill:
                out.append(indent + ".set\tnoat")
                out.extend(indent + w for w in pre_fill[idx])
            out.append(l)                       # the branch
            out.append(indent + move[idx])      # preceding insn -> delay slot
            if idx in pre_fill:
                out.append(indent + ".set\tat")
            out.append(indent + ".set\treorder")
        else:
            out.append(l)
    return "\n".join(out), True


_PURE_ALU = set((
    "lui li la addiu addu addi ori xori andi and or xor sll srl sra sllv "
    "srlv srav slt slti sltu sltiu subu sub move nor").split())


def _pure_alu(disasm):
    """A register-only instruction with no memory or control-flow effect, so two
    adjacent ones may be swapped when register-independent (no aliasing to reason
    about)."""
    p = disasm.split(None, 1)
    return bool(p) and p[0].lower() in _PURE_ALU


def _frame_store(disasm):
    """A store whose base register is the stack pointer, e.g. `sw $ra,0x10($sp)`.
    Such a store touches only the current frame; swapping it past a pure-ALU insn
    (which has no memory effect) can never alias, so the pair is safe to reorder
    when register-independent. Retail's cc1 emits the prologue register-save store
    right after the `addiu $sp` allocation, before evaluating call arguments; our
    cc1 interleaves the arg setup ahead of the save, so this lets reorder_indep
    hoist the save back to the target's position."""
    p = disasm.split(None, 1)
    if not p or p[0].lower() not in _STORE_MN or len(p) < 2:
        return False
    ops = split_ops(p[1])
    if not ops:
        return False
    mm = re.fullmatch(r".*\((\$?\w+)\)", ops[-1].strip())
    return bool(mm) and _reg(mm.group(1)) == "sp"


def _reorder_swappable(a, b):
    """True when adjacent instructions a,b may be transposed on aliasing grounds
    (register-independence is checked separately). Two pure-ALU insns qualify (no
    memory, no control flow); so does a frame store paired with a pure-ALU insn."""
    pa, pb = _pure_alu(a), _pure_alu(b)
    if pa and pb:
        return True
    # a pure-ALU insn has no memory effect, so transposing it past ANY store cannot
    # alias (only its register independence matters, checked by _indep). reorder_indep
    # is target-guided and only moves an instruction to FIX a mismatch, so widening
    # this beyond frame (sp-based) stores cannot disturb an already-matching function.
    if (pa and _is_store(b)) or (pb and _is_store(a)):
        return True
    # an ALU insn and a load: no memory write, so only registers matter
    if (pa and _is_load(b)) or (pb and _is_load(a)):
        return True
    # a stack-frame load and a store through the assembler temp ($at only ever
    # holds a global symbol's %hi address) touch disjoint memory
    return (_frame_load(a) and _at_store(b)) or (_frame_load(b) and _at_store(a))


def _is_store(disasm):
    p = disasm.split(None, 1)
    return bool(p) and p[0].lower() in _STORE_MN


def _is_load(disasm):
    p = disasm.split(None, 1)
    return bool(p) and p[0].lower() in ("lb", "lbu", "lh", "lhu", "lw")


def _mem_base(disasm):
    p = disasm.split(None, 1)
    if len(p) < 2:
        return None
    ops = split_ops(p[1])
    mm = re.fullmatch(r".*\((\$?\w+)\)", ops[-1].strip()) if ops else None
    return norm_reg(mm.group(1)) if mm else None


def _frame_load(disasm):
    return _is_load(disasm) and _mem_base(disasm) == "sp"


def _at_store(disasm):
    p = disasm.split(None, 1)
    return bool(p) and p[0].lower() in _STORE_MN and _mem_base(disasm) == "at"


def _word_eq(our_w, tgt_w, tgt_dis):
    """Words equal, tolerating a relocated low-16 immediate: when the target insn
    carries a `%hi`/`%lo`/`%gp_rel` relocation its low half is symbol-dependent
    (our un-relinked assembly leaves it 0), so compare opcode+register fields only."""
    if our_w == tgt_w:
        return True
    if "%hi" in tgt_dis or "%lo" in tgt_dis or "%gp_rel" in tgt_dis:
        return (int(our_w, 16) >> 16) == (int(tgt_w, 16) >> 16)
    if re.match(r"\s*(jal|j)\s+[A-Za-z_.]", tgt_dis):
        # symbolic jump target: its 26-bit field is a relocation, only the
        # opcode is fixed before linking
        return (int(our_w, 16) >> 26) == (int(tgt_w, 16) >> 26)
    return False


def _indep(a, b):
    """Two instructions have no register data dependency in either direction and do
    not both write the same register, so their relative order does not affect
    results."""
    ad, au = defs_uses(a)
    bd, bu = defs_uses(b)
    return not ((ad & bu) or (bd & au) or (ad & bd))


def reorder_indep_src(span, tgt, our_words):
    """Reorder independent instructions to match the target's schedule. Retail's cc1
    sometimes emits data-independent instructions in a different order to ours -- an
    immediate load and a `lui` address setup transposed, or (the common wrapper case)
    the prologue register-save `sw $ra,K($sp)` scheduled ahead of the call-argument
    setup where our cc1 interleaves it later. Relocating one instruction across a run
    of others it is independent of and cannot alias is semantics-preserving.

    Target-guided and left-to-right: at the first position whose assembled word does
    not match the target, find the later instruction that belongs there and move it
    up, provided every instruction it passes is pairwise reorderable (`_reorder_swappable`
    -- pure-ALU pairs, or a frame store paired with pure-ALU) and register-independent
    of it. One instruction relocated per step (a single adjacent swap is the length-1
    case). Stops at the first position it cannot resolve so a later pass (e.g.
    epilogue_unfill) owns the tail. Requires a 1:1 source-insn to word mapping (no
    macro expansion). The touched positions are wrapped in `.set noreorder` so the
    assembler keeps the schedule. Returns (new_span, fired).

    Our and target word counts may differ (e.g. our epilogue is still delay-filled
    while the target's is not); this pass only aligns the common prefix and stops at
    the first position it cannot resolve, leaving the tail to epilogue_unfill."""
    n = len(our_words)
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    if len(ins) != n:
        # the assembler padded words the source does not spell (a load-delay or
        # branch-slot nop) or expanded a macro: only the 1:1 prefix before the
        # first such word is safe to reorder.
        k = 0
        while k < min(n, len(ins)):
            if _src_nwords(ins[k][1]) != 1:
                break
            if is_nop(our_words[k][1]) and not _src_is_nop(ins[k][1]):
                break
            k += 1
        if k < 2:
            return span, False
        n = k
    ow = list(our_words[:n])
    order = list(range(n))                  # order[p] = original source index at p
    swapped = set()
    pos = 0
    while pos < n - 1 and pos < len(tgt):
        if _word_eq(ow[pos][0], tgt[pos][0], tgt[pos][1]):
            pos += 1
            continue
        # find the instruction that belongs at `pos` further down the stream
        j = None
        for k in range(pos + 1, n):
            if _word_eq(ow[k][0], tgt[pos][0], tgt[pos][1]):
                j = k
                break
        if j is None:
            break                           # word not produced by a mere reorder
        mover = ow[j][1]
        # every instruction the mover hops over must be safe + independent
        if not all(_reorder_swappable(mover, ow[k][1]) and _indep(mover, ow[k][1])
                   for k in range(pos, j)):
            break
        ow.insert(pos, ow.pop(j))
        order.insert(pos, order.pop(j))
        swapped |= set(range(pos, j + 1))
        pos += 1
    if not swapped:
        return span, False
    final = [ins[order[p]][1].strip() for p in range(n)]
    line_pos = {ins[p][0]: p for p in range(n)}
    out = []
    for idx, l in enumerate(lines):
        if idx in line_pos:
            p = line_pos[idx]
            indent = _src_indent(ins[p][1])
            if p in swapped and (p - 1) not in swapped:
                out.append(indent + ".set\tnoreorder")
            out.append(indent + final[p])
            if p in swapped and (p + 1) not in swapped:
                out.append(indent + ".set\treorder")
        else:
            out.append(l)
    return "\n".join(out), True


def reorder_deep_src(span, tgt, our_words):
    """Nop-aware `reorder_indep`. reorder_indep requires a 1:1 source-to-word map and
    truncates at the first maspsx-inserted delay/load nop, so a scheduling reorder that
    sits past such a nop is never reached (func_8006CB58's `lui/addiu` la-pair vs two
    stores). This pass maps each word to its source line, splits the word stream at the
    maspsx nops into NOP-FREE segments (a load-delay nop that a reorder would need is
    itself a segment boundary, so an intra-segment reorder can never create a load-use
    hazard), and runs reorder_indep's target-guided move loop inside each segment:
    relocate the instruction that belongs at a mismatched position up past a run it is
    pairwise reorderable with (`_reorder_swappable`) and register-independent of
    (`_indep`). The moved source lines re-emit under `.set noreorder`. Semantics-
    preserving (only independent, non-aliasing instructions move) and count-preserving.
    Returns (new_span, fired)."""
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    n = len(our_words)
    word_src = [None] * n
    si = 0
    for w in range(n):
        if is_nop(our_words[w][1]):
            if si < len(ins) and _src_is_nop(ins[si][1]):
                word_src[w] = ins[si][0]
                si += 1
        elif si < len(ins):
            word_src[w] = ins[si][0]
            si += 1
    if si != len(ins):
        return span, False
    edits = {}                                   # src_line_idx -> new stripped text
    noreo = set()                                # src_line_idx to wrap in noreorder
    moved = False
    w = 0
    while w < n:
        if word_src[w] is None:
            w += 1
            continue
        a = w
        while w < n and word_src[w] is not None:
            w += 1
        m = w - a                                # segment words [a, a+m)
        if m < 2 or a >= len(tgt):
            continue
        seg_ow = list(our_words[a:a + m])
        seg_src = [word_src[a + i] for i in range(m)]
        order = list(range(m))
        swapped = set()
        pos = 0
        while pos < m - 1 and a + pos < len(tgt):
            if _word_eq(seg_ow[pos][0], tgt[a + pos][0], tgt[a + pos][1]):
                pos += 1
                continue
            j = None
            for k in range(pos + 1, m):
                if _word_eq(seg_ow[k][0], tgt[a + pos][0], tgt[a + pos][1]):
                    j = k
                    break
            if j is None:
                break
            mover = seg_ow[j][1]
            if not all(_reorder_swappable(mover, seg_ow[k][1]) and _indep(mover, seg_ow[k][1])
                       for k in range(pos, j)):
                break
            seg_ow.insert(pos, seg_ow.pop(j))
            order.insert(pos, order.pop(j))
            swapped |= set(range(pos, j + 1))
            pos += 1
        if not swapped:
            continue
        moved = True
        for p in range(m):
            src_here = seg_src[p]
            edits[src_here] = lines[seg_src[order[p]]].strip()
            if p in swapped:
                noreo.add(src_here)
    if not moved:
        return span, False
    real = [i for i, _ in ins]
    pos_of = {li: p for p, li in enumerate(real)}
    out = []
    for idx, l in enumerate(lines):
        if idx in pos_of and (idx in edits or idx in noreo):
            p = pos_of[idx]
            indent = _src_indent(lines[idx])
            prev_r = real[p - 1] if p > 0 else None
            next_r = real[p + 1] if p + 1 < len(real) else None
            if idx in noreo and (prev_r is None or prev_r not in noreo):
                out.append(indent + ".set\tnoreorder")
            out.append(indent + edits.get(idx, l.strip()))
            if idx in noreo and (next_r is None or next_r not in noreo):
                out.append(indent + ".set\treorder")
        else:
            out.append(l)
    return "\n".join(out), True


def _mem_operand(line):
    """(base_reg, offset, size) of a load/store `op $r,off($b)` source/disasm line,
    or None. Offset must be a plain integer (a %lo reloc operand returns None)."""
    body = line.split("#", 1)[0].strip()
    p = body.split(None, 1)
    if len(p) < 2:
        return None
    size = {"sb": 1, "sh": 2, "sw": 4, "lb": 1, "lbu": 1, "lh": 2, "lhu": 2,
            "lw": 4}.get(p[0].lower())
    if size is None:
        return None
    ops = split_ops(p[1])
    mm = (re.fullmatch(r"(-?(?:0x[0-9a-fA-F]+|\d+))\((\$?\w+)\)", ops[-1].strip())
          if ops else None)
    if not mm:
        return None
    return _src_reg(mm.group(2)), int(mm.group(1), 0), size


def _global_base(ins, idx, reg):
    """True when the most recent source definition of `reg` before insn `idx` is a
    `lui reg,%hi(S)` or `addiu reg,reg,%lo(S)` -- i.e. reg holds a global's address,
    which can never point into the current stack frame."""
    for k in range(idx - 1, -1, -1):
        d, _u = defs_uses(ins[k][1].split("#", 1)[0].strip())
        if reg in d:
            body = ins[k][1]
            return bool(re.match(r"\s*lui\s+\S+\s*,\s*%hi\(", body) or
                        re.match(r"\s*addiu\s+\S+\s*,\s*\S+\s*,\s*%lo\(", body))
    return False


def _no_alias(ins, ia, ib):
    """Two source memory insns (by index) provably touch disjoint bytes: same base
    register (not redefined between them) with disjoint [off, off+size) ranges, or
    one is $sp-framed and the other's base holds a global address."""
    ma, mb = _mem_operand(ins[ia][1]), _mem_operand(ins[ib][1])
    if ma is None or mb is None:
        return False
    (ba, oa, sa), (bb, ob, sb) = ma, mb
    if ba == bb:
        lo, hi = min(ia, ib), max(ia, ib)
        for k in range(lo + 1, hi):
            if ba in defs_uses(ins[k][1].split("#", 1)[0].strip())[0]:
                return False
        return oa + sa <= ob or ob + sb <= oa
    if ba == "sp" and _global_base(ins, ib, bb):
        return True
    if bb == "sp" and _global_base(ins, ia, ba):
        return True
    return False


def _branch_target_label(lines, ins, l):
    """`l` is a label some instruction in the span references (a real control-flow
    join), as opposed to cc1's `LMn:` line-marker labels, which nothing branches to."""
    if not _s_is_label(l):
        return False
    name = l.strip()[:-1]
    pat = re.compile(r"(?<![\w$.])" + re.escape(name) + r"(?![\w$])")
    return any(pat.search(il.split("#", 1)[0]) for _i, il in ins)


def _slot_sink_mover(lines, ins, sp, our_words, jw, tgt_slot):
    """For the jal at source index `sp` / word index `jw`, find the earlier source
    insn A the target sinks into the delay slot (its word equals `tgt_slot`) and
    return A's source index when moving it down past the intervening insns W and the
    current slot insn B is semantics-preserving; else None.

    The window A..jal must map 1:1 source<->word (only stores and non-macro pure-ALU
    insns, which maspsx never pads), A must be a store or pure-ALU insn, register-
    independent of every insn in W and of B, and -- when A is a store -- provably
    non-aliasing with every memory insn in W. B must be pure-ALU (it only crosses the
    jal, which it already preceded in execution as a delay-slot insn)."""
    def _plain(line):
        b = line.split("#", 1)[0].strip()
        mn = b.split(None, 1)[0].lower() if b else ""
        if mn in ("la",):
            return False                    # macro -> multi-word
        if mn == "li":
            v = split_ops(b.split(None, 1)[1])[-1]
            try:
                n = int(v, 0)
            except ValueError:
                return False
            return -0x8000 <= n <= 0xFFFF
        return mn in _PURE_ALU or mn in _STORE_MN

    def _clean(line):
        return line.split("#", 1)[0].strip()

    if sp + 1 >= len(ins):
        return None
    b = _clean(ins[sp + 1][1])
    if not _pure_alu(b):
        return None
    if sp < 1 or not _plain(ins[sp - 1][1]):
        return None
    for d in range(2, jw + 1):
        p, sa = jw - d, sp - d
        if sa < 0:
            return None
        if not _plain(ins[sa][1]):
            return None
        if not _word_eq(our_words[p][0], tgt_slot[0], tgt_slot[1]):
            continue
        if sa >= 1 and _src_is_branch(ins[sa - 1][1]):
            return None                     # A is another branch's delay slot
        if any(_branch_target_label(lines, ins, l)
               for l in lines[ins[sa][0]:ins[sp][0]]):
            return None                     # a join point inside the window
        a = _clean(ins[sa][1])
        a_store = a.split(None, 1)[0].lower() in _STORE_MN
        if not (a_store or _pure_alu(a)):
            return None
        for k in range(sa + 1, sp):
            w = _clean(ins[k][1])
            if not _indep(a, w):
                return None
            if a_store and w.split(None, 1)[0].lower() in _STORE_MN:
                if not _no_alias(ins, sa, k):
                    return None
        if not _indep(a, b):
            return None
        return sa
    return None


def delay_slot_select_src(span, tgt, our_words):
    """Swap a jal's delay-slot instruction with the instruction immediately before
    the jal when the target has exactly those two transposed. Retail's cc1 and ours
    both compute two independent argument-setup instructions before a call but pick
    a different one to sink into the branch delay slot (func_80029FB4: target fills
    the slot with `addiu $a0,$zero,0x2` and emits the `%lo($a1)` addiu before the jal;
    ours does the reverse). A delay-slot instruction executes before control transfers,
    so both orderings present identical argument registers to the callee -- swapping
    the two is semantics-preserving when they are register-independent. reorder_indep
    cannot express this because the move crosses the jal (a control transfer it will
    not hop). Target-guided and minimal: fires only on an exact A<->B transposition
    around a jal where both A and B are pure-ALU and mutually independent and the
    slot does not already match.

    Anchored on the jal, NOT on a global 1:1 source-word mapping: maspsx inserts
    load-delay nops elsewhere in the body (e.g. the epilogue), so the source-insn and
    word counts differ. But a jal's immediate word neighbours DO correspond to its
    immediate source neighbours -- the pre insn is pure-ALU (we check) so no nop is
    inserted between it and the jal, and the following word is the delay slot itself.
    So align the k-th jal across our words, the target words and the source insns, and
    read A/B from the jal's neighbours in each. The touched region is wrapped in
    `.set noreorder` so the assembler keeps the schedule. Returns (new_span, fired)."""
    def _is_call(dis):
        p = dis.split(None, 1)
        return bool(p) and p[0].lower() in ("jal", "bal", "jalr")
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    our_jal = [k for k, (_w, d) in enumerate(our_words) if _is_call(d)]
    tgt_jal = [k for k, (_w, d) in enumerate(tgt) if _is_call(d)]
    src_jal = [p for p, (_i, l) in enumerate(ins)
               if re.match(r"\s*(jal|bal|jalr)\b", l)]
    if not our_jal or len(our_jal) != len(tgt_jal) or len(our_jal) != len(src_jal):
        return span, False
    swaps = []                              # (pre_pos, jal_pos, slot_pos) in ins
    for k in range(len(our_jal)):
        jw, tw, sp = our_jal[k], tgt_jal[k], src_jal[k]
        if jw < 1 or jw + 1 >= len(our_words):
            continue
        if tw < 1 or tw + 1 >= len(tgt):
            continue
        if sp < 1 or sp + 1 >= len(ins):
            continue
        aw, bw = our_words[jw - 1], our_words[jw + 1]
        if _word_eq(bw[0], tgt[tw + 1][0], tgt[tw + 1][1]):
            continue                        # slot already correct
        if not _word_eq(bw[0], tgt[tw - 1][0], tgt[tw - 1][1]):
            continue                        # our slot insn is not the target's pre
        if _word_eq(aw[0], tgt[tw + 1][0], tgt[tw + 1][1]):
            a = ins[sp - 1][1].strip()
            b = ins[sp + 1][1].strip()
            if not (_pure_alu(a) and _pure_alu(b) and _indep(a, b)):
                continue
            swaps.append((sp - 1, sp, sp + 1))
            continue
        # sink: the target's slot insn sits FURTHER back in ours (a store, e.g. a
        # struct field init, that retail's scheduler sank into the call's slot).
        m = _slot_sink_mover(lines, ins, sp, our_words, jw, tgt[tw + 1])
        if m is not None:
            swaps.append((m, sp, sp + 1))
    if not swaps:
        return span, False
    order = list(range(len(ins)))
    wrapped = set()
    for pre, j, slot in sorted(swaps, reverse=True):
        # A (at `pre`) goes to the slot; B (the old slot) goes just before the jal;
        # everything between keeps its order. The adjacent case is a transposition.
        blk = order[pre:slot + 1]
        order[pre:slot + 1] = blk[1:-2] + [blk[-1], blk[-2], blk[0]]
        wrapped |= set(range(pre, slot + 1))
    final = {p: ins[order[p]][1].strip() for p in range(len(ins))}
    line_pos = {ins[p][0]: p for p in range(len(ins))}
    out = []
    for idx, l in enumerate(lines):
        if idx in line_pos:
            p = line_pos[idx]
            indent = _src_indent(ins[p][1])
            if p in wrapped and (p - 1) not in wrapped:
                out.append(indent + ".set\tnoreorder")
            out.append(indent + final[p])
            if p in wrapped and (p + 1) not in wrapped:
                out.append(indent + ".set\treorder")
        else:
            out.append(l)
    return "\n".join(out), True


def _src_ra_save_idx(ins):
    """Index in the source insn list of the prologue `sw $ra,K($sp)` register-save,
    or None."""
    for p, l in enumerate(ins):
        m = re.match(r"\s*sw\s+(\$\w+)\s*,\s*-?(?:0x)?[0-9a-fA-F]+\((\$\w+)\)\s*$", l)
        if m and _src_reg(m.group(1)) == "ra" and _src_reg(m.group(2)) == "sp":
            return p
    return None


def _tgt_ra_save_idx(tgt):
    """Index in the target word stream of the `sw $ra,...($sp)` register-save, or
    None."""
    for i, (_w, dis) in enumerate(tgt):
        p = dis.split(None, 1)
        if not p or p[0].lower() != "sw":
            continue
        d, u = defs_uses(dis)
        if "ra" in u and "sp" in u:
            return i
    return None


def _sym_operand(line):
    """(op, has_index) when the insn's memory operand is a bare symbol (`S`,
    `S+k`, `S($r)`): a cc1 no-split macro the assembler expands. Else None."""
    b = line.split("#", 1)[0].strip()
    p = b.split(None, 1)
    if len(p) < 2:
        return None
    op = p[0].lower()
    if op not in _STORE_MN and op not in ("lb", "lbu", "lh", "lhu", "lw", "lwl", "lwr"):
        return None
    ops = split_ops(p[1])
    m = re.fullmatch(r"([A-Za-z_.][\w.$]*(?:\+\d+)?)(\(\$\w+\))?", ops[-1].strip())
    if not m:
        return None
    return op, bool(m.group(2))


def _expand_sym(line):
    """The aspsx expansion (list of source insns) of a symbolic-address load/store
    macro, or None when `line` is not one. Loads use the destination as the temp
    unless it is the index register (then $at); stores always use $at."""
    so = _sym_operand(line)
    if not so:
        return None
    b = line.split("#", 1)[0].strip()
    op, rest = b.split(None, 1)
    ops = split_ops(rest)
    r = ops[0].strip()
    m = re.fullmatch(r"([A-Za-z_.][\w.$]*(?:\+\d+)?)(?:\((\$\w+)\))?", ops[-1].strip())
    sym, idx = m.group(1), m.group(2)
    is_load = not op.startswith("s")
    t = r if (is_load and r != idx and op not in ("lwl", "lwr")) else "$1"
    out = ["lui\t%s,%%hi(%s)" % (t, sym)]
    if idx:
        out.append("addu\t%s,%s,%s" % (t, t, idx))
    out.append("%s\t%s,%%lo(%s)(%s)" % (op, r, sym, t))
    return out


def _expand_la(line):
    """The aspsx expansion of an address macro `la $r,SYM[+k]` (lui + addiu %lo),
    or None. Only used where a pass must split the macro (delay-slot filling)."""
    b = line.split("#", 1)[0].strip()
    p = b.split(None, 1)
    if len(p) < 2 or p[0] != "la":
        return None
    ops = split_ops(p[1])
    if len(ops) != 2:
        return None
    r, sym = ops[0].strip(), ops[1].strip()
    if not re.fullmatch(r"[A-Za-z_.][\w.$]*(?:\+\d+)?", sym):
        return None
    return ["lui\t%s,%%hi(%s)" % (r, sym), "addiu\t%s,%s,%%lo(%s)" % (r, r, sym)]


def _src_nwords(line):
    """Assembled word count of one cc1 source insn: symbolic-address loads/stores
    expand to lui(+addu)+access, `la` and out-of-range `li` to two words."""
    so = _sym_operand(line)
    if so:
        return 3 if so[1] else 2
    b = line.split("#", 1)[0].strip()
    p = b.split(None, 1)
    if p and p[0] == "la":
        return 2
    if p and p[0] == "li" and len(p) > 1:
        try:
            v = int(split_ops(p[1])[-1], 0)
        except ValueError:
            return 1
        # lui alone when the low half is zero (counted so only by block_iso_wide:
        # the older passes' matched recipes were tuned on the 2-word count)
        return 1 if (-0x8000 <= v <= 0xFFFF) or (_BI_WIDE[0] and (v & 0xFFFF) == 0) else 2
    return 1


def _frame_store_disjoint(a, b):
    """Both are $sp-framed stores to non-overlapping slots."""
    if not (_frame_store(a) and _frame_store(b)):
        return False
    ma, mb = _mem_operand(a), _mem_operand(b)
    if ma is None or mb is None:
        return False
    return ma[1] + ma[2] <= mb[1] or mb[1] + mb[2] <= ma[1]


def _global_load(line):
    """A load from a global symbol's storage (symbolic operand), which can never
    alias a store into the current stack frame."""
    so = _sym_operand(line)
    if so:
        return not so[0].startswith("s")
    b = line.split("#", 1)[0].strip()
    return _is_load(b) and "%lo(" in b


def prologue_save_hoist_src(span, tgt):
    """Hoist the prologue register-save `sw $ra,K($sp)` up to the position the target
    puts it (immediately after the stack allocation). Retail's cc1 emits the save right
    after the `addiu/subu $sp` allocation, before evaluating the call arguments; our cc1
    schedules the argument setup first and saves `$ra` later. Moving the save earlier is
    semantics-preserving: it stores to the freshly allocated frame and the instructions
    it passes are register-independent of it and never touch memory (a frame store can
    only alias another memory op, and there are none between). The moved region is
    wrapped in `.set noreorder`. Target-guided: fires only when the target actually
    places the save earlier than we do, and only across hop-safe independent insns.
    Word-level 1:1 mapping is NOT required (unlike reorder_indep), so it is robust to
    the load-delay nops maspsx inserts later in the body. Returns (new_span, fired)."""
    desired = _tgt_ra_save_idx(tgt)
    if desired is None:
        return span, False
    lines = span.split("\n")
    idxs = [i for i, l in enumerate(lines) if _s_is_insn(l)]
    ins = [lines[i] for i in idxs]
    s_ra = _src_ra_save_idx(ins)
    if s_ra is None:
        return span, False
    # `desired` is a target WORD index; map it to a source insn index through each
    # source insn's assembled length (symbolic-address macros expand to 2-3 words).
    w, d_src = 0, None
    for k, l in enumerate(ins):
        if w >= desired:
            d_src = k
            break
        w += _src_nwords(l)
    if d_src is None or w != desired:
        return span, False
    desired = d_src
    if desired >= s_ra:
        return span, False
    mover = ins[s_ra].strip()
    for k in range(desired, s_ra):
        other = ins[k].strip()
        if not _indep(mover, other):
            return span, False
        if not (_reorder_swappable(mover, other) or _frame_store_disjoint(mover, other)
                or _global_load(other)):
            return span, False
    # rebuild the insn order with the save relocated to `desired`
    new_ins = list(ins)
    new_ins.insert(desired, new_ins.pop(s_ra))
    reordered = set(range(desired, s_ra + 1))
    out = []
    ip = 0
    for i, l in enumerate(lines):
        if i in idxs:
            indent = _src_indent(l)
            if ip in reordered and (ip - 1) not in reordered:
                out.append(indent + ".set\tnoreorder")
            out.append(indent + new_ins[ip].strip())
            if ip in reordered and (ip + 1) not in reordered:
                out.append(indent + ".set\treorder")
            ip += 1
        else:
            out.append(l)
    return "\n".join(out), True


def _norm_skel(skel):
    """Skeleton with integer immediates canonicalized (our objdump prints `-6`, the
    retail .s prints `-0x6`; both are the same operand)."""
    out = []
    for t in skel:
        s = t.strip()
        mm = re.fullmatch(r"(-?(?:0x[0-9a-fA-F]+|\d+))\(#\)", s)
        if mm:                                  # a memory offset `N(#)`: canonicalize N
            out.append("%d(#)" % int(mm.group(1), 0))
            continue
        try:
            out.append(str(int(s, 0)))
        except ValueError:
            out.append(s)
    return out


def _reg_copy_dst_src(disasm):
    """(dst, src) ABI regs if disasm is a register-to-register copy
    (`move d,s` / `addu d,s,zero` / `or d,s,zero`), else None."""
    m, regs, skel = insn_parts(disasm)
    if m == "move" and len(regs) == 2:
        return regs[0], regs[1]
    if m in ("addu", "or", "addiu", "ori", "daddu") and len(regs) == 3 \
            and regs[2] == "zero":
        return regs[0], regs[1]
    return None


_MACRO_MNEM = {"li", "la", "move", "not", "neg", "b", "bal", "abs"}


def _src_is_macro(line):
    body = line.split("#", 1)[0]
    p = body.split()
    mn = p[0].lower() if p else ""
    return mn in _MACRO_MNEM or "%hi" in body or "%lo" in body or "%gp_rel" in body


def _src_set_op_reg(line, op_index, abi):
    """Rewrite operand `op_index` of a cc1 gas insn line so its register is `$<num>`,
    preserving a `off($b)` memory form. Returns the new line or None."""
    body, sep, comment = line.partition("#")
    m = re.match(r"^(\s*)(\S+)([ \t]+)(.*?)\s*$", body)
    if not m:
        return None
    ind, mnem, gap, rest = m.groups()
    ops = split_ops(rest)
    if op_index >= len(ops):
        return None
    num = "$%d" % ABI2NUM[abi]
    tok = ops[op_index].strip()
    mm = re.fullmatch(r"(.*)\((\$?\w+)\)", tok)
    ops[op_index] = "%s(%s)" % (mm.group(1), num) if mm else num
    new = "%s%s%s%s" % (ind, mnem, gap, ",".join(ops))
    return new + (sep + comment if sep else "")


def _li_dst_imm(disasm):
    """(dst, imm_int) if disasm loads an immediate (`li d,i` / `addiu d,zero,i` /
    `ori d,zero,i`), else None."""
    m, regs, skel = insn_parts(disasm)
    if m == "li" and len(regs) == 1 and len(skel) == 2:
        try:
            return regs[0], int(skel[1], 0)
        except ValueError:
            return None
    if m in ("addiu", "ori", "addu") and len(regs) == 2 and skel[1] == "#" \
            and regs[1] == "zero" and len(skel) == 3:
        try:
            return regs[0], int(skel[2], 0)
        except ValueError:
            return None
    return None


def _same_insn(od, td):
    """Two disassemblies are the same instruction up to spelling/relocation: equal
    register-to-register copies, equal load-immediates, or same mnemonic + registers
    (a branch/reloc whose only word difference is its unresolved target)."""
    c = _reg_copy_dst_src(od)
    if c is not None and c == _reg_copy_dst_src(td):
        return True
    li = _li_dst_imm(od)
    if li is not None and li == _li_dst_imm(td):
        return True
    om, oregs, _ = insn_parts(od)
    tm, tregs, _ = insn_parts(td)
    return om == tm and oregs == tregs


def decouple_reg_src(span, tgt, our_words):
    """Un-coalesce a register the target keeps split by a dead copy. Retail sometimes
    computes a value into one register, copies it to a second (`addu rD,rS,zero`), and
    reads the original from rS while the shift/index reads the copy rD; our cc1
    coalesces the two into one register and drops the copy, so we emit one instruction
    fewer. This pass, guided by the target, retargets our definition's destination from
    rD to rS, inserts the `addu rD,rS,zero` copy, and relabels the uses of rD that read
    the ORIGINAL (which the target reads from rS) up to the point rD is redefined.

    Splitting a live range by inserting `rD = rS` and reading rS instead of rD while the
    two hold the same value is semantics-preserving. Target-guided and count-changing
    (+1 copy); runs as a word pass and re-emits the touched run under `.set noreorder`
    so the assembler keeps the inserted copy in place. Returns (new_span, fired)."""
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    n = len(our_words)
    if n < 3:
        return span, False
    # map each assembled word to its source line, skipping the delay/load nops maspsx
    # inserts (which have no source of their own). Non-nop words consume source insns in
    # order; a real source `nop` line consumes a nop word.
    word_src = [None] * n
    si = 0
    for w in range(n):
        if is_nop(our_words[w][1]):
            if si < len(ins) and _src_is_nop(ins[si][1]):
                word_src[w] = ins[si][0]
                si += 1
        elif si < len(ins):
            word_src[w] = ins[si][0]
            si += 1
    if si != len(ins):
        return span, False                  # a macro expanded to several words: unsafe
    line_of = {i: l for i, l in enumerate(lines)}

    # locate the first word that differs from the target and read the split shape.
    p = None
    for k in range(min(n, len(tgt)) - 1):
        if _word_eq(our_words[k][0], tgt[k][0], tgt[k][1]):
            continue
        if _same_insn(our_words[k][1], tgt[k][1]):
            continue                        # spelling/branch-offset only: not a real diff
        om, oregs, osk = insn_parts(our_words[k][1])
        tm, tregs, tsk = insn_parts(tgt[k][1])
        if om != tm or _norm_skel(osk) != _norm_skel(tsk):
            return span, False
        if len(oregs) != len(tregs) or oregs[1:] != tregs[1:] or oregs[0] == tregs[0]:
            return span, False
        R, S = oregs[0], tregs[0]           # our (coalesced) dest, target (kept) dest
        if "zero" in (R, S) or R in _INJ_FIXED or S in _INJ_FIXED:
            return span, False
        cp = _reg_copy_dst_src(tgt[k + 1][1])
        if cp != (R, S):
            return span, False
        p = k
        break
    if p is None:
        return span, False

    # walk the split: our[k] aligns to tgt[k+1] (target has the extra copy). The only
    # allowed difference is a USE of R (ours) where the target reads S. Stop when R is
    # redefined (the split ends there). Bail on any other structural difference.
    if word_src[p] is None:
        return span, False
    pdef = _src_set_op_reg(line_of[word_src[p]], 0, S)      # def rD -> rS
    if pdef is None:
        return span, False
    edits = {word_src[p]: pdef}
    end = p
    for k in range(p + 1, n):
        if k + 1 >= len(tgt) or word_src[k] is None:
            return span, False
        defs, _uses = defs_uses(our_words[k][1])
        if R in defs:                       # rD redefined here: the split ends before k
            if not _same_insn(our_words[k][1], tgt[k + 1][1]):
                return span, False
            break
        om, oregs, osk = insn_parts(our_words[k][1])
        tm, tregs, tsk = insn_parts(tgt[k + 1][1])
        # a branch/jump target operand is a label that legitimately differs; compare
        # skeletons only for non-control-flow instructions.
        skel_ok = is_branch(our_words[k][1]) or _norm_skel(osk) == _norm_skel(tsk)
        if om != tm or not skel_ok or len(oregs) != len(tregs):
            return span, False
        line = line_of[word_src[k]]
        for oi in range(len(oregs)):
            if oregs[oi] == tregs[oi]:
                continue
            if oregs[oi] == R and tregs[oi] == S:
                nl = _src_set_op_reg(line, oi, S)
                if nl is None:
                    return span, False
                line = nl
            else:
                return span, False
        if line != line_of[word_src[k]]:
            edits[word_src[k]] = line
        end = k

    lo, hi = word_src[p], word_src[end]
    if any(is_nop(our_words[w][1]) and word_src[w] is None
           for w in range(p, end + 1)):
        return span, False                  # a maspsx-inserted nop inside the frozen run
    if any(_src_is_macro(lines[j]) for j in range(lo, hi + 1) if _s_is_insn(lines[j])):
        return span, False                  # a macro in the frozen run is unsafe
    indent = _src_indent(line_of[word_src[p]])
    copy_line = indent + "addu\t$%d,$%d,$0" % (ABI2NUM[R], ABI2NUM[S])
    out = []
    for idx, l in enumerate(lines):
        if idx < lo or idx > hi:
            out.append(l)
            continue
        if idx == lo:
            out.append(indent + ".set\tnoreorder")
            out.append(indent + ".set\tnomacro")
        st = l.strip()
        if not (st.startswith(".set") and re.search(r"\b(no)?(reorder|macro)\b", st)):
            out.append(edits.get(idx, l))
        if idx == word_src[p]:
            out.append(copy_line)
        if idx == hi:
            out.append(indent + ".set\tmacro")
            out.append(indent + ".set\treorder")
    return "\n".join(out), True


def delay_decouple_src(span, tgt, our_words):
    """Delay-slot variant of decouple_reg. Retail sometimes fills a branch's delay
    slot with a register copy `addu rD,rS,$0` (aliasing rS into a fresh register rD)
    and then reads rD downstream, where our cc1 leaves the slot a nop and keeps
    reading rS. Target-guided: at a branch whose target delay slot is exactly such a
    copy while OUR same branch has a nop slot, replace the (maspsx or source) nop with
    the copy under `.set noreorder`, then relabel our later reads of rS to rD wherever
    the target reads rD, up to the point rD or rS is redefined.

    Semantics-preserving: rD must be DEAD at the branch (its first later occurrence in
    our stream is a definition, never a use), so nothing live is clobbered; after the
    copy rD holds exactly rS's value, so reading rD in place of rS is identical while
    the two agree. Count-preserving (nop -> copy). Runs as a word pass; the branch and
    its slot re-emit under `.set noreorder` so the assembler keeps the filled slot.
    Returns (new_span, fired)."""
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    n = len(our_words)
    if n < 3:
        return span, False
    word_src = [None] * n
    si = 0
    for w in range(n):
        if is_nop(our_words[w][1]):
            if si < len(ins) and _src_is_nop(ins[si][1]):
                word_src[w] = ins[si][0]
                si += 1
        elif si < len(ins):
            word_src[w] = ins[si][0]
            si += 1
    if si != len(ins):
        return span, False
    line_of = {i: l for i, l in enumerate(lines)}

    p = None
    R = S = None
    for k in range(min(n, len(tgt)) - 1):
        if not is_branch(tgt[k][1]):
            continue
        if not _same_insn(our_words[k][1], tgt[k][1]):
            continue                              # not the same branch
        cp = _reg_copy_dst_src(tgt[k + 1][1])
        if cp is None:
            continue
        rD, rS = cp
        if rD == rS or "zero" in (rD, rS) or rD in _INJ_FIXED or rS in _INJ_FIXED:
            continue
        if not is_nop(our_words[k + 1][1]):
            continue                              # our slot is already filled
        if word_src[k] is None:
            continue                              # branch has no source line to anchor
        # rD must be dead at the branch: its first later occurrence is a definition.
        dead = True
        for j in range(k + 1, n):
            d, u = defs_uses(our_words[j][1])
            if rD in u and rD not in d:
                dead = False
                break
            if rD in d:
                break
        if not dead:
            continue
        p, R, S = k, rD, rS
        break
    if p is None:
        return span, False

    # relabel our reads of S to R where the target reads R (the copy makes R == S), on
    # BOTH successors of the branch: the fall-through (from p+2) and the taken target
    # block. The delay-slot copy executes before the transfer, so R holds S's value on
    # either path; relabel until R or S is redefined. Guided by the target so we only
    # rename where retail reads R. `edits` accumulates line rewrites keyed by line index.
    edits = {}

    def relabel(start):
        for k in range(start, n):
            if k >= len(tgt) or word_src[k] is None:
                return
            defs, _u = defs_uses(our_words[k][1])
            if R in defs or S in defs:
                return
            om, oregs, osk = insn_parts(our_words[k][1])
            tm, tregs, tsk = insn_parts(tgt[k][1])
            skel_ok = is_branch(our_words[k][1]) or _norm_skel(osk) == _norm_skel(tsk)
            if om != tm or not skel_ok or len(oregs) != len(tregs):
                return
            line = edits.get(word_src[k], line_of[word_src[k]])
            for oi in range(len(oregs)):
                if oregs[oi] == tregs[oi]:
                    continue
                if oregs[oi] == S and tregs[oi] == R:
                    nl = _src_set_op_reg(line, oi, R)
                    if nl is None:
                        return
                    line = nl
                else:
                    return
            if line != line_of[word_src[k]]:
                edits[word_src[k]] = line

    relabel(p + 2)                                 # fall-through path
    # taken path: find the branch's target label, then the first word at/after it.
    w_of_src = {word_src[w]: w for w in range(n) if word_src[w] is not None}
    mlab = re.search(r",\s*(\$L\w+)\s*$", line_of[word_src[p]].split("#", 1)[0])
    if mlab:
        lab = mlab.group(1) + ":"
        for li in range(len(lines)):
            if lines[li].strip() == lab:
                for lj in range(li + 1, len(lines)):
                    if _s_is_insn(lines[lj]):
                        if lj in w_of_src:
                            relabel(w_of_src[lj])
                        break
                break

    indent = _src_indent(line_of[word_src[p]])
    copy_line = indent + "addu\t$%d,$%d,$0" % (ABI2NUM[R], ABI2NUM[S])
    lo = word_src[p]
    slot_src = word_src[p + 1]                     # a real source nop to drop, if any
    out = []
    for idx, l in enumerate(lines):
        if slot_src is not None and idx == slot_src:
            continue                              # the source nop becomes our filled slot
        if idx == lo:
            out.append(indent + ".set\tnoreorder")
            out.append(indent + ".set\tnomacro")
            out.append(edits.get(idx, l))
            out.append(copy_line)                 # fill the branch delay slot
            out.append(indent + ".set\tmacro")
            out.append(indent + ".set\treorder")
            continue
        out.append(edits.get(idx, l))             # relabels elsewhere are plain renames
    return "\n".join(out), True


def reorder_indep_nops_src(span, tgt, our_words):
    """Swap two adjacent independent pure-ALU instructions to match the target's
    schedule, even when maspsx-inserted delay/load nops earlier in the function break
    the 1:1 source-to-word mapping `reorder_indep` needs (it truncates at the first
    such nop and never reaches a later swap). This pass maps each assembled word to its
    source line, skipping the maspsx nops (same word->source map as decouple_reg), then
    at each adjacent word pair (pos, pos+1) that is mismatched against the target but
    would BOTH match after a transpose, swaps their source lines -- provided both are
    real-source pure-ALU instructions with no register dependency in either direction.
    Restricting to pure-ALU pairs means neither is a load or store, so the swap cannot
    create a load-use hazard or alias, and the touched pair carries no maspsx nop of its
    own. The two lines are re-emitted under `.set noreorder` so the assembler keeps the
    order. Count-preserving. Returns (new_span, fired)."""
    lines = span.split("\n")
    ins = [(i, l) for i, l in enumerate(lines) if _s_is_insn(l)]
    n = len(our_words)
    if n < 2:
        return span, False
    # map each assembled word to its source line, skipping maspsx-inserted nops (which
    # have no source of their own): the identical mapping decouple_reg builds.
    word_src = [None] * n
    si = 0
    for w in range(n):
        if is_nop(our_words[w][1]):
            if si < len(ins) and _src_is_nop(ins[si][1]):
                word_src[w] = ins[si][0]
                si += 1
        elif si < len(ins):
            word_src[w] = ins[si][0]
            si += 1
    if si != len(ins):
        return span, False                       # a macro expanded to several words
    line_of = {i: l for i, l in enumerate(lines)}
    swaps = []                                    # (line_idx_a, line_idx_b) with a < b
    p = 0
    while p + 1 < min(n, len(tgt)):
        a, b = word_src[p], word_src[p + 1]
        if a is None or b is None:
            p += 1; continue
        oa, ob = our_words[p][1], our_words[p + 1][1]
        # already-correct positions and any nop pair are skipped
        if (_word_eq(our_words[p][0], tgt[p][0], tgt[p][1]) and
                _word_eq(our_words[p + 1][0], tgt[p + 1][0], tgt[p + 1][1])):
            p += 1; continue
        # a transpose fixes BOTH positions, both are pure-ALU, and independent
        if (_word_eq(our_words[p][0], tgt[p + 1][0], tgt[p + 1][1]) and
                _word_eq(our_words[p + 1][0], tgt[p][0], tgt[p][1]) and
                _pure_alu(oa) and _pure_alu(ob) and _indep(oa, ob)):
            swaps.append((a, b) if a < b else (b, a))
            p += 2
            continue
        p += 1
    if not swaps:
        return span, False
    swap_by_a = {a: b for a, b in swaps}
    swap_by_b = {b: a for a, b in swaps}
    out = []
    for idx, l in enumerate(lines):
        if idx in swap_by_a:                      # first line of a pair: emit the second
            b = swap_by_a[idx]
            indent = _src_indent(line_of[idx])
            out.append(indent + ".set\tnoreorder")
            out.append(indent + line_of[b].strip())
        elif idx in swap_by_b:                    # second line of a pair: emit the first
            a = swap_by_b[idx]
            indent = _src_indent(line_of[idx])
            out.append(indent + line_of[a].strip())
            out.append(indent + ".set\treorder")
        else:
            out.append(l)
    return "\n".join(out), True


_REORDER_SRC = {
    "epilogue_unfill": epilogue_unfill_src,
    "delay_fill": delay_fill_src,
    "reorder_indep": reorder_indep_src,
    "reorder_indep_nops": reorder_indep_nops_src,
    "prologue_save_hoist": prologue_save_hoist_src,
    "delay_slot_select": delay_slot_select_src,
    "decouple_reg": decouple_reg_src,
    "delay_decouple": delay_decouple_src,
    "reorder_deep": reorder_deep_src,
}


def emit_noreorder_span(span, tgt, our_words, reorder_passes, reassemble=None):
    """Apply the reordering source passes (delay_fill / epilogue_unfill) to a span
    in order. Each rewrites the cc1 source and wraps the touched instructions in
    `.set noreorder` so the assembler keeps the schedule. `tgt` is the target's
    (pad-stripped) [(word, disasm)] list; `our_words` is our assembled span.

    A word-consuming pass (delay_fill / reorder_indep / delay_slot_select) reads the
    ASSEMBLED words of the CURRENT source. When an earlier pass in the recipe already
    reordered the source (e.g. prologue_save_hoist ahead of delay_slot_select), the
    words from before that pass are stale and the positional guidance is wrong. If a
    `reassemble(txt) -> words` callback is supplied, refresh the words from the current
    span text before each word-consuming pass; otherwise fall back to the words passed
    in (correct when no earlier pass moved anything)."""
    txt = span
    for name in reorder_passes:
        fn = _REORDER_SRC.get(name)
        if fn is None:
            raise NotImplementedError("reorder pass not wired: %s" % name)
        if name in ("delay_fill", "reorder_indep", "reorder_indep_nops",
                    "delay_slot_select", "decouple_reg", "delay_decouple",
                    "reorder_deep"):
            words = reassemble(txt) if reassemble is not None else our_words
            txt, _fired = fn(txt, tgt, words)
        else:
            txt, _fired = fn(txt, tgt)
    return txt


def apply_padnop(span, our_words, tgt_full):
    """Append the trailing pad nop(s) the retail object carried but the C compile
    omitted. Count = target total words - our assembled words; only fires when the
    extra target words are all nop (a pure section-alignment pad)."""
    need = len(tgt_full) - len(our_words)
    if need <= 0:
        return span, False
    if any(w != "00000000" for w in tgt_full[len(our_words):]):
        return span, False          # tail is not pure padding: refuse
    m = re.search(r'(?m)^([ \t]*)\.end[ \t]+\S+', span)
    indent = m.group(1) if m else "\t"
    pad = "".join("%snop\n" % indent for _ in range(need))
    if m:
        return span[:m.start()] + pad + span[m.start():], True
    return span + pad, True


# --------------------------------------------------------------------------
# words: assemble our .s span, read the retail target .s
# --------------------------------------------------------------------------
def _strip_trailing_pad(words):
    """Drop trailing all-zero (`nop`/`sll zero,zero,0`) padding words the linker
    section alignment adds, so our and target lengths line up."""
    out = list(words)
    while out and out[-1][0] == "00000000":
        out.pop()
    return out


def assemble_words(ctx, sfile, fn):
    """gas .s -> maspsx --run-assembler -> objdump; return [(be_hex, disasm)] for fn.
    Memoized on the file bytes (a search re-assembles identical text often: most
    candidate passes do not fire)."""
    import hashlib
    with open(sfile, "rb") as f:
        key = (hashlib.sha1(f.read()).hexdigest(), fn,
               tuple(ctx["maspsx_flags"]), tuple(ctx["maspsx_as_flags"]))
    if key in _ASM_CACHE:
        return list(_ASM_CACHE[key]), None
    words, err = _assemble_words(ctx, sfile, fn)
    if err is None:
        if len(_ASM_CACHE) > 4096:
            _ASM_CACHE.clear()
        _ASM_CACHE[key] = list(words)
    return words, err


_ASM_CACHE = {}


def _assemble_words(ctx, sfile, fn):
    obj = sfile + ".asmnorm.o"
    cmd = ([ctx["python"], ctx["maspsx_py"]] + ctx["maspsx_flags"]
           + ["--gnu-as-path=%s" % ctx["as_bin"]] + ctx["maspsx_as_flags"]
           + ["-o", obj, sfile])
    rc, o, e = ctx["run"](cmd)
    if rc:
        return None, "MASPSX:\n" + o + e
    # -z: do NOT collapse runs of zero words into `...`, or a trailing pad of
    # `nop`s (e.g. the alignment tail padnop appends) would be miscounted.
    rc, o, e = ctx["run"]([ctx["objdump"], "-dz", obj])
    if rc:
        return None, "OBJDUMP:\n" + o + e
    words, in_fn = [], False
    for line in o.splitlines():
        if re.match(r'^[0-9a-f]+ <%s>:' % re.escape(fn), line):
            in_fn = True
            continue
        if in_fn:
            m2 = re.match(r'^[0-9a-f]+ <([A-Za-z_.$][\w.$]*)>:', line)
            if m2 and m2.group(1) != fn and not re.match(r'^(L|\.L|LM|\$L)', m2.group(1)):
                break
            m = re.match(r'^\s*[0-9a-f]+:\s+([0-9a-f]{8})\s+(.*)', line)
            if m:
                words.append((m.group(1).lower(), m.group(2).strip()))
    try:
        os.remove(obj)
    except OSError:
        pass
    return words, None


def find_target_s(asm_root, fn):
    """Locate the retail nonmatchings .s for a function under asm_root. Returns a
    path or None. No unit/path is baked in; the layout is asm/**/nonmatchings/**/."""
    want = fn + ".s"
    # the stage overlays share one address range: two can hold a func of the
    # same name, so the unit being built is searched first
    if _UNIT_ROOT:
        for dirpath, _dirs, files in os.walk(_UNIT_ROOT):
            if "nonmatchings" in dirpath.replace("\\", "/").split("/") and want in files:
                return os.path.join(dirpath, want)
    for dirpath, _dirs, files in os.walk(asm_root):
        if "nonmatchings" not in dirpath.replace("\\", "/").split("/"):
            continue
        if want in files:
            return os.path.join(dirpath, want)
    return None


def target_words(asm_root, fn):
    """splat target .s -> [(be_hex, disasm)] (little-endian column -> BE)."""
    p = find_target_s(asm_root, fn)
    if not p:
        return None
    s = open(p, encoding="utf-8", errors="replace").read()
    words = []
    pat = re.compile(r'/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+([0-9A-Fa-f]{8})\s+\*/\s+(\S+)(.*)')
    started = False
    for line in s.splitlines():
        if re.match(r'^\s*glabel\s+%s\b' % re.escape(fn), line):
            started = True
            continue
        if started and re.match(r'^\s*endlabel\b', line):
            break
        if not started:
            continue
        m = pat.search(line)
        if m:
            le = m.group(1)
            be = (le[6:8] + le[4:6] + le[2:4] + le[0:2]).lower()
            words.append((be, (m.group(2) + m.group(3)).strip()))
    return words


# --------------------------------------------------------------------------
# per-function span splicing
# --------------------------------------------------------------------------
ENT_RE = re.compile(r'(?m)^[ \t]*\.ent[ \t]+(\S+)')


def _read_bytes_str(path):
    with open(path, "rb") as f:
        return f.read().decode("latin-1")


def _write_bytes_str(path, s):
    with open(path, "wb") as f:
        f.write(s.encode("latin-1"))


def split_spans(text):
    """[(name, start, end)] for each `.ent NAME ... .end NAME` code span."""
    spans = []
    for m in ENT_RE.finditer(text):
        name = m.group(1)
        endm = re.search(r'(?m)^[ \t]*\.end[ \t]+%s\b' % re.escape(name),
                         text[m.start():])
        if not endm:
            continue
        end = m.start() + endm.end()
        nl = text.find("\n", end)
        end = len(text) if nl < 0 else nl + 1
        spans.append((name, m.start(), end))
    return spans


def normalize_span_text(span, tgt, sigma, passes):
    """Replay the manifest's ordered passes on one function's span. reg_realloc
    applies sigma (derived from the words); the .s-text operators run after."""
    txt = span
    for name in passes:
        if name == "reg_realloc":
            txt = apply_sigma_to_s(txt, sigma)
        elif name == "reg_realloc_inj":
            txt = apply_sigma_to_s(txt, _SPAN_INFO.get("sigma_inj") or {})
        else:
            fn = PASSES.get(name)
            if fn is None:
                raise RuntimeError("unknown normalizer pass: %s" % name)
            txt = fn(txt, tgt)
    return txt


def load_manifest(path=MANIFEST):
    """{func: {"passes": [name, ...]}} -- absent/empty file = {}."""
    if not os.path.exists(path):
        return {}
    with open(path, encoding="utf-8") as f:
        data = json.load(f)
    return data or {}


# --------------------------------------------------------------------------
# nosplit (META pass, not a rewrite). The retail executable links translation
# units built with DIFFERENT cc1 address-generation settings: some were compiled
# with split addresses (cc1 itself emits `lui $r,%hi(S)` / `%lo(S)($r)` pairs and
# CSEs/la-forms them), others with `-mno-split-addresses`, where cc1 emits the
# symbolic macro operand (`lw $r,S($idx)`, `sw $r,S`) and the assembler (aspsx /
# maspsx) expands it: `lui $dst,%hi(S)` + `addu` + `lw $dst,%lo(S)($dst)` for a
# load, a fresh `lui $at` for a store or when the destination is the index. The
# project compiles one 156C.c, so a function from a no-split unit is recovered by
# compiling the file a second time with -mno-split-addresses and splicing that
# function's `.ent ... .end` span in place of the default one. It is still plain
# cc1 output of the same C; the other passes in the recipe then run on it as usual.
# Local `$L`/`LM` labels are renamed in the spliced span so its numbering (which
# can drift between the two compiles) cannot collide with the rest of the file.
#
# Units also differ in who fills branch delay slots: some let cc1's delayed-branch
# pass fill them (`.set noreorder` blocks in the cc1 output), others were built
# with -fno-delayed-branch and left it to aspsx, which first inserts load-delay
# nops and then fills a slot with the preceding insn (delay_fill models that). So
# each META pass names one alternate compile ("flavor") of the same file.
# --------------------------------------------------------------------------
ALT_FLAVORS = {
    "nosplit": ["-mno-split-addresses"],
    "nosplit_nodb": ["-mno-split-addresses", "-fno-delayed-branch"],
    "nodb": ["-fno-delayed-branch"],
    "gp8": ["-G8"],
    "gp8_nosplit": ["-G8", "-mno-split-addresses"],
    "gp8_nosplit_noskip": ["-G8", "-mno-split-addresses", "-fno-cse-skip-blocks"],
    # FP registers not fixed: loop.c hoists more loop constants into s-regs
    "hf": ["-mhard-float"],
    "nosplit_hf": ["-mno-split-addresses", "-mhard-float"],
    "nodb_hf": ["-fno-delayed-branch", "-mhard-float"],
    "nosplit_nodb_hf": ["-mno-split-addresses", "-fno-delayed-branch", "-mhard-float"],
    # units built without loop strength reduction (address givs stay i*size+base)
    "nosr": ["-fno-strength-reduce"],
    "nosplit_nosr": ["-mno-split-addresses", "-fno-strength-reduce"],
    # units built without the second cse pass and without cse jump following
    "nocse": ["-fno-rerun-cse-after-loop", "-fno-cse-follow-jumps"],
    "nosplit_nocse": ["-mno-split-addresses", "-fno-rerun-cse-after-loop", "-fno-cse-follow-jumps"],
    # units built without the second (post-allocation) scheduling pass
    "nos2": ["-fno-schedule-insns2"],
    "nosplit_nos2": ["-mno-split-addresses", "-fno-schedule-insns2"],
}
META_PASSES = tuple(ALT_FLAVORS)
# local-label prefix per alternate compile (nosplit keeps the historical "ns")
_ALT_TAG = {"nosplit": "ns", "nosplit_nodb": "nsnd", "nodb": "nd", "gp8": "gp",
            "gp8_nosplit": "gpns",
            "gp8_nosplit_noskip": "gpnk", "hf": "hf", "nosplit_hf": "nshf",
            "nodb_hf": "ndhf", "nosplit_nodb_hf": "nsndhf",
            "nosr": "nsr", "nosplit_nosr": "nsnsr", "nocse": "ncse",
            "nosplit_nocse": "nsncse", "nos2": "ns2", "nosplit_nos2": "nsns2"}


def alt_flavors(manifest):
    """The alternate-compile flavors a manifest needs."""
    return sorted({p for v in manifest.values() for p in v.get("passes", [])
                   if p in ALT_FLAVORS})


def _lc_body(text, lc):
    """The data lines of constant `lc` (from its label to the next label or
    section directive), or None when it is not defined."""
    m = re.search(r"(?m)^%s:\s*\n((?:[ \t]+\.(?:ascii|byte|half|word|space|align)"
                  r"\b.*\n)*)" % re.escape(lc), text)
    return m.group(1) if m else None


def expand_sym_macros(span):
    """Expand every symbolic-address load/store macro in a span into the explicit
    words aspsx emits (see _expand_sym), so the source keeps a 1:1 insn<->word map
    for the word-level passes. Inside a `.set noreorder` block the expansion is
    left to the assembler (a macro there is already placed by cc1)."""
    out, noreorder = [], False
    for l in span.split("\n"):
        s = l.strip()
        if s.startswith(".set"):
            if "noreorder" in s:
                noreorder = True
            elif re.match(r"\.set\s+reorder\b", s):
                noreorder = False
        exp = None if (noreorder or not _s_is_insn(l)) else _expand_sym(l)
        if exp is None:
            out.append(l)
            continue
        ind = _src_indent(l)
        uses_at = any(re.search(r"\$1(?![0-9])", w) for w in exp)
        if uses_at:
            out.append(ind + ".set\tnoat")
        out.extend(ind + w for w in exp)
        if uses_at:
            out.append(ind + ".set\tat")
    return "\n".join(out)


def aspsx_label_nops(span):
    """aspsx puts a load-delay nop straight after the load, even when a label
    separates the load from the insn that consumes it; maspsx emits `label: nop`,
    which moves every branch into that label one word early. Spell the nop out
    right after the load (reorder mode only) so maspsx sees no hazard left."""
    lines = span.split("\n")
    out, noreorder = [], False
    for k, l in enumerate(lines):
        out.append(l)
        s = l.strip()
        if s.startswith(".set"):
            if "noreorder" in s:
                noreorder = True
            elif re.match(r"\.set\s+reorder\b", s):
                noreorder = False
        if noreorder or not _s_is_insn(l):
            continue
        b = l.split("#", 1)[0].strip()
        if not _is_load(b):
            continue
        d = defs_uses(b)[0]
        saw_label, j = False, k + 1
        while j < len(lines) and not _s_is_insn(lines[j]):
            if _s_is_label(lines[j]):
                saw_label = True
            j += 1
        if saw_label and j < len(lines):
            nb = lines[j].split("#", 1)[0].strip()
            # a direct `jal` reads no register when it issues (its delay slot
            # runs first); defs_uses models its argument registers as uses
            # runs first); defs_uses models its argument registers as uses. An
            # indirect `jal $31,$r` (cc1's jalr spelling) reads $r as it issues.
            mi = re.match(r"jalr?\s+(?:\$\w+\s*,\s*)?(\$\w+)\s*$", nb)
            if mi:
                uses = {norm_reg(mi.group(1))}
            else:
                uses = set() if re.match(r"jal\s", nb) else defs_uses(nb)[1]
            if d & uses:
                out.append(_src_indent(l) + "nop")
    return "\n".join(out)


def _gp_small(alt_text):
    """Symbols a -G compile declared small (`.extern SYM, N`, `.comm`/`.lcomm`
    within the threshold): cc1 leaves their accesses as macros and the
    assembler makes them $gp-relative."""
    small = set()
    for m in re.finditer(r"(?m)^\s*\.(?:extern|comm|lcomm)\s+([A-Za-z_.][\w.$]*)\s*,\s*(\d+)",
                         alt_text):
        if 0 < int(m.group(2)) <= 8:
            small.add(m.group(1))
    return small


def _gp_addr(name):
    """Address a `D_XXXXXXXX[+k]` or named `SYM[+k]` symbol resolves to, else None."""
    m = re.fullmatch(r"([A-Za-z_]\w*)(?:\+(\d+))?", name)
    a = _sym_addr(m.group(1)) if m else None
    return a + int(m.group(2) or 0) if a is not None else None


def _gp_target_refs(name):
    """(addresses, names) the retail function `name` reaches through $gp, or
    None when there is no target to consult."""
    t = find_target_s(_ASM_ROOT, name) if _ASM_ROOT else None
    if not t:
        return None
    refs = re.findall(r"%gp_rel\(([A-Za-z_.][\w.$]*(?:\+\d+)?)\)", open(t).read())
    return ({_gp_addr(r) for r in refs if _gp_addr(r) is not None},
            {r.split("+")[0] for r in refs})


def gp_rel_macros(span, small, refs=None):
    """Spell a -G compile's small-data macros the way the assembler emits them:
    `op $r,S[+k]` -> `op $r,%gp_rel(S[+k])($gp)`, `la $r,S[+k]` ->
    `addiu $r,$gp,%gp_rel(S[+k])` (one word each). With `refs` (the target's
    $gp addresses and names), a small symbol the target reaches by lui/%lo
    instead (another unit declared it bigger) stays a plain macro."""
    if not small:
        return span
    out = []
    for l in span.split("\n"):
        b = l.split("#", 1)[0].strip()
        m = re.fullmatch(r"(la|lw|lh|lhu|lb|lbu|lwl|lwr|sw|sh|sb|swl|swr)\s+(\$\w+)\s*,\s*"
                         r"([A-Za-z_.][\w.$]*)((?:\+\d+)?)", b)
        if m and refs is not None and m.group(3) in small:
            a0, a1 = _gp_addr(m.group(3)), _gp_addr(m.group(3) + m.group(4))
            if not (a0 in refs[0] or a1 in refs[0] or m.group(3) in refs[1]):
                m = None
        if m and m.group(3) in small:
            op, r, sym = m.group(1), m.group(2), m.group(3) + m.group(4)
            l = _src_indent(l) + ("addiu\t%s,$gp,%%gp_rel(%s)" % (r, sym) if op == "la"
                                  else "%s\t%s,%%gp_rel(%s)($gp)" % (op, r, sym))
        out.append(l)
    return "\n".join(out)


def splice_alt_spans(text, alt_text, names, tag="ns"):
    """Replace each function span in `names` with the same function's span from
    `alt_text`. Returns (new_text, [spliced names]). `tag` keeps the renamed local
    labels unique per alternate compile: the LM line-marker counters of two flavor
    compiles overlap, so two flavors must not share a prefix."""
    alt = {n: alt_text[s:e] for n, s, e in split_spans(alt_text)}
    small = _gp_small(alt_text)
    done = []
    for name, start, end in sorted(split_spans(text), key=lambda x: -x[1]):
        if name not in names:
            continue
        if name not in alt:
            raise RuntimeError("alt compile: %s missing" % name)
        span = alt[name]
        for lc in set(re.findall(r"\$LC\d+", span)):
            if _lc_body(text, lc) is None or _lc_body(text, lc) != _lc_body(alt_text, lc):
                raise RuntimeError("alt compile: %s references %s, which differs between "
                                   "the two compiles" % (name, lc))
        span = re.sub(r"\$L(?!C)(\w+)", r"$L%s_\1" % tag, span)
        span = re.sub(r"(?<![\w$.])LM(\d+)\b", r"LM%s\1" % tag, span)
        span = aspsx_label_nops(expand_sym_macros(
            gp_rel_macros(span, small, _gp_target_refs(name) if small else None)))
        text = text[:start] + span + text[end:]
        done.append(name)
    return text, done



# --------------------------------------------------------------------------
# jtbl binding: a switch cc1 lowers to a jump table emits its own `.rdata` table
# inside the function span. Retail's table already sits in the separate rodata
# object (splat keeps low .rodata there) and points at `.L<addr>` labels that the
# INCLUDE_ASM body defined. Once the function is C, bind the two: drop our table,
# address the retail `jtbl_<addr>` symbol instead, and define each retail
# `.L<addr>` (global, like splat's jlabel) at the label our table entry names.
# Tables pair up in order of first use; entry counts must agree. No word changes
# (the table load is a relocated %hi/%lo), only data placement and symbols.
# --------------------------------------------------------------------------
_JT_DATA = None
_OUR_JT = re.compile(r"(?m)^[ \t]*\.rdata[ \t\r]*\n(?:[ \t]*\.align[ \t]+\d+[ \t\r]*\n)?"
                     r"(\$L\w+):[ \t\r]*\n((?:[ \t]*\.(?:word|gpword)[ \t]+\$L\w+[ \t\r]*\n)+)"
                     r"[ \t]*\.text[ \t\r]*\n")


def _jt_data(asm_root):
    """{jtbl_name: [entry labels]} from every splat asm file under asm_root."""
    global _JT_DATA
    if _JT_DATA is None:
        _JT_DATA = {}
        roots = ([_UNIT_ROOT] if _UNIT_ROOT else []) + [asm_root]
        for dp, _ds, fs in (w for r in roots for w in os.walk(r)):
            for f in fs:
                if not f.endswith(".s"):
                    continue
                t = open(os.path.join(dp, f), encoding="utf-8", errors="replace").read()
                if "dlabel jtbl_" not in t:
                    continue
                for m in re.finditer(r"(?ms)^dlabel (jtbl_\w+)\n(.*?)^enddlabel", t):
                    if m.group(1) in _JT_DATA:
                        continue
                    _JT_DATA[m.group(1)] = re.findall(r"\.word\s+(\.L\w+)", m.group(2))
    return _JT_DATA


def jtbl_bind(span, name, asm_root):
    t = find_target_s(asm_root, name) if asm_root else None
    if not t:
        return span
    used = []
    for j in re.findall(r"\b(jtbl_\w+)\b", open(t, encoding="utf-8", errors="replace").read()):
        if j not in used:
            used.append(j)
    ours = list(_OUR_JT.finditer(span))
    if not used or len(used) != len(ours):
        return span
    data = _jt_data(asm_root)
    alias = {}
    for j, m in zip(used, ours):
        ent = re.findall(r"\$L\w+", m.group(2))
        if j not in data or len(data[j]) != len(ent):
            return span
        for r, o in zip(data[j], ent):
            if alias.setdefault(r, o) != o:
                return span                 # one retail label, two of ours
    for j, m in reversed(list(zip(used, ours))):
        span = span[:m.start()] + span[m.end():]
        span = re.sub(r"%s(?!\w)" % re.escape(m.group(1)), j, span)
    by_ours = {}
    for r, o in alias.items():
        by_ours.setdefault(o, []).append(r)
    for o, rs in by_ours.items():
        span = re.sub(r"(?m)^(%s:)[ \t\r]*$" % re.escape(o),
                      lambda mm: mm.group(1) + "".join("\n\t.globl\t%s\n%s:" % (r, r)
                                                       for r in sorted(rs)), span, count=1)
    return span


def normalize_s(s_file, ctx, manifest=None):
    """Splice-normalize the manifest functions in a cc1 .s in place. Reads once,
    rewrites once. Returns the sorted list of function names it rewrote.

    ctx keys: python, maspsx_py, maspsx_flags, as_bin, maspsx_as_flags, objdump,
    run (callable -> (rc, out, err)), asm_root."""
    global _ASM_ROOT, _UNIT_ROOT, _JT_DATA
    _ASM_ROOT = ctx.get("asm_root")
    if ctx.get("asm_unit_root") != _UNIT_ROOT:
        _UNIT_ROOT = ctx.get("asm_unit_root")
        for c in (_FN_ADDR, _CALLEE_S, _CALLEE_RD, _CALLEE_CFG):
            c.clear()
        _JT_DATA = None
    if manifest is None:
        manifest = load_manifest()
    text = _read_bytes_str(s_file)
    rewrote = []
    # Pass 0 -- alternate-compile flavors (nosplit, ...): take the function's span
    # from that flavor's cc1 output before any other pass sees it.
    for flavor in alt_flavors(manifest):
        ns = [n for n in manifest if flavor in manifest[n].get("passes", [])]
        alt = (ctx.get("alt_s") or {}).get(flavor)
        if not alt or not os.path.exists(alt):
            raise RuntimeError("%s functions %s need ctx['alt_s'][%r]"
                               % (flavor, ns, flavor))
        text, done = splice_alt_spans(text, _read_bytes_str(alt), ns,
                                      _ALT_TAG.get(flavor, flavor))
        _write_bytes_str(s_file, text)
        rewrote.extend(done)
    spans = split_spans(text)
    out = text
    # Pass 1 -- text passes (reg_realloc / commutative_swap / laform). Splice from
    # the tail so earlier (start,end) offsets stay valid; words are always assembled
    # from the ON-DISK cc1 .s (unmodified until the pass-1 write below).
    for name, start, end in sorted(spans, key=lambda x: -x[1]):
        if name not in manifest:
            continue
        passes = [p for p in manifest[name].get("passes", []) if p not in META_PASSES]
        text_passes = [p for p in passes if p not in WORD_PASSES]
        if not text_passes:
            if any(p in WORD_PASSES for p in passes):
                rewrote.append(name)
            continue
        tgt = target_words(ctx["asm_root"], name)
        if tgt is None:
            raise RuntimeError("no target .s found for %s under %s"
                               % (name, ctx["asm_root"]))
        tgt = _strip_trailing_pad(tgt)

        # Split the recipe around sigma: count-changing PRE_SIGMA passes (e.g.
        # un_hi_cse) run first so sigma is derived from count-aligned assembly.
        pre = [p for p in text_passes if p in PRE_SIGMA_PASSES]
        rest = [p for p in text_passes if p not in PRE_SIGMA_PASSES]
        span = out[start:end]
        _SPAN_INFO["void"] = bool(re.search(
            r"\.def\s+%s;\s*\.val\s+%s;\s*\.scl\s+2;\s*\.type\s+0x21;"
            % (re.escape(name), re.escape(name)), out))
        for p in pre:
            span = PASSES[p](span, tgt)
        if pre:                             # re-assemble to align sigma to remat form
            out_pre = out[:start] + span + out[end:]
            _write_bytes_str(s_file, out_pre)
        our, err = assemble_words(ctx, s_file, name)
        if err:
            raise RuntimeError("assemble %s:\n%s" % (name, err))
        our = _strip_trailing_pad(our)
        sigma, _conf = derive_sigma(our, tgt)
        if "reg_realloc_inj" in rest:
            _SPAN_INFO["sigma_inj"] = derive_sigma_inj(our, tgt)
        norm = normalize_span_text(span, tgt, sigma, rest)
        out = out[:start] + norm + out[end:]
        if pre:                             # keep disk in sync for the next span
            _write_bytes_str(s_file, out)
        if name not in rewrote:
            rewrote.append(name)
    _SPAN_INFO.clear()

    # Pass 2 -- word passes. These need the ASSEMBLED words of the text-normalized
    # code, so write pass 1 to disk first and assemble each span in full-file
    # context. Reordering ops (delay_fill / epilogue_unfill) run before padnop,
    # because they change the word count and padnop must re-measure after them.
    word_funcs = [n for n in manifest
                  if any(p in WORD_PASSES for p in manifest[n].get("passes", []))]
    if word_funcs:
        # 2a -- reordering passes (source rewrite + `.set noreorder`)
        _write_bytes_str(s_file, out)
        for name, start, end in sorted(split_spans(out), key=lambda x: -x[1]):
            if name not in word_funcs:
                continue
            reorder = [p for p in manifest[name]["passes"]
                       if p in ("delay_fill", "epilogue_unfill", "reorder_indep",
                                "reorder_indep_nops", "prologue_save_hoist",
                                "delay_slot_select", "decouple_reg",
                                "delay_decouple", "reorder_deep")]
            if not reorder:
                continue
            our, err = assemble_words(ctx, s_file, name)
            if err:
                raise RuntimeError("assemble %s (reorder):\n%s" % (name, err))
            tgt = target_words(ctx["asm_root"], name)
            if tgt is None:
                raise RuntimeError("no target .s for %s under %s"
                                   % (name, ctx["asm_root"]))
            tgt = _strip_trailing_pad(tgt)

            def _reasm(span_txt, _s=start, _e=end, _n=name):
                """Refresh the assembled words from the current (partially reordered)
                span so a later word-consuming pass sees the real schedule. Writes the
                whole file with only this span replaced; earlier (higher-offset) spans
                are already edited in `out`, later (lower-offset) spans are untouched
                and still assemble, and this span's own words are what we need."""
                _write_bytes_str(s_file, out[:_s] + span_txt + out[_e:])
                w, werr = assemble_words(ctx, s_file, _n)
                if werr:
                    raise RuntimeError("assemble %s (reorder-refresh):\n%s" % (_n, werr))
                return _strip_trailing_pad(w)

            new_span = emit_noreorder_span(out[start:end], tgt, our, reorder,
                                           reassemble=_reasm)
            out = out[:start] + new_span + out[end:]

        # 2b -- padnop (pure text append; re-measure against post-reorder words)
        _write_bytes_str(s_file, out)
        for name, start, end in sorted(split_spans(out), key=lambda x: -x[1]):
            if name not in word_funcs:
                continue
            if "padnop" not in manifest[name]["passes"]:
                continue
            our, err = assemble_words(ctx, s_file, name)
            if err:
                raise RuntimeError("assemble %s (padnop):\n%s" % (name, err))
            tgt_full = target_words_full(ctx["asm_root"], name)
            if tgt_full is None:
                raise RuntimeError("no target .s for %s under %s"
                                   % (name, ctx["asm_root"]))
            our_hex = [w for w, _ in our]
            new_span, _fired = apply_padnop(out[start:end], our_hex, tgt_full)
            out = out[:start] + new_span + out[end:]

    # Pass 3 -- bind C switch tables to the retail jump tables
    for name, start, end in sorted(split_spans(out), key=lambda x: -x[1]):
        if name in manifest:
            out = out[:start] + jtbl_bind(out[start:end], name, ctx.get("asm_root")) + out[end:]
    _write_bytes_str(s_file, out)
    return sorted(set(rewrote))
