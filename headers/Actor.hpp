#pragma once
#include <string>
#include "Object.hpp"

class Actor : public Object
{
public:
	Actor();
	Actor(const std::string& name);

	void paint(SDL_Surface* surface);

	void setName(const std::string& name);

private:
	std::string m_name;
};
