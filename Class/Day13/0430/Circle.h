#pragma once

#define PI 3.141592

struct Point {
	float x;
	float y;
};

class Circle
{
private:
	Point center;	// 중심 x, y 좌표
	float c_r;		// r 반지름

public:
	Circle();
	~Circle();

	void Area();
	void Lenght();

	void SetCenter(float x, float y);
	Point SetCenter(Point p_x);

	Point GetCenter();
	
	void SetRadius(float r);


};

