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

	// Exit
	return 0;
}