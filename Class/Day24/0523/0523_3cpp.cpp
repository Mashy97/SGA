#include <iostream>
#include <set>
/*
	Set - �ڵ� ���ĵǴ� ��� ��� �����̳� ( ����Ʈ���� ���� )
	�⺻�����δ� ���������̸� greater�� ����Ͽ� ������������ ���� �����ϴ�.


	�÷��ǿ��� �����͸� �����ϰ� �˻��ϴ� �� ���
	����� set ���� �����ϸ� �����Ͱ� �ڵ����� ���ĵǴ� Ű ������ ���

	insert		// ���� �߰�, �ߺ��� ���� �߰����� �ʴ´�.
	earse(��)	// ���� ã�Ƽ� �����ϴ� ����� �Ѵ�.
	find		// ��Ī�� ���� ã���ش�. ��ã�´ٸ� end() �����͸� �Ѱ��ش�
	
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
		std::cout << "50�� ã�ҽ��ϴ�." << std::endl;
	}
	else {
		std::cout << "50 ���� �����ϴ�." << std::endl;
	}
	return 0;
}