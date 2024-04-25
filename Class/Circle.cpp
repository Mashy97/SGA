#include "Circle.h"
#include "stdafx.h"
double Circle::getArea() {
	area = PI * radius * radius;
	return area;
}

double Circle::getDul() {
	dul = 2 * PI * radius;
	return dul;
}

Circle::Circle() {
	cout << "持失" << endl;
}

Circle::Circle(int r) {
	cout << "持失" << endl;
	radius = r;
}
Circle::~Circle() {
	cout << "社瑚" << endl;
}
