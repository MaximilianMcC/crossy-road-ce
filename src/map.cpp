#include <graphx.h>
#include <time.h>
#include "gfx/gfx.h"
#include <debug.h>

// Get the tilemap data
extern unsigned char tilemapMap[];

#ifndef MAP


// Tile map settings and stuff
#define TILE_SIZE 16

// TODO: Play around with these until something good pops up. Maybe do some sus maths
#define TILEMAP_WIDTH 32
#define TILEMAP_HEIGHT 25
#define TILEMAP_DRAW_WIDTH  20
#define TILEMAP_DRAW_HEIGHT 14




class Map
{
public:
	gfx_tilemap_t tilemap;

	Map()
	{
		// Set the random seed as the current time
		// so that the map generation can be random
		srand(time(NULL));

		// Initialize the tilemap structure
		tilemap.map = tilemapMap;
		tilemap.tiles = tileset_tiles;
		tilemap.type_width = gfx_tile_16_pixel;
		tilemap.type_height = gfx_tile_16_pixel;
		tilemap.tile_height = TILE_SIZE;
		tilemap.tile_width = TILE_SIZE;
		tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
		tilemap.draw_width = TILEMAP_DRAW_WIDTH;
		tilemap.height = TILEMAP_HEIGHT;
		tilemap.width = TILEMAP_WIDTH;
		tilemap.y_loc = -16; // 1 tile above the screen
		tilemap.x_loc = 0;
	}

	// Draw the map to the screen
	void render()
	{
		// Draw the tilemap
		gfx_Tilemap_NoClip(&tilemap, 0, 0);
	}


	// Add a row to the map
	void addRow()
	{
		
	}
};

#endif