#pragma once
#include "stdafx.h"

class Music{
public:
	string Mvocal;		// Music_vocalist
	string Mname;		// Music_name
	int Mnum;			// Music_num
	string Mgenre;		// Misic_genre
	void virtual Mplay();

	Music();
	~Music() {};

	void Print(string str);
};
