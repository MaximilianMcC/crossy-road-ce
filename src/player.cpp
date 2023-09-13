#include "player.h"
#include <graphx.h>
#include <ti/getcsc.h>
#include <debug.h>

// Update the player's logic and stuff
void Player::update()
{

}

// Draw/render the player
void Player::draw()
{
	gfx_SetTextFGColor(123);
	gfx_PrintStringXY("I am the player (real)", x, y);
}




// Move the player
void Player::movement()
{

}