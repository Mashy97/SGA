#include "InputFile.h"

InputFile::InputFile(){

}

InputFile::~InputFile(){

}

void InputFile::Input(){
	string readText;
	ifstream inputFile("example.txt");		// 파일 열기
	if (inputFile.is_open()) {				// 만약 inputFile이 오픈 되었다면

		int count = 1;
		while (getline(inputFile, readText)) {// 해당 파일의 1줄씩 가져온다
			cout << "라인 번호 : " << count << "\t" << readText << endl;
			count++;
		}

		inputFile.close();
	}
	else {
		cout << "Unalbe to open the file for reading." << endl;
	}
}
