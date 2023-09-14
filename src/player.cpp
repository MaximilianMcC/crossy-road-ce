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
		// gfx_Sprite(emoji, x, y);
		gfx_TransparentSprite(emoji, x, y);
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