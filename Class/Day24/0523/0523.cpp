#include <iostream>
#include "0523.h"
/*
	클래스 선언
	class 클래스명{ 
	public:		// 어디서든지 접근 가능
	private:	// 클래스 내부에서만 사용 가능	 (default)
	protected:	// 자식 클래스 && 클래스 내부에서 사용가능
	}
*/
class Car{
public:
	Car():x(0),y(0),protectedVar(0){}
	Car(const Car& other) {
		this->x = other.x;
		this->y = other.y;
	}
	~Car() {}
	void checkValue() {
		std::cout << x <<std::endl;
		std::cout << y <<std::endl;
	}
	void publicFunc(int x, int y) {
		this-> x = x;
		this-> y = y;
	};
private:
	int x, y;

	void privateFunc() {
		std::cout << "Car::privateFunc()" << std::endl;
	};
protected:
	int protectedVar;
};

int main() {
	Car car;		// 인스턴스 생성
	car.publicFunc(5,4);

	Car* pcar = new Car();	// 인스턴스 생성2, 동적 할당
	pcar->publicFunc(10,400);
	delete pcar;

	Car car_1(car);
	car_1.checkValue();

	return 0;
}
