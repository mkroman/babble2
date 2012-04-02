#include "Timer.hpp"
#include "Engine.hpp"
#include "EventHandler.hpp"

Engine::Engine(EventHandler* receiver)
	: m_receiver(receiver), m_state(EngineStopped)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		_debug("Failed to initialize everything in SDL");
	}

	SDL_WM_SetCaption("Babble 1.0", NULL);

	createSurface();
}

Engine::~Engine()
{
	SDL_Quit();
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
	Timer fps;
	SDL_Event event;

	if (m_state != EngineStarted) {
		_debug("Starting engine");

		m_start = SDL_GetTicks();
		m_state = EngineStarted;
	}
	else {
		return;
	}

	while (m_state == EngineStarted)
	{
		fps.start();

		while (SDL_PollEvent(&event)) {
			onEvent(&event);
		}

		repaint();

		if (fps.ticks() < 1000 / kGameFPS) {
			SDL_Delay((1000 / kGameFPS) - fps.ticks());
		}
	}
}

void Engine::onEvent(SDL_Event* event)
{
	switch (event->type)
	{
		case SDL_ACTIVEEVENT:
		{
			switch (event->active.state)
			{
				case SDL_APPMOUSEFOCUS:
				{
					if (event->active.gain) {
						m_receiver->onMouseFocus();
					}
					else {
						m_receiver->onMouseBlur();
					}

					break;
				}

				case SDL_APPINPUTFOCUS:
				{
					if (event->active.gain) {
						m_receiver->onInputFocus();
					}
					else {
						m_receiver->onInputBlur();
					}

					break;
				}

				case SDL_APPACTIVE:
				{
					if (event->active.gain) {
						m_receiver->onRestore();
					}
					else {
						m_receiver->onMinimize();
					}

					break;
				}

				default:
				{

				}
			}

			break;
		}

		case SDL_KEYDOWN:
		{
			m_receiver->onKeyPress(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);

			break;
		}

		case SDL_KEYUP:
		{
			m_receiver->onKeyRelease(event->key.keysym.sym, event->key.keysym.mod, event->key.keysym.unicode);
		
			break;
		}

		case SDL_MOUSEMOTION:
		{
			// (Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0
			bool left_button_pressed   = (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT))   != 0;
			bool middle_button_pressed = (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0;
			bool right_button_pressed  = (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT))  != 0;

			m_receiver->onMouseMove(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel,
								left_button_pressed, middle_button_pressed, right_button_pressed);

			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			switch (event->button.button)
			{
				case SDL_BUTTON_LEFT:
				{
					m_receiver->onLeftButtonPress(event->button.x, event->button.y);

					break;
				}

				case SDL_BUTTON_MIDDLE:
				{
					m_receiver->onMiddleButtonPress(event->button.x, event->button.y);
				
					break;
				}

				case SDL_BUTTON_RIGHT:
				{
					m_receiver->onRightButtonPress(event->button.x, event->button.y);
				
					break;
				}
			}
		
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			switch (event->button.button)
			{
				case SDL_BUTTON_LEFT:
				{
					m_receiver->onLeftButtonRelease(event->button.x, event->button.y);

					break;
				}

				case SDL_BUTTON_MIDDLE:
				{
					m_receiver->onMiddleButtonRelease(event->button.x, event->button.y);
				
					break;
				}

				case SDL_BUTTON_RIGHT:
				{
					m_receiver->onRightButtonRelease(event->button.x, event->button.y);
				
					break;
				}
			}
		
			break;
		}

		case SDL_VIDEORESIZE:
		{
			m_receiver->onResize(event->resize.w, event->resize.h);

			break;
		}

		case SDL_VIDEOEXPOSE:
		{
			m_receiver->onExpose();
		
			break;
		}

		case SDL_QUIT:
		{
			m_receiver->onExit();

			break;
		}

		case SDL_SYSWMEVENT:
		{
			break;
		}

		default:
		{
			m_receiver->onUserEvent(event->user.type, event->user.code, event->user.data1, event->user.data2);
		}
	}
}

void Engine::stop()
{
	m_state = EngineStopped;

	_debug("Stopping engine");
}

void Engine::repaint()
{
	ObjectVector::iterator it;

	// Clean the surface.
	SDL_Rect blank = { 0, 0, m_surface->w, m_surface->h };
	SDL_FillRect(m_surface, &blank, 0);

	for (it = m_objects.begin(); it != m_objects.end(); it++) {
		(*it).update(2);
		(*it).paint(m_surface);
	}

	SDL_Flip(m_surface);
}

void Engine::addObject(const Object& object)
{
	m_objects.push_back(object);
}
