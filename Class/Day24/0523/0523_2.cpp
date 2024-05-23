#include <iostream>
#include <set>
#include <vector>

/*
	iterator - 반복
	어떤 컨테이너에 접근하든 동일한 방법으로 접근하기 위해서 제공되는 객체.

	vector<type>


*/

int main() {
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	vec.push_back(10);

	std::vector<int>::iterator it_start = vec.begin();
	std::vector<int>::iterator it_end = vec.end();

	for (it_start; it_start != it_end; ++it_start) {
		(*it_start) *= 2;
		std::cout << *it_start << std::endl;
	}

	std::cout << "================" << std::endl;

	// 범위기반 for - loop 사용
	for (const int &vec_value : vec) {
		std::cout << vec_value << std::endl;
	}



	return 0;
}