#include <graphx.h>
#include <time.h>
#include "gfx/gfx.h"
#include <debug.h>

// Get the tilemap data
extern unsigned char tilemapMap[];

#ifndef MAP


// Tile map settings and stuff
#define TILE_SIZE 32

// TODO: Play around with these until something good pops up. Maybe do some sus maths
//☝️ Original crossy road has 9 available spaces. to move, then the outside is always tree. 11 total spaces.
#define TILEMAP_WIDTH 11
#define TILEMAP_HEIGHT 20
#define TILEMAP_DRAW_WIDTH 11 // How many to draw on x
#define TILEMAP_DRAW_HEIGHT 8 // How many to draw on y


// All of the tiles in the tilemap
#define GRASS_TILE_1 0x0
#define GRASS_TILE_2 0x1
#define ROCK_TILE_1 0x2
#define ROCK_TILE_2 0x3
#define TREE_TILE_1 0x4
#define TREE_TILE_2 0x5
#define WATER_TILE_1 0x6
#define ROAD_TILE_1 0x7



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
		tilemap.map = tilemapMap;
		tilemap.tiles = tileset_tiles;

		// Set the tilemap tile size
		tilemap.type_width = gfx_tile_32_pixel;
		tilemap.type_height = gfx_tile_32_pixel;
		tilemap.tile_height = TILE_SIZE;
		tilemap.tile_width = TILE_SIZE;

		// Set the tilemap dimensions
		tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
		tilemap.draw_width = TILEMAP_DRAW_WIDTH;
		tilemap.height = TILEMAP_HEIGHT;
		tilemap.width = TILEMAP_WIDTH;

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


	// Add a row to the map
	void addRow()
	{
		
	}
};

#endif