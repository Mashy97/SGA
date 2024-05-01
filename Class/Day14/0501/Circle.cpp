#include "Circle.h"
#define PI 3.141592


void Circle::Area()
{
	m_area = PI * m_radius * m_radius;
	Print("Circle::Area()");
}

void Circle::Length()
{
	m_length = 2 * PI * m_radius;
	Print("Circle::Length()");
}

Circle::Circle()
:m_radius(0), m_area(0), m_length(0)
{
	center.m_x = 0;
	center.m_y = 0;
}

Circle::~Circle()
{
}
