#include "Util.h"

vector<Music> myMusic;
Util myUtil;


void lineSeparator(){
    std::cout << "\n----------------------------------------------------------------------------------------------------\n";
}

void Util::LoadMusicData(string filename ,vector<Music> &musics)
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
