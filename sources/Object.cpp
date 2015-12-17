#include <SDL/SDL.h>
#include "Object.hpp"

Object::Object()
{
}

void Object::move(float x, float y)
{
	m_position.x = x;
	m_position.y = y;
}

void Object::update(uint32_t delta)
{
}

void Object::paint(SDL_Surface* surface)
{
}
