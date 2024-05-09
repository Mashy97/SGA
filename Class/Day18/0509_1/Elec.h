#pragma once
#include "Music.h"
class Elec :
    public Music{

public:
    void Mplay();
    Elec();
    Elec(string vocal, string name);
    ~Elec();
};
