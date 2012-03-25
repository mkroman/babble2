#include "Application.hpp"

Application::Application()
{

}

Application::~Application()
{
	SDL_Quit();
}

void Application::run(int argc, char* argv[])
{
	m_engine.initiate();
	m_engine.run();
}
