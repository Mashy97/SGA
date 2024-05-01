#include "stdafx.h"

int main() {

	Rectangle rect = {};
	Circle circle = {};
	Triangle tri = {};
	Sphere sphere;

	rect.center.m_x = 10;
	rect.center.m_y = 10;
	rect.m_width = 100;
	rect.m_length = 100;

	rect.Area();
	rect.Length();

	circle.center.m_x = 20;
	circle.center.m_y = 20;
	circle.m_length = 100;
	circle.m_radius = 10;

	circle.Area();
	circle.Length();

	tri.center.m_x = 10;
	tri.center.m_y = 15;
	tri.m_width = 100;
	tri.m_height = 100;

	tri.Area();
	tri.Length();


	return 0;
}