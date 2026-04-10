# cub3D

A raycasting engine in C using MinilibX, rendering a pseudo-3D first-person view from a 2D tile map — inspired by Wolfenstein 3D.

## Architecture

```
┌─────────────────────────────────────────┐
│              Main Loop                  │
│  mlx_loop_hook → render_hook()          │
├────────────┬────────────────────────────┤
│  Input     │  Rendering Pipeline        │
│  hook.c    │                            │
│  ┌───────┐ │  rays() ──► For each column│
│  │W/A/S/D│ │    ├─ check_horizontal()   │
│  │←  →   │ │    ├─ check_vertical()     │
│  │ ESC   │ │    ├─ check_hit()          │
│  └───────┘ │    └─ draw()               │
│            │        ├─ wall_image()     │
│            │        ├─ texture sampling │
│            │        └─ put_pixel()      │
├────────────┴────────────────────────────┤
│  Parser (parser.c)                      │
│  .cub file → textures + colors + map    │
├─────────────────────────────────────────┤
│  MinilibX (X11 window + image buffer)   │
└─────────────────────────────────────────┘
```

## Tech Stack

| Component | Detail |
|-----------|--------|
| Language | C (42 Norm compliant) |
| Graphics | MinilibX (X11/XShm wrapper) |
| Algorithm | DDA Raycasting |
| Textures | XPM file format, 64×64 tiles |
| Build | Makefile, `cc -Wall -Wextra -Werror` |
| Dependencies | libft, MinilibX, X11, Xext, math |

## Building & Running

```bash
make
./cub3D maps/map.cub
```

### Controls

| Key | Action |
|-----|--------|
| W / S | Move forward / backward |
| A / D | Strafe left / right |
| ← / → | Rotate camera |
| ESC | Quit |

## Map Format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 135,206,235

111111
100101
101001
1100N1
111111
```

`0` = floor, `1` = wall, `N/S/E/W` = player spawn + facing direction.

## Key Engineering Decisions

- **DDA raycasting with separate horizontal/vertical checks** ([src/check_horizontal.c](src/check_horizontal.c), [src/check_vertical.c](src/check_vertical.c)): Each ray checks horizontal and vertical grid intersections independently, then the shorter distance wins. This avoids the overhead of a unified step-based DDA while keeping wall-face detection trivial.

- **Fisheye correction** ([src/draw_utils.c](src/draw_utils.c)): Raw ray distances are multiplied by `cos(playerAngle - rayAngle)` to eliminate the fisheye distortion inherent in per-column raycasting.

- **Texture-mapped walls** ([src/draw.c](src/draw.c), [src/draw_utils.c](src/draw_utils.c) `wall_image()`): Wall texture selection is based on which face was hit (N/S/E/W), and the texture column (`tx`) is derived from the fractional hit position. Vertical texture coordinate (`ty`) is stepped per screen-pixel for correct perspective scaling.

- **Named constants for tuning** ([inc/defines.h](inc/defines.h)): All magic numbers — `RAY_MAX_DIST`, `ROTATION_SPEED`, `MOVE_SPEED`, `COLLISION_MARGIN`, `RAY_OFFSET` — are defined as named constants, making the engine easy to tune without hunting through source files.

- **Bounds-safe raycasting** ([src/check_horizontal.c](src/check_horizontal.c), [src/check_vertical.c](src/check_vertical.c)): Grid coordinates are validated against map dimensions before array access, with an early return on out-of-bounds to prevent undefined behavior.
