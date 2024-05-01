#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

class Shape
{
public:
	Point center;	// 도형의 중심

	// virtual 함수
	virtual void Area();
	virtual void Length();

	void Print(string str);

};

