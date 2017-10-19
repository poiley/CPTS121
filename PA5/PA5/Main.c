# include "header.h"

int main(void) {
	int menu_val = 0;
	srand((unsigned int)time(NULL));

	while (menu_val != 3)
		menu_val = menu(menu_val);
	
	return 0;
}