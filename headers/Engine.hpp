#ifndef __ENGINE_HPP
#define __ENGINE_HPP
#include <deque>
#include <stdint.h>
#include <iostream>
#include <SDL/SDL.h>

#include "Babble.hpp"

class EventHandler;

enum EngineState
{
	EngineStarted,
	EngineStopped
};

class Engine
{
public:
	Engine(EventHandler* receiver);
	~Engine();

	void run();
	void stop();
	void repaint();

	void onEvent(SDL_Event* event);

private:
	void createSurface();

	/*!
	 * Holds the tick time of the latest frame.
	 */
	uint32_t m_tick;

	/*!
	 * Holds the tick time of when the engine initially started.
	 */
	uint32_t m_start;

	/*!
	 * Holds the current state of the engine, running or stopped.
	 */
	EngineState m_state;

	/*!
	 * \b The surface for drawing the game.
	 */
	SDL_Surface* m_surface;

	/*!
	 * Pointer reference to the application receiving and dealing with user input.
	 */
	EventHandler* m_receiver;
};

#endif
