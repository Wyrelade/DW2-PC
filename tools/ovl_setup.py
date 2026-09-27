"""ovl_setup.py: splat configs for the 7 stage overlays (AAA/3.PRO/STAG*.PRO, load address 0x80063360).

Writes configs/USA/stagXXXX.yaml + configs/USA/sym.stagXXXX.txt, copies the overlay to dumps/disc/,
prints the table (size, text start/end, sha1) for tools/build_dw2.py. Then run
`python3 -m splat split configs/USA/stagXXXX.yaml` per overlay.

Source: assets/disc/AAA/3.PRO (a `dumpsxiso -pt` extract of your own disc).
STAG2000.PRO is 0xDBEE bytes; splat drops the odd 2-byte tail, so after a re-split add
`.short 0x0000` at the end of asm/USA/stag2000/data/stag2000_data.data.s.
Rerunning this overwrites the yaml files (keep any hand edits)."""
import glob, hashlib, os, re, shutil, struct
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
BASE = 0x80063360


def asciiish(x):
    b = x.to_bytes(4, 'little')
    return all(c == 0 or c == 10 or 0x20 <= c < 0x7F for c in b) and sum(0x20 <= c < 0x7F for c in b) >= 2


def ptr(x):
    return 0x80000000 <= x < 0x80200000


main_syms = []
for l in open('configs/USA/sym.main.txt', encoding='utf-8'):
    m = re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;(.*)$', l)
    if m:
        main_syms.append((m.group(1), int(m.group(2), 16), l.rstrip('\n')))

rows = []
for f in sorted(glob.glob('assets/disc/AAA/3.PRO/STAG*.PRO')):
    stem = os.path.basename(f)[:-4]            # STAG1000
    low = stem.lower()
    d = open(f, 'rb').read()
    n = len(d) // 4
    w = [struct.unpack_from('<I', d, i * 4)[0] for i in range(n)]
    jr = [i for i in range(n) if w[i] == 0x03E00008]
    pro = [i for i in range(n) if (w[i] >> 16) == 0x27BD and (w[i] & 0x8000)]
    s = pro[0]
    while s > 0 and not ptr(w[s - 1]) and w[s - 1] != 0 and not asciiish(w[s - 1]):
        s -= 1
    e = jr[-1] + 2
    ts, te = s * 4, e * 4
    sha = hashlib.sha1(d).hexdigest()
    os.makedirs('dumps/disc/AAA/3.PRO', exist_ok=True)
    shutil.copyfile(f, 'dumps/disc/AAA/3.PRO/%s.PRO' % stem)
    end = BASE + len(d)
    # main exe symbols the overlay can reference: everything outside the overlay's own range
    syms = [l for name, a, l in main_syms if not (BASE <= a < end)]
    open('configs/USA/sym.%s.txt' % low, 'w', encoding='utf-8', newline='\n').write('\n'.join(syms) + '\n')
    subs = []
    if ts:
        subs.append('      - [0x0, rodata, %s_rodata]' % low)
    subs.append('      - [0x%X, c, %s]' % (ts, low))
    if te < len(d):
        subs.append('      - [0x%X, data, %s_data]' % (te, low))
    y = '''name: Stage overlay %(stem)s.PRO
sha1: %(sha)s
options:
  basename: %(low)s
  target_path: dumps/disc/AAA/3.PRO/%(stem)s.PRO
  base_path: ../..
  platform: psx
  compiler: PSYQ

  asm_path: asm/USA/%(low)s
  src_path: src/%(low)s
  build_path: build/USA
  ld_script_path: linkers/USA/%(low)s.ld
  elf_path: build/USA/%(low)s.elf
  ld_dependencies: False

  find_file_boundaries: True
  migrate_rodata_to_functions: False
  pair_rodata_to_text: False
  gp_value: 0x800506F8

  o_as_suffix: False
  use_legacy_include_asm: False

  asm_function_macro: glabel
  asm_jtbl_label_macro: jlabel
  asm_data_macro: dlabel
  generate_asm_macros_files: False

  section_order: [".rodata", ".text", ".data", ".sdata", ".sbss", ".bss"]

  symbol_addrs_path:
    - configs/USA/sym.%(low)s.txt

  undefined_funcs_auto_path: linkers/USA/undefined_funcs_auto.%(low)s.txt
  undefined_syms_auto_path: linkers/USA/undefined_syms_auto.%(low)s.txt

  subalign: 4

  string_encoding: ASCII
  data_string_encoding: ASCII
  rodata_string_guesser_level: 2
  data_string_guesser_level: 2

  ld_bss_is_noload: True

# Stage overlay: loaded by Ovl_Load (main exe) to 0x80063360, over the main exe's
# .data there. Text range found by scanning for the first prologue / last `jr ra`.
segments:
  - name: %(low)s
    type: code
    start: 0x0
    vram: 0x80063360
    align: 4
    subalign: 4
    subsegments:
%(subs)s
  - [0x%(size)X]
''' % dict(stem=stem, low=low, sha=sha, subs='\n'.join(subs), size=len(d))
    open('configs/USA/%s.yaml' % low, 'w', encoding='utf-8', newline='\n').write(y)
    rows.append((stem, len(d), ts, te, sha))
for r in rows:
    print('%s size 0x%X text 0x%X-0x%X sha1 %s' % r)
