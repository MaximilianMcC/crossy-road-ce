#include <graphx.h>
#include <time.h>

#ifndef MAP

// Map settings
#define ROWS 15 // tiles on the x
#define COLUMNS 11 // Tiles on the y
#define TILE_SIZE 21 //? 320/15 = 21.3

class Map
{
public:
	

	//todo the player can go backwards but cant go off screen/scroll screen backwards.

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
	void addRow(uint8_t previousRow[ROWS])
	{
		// TODO: Use the previous row to change generation. For example, if the previous row was water, also make this water, but if there were 5 previous waters make this land

		uint8_t row[ROWS];

		// Determine if the whole row is going to be water or not (20% chance)
		bool water = false;
		if (percentage(20)) water = true;

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
				// No collision (1 = 1)
				tile |= (1 << 1);

				// Can kill the player (2 = 1)
				tile |= (1 << 2);

				// Texture index of 9 (3-6 = 1001)
				//! Clearing will slow down, but its barely noticeable. If speed is ABSOLUTELY needed then remove, otherwise keep because its easier to read
				//? `~` flips a bit. for example, 001 flipped would be 100. for setting to 0 can also use (0 << index), but apparently ~(1 << index) is standard practice
				tile |= (1 << 3);
				tile &= ~(1 << 4);
				tile &= ~(1 << 5);
				tile |= (1 << 6);

				// Make the next tile
				continue;
			}

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
				
			}
		}
		
	}



private:

	// The map
	uint8_t map[ROWS * COLUMNS];



	// Percentage
	bool percentage(short percentage)
	{
		// Get a random number from 1-100
		int chance = (rand() % 100) + 1;
		return chance <= percentage;
	}

};

#endif