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
	cout << "����" << endl;
}

Circle::Circle(int r) {
	cout << "����" << endl;
	radius = r;
}
Circle::~Circle() {
	cout << "�Ҹ�" << endl;
}
