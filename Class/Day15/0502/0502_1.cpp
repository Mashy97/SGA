#include "stdafx.h"
#include "0502_2.h"

class Animal {
public:
	virtual ~Animal() {
		cout << "家戈" << endl;
	};

	virtual void makeSound() const {
		cout << "悼拱 家府" << endl;
	}

};

class Dog : public Animal {
public:
	void makeSound() const override {
		cout << "港港" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() const override {
		cout << "具克" << endl;
	}
};

class A : public Animal {
public:

};

int main() {
	Animal* animal = new Animal();	// new Animal << default 积己磊
	Animal* a_Dog = new Dog();
	Animal* a_Cat = new Cat();
	Animal* a_A = new A();
	Animal* pt = new Animal[3];

	animal->makeSound();
	a_Dog->makeSound();
	a_Cat->makeSound();
	a_A->makeSound();

	delete[] pt;
	delete animal;
	delete a_Dog;
	delete a_Cat;
	delete a_A;

	return 0;
}