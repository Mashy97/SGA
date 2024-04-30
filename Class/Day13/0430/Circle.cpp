#include "Circle.h"

void Circle::Area()
{
	c_r * c_r * PI;
}

void Circle::Lenght()
{
	2 * c_r * PI;
}

void Circle::SetCenter(float x, float y)
{
	center.x = x;
	center.y = y;
}

Point Circle::SetCenter(Point p_x)
{	
	center.x = p_x.x;
	center.y = p_x.y;
	return center;
}

Point Circle::GetCenter()
{
	return center;
}

void Circle::SetRadius(float r)
{
	c_r =  r;
}

Circle::Circle()
	:c_r(0), center { 0.0f, 0.0f }
{
	// c_r = 0;
	// center.x = 0;
	// center.y = 0;
}
Circle::~Circle() {

}

