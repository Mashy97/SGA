#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <time.h>
/** 리스트 예제
* 1. 리스트에 랜덤함수를 이용하여 30개 정도를 입력
* 2. 짝수만 삭제하고 홀수만 남기기
*
*
* 
* 
**/

int main() {
	
	std::list<int> myList;
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 30; i++) {
		int a = rand() % 100;
		myList.push_back(a);
	}

	for (auto it = myList.begin(); it != myList.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

	auto it = myList.begin();
	for (int i = 0; i < 30; i++) {
		if (*it % 2 != 0) {
			std::advance(it, 1);
		}
		else {
			it = myList.erase(it);
		}
	}
	for (auto it1 = myList.begin(); it1 != myList.end(); ++it1)
		std::cout << *it1 << std::endl;
		std::cout << myList.size() << std::endl;
		std::cout << "======" << std::endl;


}