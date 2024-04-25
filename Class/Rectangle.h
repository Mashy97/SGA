#pragma once

// 사각형 대한 클래스
class Rectangle {
private:
	int Area = 0;
	int Dul = 0;
	int width = 0;
	int height = 0;
public:
	Rectangle();	// 생성자
	Rectangle(int w, int h);
	~Rectangle();	// 소멸자
	int	getArea();
	int getDul();
};

