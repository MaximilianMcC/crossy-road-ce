#include <graphx.h>
#include <ti/getcsc.h>
#include <debug.h>
#include "gfx/gfx.h" // Created using `make gfx`


#ifndef PLAYER

class Player
{
public:
	short x = 0;
	short y = 0;
	short shortGridPositionX = 0;
	short shortGridPositionY = 0;

	// Update the player's logic and stuff
	void update(uint8_t key)
	{
		movement(key);
	}

	// Draw/render the player
	void draw()
	{
		// gfx_SetTextFGColor(123);
		// gfx_PrintStringXY("i am the player (real)", x, y);
		gfx_Sprite(blue, 0, 0);
		// gfx_TransparentSprite_NoClip(test, x, y);
	}

private:
	
	#define SPEED 15

	// Move the player
	void movement(uint8_t key)
	{
		// Get the player input and check for what direction they want to go in
		// TODO: Use switch
		if (key == sk_Up) y -= SPEED;
		if (key == sk_Down) y += SPEED;
		if (key == sk_Left) x -= SPEED;
		if (key == sk_Right) x += SPEED;
	}

};


#endif