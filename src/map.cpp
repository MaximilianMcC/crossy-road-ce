#include <graphx.h>
#include <time.h>
#include "gfx/gfx.h"
#include <debug.h>

// Get the tilemap data
extern unsigned char map[];

#ifndef MAP


// Tile map settings and stuff
#define TILE_SIZE 32

// TODO: Play around with these until something good pops up. Maybe do some sus maths
//☝️ Original crossy road has 9 available spaces. to move, then the outside is always tree. 11 total spaces.
#define ROWS 11
#define COLUMNS 20
#define TILEMAP_DRAW_WIDTH 11 // How many tiles to draw on x
#define TILEMAP_DRAW_HEIGHT 8 // How many tiles to draw on y


// All of the tiles in the tilemap
#define UNKNOWN_TILE 0x0
#define DEBUG_TILE 0x8
#define GRASS_TILE_1 0x1
#define GRASS_TILE_2 0x2
#define ROCK_TILE_1 0x3
#define ROCK_TILE_2 0x4
#define TREE_TILE_1 0x5
#define TREE_TILE_2 0x6
#define WATER_TILE_1 0x7
#define ROAD_TILE_1 0x9



class Map
{
public:
	gfx_tilemap_t tilemap;

	Map()
	{
		// Set the random seed as the current time
		// so that the map generation can be random
		srand(time(NULL));

		
		// Initialize the tilemap
		tilemap.map = map;
		tilemap.tiles = tileset_tiles;

		// Set the tilemap tile size
		tilemap.type_width = gfx_tile_32_pixel;
		tilemap.type_height = gfx_tile_32_pixel;
		tilemap.tile_height = TILE_SIZE;
		tilemap.tile_width = TILE_SIZE;

		// Set the tilemap dimensions
		tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
		tilemap.draw_width = TILEMAP_DRAW_WIDTH;
		tilemap.width = ROWS;
		tilemap.height = COLUMNS;

		// Make everything in the centre on the X, and at the bottom on the Y
		tilemap.y_loc = 0;
		tilemap.x_loc = -16;
	}

	// Draw the map to the screen
	void render()
	{
		// Draw the tilemap
		gfx_Tilemap(&tilemap, 0, 0);
	}


	// Add a row to the map, and remove the previous ones
	void addRow()
	{
		// Default empty row
		uint8_t row[ROWS] = { UNKNOWN_TILE };

		// Decide if the row is going to be a road, river, or nothing
		if (percentage(40))
		{
			// Make the entire row a road
			for (uint8_t i = 0; i < ROWS; i++)
			{
				row[i] = ROAD_TILE_1;
			}

			// TODO: Save the current row position or something so that cars can spawn
			// TODO: roadPositions = i;
		}
		else if (percentage(25))
		{
			// Make the entire row a road
			for (uint8_t i = 0; i < ROWS; i++)
			{
				row[i] = WATER_TILE_1;
			}

			// TODO: Save the current row position or something so that logs can spawn
			// TODO: riverPositions = i;
		}
		else
		{
			// Loop through all of the different tiles in the row
			for (uint8_t i = 0; i < ROWS; i++)
			{
				// Choose for if an obstacle should be placed or not
				if (percentage(35))
				{
					// Pick a tile to place
					const uint8_t tileCount = 4; // TODO: Make this a definition
					uint8_t tiles[tileCount] = { TREE_TILE_1, TREE_TILE_2, ROCK_TILE_1, ROCK_TILE_2 };
					row[i] = tiles[(rand() % tileCount)];
				}
				else row[i] = tileChoice(GRASS_TILE_1, GRASS_TILE_2);
			}

			// Overwrite the first and last tile with a random tree to create the border
			row[0] = tileChoice(TREE_TILE_1, TREE_TILE_2);
			row[ROWS - 1] = tileChoice(TREE_TILE_1, TREE_TILE_2);

			// Overwrite the middle tile to make there always a guaranteed chance for there to be a clean path to the next row
			row[5] = tileChoice(GRASS_TILE_1, GRASS_TILE_2);
		}
	}

private:

	bool percentage(uint8_t percentage)
	{
		// Get a random number from 1-100
		const uint8_t chance = rand() % 100;
		return chance <= percentage;
	}

	uint8_t tileChoice(uint8_t tile1, uint8_t tile2)
	{
		// 50% chance to spawn each tile
		return percentage(50) ? tile1 : tile2;

		// TODO: Make method overload for more than 2
	}
};

#endif