#include "OutputFile.h"

OutputFile::OutputFile(){

}

OutputFile::~OutputFile(){

}

void OutputFile::Output(string str){
	// 파일에 문자열 쓰기
	ofstream outputFile("example.txt");		// 파일 생성 및 파일 열기 ( 주소는 절대경로 및 상대경로 가능 )
	if (outputFile.is_open()) {				// 만약 outputFile이 오픈 되었다면
		outputFile << str;					// textToWrite에 입력된 문자열 넣기
		outputFile << str;					// textToWrite에 입력된 문자열 넣기
		outputFile << str;					// textToWrite에 입력된 문자열 넣기
		outputFile.close();					// outputFile 닫기
	}
	else {
		cout << "Unable to open the file for writting." << endl;
	}
}

void OutputFile::AppOutput(string str){
	fstream outputFile("example.txt", ios::out | ios::app); // 쓰기, 추가 입력 하기

	if (outputFile.is_open()) {
		outputFile << str;
		outputFile.seekg(0);
		outputFile.close();
	}
	else {
		cout << "Unalbe to open the file for reading." << endl;
	}

}
