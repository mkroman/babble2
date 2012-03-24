#include "Engine.hpp"

Engine::Engine()
	: m_running(false)
{
	SDL_Init(SDL_INIT_EVERYTHING);
}

void Engine::initiate()
{
	createSurface();

	SDL_WM_SetCaption("Babble", NULL);
}

void Engine::createSurface()
{
	SDL_Surface* surface;

	surface = SDL_SetVideoMode(kGameWidth, kGameHeight, 32,
				SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT);

	if (!surface) {
		_debug("Failed to create surface");

		return;
	}
}

void Engine::run()
{
	SDL_Event event;

	m_running = true;

	while (m_running && SDL_WaitEvent(&event))
	{
		switch (event.type)
		{
			case SDL_ACTIVEEVENT:
			{
				SDL_ActiveEvent* active_event = reinterpret_cast<SDL_ActiveEvent*>(&event);

				if (active_event->state == SDL_APPINPUTFOCUS) {
					if (active_event->gain == 1) {
						_debug("Gained window focus");
					}
					else {
						_debug("Lost window focus");
					}
				}

				break;
			}

			case SDL_KEYDOWN:
				redraw();

				break;

			case SDL_KEYUP:
			{
				redraw();

				break;
			}

			case SDL_MOUSEMOTION:
				// std::cout << "mouse motion" << std::endl;
				break;

			case SDL_MOUSEBUTTONDOWN:
				// std::cout << "mouse down" << std::endl;
				break;

			case SDL_MOUSEBUTTONUP:
				// std::cout << "mouse up" << std::endl;
				break;

			case SDL_VIDEORESIZE:
				// std::cout << "video resize" << std::endl;
				break;

			case SDL_VIDEOEXPOSE:
				// std::cout << "video expose" << std::endl;
				break;

			case SDL_QUIT:
			{
				_debug("Received SDL_QUIT event, shutting down gracefully");

				stop();

				break;
			}

			case SDL_USEREVENT:
				std::cout << "user event" << std::endl;
				break;

			case SDL_SYSWMEVENT:
				std::cout << "wm event" << std::endl;
				break;

			default:
				break;
		}
	}
}

void Engine::stop()
{
	m_running = false;

	_debug("Stopping engine");
}

void Engine::redraw()
{
	_debug("Redrawing");
}
