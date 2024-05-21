#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <time.h>
/** ����Ʈ ����
* 1. ����Ʈ�� �����Լ��� �̿��Ͽ� 30�� ������ �Է�
* 2. ¦���� �����ϰ� Ȧ���� �����
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