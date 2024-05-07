#pragma once
#include "Animal.h"
class Dove :
    public Animal{
private:

public:
    Dove();
    Dove(string str);
    ~Dove();
    void PlaySound();

};

