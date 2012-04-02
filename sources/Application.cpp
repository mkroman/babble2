#include "Application.hpp"
#include "Actor.hpp"

Application::Application(int argc, char* argv[])
	: m_engine(this), m_actor("test")
{
	m_engine.addObject(&m_actor);
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

void Application::onLeftButtonPress(int x, int y)
{
	m_actor.move(x, y);
}
