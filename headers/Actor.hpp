#pragma once
#include <string>
#include "RigidObject.hpp"

class Actor : public Object
{
public:
	Actor();
	Actor(const std::string& name);
	~Actor();

	void move(float x, float y);
	void paint(SDL_Surface* surface);
	void setName(const std::string& name);

private:
	std::string  m_name;
	SDL_Surface* m_surface;
};
