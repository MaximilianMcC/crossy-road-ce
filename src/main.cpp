#include <ti/screen.h>
#include <debug.h>
#include "game.h"

int main()
{
	// Clear the screen
	os_ClrHome();	

	// Create, then run the game
	Game game;
	game.start();

	// Exit
	return 0;
}