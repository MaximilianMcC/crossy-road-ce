#include "game.h"
#include <graphx.h>
#include <ti/getcsc.h>
#include <debug.h>

// Start the game
void Game::start()
{
	gfx_Begin();
	dbg_printf("[Crossy Road] Starting game.\n");

	// Main game loop
	while (true)
	{
		// Get keyboard input
		uint8_t key = os_GetCSC();
		if (key == sk_Clear) break;

		gfx_PrintStringXY("Hello, world!", 50, 50);
	}
	

	gfx_End();
}