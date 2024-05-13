#pragma once
#include "Music.h"
class Pop :
    public Music{
public:
    void Mplay();
    Pop();
    Pop(string vocal, string name);
    ~Pop();
};

