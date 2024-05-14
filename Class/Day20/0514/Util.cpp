#include "Util.h"

vector<Music> myMusic;

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
}

void search_vocal() {
	string vocal;
	cout << " ================================= " << endl;
	cout << " ���� �̸��� �Է��ϼ��� : ";
	cin >> vocal;
	cout << vocal << "�� ���� ����Ʈ " << endl;
	for (int i = 0; i < 100; i++) {
		if (myMusic[i].getSinger() == vocal) {
			cout << myMusic[i].getTitle() << " - " << myMusic[i].getReleaseDate() << endl;
		}
	}

}

void play_music() {
	string name;
	cout << " ================================= " << endl;
	cout << " �뷡 ������ �Է��ϼ��� : ";
	cin >> name;
	for (int i = 0; i < 100; i++) {
		if (myMusic[i].title == name) {
			myMusic[i].getPlaying();
		}
	}
}

void all_music() {
	cout << " ================================= " << endl;
	cout << " =========== ��ü �뷡 =========== " << endl;
	cout << "����" << "\t" << "����" << "\t" << "�帣" << endl;
	for (int i = 0; i < 100; i++) {
		cout << myMusic[i].getTitle() << "\t" << myMusic[i].getSinger() << "\t" << myMusic[i].getGenre()<< endl;
	}
}