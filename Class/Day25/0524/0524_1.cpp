#include <iostream>
#include <string>
#include <list>
#include <conio.h>


// 노래 정보 모음
// 가수로 찾고 입력
// 노래 정보 입력 가능하게 설정
// 가수이름 -> 노래 출력
// 노래가 2개 이상이라면 화살표를 이용하여 다음 노래 출력 및 이전 노래 출력 기능


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
			std::cout << " 다시 입력 " << std::endl;
		}

		
			switch (input)
			{
			case 75:		// 왼쪽
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
					std::cout << " 제일 앞 " << std::endl;
					break;
				}
				break;
			
			case 77:		// 오른쪽
				if (it != test_getch.end()) {
					std::advance(it, 1);
					if (it != test_getch.end()){
					std::cout << *it << std::endl;
					}
				}
				else {
					std::cout << " 제일 뒤 " << std::endl;
					break;
				}
				break;
			
			default:
				break;
			}
		
	
	}
	

}