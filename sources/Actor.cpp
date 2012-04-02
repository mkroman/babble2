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
