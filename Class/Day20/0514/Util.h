#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <set>
#include <algorithm>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include "Music.h"

void lineSeparator();

class Util{
public:
    void LoadMusicData(string filename, vector<Music>& music);
};

void main_screan();

void menu_screan();

void select_genre();
void search_vocal();
void play_music();

void all_music();

