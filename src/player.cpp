#include <graphx.h>
#include <ti/getcsc.h>
#include <tice.h>
#include <debug.h>
#include "gfx/gfx.h"


#ifndef PLAYER

class Player
{
public:

	void update(uint8_t key)
	{
		movement(key);
	}

	// Draw/render the player
	void render()
	{

	}

private:

	// Move the player
	void movement(uint8_t key)
	{

	}

};


#endif