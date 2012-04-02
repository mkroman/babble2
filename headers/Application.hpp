#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP
#include "Engine.hpp"
#include "Actor.hpp"
#include "EventHandler.hpp"

class Application : public EventHandler
{
public:
	Application(int argc, char* argv[]);
	~Application();

	void run();
	void onExit();
	void onLeftButtonPress(int x, int y);

private:
	Actor m_actor;
	Engine m_engine;
};

#endif
