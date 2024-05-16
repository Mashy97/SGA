#include "stdafx.h"
#include "Music.h"
#include "Util.h"
#include <time.h>
void check_size(std::vector<Music> vm) {

	std::cout << vm.size() << endl;
}

void push_vector(std::vector<Music>* vm) {
	Music music;
	
	for(int i = 0; i < 10; i++)
	vm->push_back(music);
}

void rand_Music(std::vector<Music> music) {
	srand((unsigned int)time(NULL));

	int num = rand() % music.size();
	std::cout << "=========================" << std::endl;
	std::cout << music[num].getTitle() << std::endl;
	std::cout << "=========================" << std::endl;
	std::cout << music[num].getPlaying() << std::endl;
}

int main() {

	std::vector<Music> music;
	std::vector<Music> musics;
	Util util;
	util.LoadMusicData("MusicBaseData.csv", music);
	util.LoadMusicData("MusicBaseData.csv", musics);
	
	// vector 사이즈 확인 - 100
	check_size(music);

	// vector 데이터 전체 삭제 - clear()
	music.clear();
	// clear 후 vector 사이즈 확인 - 0
	check_size(music);

	// push_back 이후 size 확인
	push_vector(&music);
	check_size(music);

	rand_Music(musics);

	return 0;
}
