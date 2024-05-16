#pragma once
#include <sstream>
#include <fstream>
#include <vector>
#include "Music.h"
#include <string>

using namespace std;

void lineSeparator();

class Util{
public:
    void LoadMusicData(string filename, vector<Music>& music);
};
