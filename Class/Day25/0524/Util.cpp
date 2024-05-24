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
	cout << " 메뉴를 선택하세요" << endl;
	cout << " 메인 화면 : 0" << endl;
	cout << " 전체 음악 : 1" << endl;
	cout << " 장르 선택 : 2" << endl;
	cout << " 가수 검색 : 3" << endl;
	cout << " 음악 재생 : 4" << endl;
	cout << "   EXIT   : 99" << endl;
	cout << " 입력 숫자 : ";
}

void select_genre() {
	myUtil.LoadMusicData("MusicBaseData.csv", myMusic);
	string str;
	
	cout << " ================================= " << endl;
	cout << " 원하는 장르를 입력하세요 : ";
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
	cout << " 가수 이름을 입력하세요 : ";
	cin >> vocal;
	cout << vocal << "의 음악 리스트 " << endl;
	for (int i = 0; i < 100; i++) {
		if (myMusic[i].getSinger().find(vocal) != string::npos ) {
			index.push_back(myMusic[i]);
		}
	}

	auto it = index.begin();
	system("cls");
	std::cout << it->getSinger() << "의 음악 리스트" << std::endl;
	std::cout << it->getTitle() << std::endl;
	std::cout << " < > 이동" << std::endl;


	bool wbool = true;
	while (wbool) {

		int input = _getch();
		if (input == 224) {
			input = _getch();
		}
		else {
			std::cout << " 다시 입력 " << std::endl;
		}

		switch (input)
		{
		case 75:		// 왼쪽
			if (it != index.begin()) {
				if (it != index.end()) {
					std::advance(it, -1);
					system("cls");
					std::cout << it->getSinger() << "의 음악 리스트" << std::endl;
					std::cout << it->getTitle() << std::endl;
					std::cout << " < > 이동" << std::endl;
				}
				else {
					std::advance(it, -1);
				}
			}
			else {
				std::cout << " 제일 앞 " << std::endl;
				break;
			}
			break;

		case 77:		// 오른쪽
			if (it != index.end()) {
				std::advance(it, 1);
				if (it != index.end()) {
					system("cls");
					std::cout << it->getSinger() << "의 음악 리스트" << std::endl;
					std::cout << it->getTitle() << std::endl;
					std::cout << " < > 이동" << std::endl;
				}
			}
			else {
				std::cout << " 제일 뒤 " << std::endl;
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
	cout << " 노래 제목을 입력하세요 : ";
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
	cout << " =========== 전체 노래 =========== " << endl;
	cout << "제목" << "\t" << "가수" << "\t" << "장르" << endl;
	for (int i = 0; i < 100; i++) {
		cout << myMusic[i].getTitle() << "\t" << myMusic[i].getGenre()<< endl;
	}
}