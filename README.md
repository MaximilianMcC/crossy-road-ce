# Crossy Road CE
A simplified version of the game [crossy road](https://en.wikipedia.org/wiki/Crossy_Road) made for the TI 84 Plus CE graphing calculator. This project is also being used for NCEA Level 3 DTS. You can view the project management side of it [here](https://github.com/users/MaximilianMcC/projects/4).

## Project versions
The end goal is to get a game that looks like crossy road. Because I only have basically a week to create this, I will first be creating it in 2D. In the second version of this game I will be including isometric graphics. This first version is simple 2D top down, however this is temporary.

## Notes and stuff for when I'm developing
- Run `make` for normal compiling
- Run `make debug` for compiling with debugging features like CEmu console
- Run `make gfx` to convert graphics to binary
- To make a part of an image make the part that you want transparent `#ff0080`/`255, 0, 128`

### All textures/tiles into stuff:
| Texture Name | Texture Count | Sprite Sheet Index | 
|--------------|---------------|--------------------|
| grass | 1 | `0x0` - `0000` |
| grass | 2 | `0x1` - `1000` |
| tree | 1 | `0x2` - `0100` |
| tree | 2 | `0x3` - `1100` |
| rock | 1 | `0x4` - `0010` |
| rock | 2 | `0x5` - `1010` |
| rock | 3 | `0x6` - `0110` |
| lillypad | 1 | `0x7` - `1110` |
| lillypad | 2 | `0x8` - `0001` |
| water | 1 | `0x9` - `1001` |

### Tile binary bit structure thing
| Bit index | What it is | Example |
|-----------|------------|---------|
| 1 (**0**00000) | Tile has collisions or not | `01` no collisions, grass or something |
| 2 (0**0**0000) | Tile can kill the player or not | `1` water kills the player |
| 3-6 (00**0000**) | Tile sprite sheet index | `0010` is the 4th sprite |