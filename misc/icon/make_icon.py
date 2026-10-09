#!/usr/bin/env python3
"""App icon for the PC port: misc/icon/dw2.ico (16..256) and host/icon_rgba.h.

Original artwork, drawn here: a rounded badge with an orange to gold sunburst, a few
"digital" squares and the letters DW2 in cyan to blue with a dark navy outline. No game
data is used. Each size is drawn at 4x and scaled down so the small sizes stay sharp.

  venv/Scripts/python.exe misc/icon/make_icon.py

Writes dw2.ico (built into dw2.exe through host/dw2.rc), build/icon_preview.png (all sizes side
by side, not used by the build) and host/icon_rgba.h (64x64 RGBA for SDL_SetWindowIcon on
Linux). Needs a bold italic font from C:/Windows/Fonts (Segoe UI Black Italic first).
"""

import math
import os
import sys

from PIL import Image, ImageDraw, ImageFilter, ImageFont

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
ICO = os.path.join(HERE, "dw2.ico")
PREVIEW = os.path.join(ROOT, "build", "icon_preview.png")
HEADER = os.path.join(ROOT, "host", "icon_rgba.h")

SIZES = [16, 24, 32, 48, 64, 128, 256]
SS = 4
TEXT = "DW2"

BG_TOP = (255, 214, 64)
BG_MID = (255, 150, 20)
BG_BOTTOM = (196, 70, 8)
RAY = (255, 248, 200)
NAVY = (8, 22, 70)
TXT_HI = (235, 255, 255)
TXT_MID = (70, 215, 255)
TXT_LO = (18, 110, 235)

FONTS = ["seguibli.ttf", "ariblk.ttf", "impact.ttf", "segoeuib.ttf"]


def font_path():
    for name in FONTS:
        p = os.path.join(os.environ.get("WINDIR", "C:/Windows"), "Fonts", name)
        if os.path.exists(p):
            return p
    sys.exit("no bold font found in C:/Windows/Fonts")


def gradient(w, h, stops):
    """Vertical gradient through (t, rgb) stops."""
    col = Image.new("RGB", (1, h))
    for y in range(h):
        t = y / max(1, h - 1)
        for (t0, c0), (t1, c1) in zip(stops, stops[1:]):
            if t0 <= t <= t1:
                k = (t - t0) / max(1e-6, t1 - t0)
                col.putpixel((0, y), tuple(int(c0[i] + (c1[i] - c0[i]) * k) for i in range(3)))
                break
    return col.resize((w, h)).convert("RGBA")


def badge_mask(c, radius):
    m = Image.new("L", (c, c), 0)
    ImageDraw.Draw(m).rounded_rectangle([0, 0, c - 1, c - 1], radius=radius, fill=255)
    return m


def fit_font(path, target_w, target_h):
    lo, hi, best = 4, target_h * 2, 4
    probe = ImageDraw.Draw(Image.new("L", (4, 4)))
    while lo <= hi:
        mid = (lo + hi) // 2
        l, t, r, b = probe.textbbox((0, 0), TEXT, font=ImageFont.truetype(path, mid))
        if r - l <= target_w and b - t <= target_h:
            best, lo = mid, mid + 1
        else:
            hi = mid - 1
    return ImageFont.truetype(path, best)


