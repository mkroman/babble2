#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP
#include "Engine.hpp"
#include "EventHandler.hpp"

class Application : public EventHandler
{
public:
	Application(int argc, char* argv[]);
	~Application();

	void run();
	void onExit();

private:
	Engine m_engine;
};

#endif
