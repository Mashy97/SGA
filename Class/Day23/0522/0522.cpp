#include <iostream>
#include <string>

// 인터페이스
class Animal {
public:
	// 가상 함수 - 구현 필수 x
	virtual void Speak() {
		std::cout << "Animal::Speak" << std::endl;
	}

	// 순수 가상 함수 - 자식 클래스는 필수적으로 구현하여야 한다.
	virtual void Speak_() = 0;
};
class Dog : public Animal {
public:
	void Speak() {
		std::cout << "멍멍" << std::endl;
	}

	void Speak_() {
		std::cout << "멍멍멍" << std::endl;

	}
};

int main(){


	return 0;
}

