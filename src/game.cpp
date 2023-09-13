#include "game.h"
#include <graphx.h>
#include <ti/getcsc.h>
#include <debug.h>
#include "player.h"

// Start the game
void Game::start()
{
	gfx_Begin();
	dbg_printf("[Crossy Road] Starting game.\n");



	// Create a new player
	Player player;


	// Main game loop
	while (true)
	{
		// Get keyboard input
		uint8_t key = os_GetCSC();
		if (key == sk_Clear) break;



		// Update everything in the game
		player.update();



		// Render everything in the game
		gfx_FillScreen(0);
		player.draw();
		gfx_SwapDraw();
	}
	

	gfx_End();
}