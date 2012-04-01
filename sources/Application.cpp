#include "Application.hpp"

Application::Application(int argc, char* argv[])
	: m_engine(this)
{
}

Application::~Application()
{
	
}

void Application::run()
{
	m_engine.run();
}

void Application::onExit()
{
	_debug("Application received exit signal");

	m_engine.stop();
}
