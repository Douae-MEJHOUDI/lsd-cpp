#include "class.hpp"

using namespace std;


Shape::Shape(float width, float height)
{
	m_width = width;
	m_height = height;
}

Triangle::Triangle(float width, float height):Shape{width,height}
{
}

Rectangle::Rectangle(float width, float height):Shape{width,height}
{
}

float Triangle::area()
{
	return (m_width*m_height)/2;
}

float Rectangle::area()
{
	return m_width*m_height;
}
