#include "stdafx.h"
#include "main.h"

class Base {
public:
	std::string name;
	virtual void display() {
		Print("�θ� Ŭ������ display �Լ�");
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
		Print("�ڽ� Ŭ������ display �Լ�");
	};
};

int main() {

	Base base;
	Base* baseptr = new Base;
	Derived derived;
	base.name = "ȫ�浿";
	base.display();		// �θ� Ŭ���� display()

	baseptr = &derived;	// �ڽ� Ŭ������ �ּ� ����
	baseptr->name = "ȫ�浿2";
	baseptr->display();	// �ڽ� Ŭ���� �ּ��� display()

	return 0;
}