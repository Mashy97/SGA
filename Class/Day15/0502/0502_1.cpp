#include "stdafx.h"
#include "0502_2.h"

class Animal {
public:
	virtual ~Animal() {
		cout << "�Ҹ�" << endl;
	};

	virtual void makeSound() const {
		cout << "���� �Ҹ�" << endl;
	}

};

class Dog : public Animal {
public:
	void makeSound() const override {
		cout << "�۸�" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() const override {
		cout << "�߿�" << endl;
	}
};

class A : public Animal {
public:

};

int main() {
	Animal* animal = new Animal();	// new Animal << default ������
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