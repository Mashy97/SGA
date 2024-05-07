#pragma once
#include "stdafx.h"

class Animal {
private:
	int number;

public:
	Animal();	// 持失切
	Animal(string name);
	Animal(int num);
	Animal(string name, int num);
	~Animal();	// 社瑚切
	void virtual PlaySound();

protected:
	string aniname;
	string sound;
	int legs;
	void Print();
	void Print(string str);
};

