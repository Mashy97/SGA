#include "Rectangle.h"
#include "stdafx.h"
int Rectangle::getArea() {
	Area = (width * height);
	return Area;
}

int Rectangle::getDul() {
	Dul = (width + height) * 2;
	return Dul;
}

// 持失切
Rectangle::Rectangle() {
	cout << "持失" << endl;
}

Rectangle::Rectangle(int w, int h) {
	cout << "持失" << endl;
	width = w;
	height = h;
}
// 社瑚切
Rectangle::~Rectangle() {
	cout << "社瑚" << endl;
}