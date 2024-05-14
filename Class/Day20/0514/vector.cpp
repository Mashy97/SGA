#include "stdafx.h"

int vector(){
	// vector class - 배열 형태
	// 동적 배열을 할당을 클래스 형태로
	std::vector<int> myVector(5);

	// 사이즈를 선언 후 초기화
	myVector[0] = 1;
	myVector[1] = 10;
	myVector[2] = 20;
	myVector[3] = 30;
	myVector[4] = 40;

	// Vector의 사이즈 확인하기
	std::cout << "myVector.size() = " << myVector.size() << std::endl;

	// myVector 출력
	for (int i = 0; i < myVector.size(); i++) {
		std::cout << "myVector[" << i << "] = " << myVector[i] << std::endl;
	}

	std::cout << "======" << std::endl;

	// push_back을 사용하여 요소 추가
	myVector.push_back(50);
	myVector[5] = 50;

	std::cout << "myVector.size() = " << myVector.size() << std::endl;

	// myVector 출력 - push_back, myVector[5] 확인
	for (int i = 0; i < myVector.size(); i++) {
		std::cout << "myVector[" << i << "] = " << myVector[i]<<std::endl;
	}

	std::cout << "======" << std::endl;

	// pop_back을 사용하여 요소 삭제
	myVector.pop_back();
	myVector.pop_back();
	myVector.pop_back();

	std::cout << "myVector.size() = " << myVector.size() << std::endl;

	// myVector 출력 - pop_back 확인
	for (int i = 0; i < myVector.size(); i++) {
		int value = myVector.at(i); // at() 배열에서 인덱스로 값을 가져오는 명령어
		std::cout << "myVector[" << i << "] = " << value << std::endl;
	}

	std::cout << "======" << std::endl;

	// for-each문을 활용한 vector 값 출력
	std::vector<int> mVector = { 0,1,2,3,4,5,6,7,8,9 };

	for (int m : mVector) {
		int value = mVector.at(m);
		std::cout << "mVector[" << m << "] = " << value << std::endl;
	}

	// vector 포인터로 접근
	std::vector<int> myInt(6);
	
	int* pInt = myInt.data();

	// 포인터로 접근하여 해당된 vector 값 수정
	*(pInt + 0) = 100;	// myInt[0] = 100
	*(pInt + 5) = 50;	// myInt[5] = 50;

	// const_cast 사용
	const int* cpInt = myInt.data();
	//*(cpInt + 0) = 500;		// 오류 - const로 지정된 값은 const_cast이외의 방법으로 수정이 불가능
	
	int* ptr = const_cast<int*>(cpInt);	// ptr이 cpInt를 수정이 가능하도록 const_cast로 정의
	*(ptr + 0) = 800;		// 정상 작동 


	return 0;
}
