#include "OutputFile.h"

OutputFile::OutputFile(){

}

OutputFile::~OutputFile(){

}

void OutputFile::Output(string str){
	// ���Ͽ� ���ڿ� ����
	ofstream outputFile("example.txt");		// ���� ���� �� ���� ���� ( �ּҴ� ������ �� ����� ���� )
	if (outputFile.is_open()) {				// ���� outputFile�� ���� �Ǿ��ٸ�
		outputFile << str;					// textToWrite�� �Էµ� ���ڿ� �ֱ�
		outputFile << str;					// textToWrite�� �Էµ� ���ڿ� �ֱ�
		outputFile << str;					// textToWrite�� �Էµ� ���ڿ� �ֱ�
		outputFile.close();					// outputFile �ݱ�
	}
	else {
		cout << "Unable to open the file for writting." << endl;
	}
}

void OutputFile::AppOutput(string str){
	fstream outputFile("example.txt", ios::out | ios::app); // ����, �߰� �Է� �ϱ�

	if (outputFile.is_open()) {
		outputFile << str;
		outputFile.seekg(0);
		outputFile.close();
	}
	else {
		cout << "Unalbe to open the file for reading." << endl;
	}

}
