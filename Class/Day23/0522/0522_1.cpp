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
//	std::list<int> temp = number;	// temp에 number 초기 값 저장

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;
	
	number.sort();			// 정렬
	number.unique();		// 중복 제거

//	std::list<int> uni_number = number;

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

	/*
		sort - 데이터를 정렬하는 역할
		unique - 데이터의 앞, 뒤 정보를 비교하여 삭제하는 역할

		앞, 뒤를 비교한다고 생각한 이유 
		list에 { 10, 9, 8, 8, 9, 10, 10 }을 입력하였을 때
		sort를 사용하지 않고 unique를 사용할 시 리스트 출력 값이 10 9 8 9 10로 나타내는 것으로 확인 
	 
		sort를 왜 써야하는가 ?
		unique를 사용하여 중복을 없애기 위해서는 sort를 사용하여 정렬을 먼저 해야한다.

		이유1. 
		오름차순, 내림차순으로 정렬을 하지 않고 진행한다면
		비교 횟수도 많아지고 그에 따라서 더 많은 시스템 자원을 소요하게 된다.

		이유2.
		데이터가 적다면 비교적 차이는 많이 없지만
		데이터가 많아진다면 소요되는 시간 역시 증가한다.

		결과 - 전체를 확인하여 중복을 제거하는 것 보다 정렬하고 앞, 뒤를 비교하는 것이 더욱 효율적이기 때문이다.

	**/

}

/*
123334455
12345





*/