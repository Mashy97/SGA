#pragma once

#define PI 3.141592

struct Point {
	float x;
	float y;
};

class Circle
{
private:
	Point center;	// �߽� x, y ��ǥ
	float c_r;		// r ������

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

