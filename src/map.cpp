#include <graphx.h>
#include <time.h>
#include <debug.h>

#ifndef MAP

// Map settings
#define ROWS 15 // tiles on the x
#define COLUMNS 11 // Tiles on the y
#define TILE_SIZE 21 //? 320/15 = 21.3

class Map
{
public:
	

	// TODO: the player can go backwards but cant go off screen/scroll screen backwards.

	// TODO: Use const more

	Map()
	{
		// Set the random seed as the current time
		srand(time(NULL));

		// TODO: Generate the "spawn" part of the map (same every time) have it have heaps of trees and rocks and stuff
	}

	void render()
	{
		// Loop through all of the tiles
		for (short i = 0; i < COLUMNS; i++)
		{
			for (short j = 0; j < ROWS; j++)
			{

			}
		}
	}

	// Add a row to the map
	void addRow()
	{
		// TODO: Use the previous row to change generation. For example, if the previous row was water, also make this water, but if there were 5 previous waters make this land

		// Make an empty row
		uint8_t row[ROWS] = { };
		

		// Determine if the whole row is going to be water or not (20% chance)
		bool water = false;
		if (percentage(100)) water = true;
		dbg_printf("Water: %d\n", water);

		// Loop through every tile in the row
		// TODO: Use uint8/char instead of short because we dont need all that space and stuff
		for (short i = 0; i < ROWS; i++)
		{
			// Create the tile byte, with a default value of 0x000000
			//? Using uint8_t because its just an unsigned char, giving access to 256 bits
			uint8_t tile = 0;

			// Check for if the entire row is water and make the tile water
			if (water)
			{
				dbg_printf("Making water\n");

				// No collision (0 = 1)
				tile |= (1 << 0);

				// Can kill the player (1 = 1)
				tile |= (1 << 1);

				// Texture index of 9 (2-5 = 1001)
				tile |= (0x9 << 2);

				// Add the row to the tile then make the next tile
				row[i] = tile;
				continue;
			}

			dbg_printf("Finished generating water outside of loop\n");

			// Check for if the current tile is going to have an obstacle
			// chance for it to be is higher if closer to the edges (80% for edge, 40% for not edge)
			bool obstacle = false;
			if (i <= 3 || i >= (ROWS - 3)) obstacle = percentage(80);
			else obstacle = percentage(40);

			// The middle row MUST be clear so that there is always a guaranteed path for the player
			if (i == (ROWS / 2)) obstacle = false;


			// Check for if the tile is an obstacle, then give it a texture/obstacle type
			if (obstacle)
			{
				dbg_printf("Making obstacle\n");
				// Get a random sprite index from the lookup table
				// TODO: Remove the lookup table
				const uint8_t spriteCount = 7;
				const uint8_t spriteIndex = rand() % (spriteCount - 1);

				// Set the bits to the index
				tile |= (spriteIndex << 3);
			}

			// Add the completed tile to the row
			row[i] = tile;
		}



		//!DEBUG: Print the row
		for (size_t i = 0; i < ROWS; i++)
		{
			printBinary(row[i]);
		}
		
		
	}



private:

	// The map
	uint8_t map[ROWS * COLUMNS];



	// Percentage
	bool percentage(short percentage)
	{
		// Get a random number from 1-100
		int chance = rand() % 100;
		return chance <= percentage;
	}	



	//! debug stuff remove when done!!!
	void printBinary(char value) {

	    for (int i = 7; i >= 0; --i) {
	        dbg_printf("%c", (value & (1 << i)) ? '1' : '0');
    	}
		dbg_printf("\n");
	}
};

#endif