def render(size, path, letters=True):
    c = size * SS
    mask = badge_mask(c, int(c * 0.2))
    img = Image.new("RGBA", (c, c), (0, 0, 0, 0))
    img.paste(gradient(c, c, [(0.0, BG_TOP), (0.5, BG_MID), (1.0, BG_BOTTOM)]), (0, 0), mask)

    deco = Image.new("RGBA", (c, c), (0, 0, 0, 0))
    d = ImageDraw.Draw(deco)
    cx, cy = c * 0.5, c * 0.42
    if size >= 32:
        # Sunburst rays from just above the centre.
        n = 14
        for i in range(n):
            a0 = 2 * math.pi * i / n
            a1 = a0 + math.pi / n * 0.55
            r = c * 1.2
            d.polygon([(cx, cy), (cx + r * math.cos(a0), cy + r * math.sin(a0)),
                       (cx + r * math.cos(a1), cy + r * math.sin(a1))], fill=RAY + (70,))
        # Digital squares, top left and bottom right.
        for fx, fy, fs, a in [(0.12, 0.12, 0.07, 150), (0.22, 0.08, 0.045, 110),
                              (0.08, 0.25, 0.04, 90), (0.80, 0.80, 0.07, 120),
                              (0.70, 0.86, 0.045, 90), (0.88, 0.68, 0.04, 80)]:
            s = c * fs
            d.rectangle([c * fx, c * fy, c * fx + s, c * fy + s], fill=(255, 255, 230, a))
    glow = Image.new("L", (c, c), 0)
    ImageDraw.Draw(glow).ellipse([cx - c * 0.42, cy - c * 0.32, cx + c * 0.42, cy + c * 0.32], fill=150)
    glow = glow.filter(ImageFilter.GaussianBlur(c * 0.08))
    deco = Image.alpha_composite(deco, Image.composite(Image.new("RGBA", (c, c), RAY + (255,)),
                                                       Image.new("RGBA", (c, c), (0, 0, 0, 0)), glow))
    deco.putalpha(Image.composite(deco.getchannel("A"), Image.new("L", (c, c), 0), mask))
    img = Image.alpha_composite(img, deco)

    if not letters:
        return img.resize((size, size), Image.LANCZOS)

    # Letters: outline width scales with the size, thicker on small icons so they read.
    pad = c * (0.03 if size <= 24 else 0.07)
    stroke = max(1, int(c * (0.05 if size <= 24 else 0.035)))
    font = fit_font(path, c - 2 * pad - 2 * stroke, c * 0.7)
    pos = (c / 2, c * 0.53)
    fill = Image.new("L", (c, c), 0)
    ImageDraw.Draw(fill).text(pos, TEXT, font=font, fill=255, anchor="mm")
    outline = Image.new("L", (c, c), 0)
    ImageDraw.Draw(outline).text(pos, TEXT, font=font, fill=255, anchor="mm",
                                 stroke_width=stroke, stroke_fill=255)
    if size >= 32:
        shadow = outline.filter(ImageFilter.GaussianBlur(c * 0.02))
        shadow = Image.eval(shadow, lambda v: v * 0.6)
        off = int(c * 0.025)
        img = Image.alpha_composite(img, Image.composite(
            Image.new("RGBA", (c, c), (40, 10, 0, 255)), Image.new("RGBA", (c, c), (0, 0, 0, 0)),
            shadow.transform((c, c), Image.AFFINE, (1, 0, -off, 0, 1, -off))))
    img.paste(Image.new("RGBA", (c, c), NAVY + (255,)), (0, 0), outline)
    img.paste(gradient(c, c, [(0.0, TXT_HI), (0.45, TXT_MID), (0.75, TXT_LO), (1.0, TXT_LO)]), (0, 0), fill)
    if size >= 48:
        # Shine band across the upper half of the letters.
        shine = Image.new("L", (c, c), 0)
        ImageDraw.Draw(shine).rectangle([0, 0, c, c * 0.47], fill=90)
        shine = Image.composite(shine, Image.new("L", (c, c), 0), fill)
        img = Image.alpha_composite(img, Image.composite(
            Image.new("RGBA", (c, c), (255, 255, 255, 255)), Image.new("RGBA", (c, c), (0, 0, 0, 0)), shine))

    bw = max(1, int(c * 0.018))
    ImageDraw.Draw(img).rounded_rectangle([bw // 2, bw // 2, c - 1 - bw // 2, c - 1 - bw // 2],
                                          radius=int(c * 0.2), outline=(120, 40, 0, 200), width=bw)
    return img.resize((size, size), Image.LANCZOS)


# 16 px: hand-placed pixel letters (a scaled font blurs into one blob at this size).
GLYPHS_16 = {
    "D": ["###.", "#..#", "#..#", "#..#", "#..#", "#..#", "###."],
    "W": ["#...#", "#...#", "#...#", "#.#.#", "#.#.#", "##.##", "#...#"],
    "2": ["###", "..#", "..#", "###", "#..", "#..", "###"],
}
ROWS_16 = [TXT_HI, TXT_MID, TXT_MID, TXT_MID, TXT_LO, TXT_LO, TXT_LO]


def render16(path):
    img = render(16, path, letters=False)
    px = img.load()
    on = set()
    x = 1
    for ch in TEXT:
        rows = GLYPHS_16[ch]
        for y, row in enumerate(rows):
            for i, v in enumerate(row):
                if v == "#":
                    on.add((x + i, 4 + y))
        x += len(rows[0]) + 1
    for (x, y) in {(x + dx, y + dy) for x, y in on for dx in (-1, 0, 1) for dy in (-1, 0, 1)}:
        if 0 <= x < 16 and 0 <= y < 16:
            px[x, y] = NAVY + (255,)
    for (x, y) in on:
        px[x, y] = ROWS_16[y - 4] + (255,)
    return img


def write_header(img):
    data = img.tobytes()
    lines = ["/* Generated by misc/icon/make_icon.py: 64x64 RGBA window icon (original art). */",
             "#define DW2_ICON_W 64", "#define DW2_ICON_H 64",
             "static const unsigned char dw2_icon_rgba[64 * 64 * 4] = {"]
    for i in range(0, len(data), 16):
        lines.append("    " + ", ".join("0x%02x" % v for v in data[i:i + 16]) + ",")
    lines.append("};")
    with open(HEADER, "w", newline="\n") as f:
        f.write("\n".join(lines) + "\n")


def main():
    path = font_path()
    frames = {s: render(s, path) for s in SIZES}
    frames[16] = render16(path)
    frames[256].save(ICO, format="ICO", sizes=[(s, s) for s in SIZES],
                     append_images=[frames[s] for s in SIZES[:-1]])
    write_header(frames[64])
    prev = Image.new("RGBA", (sum(SIZES) + 12 * len(SIZES) + 12, 280), (40, 40, 46, 255))
    x = 12
    for s in reversed(SIZES):
        prev.alpha_composite(frames[s], (x, (280 - s) // 2))
        x += s + 12
    os.makedirs(os.path.dirname(PREVIEW), exist_ok=True)
    prev.save(PREVIEW)
    for p in (ICO, PREVIEW, HEADER):
        print(os.path.relpath(p, ROOT), os.path.getsize(p))


if __name__ == "__main__":
    main()
