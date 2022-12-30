#ifndef DEF_CLASS
#define DEF_CLASS


#include <iostream>

class Shape 
{
	public:
	Shape(float width, float height);
	
	protected:
	float m_width;
	float m_height;

};

class Triangle: public Shape
{
	public:
	Triangle(float width, float height);
	float area();
};

class Rectangle: public Shape
{
	public:
	Rectangle(float width, float height);
	float area();
};

#endif
