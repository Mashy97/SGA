#pragma once
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

class Shape
{
public:
	Point center;	// ������ �߽�

	// virtual �Լ�
	virtual void Area();
	virtual void Length();

	void Print(string str);

};

