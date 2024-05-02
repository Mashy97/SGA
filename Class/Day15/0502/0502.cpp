#include "stdafx.h"
#include "main.h"

class Base {
public:
	std::string name;
	virtual void display() {
		Print("부모 클래스의 display 함수");
	}

	void Print(std::string str) {
		std::cout << name << " " << str << std::endl;
	}

	Base() {};
	~Base() {};
};

class Derived : public Base {
public:
	void display() override {	
		Print("자식 클래스의 display 함수");
	};
};

int main() {

	Base base;
	Base* baseptr = new Base;
	Derived derived;
	base.name = "홍길동";
	base.display();		// 부모 클래스 display()

	baseptr = &derived;	// 자식 클래스의 주소 저장
	baseptr->name = "홍길동2";
	baseptr->display();	// 자식 클래스 주소의 display()

	return 0;
}