#include "Engine.hpp"
#include "BaseObject.hpp"
#include "VisualObject.hpp"

Engine::Engine()
	: m_running(false)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		_debug("Failed to initialize everything in SDL");
	}
}

Engine::~Engine()
{
	if (m_surface != NULL) {
		SDL_FreeSurface(m_surface);
	}

	delete m_player;

	// Release each individual object from memory.
	ObjectDeque::iterator it;

	for (it = m_objects.begin(); it != m_objects.end(); it++)
	{
		delete *it;
	}
}

void Engine::initiate()
{
	createSurface();

	SDL_WM_SetCaption("Babble", NULL);

	m_player = new VisualObject("root.gif");

	m_objects.push_back(m_player);
	m_objects.push_back(new BaseObject());
	m_objects.push_back(new BaseObject());

	repaint();
}

void Engine::createSurface()
{
	SDL_Surface* surface;

	surface = SDL_SetVideoMode(kGameWidth, kGameHeight, 32,
				SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_ANYFORMAT);

	if (!surface) {
		_debug("Failed to create surface");
	}
	else {
		m_surface = surface;
	}
}

void Engine::run()
{
	SDL_Event event;

	m_running = true;

	_debug("Starting engine");

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
			{
				repaint();

				break;
			}

			case SDL_KEYUP:
			{
				repaint();

				break;
			}

			case SDL_MOUSEMOTION:
				// std::cout << "mouse motion" << std::endl;
				break;

			case SDL_MOUSEBUTTONDOWN:
			{
				SDL_MouseButtonEvent* mouse_event = reinterpret_cast<SDL_MouseButtonEvent*>(&event);

				handleMouseButtonClick(mouse_event);
				
				break;
			}

			case SDL_MOUSEBUTTONUP:
			{
				SDL_MouseButtonEvent* mouse_event = reinterpret_cast<SDL_MouseButtonEvent*>(&event);

				handleMouseButtonRelease(mouse_event);

				break;
			}

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

void Engine::repaint()
{
	// Clean the surface.
	SDL_Rect blank = { 0, 0, m_surface->w, m_surface->h };
	SDL_FillRect(m_surface, &blank, 0);

	// Start painting each individual object.
	ObjectDeque::iterator it;

	for (it = m_objects.begin(); it != m_objects.end(); it++)
	{
		_debug("Painting object 0x%x ..", *it);

		(*it)->paint(m_surface);
	}

	SDL_Flip(m_surface);
}

void Engine::handleMouseButtonClick(SDL_MouseButtonEvent* event)
{
	m_player->setPosition(event->x, event->y);

	repaint();
}

void Engine::handleMouseButtonRelease(SDL_MouseButtonEvent* event)
{
	
}
