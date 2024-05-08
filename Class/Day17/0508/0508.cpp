#include "stdafx.h"
#include "InputFile.h"
#include "OutputFile.h"

int main() {
	
	// 파일 입출력 
	// fstream - 입출력, istream - 입력, ostream - 출력
	OutputFile ofile;
	InputFile ifile;
	string str = "string 문자열 테스트\n";
	ofile.Output(str);	// str 입력
	ifile.Input();

	cout << "=======================" << endl;
	string str1 = "Add Line";
	ofile.AppOutput(str1);	// str1 추가 입력하기
	ifile.Input();

	// CSV ( Comma - Separated Values ) 
	// Comma 쉼표를 기준으로 데이터의 값을 분할한다.

	// CSV 데이터 분할 및 출력
	
	string filename = "data.csv";

	// 파일 열기
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Failed to open the file: " << filename << endl;
		return 1;
	}
	// 파일에서 줄 단위로 데이터 가져오기, 읽기
	string line;
	while (getline(file, line)) {
		// 줄을 쉼표로 분리하기 위하여	 stringstream 사용
		stringstream ss(line);				// stringstream 문자열을 나누는 기능
		string field;
		vector<string> fields;

		// 쉼표로 분할된 각 필드 읽기
		while (getline(ss, field, ',')) {
			fields.push_back(field);
		}

		// 각 필드 출력
		for (const auto& f : fields) {
			cout << f << " ";
		}
		cout << endl;

	}
}
