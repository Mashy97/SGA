#include "Util.h"

Music M[100];

Music* px = M;
Elec elec;
Jazz jazz;
Rock rock;
Pop pop;
Hip hip;

void main_screan() {
	cout << " ================================= " << endl;
	cout << " ============= Music ============= " << endl;

}

void menu_screan() {
	cout << " ================================= " << endl;
	cout << " �޴��� �����ϼ���" << endl;
	cout << " ���� ȭ�� : 0" << endl;
	cout << " ��ü ���� : 1" << endl;
	cout << " �帣 ���� : 2" << endl;
	cout << " ���� �˻� : 3" << endl;
	cout << " ���� ��� : 4" << endl;
	cout << "   EXIT   : 99" << endl;
	cout << " �Է� ���� : ";
}

void select_gerne() {
	int temp = 0;
	cout << " ================================= " << endl;
	cout << " �帣�� �����ϼ��� " << endl;
	cout << " �Ϸ� : 1 " << endl;
	cout << " ���� : 2 " << endl;
	cout << " �� : 3 " << endl;
	cout << " �� : 4 " << endl;
	cout << " ���� : 5 " << endl;
	cout << " �Է� ���� : ";
	cin >> temp;

	switch (temp)
	{
	case 1:
		cout << " ========= �Ϸ� ========= " << endl;
		cout << "��ȣ" << "\t" << "����" << "\t" << "����" << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Elec") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 2:
		cout << " ========= ���� ========= " << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Jazz") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 3:
		cout << " ========= �� ========= " << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Rock") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 4:
		cout << " ========= �� ========= " << endl;
		for (int i = 0; i < 100; i++) {
			if (M[i].Mgenre == "Pop") {
				cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
			}
		}
		break;
	case 5:
		cout << " ========= ���� ========= " << endl;
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
	cout << " ���� �̸��� �Է��ϼ��� : ";
	cin >> vocal;
	cout << vocal << "�� ���� ����Ʈ " << endl;
	for (int i = 0; i < 100; i++) {
		if (M[i].Mvocal == vocal) {
			cout << M[i].Mnum << "\t" << M[i].Mname << "\t" << M[i].Mvocal << endl;
		}
	}

}

void play_music() {
	string name;
	cout << " ================================= " << endl;
	cout << " �뷡 ������ �Է��ϼ��� : ";
	cin >> name;
	for (int i = 0; i < 100; i++) {
		if ((px+i)->Mname == name) {
			(px+i)->Mplay();
		}
	}
}

void all_music() {
	cout << " ================================= " << endl;
	cout << " =========== ��ü �뷡 =========== " << endl;
	cout << "��ȣ" << "\t" << "����" << "\t" << "����" << "\t" << "�帣" << endl;
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
			*(px + i) = elec;
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
			*(px + i) = jazz;
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
			*(px + i) = rock;
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
			*(px + i) = pop;
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
			*(px + i) = hip;
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
