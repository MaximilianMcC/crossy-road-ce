#include <graphx.h>
#include <ti/getcsc.h>
#include <debug.h>
#include "player.cpp"
#include "gfx/gfx.h" // Created using `make gfx`

#ifndef GAME

class Game
{
public:

	// Start the game
	void start()
	{
		// Setup graphics stuff
		gfx_Begin();
		gfx_SetPalette(global_palette, sizeof_global_palette, 0);
		gfx_SetTransparentColor(0);
		dbg_printf("[Crossy Road] Starting game rn.\n");



		// Create a new player
		Player player;


		// Main game loop
		while (true)
		{
			// Get keyboard input
			uint8_t key = os_GetCSC();
			if (key == sk_Clear) break;



			// Update everything in the game
			player.update(key);



			// Render everything in the game
			gfx_FillScreen(2);
			gfx_Sprite(blue, 0, 0);
			player.draw();
			gfx_SwapDraw();
		}
		

		dbg_printf("[Crossy Road] Ending game.\n");
		gfx_End();
	}

};

#endif