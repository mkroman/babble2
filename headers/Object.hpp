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

	virtual void update(uint32_t delta);
	virtual void paint(SDL_Surface* surface);

private:
	Position m_position;
};
