#include "Title.h"

void Title::scean(){
	int screan_select = 0;
	bool Wbool = true;
	while (Wbool) {
		switch (screan_select)
		{
		case 0:
			main_screan();
			break;
		case 1:
			all_music();
			break;
		case 2:
			select_gerne();
			break;
		case 3:
			search_vocal();
			break;
		case 4:
			play_music();
			break;

		default:
			break;
		}

		menu_screan();
		cin >> screan_select;

		if (screan_select == 99) {
			Wbool = false;
		}

	}
}

Title::Title(){

}
