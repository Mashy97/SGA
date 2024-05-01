#include "Rectangle.h"

void Rectangle::Area()
{
	m_area = m_width * m_height;
	Print("Rectangle::Area()");
}

void Rectangle::Length()
{
	m_length = 2 * (m_width + m_height);
	Print("Rectangle::Length()");
}

Rectangle::Rectangle() 
	:m_width(0), m_height(0), m_area(0), m_length(0)
{
	center.m_x = 0;
	center.m_y = 0;
}

Rectangle::~Rectangle() {

}