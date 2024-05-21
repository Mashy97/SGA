#include <iostream>
#include <vector>
#include <list>
#include <string>

/*
	std::list
	구현 - 이중 연결리스트 구현, C++ 표준 라이브러리 컨테이너
	요소의 삽입과 삭제가 빠르지만, 임의 접근이 느리다.

	형태 list<Type> 변수명
	선언 및 초기화
	ex) std::list<int> myList;			// 초기화 사이즈 0
		std::list<std::string> myListS 
		std::list<float> myListF(10);		// 초기화 사이즈 10


*/

int main(){

	std::list<int> myList;
	std::list<std::string> myListStr;

	// 요소 추가
	myList.push_back(6);
	for (auto it = myList.begin(); it != myList.end(); ++it)
		std::cout << *it <<std::endl;
	std::cout << "======" << std::endl;

	// 요소 추가
	myList.push_front(4);
	myList.push_back(3);
	for (auto it = myList.begin(); it != myList.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

	// 지정 위치의 요소 확인
	auto it1 = myList.begin();
	std::cout << *it1 << std::endl;
	std::advance(it1, 1);		// it1 += 1;
	std::cout << *it1 << std::endl;
	std::cout << "======" << std::endl;

	// 지정 위치에 요소 추가
	myList.insert(it1, 1000);
	for (auto it = myList.begin(); it != myList.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

	// 요소 삭제
	myList.pop_back();			// myList.erase(myList.begin());
	myList.pop_front();			// 
	for (auto it = myList.begin(); it != myList.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

	// List 초기화
	myList.clear();
	for (auto it = myList.begin(); it != myList.end(); ++it)
		std::cout << *it << std::endl;

		
	return 0;
}



















