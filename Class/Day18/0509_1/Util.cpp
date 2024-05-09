#include "Util.h"

Music M[100];

Music* px = M;
Elec E;
Jazz J;
Rock R;
Pop P;
Hip H;

void main_screan() {
	cout << " ================================= " << endl;
	cout << " ============= Music ============= " << endl;

}

void menu_screan() {
	cout << " ================================= " << endl;
	cout << " 메뉴를 선택하세요" << endl;
	cout << " 메인 화면 : 0" << endl;
	cout << " 전체 음악 : 1" << endl;
	cout << " 장르 선택 : 2" << endl;
	cout << " 가수 검색 : 3" << endl;
	cout << " 제목 검색 : 4" << endl;
	cout << " 입력 숫자 : ";
}

void select_gerne() {
	int temp = 0;
	cout << " ================================= " << endl;
	cout << " 장르를 선택하세요 " << endl;
	cout << " 일렉 : 1 " << endl;
	cout << " 재즈 : 2 " << endl;
	cout << " 락 : 3 " << endl;
	cout << " 팝 : 4 " << endl;
	cout << " 힙합 : 5 " << endl;
	cout << " 입력 숫자 : ";
	cin >> temp;

	switch (temp)
	{
	case 1:
		cout << " ========= 일렉 ========= " << endl;
		cout << "번호" << "\t" << "제목" << "\t" << "가수" << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Elec") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 2:
		cout << " ========= 재즈 ========= " << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Jazz") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 3:
		cout << " ========= 락 ========= " << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Rock") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 4:
		cout << " ========= 팝 ========= " << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Pop") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 5:
		cout << " ========= 힙합 ========= " << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Hip") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	default:
		break;
	}

}

void search_vocal() {
	string vocal;
	cout << " ================================= " << endl;
	cout << " 가수 이름을 입력하세요 : ";
	cin >> vocal;
	cout << vocal << "의 음악 리스트 " << endl;
	for (int i = 0; i < 100; i++) {
		if (M[i].Mvocal == vocal) {
			cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
		}
	}

}

void play_music() {
	string name;
	cout << " ================================= " << endl;
	cout << " 노래 제목을 입력하세요 : ";
	cin >> name;
	for (int i = 0; i < 100; i++) {
		if (M[i].Mname == name) {
			M[i].Mplay();
		}
	}
}

void all_music() {
	cout << " ================================= " << endl;
	cout << " =========== 전체 노래 =========== " << endl;
	cout << "번호" << "\t" << "제목" << "\t" << "가수" << "\t" << "장르" << endl;
	for (int i = 0; i < 100; i++) {
		cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << "\t" << M[i].Mgenre << endl;
	}
}

void Create_Music() {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {
		int a = rand();
		int b = a % 5;
		switch (b)
		{
		case 0:
			*(px + i) = E;
			(px + i)->Mnum = i + 1;
			(px + i)->Mname = "Elec" + to_string(i);
			if (i > 50) {
				(px + i)->Mvocal = "a";
			}
			else {
				(px + i)->Mvocal = "f";
			}
			break;

		case 1:
			*(px + i) = J;
			(px + i)->Mnum = i + 1;
			(px + i)->Mname = "Jazz" + to_string(i);
			if (i > 50) {
				(px + i)->Mvocal = "b";
			}
			else {
				(px + i)->Mvocal = "e";
			}
			break;
		case 2:
			*(px + i) = R;
			(px + i)->Mnum = i + 1;
			(px + i)->Mname = "Rock" + to_string(i);
			if (i > 50) {
				(px + i)->Mvocal = "c";
			}
			else {
				(px + i)->Mvocal = "d";
			}
			break;
		case 3:
			*(px + i) = P;
			(px + i)->Mnum = i + 1;
			(px + i)->Mname = "Pop" + to_string(i);
			if (i > 50) {
				(px + i)->Mvocal = "f";
			}
			else {
				(px + i)->Mvocal = "b";
			}
			break;
		case 4:
			*(px + i) = H;
			(px + i)->Mnum = i + 1;
			(px + i)->Mname = "Hip" + to_string(i);
			if (i > 50) {
				(px + i)->Mvocal = "e";
			}
			else {
				(px + i)->Mvocal = "a";
			}
			break;
		default:
			break;
		}
	}
};
