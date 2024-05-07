#include "stdafx.h"
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Dove.h"

int main(){
	Animal* panimal = nullptr;
	Dog dog;
	Cat cat;
	Dove dove;

	dog.PlaySound();
	cat.PlaySound();
	dove.PlaySound();

	cout << " =================== " << endl;

	panimal = &cat;
	panimal->PlaySound();

	panimal = &dog;
	panimal->PlaySound();

	panimal = &dove;
	panimal->PlaySound();

	cout << " =================== " << endl;
	// Reference
	// 메모리 복사해서 내용도 같이 복사

	Animal& ranimal = dove;
	ranimal.PlaySound();

	ranimal = dog;
	ranimal.PlaySound();

	ranimal = cat;
	ranimal.PlaySound();
}
