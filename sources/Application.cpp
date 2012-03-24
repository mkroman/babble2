#include "Application.hpp"

Application::Application()
{

}

void Application::run(int argc, char* argv[])
{
	m_engine.initiate();
	m_engine.run();
}
