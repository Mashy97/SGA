#pragma once
#include "stdafx.h"

enum Element {
	TITLE,
	GENRE,
	SINGER,
};	

class Music{
public:
	string title;
	string singer;
	string genre;
	string releaseDate;
	string playing;

	Music();
	Music(string title, string genre, string singer);
	~Music() {};

	string getTitle();
	string getSinger();
	string getGenre();
	string getReleaseDate();
	string getPlaying();

	void Play();
	void Display();
};

