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
//	std::list<int> temp = number;	// temp�� number �ʱ� �� ����

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;
	
	number.sort();			// ����
	number.unique();		// �ߺ� ����

//	std::list<int> uni_number = number;

	for (auto it = number.begin(); it != number.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "======" << std::endl;

	/*
		sort - �����͸� �����ϴ� ����
		unique - �������� ��, �� ������ ���Ͽ� �����ϴ� ����

		��, �ڸ� ���Ѵٰ� ������ ���� 
		list�� { 10, 9, 8, 8, 9, 10, 10 }�� �Է��Ͽ��� ��
		sort�� ������� �ʰ� unique�� ����� �� ����Ʈ ��� ���� 10 9 8 9 10�� ��Ÿ���� ������ Ȯ�� 
	 
		sort�� �� ����ϴ°� ?
		unique�� ����Ͽ� �ߺ��� ���ֱ� ���ؼ��� sort�� ����Ͽ� ������ ���� �ؾ��Ѵ�.

		����1. 
		��������, ������������ ������ ���� �ʰ� �����Ѵٸ�
		�� Ƚ���� �������� �׿� ���� �� ���� �ý��� �ڿ��� �ҿ��ϰ� �ȴ�.

		����2.
		�����Ͱ� ���ٸ� ���� ���̴� ���� ������
		�����Ͱ� �������ٸ� �ҿ�Ǵ� �ð� ���� �����Ѵ�.

		��� - ��ü�� Ȯ���Ͽ� �ߺ��� �����ϴ� �� ���� �����ϰ� ��, �ڸ� ���ϴ� ���� ���� ȿ�����̱� �����̴�.

	**/

}

/*
123334455
12345





*/