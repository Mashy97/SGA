#include "stdafx.h"
#include <iomanip>
// 클래스를 이용하여 사각형 둘레, 넓이 구하기
int main()
{

	cout << setprecision(10);

	Rectangle trect(3, 5);	// rect.width = 3; rect.height = 5;

	cout << "trect의 면적은 " << trect.getArea() << endl;
	cout << "trect의 둘레는 " << trect.getDul() << endl;
	cout << "============================" << endl;

	Circle donut(1);		// donut.radius = 1;
	cout << "donut의 면적은 " << donut.getArea() << endl;
	cout << "donut의 둘레는 " << donut.getDul() << endl;
	cout << "============================" << endl;

	Circle pizza(30);		// pizza.radius = 30;
	cout << "pizza의 면적은 " << pizza.getArea() << endl;
	cout << "pizza의 둘레는 " << pizza.getDul() << endl;

	return 0;
}

