#include <iostream>
#include <set>
/*
	Set - 자동 정렬되는 노드 기반 컨테이너 ( 이진트리로 구현 )
	기본적으로는 오름차순이며 greater을 사용하여 내림차순으로 정렬 가능하다.


	컬렉션에서 데이터를 저장하고 검색하는 데 사용
	요소의 set 값은 고유하며 데이터가 자동으로 정렬되는 키 값으로 사용

	insert		// 값을 추가, 중복된 값은 추가하지 않는다.
	earse(값)	// 값을 찾아서 삭제하는 기능을 한다.
	find		// 매칭된 값을 찾아준다. 못찾는다면 end() 포인터를 넘겨준다
	
*/


int main() {

	std::set<int> mySet;	// size = 0;

	if (mySet.empty()) {
		mySet.insert(5);
		mySet.insert(30);
		mySet.insert(10);
		mySet.insert(20);
	}

	mySet.insert(15);

	for (int value : mySet) {
		std::cout << value << std::endl;
	}

	std::cout << "erase(30) TEST " << std::endl;
	mySet.erase(30);

	for (auto it = mySet.begin(); it != mySet.end(); ++it ) {
		std::cout << *it << std::endl;
	}

	// find 
	auto it = mySet.find(50);
	if (it != mySet.end()) {	// find success
		std::cout << "50을 찾았습니다." << std::endl;
	}
	else {
		std::cout << "50 값이 없습니다." << std::endl;
	}
	return 0;
}