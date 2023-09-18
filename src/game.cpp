#include <graphx.h>
#include <ti/getcsc.h>
#include <debug.h>
#include "player.cpp"
#include "map.cpp"

#ifndef GAME

class Game
{
public:

	// Start the game
	void run()
	{
		dbg_printf("[Crossy Road] Starting game.\n");

		// Setup graphics stuff
		gfx_Begin();
		gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    	gfx_SetTransparentColor(2);
    	gfx_SetDrawBuffer();

		// Keep track of player input
		uint8_t key;


		
		// Create a new map
		Map map;



		// Main game loop
		do
		{
			// Get the player key input
			key = os_GetCSC();


			// Render everything
			map.render();
        	gfx_SwapDraw();
			
		} while (key != sk_Clear);

		// End the program
		gfx_End();

		dbg_printf("[Crossy Road] Ending game.\n");
	}

};

#endif