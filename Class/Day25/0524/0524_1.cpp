#include <iostream>
#include <string>
#include <list>
#include <conio.h>


// �뷡 ���� ����
// ������ ã�� �Է�
// �뷡 ���� �Է� �����ϰ� ����
// �����̸� -> �뷡 ���
// �뷡�� 2�� �̻��̶�� ȭ��ǥ�� �̿��Ͽ� ���� �뷡 ��� �� ���� �뷡 ��� ���


int main() {

	srand((unsigned int)time(NULL));

	std::list<int> test_getch;

	/*for (int i = 0; i < 5; i++) {
		test_getch.push_back(rand() % 10);
	}*/
	
	test_getch.push_back(10);
	test_getch.push_back(20);
	test_getch.push_back(30);
	test_getch.push_back(40);
	test_getch.push_back(50);
	test_getch.push_back(60);


	auto it = test_getch.begin();

	while (true) {

		int input = _getch();
		if (input == 224) {
			input = _getch();
		}
		else {
			std::cout << " �ٽ� �Է� " << std::endl;
		}

		
			switch (input)
			{
			case 75:		// ����
				if (it != test_getch.begin()) {
					if (it != test_getch.end()) {
						std::advance(it, -1);
						std::cout << *it << std::endl;
					}
					else {
						std::advance(it, -1);
					}
				}
				else {
					std::cout << " ���� �� " << std::endl;
					break;
				}
				break;
			
			case 77:		// ������
				if (it != test_getch.end()) {
					std::advance(it, 1);
					if (it != test_getch.end()){
					std::cout << *it << std::endl;
					}
				}
				else {
					std::cout << " ���� �� " << std::endl;
					break;
				}
				break;
			
			default:
				break;
			}
		
	
	}
	

}