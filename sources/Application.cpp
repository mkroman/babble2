#include "Application.hpp"
#include "PlayerObject.hpp"

Application::Application()
{

}

Application::~Application()
{
	
}

void Application::run(int argc, char* argv[])
{
	m_engine.run();
}
