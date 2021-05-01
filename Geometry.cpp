#include "Geometry.h"

Point::Point():m_x(0),m_y(0){}

Point::Point(int x, int y):m_x(x),m_y(y){}

Point::~Point()
{

}

bool Point::operator==(const Point& target) const
{
	return (this->m_x == target.m_x) && (this->m_y == target.m_y);
}

bool Point::equals(const Point& target) const
{
	return (this->m_x == target.m_x) && (this->m_y == target.m_y);
}

void Point::setPosition(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

void Point::move(DIR dir,int speed)
{
	switch (dir)
	{
	case DIR::UP:
		m_y -= speed;
		break;
	case DIR::DOWN:
		m_y += speed;
		break;
	case DIR::LEFT:
		m_x -= speed;
		break;
	case DIR::RIGHT:
		m_x += speed;
		break;
	}
}
//****************Size********************
Size::Size():width(0),height(0){}

Size::Size(int width, int height):width(width),height(height){}

Size::~Size(){}

void Size::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

bool Size::equals(const Size& target) const
{
	return (this->width == target.width) && (this->height == target.height);
}
