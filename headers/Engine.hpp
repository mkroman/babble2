#ifndef __ENGINE_HPP
#define __ENGINE_HPP
#include <vector>
#include <iostream>
#include <SDL/SDL.h>

#include "Babble.hpp"

class Engine
{
public:
	Engine();

	void run();
	void stop();
	void redraw();
	void initiate();

private:
	void createSurface();

	bool         m_running;
	SDL_Surface* m_surface;
};

#endif
