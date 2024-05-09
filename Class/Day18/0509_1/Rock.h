#pragma once
#include "Music.h"
class Rock :
    public Music{
public:
    void Mplay();

    Rock();
    Rock(string vocal, string name);
    ~Rock();
};

