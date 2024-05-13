#pragma once
#include "Music.h"
class Jazz :
    public Music{

public:
    void Mplay();

    Jazz();
    Jazz(string vocal, string name);
    ~Jazz();

};

