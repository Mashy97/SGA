#include "Triangle.h"

void Triangle::Area()
{
	m_area = m_width * m_height / 2;
	Print("Triangle::Area()");
}

void Triangle::Length()
{
	m_length = m_width * 3;
	Print("Triangle::Length()");
}
