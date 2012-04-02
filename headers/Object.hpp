#pragma once
#include <stdint.h>

struct SDL_Surface;

struct Position
{
	int x;
	int y;
};

class Object
{
public:
	Object();

	virtual void move(int x, int y);
	virtual void update(uint32_t delta);
	virtual void paint(SDL_Surface* surface);

protected:
	Position m_position;
};
