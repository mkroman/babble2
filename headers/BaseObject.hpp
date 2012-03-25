#ifndef __BASE_OBJECT_HPP
#define __BASE_OBJECT_HPP
#include <SDL/SDL.h>
#include "Babble.hpp"

class BaseObject
{
public:
	BaseObject() {};
	virtual ~BaseObject() {};

	const Vector& position()
	{
		return m_position;
	}

	virtual void setPosition(float x, float y);
	
	virtual void paint(SDL_Surface* const surface) {};

protected:
	Vector m_position;
};

#endif
