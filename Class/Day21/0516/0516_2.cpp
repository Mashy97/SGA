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
	
	// vector ������ Ȯ�� - 100
	check_size(music);

	// vector ������ ��ü ���� - clear()
	music.clear();
	// clear �� vector ������ Ȯ�� - 0
	check_size(music);

	// push_back ���� size Ȯ��
	push_vector(&music);
	check_size(music);

	rand_Music(musics);

	return 0;
}
