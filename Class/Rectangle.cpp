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

// ������
Rectangle::Rectangle() {
	cout << "����" << endl;
}

Rectangle::Rectangle(int w, int h) {
	cout << "����" << endl;
	width = w;
	height = h;
}
// �Ҹ���
Rectangle::~Rectangle() {
	cout << "�Ҹ�" << endl;
}