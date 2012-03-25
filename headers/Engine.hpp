#ifndef __ENGINE_HPP
#define __ENGINE_HPP
#include <deque>
#include <iostream>
#include <SDL/SDL.h>

#include "Babble.hpp"

class BaseObject;
class VisualObject;

class Engine
{
public:
	Engine();
	~Engine();

	void run();
	void stop();
	void repaint();
	void initiate();

private:
	typedef std::deque<BaseObject*> ObjectDeque;

	void createSurface();

	void handleMouseButtonClick(SDL_MouseButtonEvent* event);
	void handleMouseButtonRelease(SDL_MouseButtonEvent* event);

	VisualObject* m_player;

	bool         m_running;
	ObjectDeque  m_objects;
	SDL_Surface* m_surface;
};

#endif
