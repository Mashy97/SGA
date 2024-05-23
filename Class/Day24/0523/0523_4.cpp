#include <iostream>
#include <set>
#include <string>
#include <time.h>
#include <list>

// 랜덤 값 ( a-z, A-Z )
// 랜덤한 문자 15개를 선택하여 
// 문자열을 2개 만듬 - A,B
// 비교하여 같은 알파벳 확인 - find 

int main() {

	srand((unsigned int)time(NULL));
	std::set<char> A;
	std::list<char> listA;
	std::set<char> B;
	std::list<char> listB;

	int randInt;
	char randChar;
		for (int i = 0; i < 15; i++) {
			int number = rand() % 2;
			if (number == 0) {
				randChar = 'a' + rand() % 26;
				listA.push_back(randChar);
				A.insert(randChar);
			}
			else {
				randChar = 'A' + rand() % 26;
				listA.push_back(randChar);
				A.insert(randChar);
			}
		}

		for (int i = 0; i < 15; i++) {
			int number = rand() % 2;
			if (number == 0) {
				randChar = 'a' + rand() % 26;
				listB.push_back(randChar);
				B.insert(randChar);
			}
			else {
				randChar = 'A' + rand() % 26;
				listB.push_back(randChar);
				B.insert(randChar);
			}
		}
		std::cout << "=== A ===" << std::endl;
		for (auto it = A.begin(); it != A.end(); ++it) {
			std::cout << *it;
		}
		std::cout << std::endl;

		std::cout << "=== B ===" << std::endl;
		for (auto it = B.begin(); it != B.end(); ++it) {
			std::cout << *it;
		}

		std::cout << std::endl;

		// List B의 값을 가져와 A.find() 
		for (auto ita = listA.begin(); ita != listA.end(); ++ita) {
			auto it_B = B.begin();
			for (auto itb = B.begin(); itb != B.end(); ++itb) {
				if (A.find(*it_B) != A.end()) {
					std::cout << *it_B << " 삭제 " << std::endl;
					A.erase(*it_B);
				}
				else {
						std::advance(it_B, 1);
				
				}
			}
		}

		std::cout << "=== A ===" << std::endl;
		for (auto it = A.begin(); it != A.end(); ++it) {
			std::cout << *it;
		}

		

	return 0;
}