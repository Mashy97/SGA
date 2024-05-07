#include "Animal.h"

Animal::Animal()
	:aniname(""), number(0), legs(0) {

}

Animal::Animal(string name)
	: number(0), legs(0) {
	aniname = name;
}

Animal::Animal(int num)
	:aniname(""), legs(0) {
	number = num;
}

Animal::Animal(string name, int num){
	aniname = name;
	number = num;;
}

Animal::~Animal(){

}

void Animal::PlaySound(){
	Print("Animal::PlaySound()");
	Print(sound);
}

void Animal::Print(){
	cout << "Animal Name :" << aniname << endl;
	cout << "Animal Number :" << number << endl;
}

void Animal::Print(string str) {
	cout << str << endl;
}
