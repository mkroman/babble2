#pragma once
#include <stdint.h>
#include <SDL/SDL.h>
#include "Babble.hpp"

class Object
{
public:
	Object();

	virtual void move(float x, float y);
	virtual void update(uint32_t delta);
	virtual void paint(SDL_Surface* surface);

protected:
	Position m_position;
};
