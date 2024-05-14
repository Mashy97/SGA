#include "stdafx.h"
#include "Music.h"
#include "Util.h"

int main(){

	vector<Music> myMusics;

	Util myUtil;

	myUtil.LoadMusicData("MusicBaseData.csv", myMusics);

	for (int i = 0; i < myMusics.size(); i++)
		cout << myMusics[i].getGenre() << endl;


	return 0;
}
