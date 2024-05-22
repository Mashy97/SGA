// 1~20 까지의 범위를 가진 숫자 int를 저장하는 리스트 컨테이너를 만들고
// 리스트 사이즈 20
// 중복 숫자를 삭제하는 프로그램

#include <iostream>
#include <string>
#include <list>
#include <time.h>

int main() {

	srand((unsigned int)time(NULL));
	std::list<int> number;

	for(int i= 0; i < 20; i++){
		int temp = rand() % 20;
		number.push_back(temp);
	}
	std::list<int> basic_number = number;	// basic_number에 number 초기 값 저장

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;
	
	// 중복 삭제
	number.sort();			// 정렬
	number.unique();		// 중복 제거

	std::list<int> uni_number = number;	// uni_number에 중복 삭제 결과 저장

	basic_number.sort();

	auto tit = basic_number.begin();	// 
	std::advance(tit, 1);

	auto uit = uni_number.begin();

	// 중복 삭제 값 확인
	for (int i = 0; i <= basic_number.size(); i++) {
		for (int j = 0; j < basic_number.size(); j++) {
			if (*tit == *uit) {
				std::cout << *tit << " 삭제" << std::endl;
				tit = basic_number.erase(tit);
			}
			else if (uni_number.size() != 2) {
				uit = uni_number.erase(uit);
				tit = basic_number.erase(tit);
			}
			else {
				uit = uni_number.erase(uit);
			}
		}
	}
	std::cout << "======" << std::endl;

	// 중복 삭제 결과

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

}
