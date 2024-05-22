// 1~20 ������ ������ ���� ���� int�� �����ϴ� ����Ʈ �����̳ʸ� �����
// ����Ʈ ������ 20
// �ߺ� ���ڸ� �����ϴ� ���α׷�

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
	std::list<int> basic_number = number;	// basic_number�� number �ʱ� �� ����

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;
	
	// �ߺ� ����
	number.sort();			// ����
	number.unique();		// �ߺ� ����

	std::list<int> uni_number = number;	// uni_number�� �ߺ� ���� ��� ����

	basic_number.sort();

	auto tit = basic_number.begin();	// 
	std::advance(tit, 1);

	auto uit = uni_number.begin();

	// �ߺ� ���� �� Ȯ��
	for (int i = 0; i <= basic_number.size(); i++) {
		for (int j = 0; j < basic_number.size(); j++) {
			if (*tit == *uit) {
				std::cout << *tit << " ����" << std::endl;
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

	// �ߺ� ���� ���

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

}
