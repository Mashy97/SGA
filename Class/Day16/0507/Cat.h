#pragma once
#include "Animal.h"

class Cat :
    public Animal{
private:

public:
    Cat();
    Cat(string str);
    ~Cat();
    void PlaySound();

};

