#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Actor.hpp"

Actor::Actor()
{
}

Actor::Actor(const std::string& name)
	: m_name(name)
{
	m_surface = IMG_Load("assets/root.gif");
}

Actor::~Actor()
{
	SDL_FreeSurface(m_surface);
}

void Actor::setName(const std::string& name)
{
	m_name = name;
}

void Actor::move(float x, float y)
{
	m_position.x = (x - (m_surface->w / 2));
	m_position.y = (y - (m_surface->h / 2));
}

void Actor::paint(SDL_Surface* surface)
{
	SDL_Rect root_box = { m_position.x, m_position.y, m_surface->w, m_surface->h };

	SDL_BlitSurface(m_surface, NULL, surface, &root_box);
}
