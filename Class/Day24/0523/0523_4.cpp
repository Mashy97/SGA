#include <iostream>
#include <set>
#include <string>
#include <time.h>
#include <list>

// ���� �� ( a-z, A-Z )
// ������ ���� 15���� �����Ͽ� 
// ���ڿ��� 2�� ���� - A,B
// ���Ͽ� ���� ���ĺ� Ȯ�� - find 

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

		// List B�� ���� ������ A.find() 
		for (auto ita = listA.begin(); ita != listA.end(); ++ita) {
			auto it_B = B.begin();
			for (auto itb = B.begin(); itb != B.end(); ++itb) {
				if (A.find(*it_B) != A.end()) {
					std::cout << *it_B << " ���� " << std::endl;
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