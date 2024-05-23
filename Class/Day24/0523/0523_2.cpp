#include <iostream>
#include <set>
#include <vector>

/*
	iterator - �ݺ�
	� �����̳ʿ� �����ϵ� ������ ������� �����ϱ� ���ؼ� �����Ǵ� ��ü.

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

	// ������� for - loop ���
	for (const int &vec_value : vec) {
		std::cout << vec_value << std::endl;
	}



	return 0;
}