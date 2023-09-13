#ifndef PLAYER

class Player
{
public:
	short x = 10;
	short y = 10;

	void update();
	void draw();

private:
	void movement();
};


#endif