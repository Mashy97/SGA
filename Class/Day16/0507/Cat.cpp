#include "Cat.h"

Cat::Cat(){
	sound = "�߿�";
	aniname = "�����";
	legs = 4;
}

Cat::Cat(string str){
	sound = str;
}

Cat::~Cat(){

}

void Cat::PlaySound(){
	Print(sound);
}
