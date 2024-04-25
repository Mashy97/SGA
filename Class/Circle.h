#pragma once

class Circle {
private:
	double area = 0;
	double dul = 0;
	int radius = 0;
public:
	double getArea();
	double getDul();
	Circle();
	Circle(int r);
	~Circle();
};

