#ifndef __ENGINE_HPP
#define __ENGINE_HPP
#include <stdint.h>
#include <SDL/SDL.h>
#include <vector>
#include <iostream>

#include "Babble.hpp"
#include "Object.hpp"

class EventHandler;

enum EngineState
{
	EngineStarted,
	EngineStopped
};

class Engine
{
public:
	typedef std::vector<Object*> ObjectVector;

	Engine(EventHandler* receiver);
	~Engine();

	void run();
	void stop();
	void repaint(uint32_t delta);

	void onEvent(SDL_Event* event);

	void addObject(Object* object);

private:
	void createSurface();

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

	ObjectVector m_objects;

	/*!
	 * Pointer reference to the application receiving and dealing with user input.
	 */
	EventHandler* m_receiver;
};

#endif
