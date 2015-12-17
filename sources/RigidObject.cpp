#include "RigidObject.hpp"

RigidObject::RigidObject()
{
}

RigidObject::~RigidObject()
{
}

void RigidObject::move(float x, float y)
{
	m_endpoint.x = x;
	m_endpoint.y = y;

	if (x > m_position.x) {
		m_velocity.x = 200;
	}
	else {
		m_velocity.x = -200;
	}

	if (y > m_position.y) {
		m_velocity.y = 200;
	}
	else {
		m_velocity.y = -200;
	}

	_debug("position: %f,%f endpoint: %f,%f", m_position.x, m_position.y, m_endpoint.x, m_endpoint.y);
}

void RigidObject::update(uint32_t delta_time)
{
	m_position.x += m_velocity.x * ((float)delta_time / 1000.0);
	m_position.y += m_velocity.y * ((float)delta_time / 1000.0);
}
