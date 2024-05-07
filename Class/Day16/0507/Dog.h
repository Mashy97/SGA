#pragma once
#include "Animal.h"
class Dog :
    public Animal{

private:


public:
    Dog();      
    Dog(string str);
    ~Dog();
    void PlaySound();

};

