#include "InputFile.h"

InputFile::InputFile(){

}

InputFile::~InputFile(){

}

void InputFile::Input(){
	string readText;
	ifstream inputFile("example.txt");		// ���� ����
	if (inputFile.is_open()) {				// ���� inputFile�� ���� �Ǿ��ٸ�

		int count = 1;
		while (getline(inputFile, readText)) {// �ش� ������ 1�پ� �����´�
			cout << "���� ��ȣ : " << count << "\t" << readText << endl;
			count++;
		}

		inputFile.close();
	}
	else {
		cout << "Unalbe to open the file for reading." << endl;
	}
}
