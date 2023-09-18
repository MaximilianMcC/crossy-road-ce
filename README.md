# ***Crossy Road CE***
A simplified version of the game *[crossy road](https://en.wikipedia.org/wiki/Crossy_Road)* made for the *TI-84 Plus CE* graphing calculator. This project is also being used for NCEA Level 3 DTS. You can view the project management side of it [here](https://github.com/users/MaximilianMcC/projects/4).

## Project versions
The end goal is to get a game that looks and plays like crossy road. Because I only have basically a week to create this, I will first be creating it in 2D. In the second version of this game I will be including isometric graphics. This first version is simple 2D top down style, however this is temporary. Once this project doesn't carry the weight of school I will begin to implement additional features and graphical improvements.

This is currently the second version of the project. In the first version I massively overcomplicated everything.

## Developer notes
- `make gfx` to compile images to binary
- `make` for code to be ran on hardware
- `make debug` for emulator code
- If debugging versions aren't updating, do `make clean` to remove all compiled stuff

### Tiles
To be efficient, tiles are stored as a single hexadecimal number. Below is the lookup table for all of the tiles:
| Name  | Index | Collision |
|-------|-------|:---------:|
| Grass | `0x0` | ❌        |
| Grass | `0x1` | ❌        |
| Rock  | `0x2` | ✅        |
| Rock  | `0x3` | ✅        |
| Tree  | `0x4` | ✅        |
| Tree  | `0x5` | ✅        |
| Water | `0x6` | ❌        |
| Road  | `0x7` | ❌        |
Tile map index starts at 0 and is automatically carried on to the next column