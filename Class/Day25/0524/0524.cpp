#include <iostream>

// 중복 허용 x, 자동 정렬
#include <set>

// 중복 허용 x, 자동 정렬 x
#include <unordered_set>	

int main(){
	std::set<int> mySet;
	std::unordered_set<int> un_Set;

	mySet.insert(100);
	mySet.insert(10);
	mySet.insert(20);
	mySet.insert(30);
	mySet.insert(10);

	un_Set.insert(100); // 100
	un_Set.insert(10);	// 100 10
	un_Set.insert(20);	// 20 100 10
	un_Set.insert(30);	// 100 10 20 30
	un_Set.insert(10);	// 20 100 10 30


	for (int num : mySet) {
		std::cout << num << " ";
	}
	std::cout << std::endl;


	for (int num : un_Set) {
		std::cout << num << " ";
	}

}
