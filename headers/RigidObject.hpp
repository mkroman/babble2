#pragma once
#include "Object.hpp"

class RigidObject : public Object
{
public:
	RigidObject();
	~RigidObject();

	virtual void move(float x, float y);
	virtual void update(uint32_t delta_time);

protected:
	Vector m_velocity;
	Vector m_endpoint;
};
