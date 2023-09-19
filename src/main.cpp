#include <ti/screen.h>
#include <debug.h>
#include "game.cpp"

int main()
{
	// Clear the screen
	os_ClrHome();	

	// Create, then run the game
	Game game;
	game.run();

	// Get rid of any crap that may have been left behind when exiting
	os_ClrHome();

	// Exit
	return 0;
}