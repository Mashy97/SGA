#pragma once

// �簢�� ���� Ŭ����
class Rectangle {
private:
	int Area = 0;
	int Dul = 0;
	int width = 0;
	int height = 0;
public:
	Rectangle();	// ������
	Rectangle(int w, int h);
	~Rectangle();	// �Ҹ���
	int	getArea();
	int getDul();
};

