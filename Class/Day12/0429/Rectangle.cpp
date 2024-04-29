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
	cout << "���� : " << m_area << endl;
}

void Rectangle::PrintLenght()
{
	cout << "�ѷ� : " << m_lenght << endl;
}

void Rectangle::PrintInfo()
{
	cout << "=== Rectangle Info === " << endl;
	cout << "���� : " << m_width << endl;
	cout << "���� : " << m_height << endl;
	PrintArea();
	PrintLenght();
}

void Rectangle::Init(int width, int height)
{
	m_width = width;
	m_height = height;
}

Rectangle::Rectangle()
	:m_width(0),m_height(0)	// ������ ���۽� ������ �ʱ�ȭ ����
{

}

Rectangle::~Rectangle() {

}
