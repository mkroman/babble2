#pragma once
#include <string>
#include "RigidObject.hpp"

class Actor : public RigidObject
{
public:
	Actor();
	Actor(const std::string& name);

	void paint(SDL_Surface* surface);
	void setName(const std::string& name);

private:
	std::string m_name;
	bool        m_moving;
	Vector      m_velocity;
	Vector      m_destination;
};
