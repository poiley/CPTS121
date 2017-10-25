# include "Header.h"

int main(void) {
	int menu_selection;
	
	do {
		printf("\nMenu:\n1.\tPlay\n2.\tRules\n3.\tQuit\n");
		scanf("%d", &menu_selection);
		menu_selection = welcome_screen(menu_selection);
	} while (menu_selection != 0);
}