#include "Timer.hpp"
#include "Object.hpp"

Timer::Timer()
	 : m_active(false)
{
}

Timer::~Timer()
{
}

int Timer::ticks()
{
	// _debug("sdl: %d timer: %d = %d", SDL_GetTicks(), m_time, (SDL_GetTicks() - m_time));

	return (SDL_GetTicks() - m_time);
}

void Timer::start()
{
	m_active = true;
	m_time = SDL_GetTicks();
}

void Timer::stop()
{
	m_active = false;	
}
