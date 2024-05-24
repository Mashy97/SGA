#include "Util.h"

vector<Music> myMusic;
Util myUtil;


void lineSeparator(){
    std::cout << "\n----------------------------------------------------------------------------------------------------\n";
}

void Util::LoadMusicData(string filename,vector<Music> &musics)
{
    ifstream file(filename);
    string line;
    getline(file, line);
    while (getline(file, line))
    {
        istringstream ss(line);
        Music row;
        getline(ss, row.title, ',');
        getline(ss, row.singer, ',');
        getline(ss, row.genre, ',');
        getline(ss, row.releaseDate, ',');
        getline(ss, row.playing , ',');
        musics.push_back(row);
    }
    file.close();
}

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

void select_genre() {
	myUtil.LoadMusicData("MusicBaseData.csv", myMusic);
	string str;
	
	cout << " ================================= " << endl;
	cout << " ���ϴ� �帣�� �Է��ϼ��� : ";
	cin >> str;
	for (int i = 0; i < myMusic.size(); i++) {
		if (myMusic[i].getGenre().find(str) != string::npos) {
			cout << myMusic[i].getTitle() << endl;
		}
	}

}

void search_vocal() {

	myUtil.LoadMusicData("MusicBaseData.csv", myMusic);

	list<Music> index;

	string vocal;
	cout << " ================================= " << endl;
	cout << " ���� �̸��� �Է��ϼ��� : ";
	cin >> vocal;
	cout << vocal << "�� ���� ����Ʈ " << endl;
	for (int i = 0; i < 100; i++) {
		if (myMusic[i].getSinger().find(vocal) != string::npos ) {
			index.push_back(myMusic[i]);
		}
	}

	auto it = index.begin();
	system("cls");
	std::cout << it->getSinger() << "�� ���� ����Ʈ" << std::endl;
	std::cout << it->getTitle() << std::endl;
	std::cout << " < > �̵�" << std::endl;


	bool wbool = true;
	while (wbool) {

		int input = _getch();
		if (input == 224) {
			input = _getch();
		}
		else {
			std::cout << " �ٽ� �Է� " << std::endl;
		}

		switch (input)
		{
		case 75:		// ����
			if (it != index.begin()) {
				if (it != index.end()) {
					std::advance(it, -1);
					system("cls");
					std::cout << it->getSinger() << "�� ���� ����Ʈ" << std::endl;
					std::cout << it->getTitle() << std::endl;
					std::cout << " < > �̵�" << std::endl;
				}
				else {
					std::advance(it, -1);
				}
			}
			else {
				std::cout << " ���� �� " << std::endl;
				break;
			}
			break;

		case 77:		// ������
			if (it != index.end()) {
				std::advance(it, 1);
				if (it != index.end()) {
					system("cls");
					std::cout << it->getSinger() << "�� ���� ����Ʈ" << std::endl;
					std::cout << it->getTitle() << std::endl;
					std::cout << " < > �̵�" << std::endl;
				}
			}
			else {
				std::cout << " ���� �� " << std::endl;
				break;
			}
			break;

		default:
			wbool = false;
			break;
		}


	}



}

void play_music() {
	myUtil.LoadMusicData("MusicBaseData.csv", myMusic);

	string name;
	cout << " ================================= " << endl;
	cout << " �뷡 ������ �Է��ϼ��� : ";
	cin >> name;
	for (int i = 0; i < 100; i++) {
		if (myMusic[i].getTitle().find(name) != string::npos) {
			cout << myMusic[i].getTitle() << endl;
			cout << myMusic[i].getPlaying() << endl;	
			break;
		}
	}
}

void all_music() {
	myUtil.LoadMusicData("MusicBaseData.csv", myMusic);

	cout << " ================================= " << endl;
	cout << " =========== ��ü �뷡 =========== " << endl;
	cout << "����" << "\t" << "����" << "\t" << "�帣" << endl;
	for (int i = 0; i < 100; i++) {
		cout << myMusic[i].getTitle() << "\t" << myMusic[i].getGenre()<< endl;
	}
}