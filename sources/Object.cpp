#include <SDL/SDL.h>
#include "Object.hpp"

Object::Object()
{
}

void Object::move(int x, int y)
{
	m_position.x = x;
	m_position.y = y;

	_debug("Moving to %d,%d", x, y);
}

void Object::update(uint32_t delta)
{
}

void Object::paint(SDL_Surface* surface)
{
}
