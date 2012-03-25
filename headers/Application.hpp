#ifndef __APPLICATION_HPP
#define __APPLICATION_HPP
#include "Engine.hpp"

class Application
{
public:
	Application();
	~Application();

	void run(int argc, char* argv[]);

private:
	Engine m_engine;
};

#endif
