#include "Timer.hpp"

Timer::Timer()
	 : m_active(false)
{
}

Timer::~Timer()
{
}

int Timer::ticks()
{
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
