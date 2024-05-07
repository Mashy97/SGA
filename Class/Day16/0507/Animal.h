#pragma once
#include "stdafx.h"

class Animal {
private:
	int number;

public:
	Animal();	// ������
	Animal(string name);
	Animal(int num);
	Animal(string name, int num);
	~Animal();	// �Ҹ���
	void virtual PlaySound();

protected:
	string aniname;
	string sound;
	int legs;
	void Print();
	void Print(string str);
};

