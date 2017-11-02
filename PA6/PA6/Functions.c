# include "Header.h"

int welcome_screen(int menu_selection) {
	switch (menu_selection) {
		case 1:
			//Play Game
			play_game();
			return 0;
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

	printf("[Y/N] Player 1, would you like to manually place your boats?\n");
	scanf(" %c", &input);
	if (input == 'Y' || input == 'y')
		player1_board[10][10] = manually_place_ships(player1_board);
	else
		player1_board[10][10] = randomly_place_ships(player1_board);
	player2_board[10][10] = randomly_place_ships(player2_board);
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

char * place_ship(char board[10][10], int size, char ship_name[], char ship_code) {
	char input_c = '!', row_s, row_e;
	int input_i = -1, column_s, column_e;

	do {
		printf("What row would you like to place your %s?\n", ship_name);
		scanf(" %c", &input_c);
		if ((int)input_c < 65 || (int)input_c > 90)
			input_c = '!';
		if (input_c != '!') row_s = input_c;

		printf("What column would you like to place your %s?\n", ship_name);
		scanf(" %d", &input_i);
		if (input_i > 9 || input_i < 0)
			input_c = '!';
		column_s = input_i;

		if (board[(int)row_s - 65][column_s] != '-')
			input_c = '!';

		printf("Starting coordinate is %c%d\n", row_s, column_s);

		printf("Would you like to place this (H)orizontally or (V)ertically?\n");
		scanf(" %c", &input_c);

		if (input_c == 'H') {
			row_e = row_s;
			if (column_s < (size - 1)) {
				column_e = column_s + size;
			} else if (column_s >(10 - size)) {
				column_e = column_s - size;
			} else {
				printf("Would you like the %s to move (L)eft or (R)ight from your starting coordinate?\n", ship_name);
				scanf(" %c", &input_c);
				if (input_c == "L") column_e = column_s - size;
				else if (input_c = "R") column_e = column_s + size;
				else input_c = '!';
			}
		} else if (input_c == 'V') {
			column_e = column_s;
			if ((int)row_s < (64 + size)) {
				row_e = row_s + size;
			} else if ((int)row_s >(75 - size)) {
				row_e = row_s - size;
			} else {
				printf("Would you like the %s to move (U)p or (D)own from your starting coordinate?\n", ship_name);
				scanf(" %c", &input_c);
				if (input_c == 'U') row_e = (char)((int)row_s - size);
				else if (input_c == 'D') row_e = (char)((int)row_s + size);
				else input_c = '!';
			}
		} else {
			input_c = '!';
		}

		if (check_collision(board, size, row_s, row_e, column_s, column_e) == 0)
			input_c = '!';

		if (row_s == row_e)
			for (int i = 0; i < size; i++)
				board[((int)row_s) - 65][column_s + i] = ship_code;
		else if (column_s == column_e)
			for (int i = 0; i < size; i++)
				board[(((int)row_s) - 65) + i][column_s] = ship_code;
		else
			printf("Something is seriously fucky here Ben!");

		if (input_c == '!')
			printf("\nSomething was wrong with your input, please try again.\n");
	} while (input_c == '!');

	return board;
}

char * place_ship_auto(char board[10][10], int size, char ship_code) {
	int horizontal_or_vertical = -1, row_s = 0, column_s = 0, column_e = 0, row_e = 0;
	char error = 'x';
	size -= 1;
	do {
		horizontal_or_vertical = rand() % 2; // 0 = H, 1 = V
	 	row_s = rand() % 10;
		column_s = rand() % 10;

		if (horizontal_or_vertical == 0) { //Horizontal
			row_e = row_s;
			if (column_s < (size - 1)) {
				column_e = column_s + size;
			} else {
				column_e = column_s - size;
			}
		} else if(horizontal_or_vertical == 1) { //Vertical
			column_e = column_s;
			if (row_s < (size - 1)) {
				row_e = row_s + size;
			} else {
				row_e = row_s - size;
			}
		}
		
	} while (error == '!');
	size += 1;
	
	if (row_e == -1) {
		row_e = 0;
		row_s++;
	} else if (row_s == -1) {
		row_s = 0;
		row_e++;
	} else if (column_e == -1) {
		column_e = 0;
		column_s++;
	} else if (column_s == -1) {
		 column_s = 0;
		 column_e++;
	}

	/*if (check_collision(board, size, row_s, row_e, column_s, column_e) == 0)
		error = '!';*/

	/*if (row_s == row_e)
		for (int i = 0; i < size; i++)
			board[((int)row_s) - 65][column_s + i] = ship_code;
	else if (column_s == column_e)
		for (int i = 0; i < size; i++)
			board[(((int)row_s) - 65) + i][column_s] = ship_code;
	else
		printf("Something is seriously fucky here Ben!");*/

	printf("\nSize %d; %d %d to %d %d", size, row_s, column_s, row_e, column_e);

	return board;
}

int check_collision(char board[10][10], int size, int row_s, int row_e, int column_s, int column_e) {
	if (row_s == row_e) //horizontal
		for (int i = 0; i <= size; i++)
			if (board[column_s + i][row_s] != '-')
				return 0;
	else 
		for (int i = 0; i <= size; i++)
			if (board[column_s][row_s+i] != '-')
				return 0;
	
	return 1;
}

// Carrier first, Battleship second, Cruiser third, Submarine fourth, and the Destroyer last.
char * manually_place_ships(char board[10][10]) {
	board = place_ship(board, 5, "Carrier", 'c');
	board = place_ship(board, 4, "Battleship", 'b');
	board = place_ship(board, 3, "Cruiser", 'r');
	board = place_ship(board, 3, "Submarine", 's');
	board = place_ship(board, 2, "Destroyer", 'd');
	
	display_board(board);
	printf("NOT RETURN OR CRASH");
	return board;
}

char * randomly_place_ships(char board[10][10]) {
	board = place_ship_auto(board, 5, 'c');
	display_board(board);

	board = place_ship_auto(board, 4, 'b');
	board = place_ship_auto(board, 3, 'r');
	board = place_ship_auto(board, 3, 's');
	board = place_ship_auto(board, 2, 'd');

	display_board(board);

	return board;
}

int check_shot(char board[10][10]) {}
int check_if_ship_sunk(char board[10][10]) {}
int is_winner(char board[10][10]) {}
void update_board(char board[10][10]) {}

void output_current_move(char board[10][10], char x, int y, int move_status) {}
void output_stats(int winner, int player1_stats[], int player2_stats[]) {}
