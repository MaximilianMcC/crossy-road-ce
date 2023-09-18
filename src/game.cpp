#include <graphx.h>
#include <ti/getcsc.h>
#include <debug.h>
#include "player.cpp"
#include "map.cpp"
#include "gfx/gfx.h"

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
		






		// End the program
		gfx_End();

		dbg_printf("[Crossy Road] Ending game.\n");
	}

};

#endif