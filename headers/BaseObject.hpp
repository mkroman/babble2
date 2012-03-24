#ifndef __BASE_OBJECT_HPP
#define __BASE_OBJECT_HPP

struct Vector {
	float x;
	float y;
};

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

private:
	Vector m_position;
};

#endif
