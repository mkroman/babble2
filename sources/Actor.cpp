#include <SDL/SDL.h>
#include "Actor.hpp"

Actor::Actor()
{
}

Actor::Actor(const std::string& name)
	: m_name(name)
{
}

void Actor::setName(const std::string& name)
{
	m_name = name;
}

void Actor::paint(SDL_Surface* surface)
{
	SDL_Rect rect = { m_position.x, m_position.y, 60, 90 };
	SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 255, 255, 255));
}
