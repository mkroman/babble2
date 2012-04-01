#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP
#include "Engine.hpp"
#include "EventHandler.hpp"

class Application : public EventHandler
{
public:
	Application();
	~Application();

	void run(int argc, char* argv[]);

private:
	Engine m_engine;
};

#endif
