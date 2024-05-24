#include "Music.h"

Music::Music() 
	:title("unknown"), genre("x"), singer("unknown"), playing("no data") {

}

Music::Music(string title, string genre, string singer)
	:title(title), genre(genre), singer(singer){
	playing = "now playing " + singer + "-" + title;
}

string Music::getTitle(){
	return title;
}

string Music::getSinger(){
	return singer;
}

string Music::getGenre(){
	return genre;
}

string Music::getReleaseDate(){
	return releaseDate;
}

string Music::getPlaying(){
	return playing;
}

void Music::Play(){
	cout << playing << endl;
}

void Music::Display(){
	cout << title << "\t\t" << genre << "\t\t" << singer << endl;
}

