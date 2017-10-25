# include "Header.h"

int welcome_screen(int menu_selection) {
	switch (menu_selection) {
		case 1:
			//Play Game
			play_game();
			return 1;
		case 2:
			//Display Rules
			printf("RULES");
			return 1;
		case 3:
			printf("\nQuitting!\n");
			return 0;
		default:
			printf("Invalid input!");
			return 1;
	}
}

void play_game() {
	char input;
	char player1_board[10][10] = { '-' };
	char player2_board[10][10] = { '-' };
	initialize_board(player1_board);
	initialize_board(player2_board);
	display_board(player1_board);

	printf("[Y/N] Player 1, would you like to manually place your boats?");
	scanf("%c", &input);
	if (input == 'Y' || input == 'y')
		manually_place_ships(player1_board);
	else
		randomly_place_ships(player1_board);
	randomly_place_ships(player2_board);
}

void initialize_board(char board[10][10]) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			board[i][j] = '-';
}

void display_board(char board[10][10]) {
	for (int i = 0; i <= 10; i++) printf("----");
	printf("-\n|   ");
	for (int i = 0; i < 10; i++) printf("| %d ", i);
	printf("|\n");
	for (int i = 0; i <= 10; i++) printf("----");
	printf("-\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) 
				printf("| %c ", 65 + i);
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		for (int i = 0; i <= 10; i++) printf("----");
		printf("-\n");
	}
}

void manually_place_ships(char board[10][10]) {
	char input_c = '!', row_s, row_e;
	int input_i = -1, column_s, column_e;
	do {
		printf("What row would you like to place your Carrier?\n");
		scanf("%c", &input_c);
		if ((int)input_c < 65 || (int)input_c > 90)
			input_c = '!';
		if (input_c != '!') row_s = input_c;

		printf("What column would you like to place your Carrier?\n");
		scanf("%d", &input_i);
		if (input_i > 9 || input_i < 0)
			input_c = '!';
		column_s = input_i;

		printf("Starting coordinate is %c%d", row_s, column_s);

		printf("Would you like to place this (H)orizontally or (V)ertically?\n");
		scanf("%c", &input_c);

		if (input_c == 'H') {
			row_e = row_s;
			if (column_s < 4) {
				column_e = column_s + 5;
			} else if (column_s > 5) {
				column_e = column_s - 5;
			} else {
				printf("Would you like the Carrier to move (L)eft or (R)ight from your starting coordinate?\n");
				scanf("%c", &input_c);
				if (input_c == "L") column_e = column_s - 5;
				else if (input_c = "R") column_e = column_s + 5;
				else input_c = '!';
			}
		} else if (input_c == 'V') {
			column_e = column_s;
			if ((int)row_s < 69) {
				row_e = row_s + 5;
			} else if ((int)row_s > 70) {
				row_e = row_s - 5;
			} else {
				printf("Would you like the Carrier to move (U)p or (D)own from your starting coordinate?\n");
				scanf("%c", &input_c);
				if (input_c == 'U') row_e = (char)((int)row_s - 5);
				else if (input_c == 'D') row_e = (char)((int)row_s + 5);
				else input_c = '!';
			}
		} else {
			input_c = '!';
		}

	} while (input_c == '!');
}

void randomly_place_ships(char board[10][10]) {}
int check_shot(char board[10][10]) {}
int check_if_ship_sunk(char board[10][10]) {}
int is_winner(char board[10][10]) {}
void update_board(char board[10][10]) {}

void output_current_move(char board[10][10], char x, int y, int move_status) {}
void output_stats(int winner, int player1_stats[], int player2_stats[]) {}
