#include "stdafx.h"
#include "Rectangle.h"

void Rectangle::Area()
{
	this->m_area = m_width * m_height;
}

void Rectangle::Lenght()
{
	this->m_lenght = 2 * (m_width + m_height);
}

void Rectangle::PrintArea()
{
	cout << "넓이 : " << m_area << endl;
}

void Rectangle::PrintLenght()
{
	cout << "둘레 : " << m_lenght << endl;
}

void Rectangle::PrintInfo()
{
	cout << "=== Rectangle Info === " << endl;
	cout << "가로 : " << m_width << endl;
	cout << "세로 : " << m_height << endl;
	PrintArea();
	PrintLenght();
}

void Rectangle::Init(int width, int height)
{
	m_width = width;
	m_height = height;
}

Rectangle::Rectangle()
	:m_width(0),m_height(0)	// 생성자 시작시 변수의 초기화 가능
{

}

Rectangle::~Rectangle() {

}
