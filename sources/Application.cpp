#include "Application.hpp"

Application::Application()
	: m_engine(this)
{
}

Application::~Application()
{
	
}

void Application::run(int argc, char* argv[])
{
	m_engine.run();
}
