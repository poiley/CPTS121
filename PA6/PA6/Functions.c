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

void play_game(void) {
	//INTEGER win: 0 means nobody has won the game yet, 1 means player1 has won, 2 is player2
	//INTEGER guess_status: 0 = hit, 1 = miss
	int win = 0, guessed_column, guessed_row_int, guess_status, player1_sunk, player2_sunk;
	char input, guessed_row;

	//INTEGER[] player#_hit_stats: 0/Carrier, 1/Cruiser, 2/Battleship, 3/Submarine, 4/Destroyer
	int player1_hit_stats[5] = { 0 };
	int player2_hit_stats[5] = { 0 };

	char player1_board[10][10] = { { '-' } };
	char player2_board[10][10] = { { '-' } };

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

	display_board(player1_board);
	display_board(player2_board);

	do {
		/*PLAYER 1 TURN*/
		printf("\nPlayer 1: Target position's coordinates?\nYour board:\n");
		display_board(player1_board);
		scanf(" %c%d", &guessed_row, &guessed_column);
		printf("\nYou chose to target %c%d!", guessed_row, guessed_column);
		guessed_row_int = ((int)guessed_row) - 65;

		if (player2_board[guessed_row_int][guessed_column] == '-') {
			guess_status = 0;
			printf("\nMISS");
			player2_board[guessed_row_int][guessed_column] = 'm';
		}
		else if (player2_board[guessed_row_int][guessed_column] != '-' || player2_board[guessed_row_int][guessed_column] != 'x') { //MISS
			guess_status = 1;
			printf("\nHIT!");

			char hit_cell = player2_board[guessed_row_int][guessed_column];
			player2_board[guessed_row_int][guessed_column] = 'x';

			if (ship_sunk(player2_board, 'c') == 1 && hit_cell == 'c') {
				printf("\nCarrier sunk!");
				player1_sunk++;
			}
			else if (ship_sunk(player2_board, 'b') == 1 && hit_cell == 'b') {
				printf("\nBattleship sunk!");
				player1_sunk++;
			}
			else if (ship_sunk(player2_board, 'r') == 1 && hit_cell == 'r') {
				printf("\nCruiser sunk!");
				player1_sunk++;
			}
			else if (ship_sunk(player2_board, 's') == 1 && hit_cell == 's') {
				printf("\nSubmarine sunk!");
				player1_sunk++;
			}
			else if (ship_sunk(player2_board, 'd') == 1 && hit_cell == 'd') {
				printf("\nDestroyer sunk!");
				player1_sunk++;
			}

			if (player1_sunk == 5) {
				win = 1;
				break;
			}
		}

		system("cls");

		/*PLAYER 2 TURN*/
		printf("\n\nPlayer 2: Target position's coordinates?\nYour board:\n");
		display_board(player2_board);
		scanf(" %c%d", &guessed_row, &guessed_column);
		printf("\nYou chose to target %c%d!", guessed_row, guessed_column);
		guessed_row_int = ((int)guessed_row) - 65;

		if (player1_board[guessed_row_int][guessed_column] == '-') {
			guess_status = 0;
			printf("\nMISS");
			player1_board[guessed_row_int][guessed_column] = 'm';
		}
		else if (player1_board[guessed_row_int][guessed_column] == 'x') {
			printf("You have already guessed this coordinate!");
			continue;
		}
		else if (player1_board[guessed_row_int][guessed_column] != '-' || player1_board[guessed_row_int][guessed_column] != 'x') { //MISS
			guess_status = 1;
			printf("\nHIT!");

			char hit_cell = player1_board[guessed_row_int][guessed_column];
			player1_board[guessed_row_int][guessed_column] = 'x';

			if (ship_sunk(player1_board, 'c') == 1 && hit_cell == 'c') {
				printf("\nCarrier sunk!");
				player2_sunk++;
			}
			else if (ship_sunk(player1_board, 'b') == 1 && hit_cell == 'b') {
				printf("\nBattleship sunk!");
				player2_sunk++;
			}
			else if (ship_sunk(player1_board, 'r') == 1 && hit_cell == 'r') {
				printf("\nCruiser sunk!");
				player2_sunk++;
			}
			else if (ship_sunk(player1_board, 's') == 1 && hit_cell == 's') {
				printf("\nSubmarine sunk!");
				player2_sunk++;
			}
			else if (ship_sunk(player1_board, 'd') == 1 && hit_cell == 'd') {
				printf("\nDestroyer sunk!");
				player2_sunk++;
			}

			if (player2_sunk == 5) {
				win = 2;
				break;
			}
			system("cls");
		}
	} while (win == 0);

	if (win == 1) {
		printf("Congratulations Player 1! You have won the game.");
	}
	else {
		printf("Congratulations Player 2! You have won the game.");
	}
}

int ship_sunk(char board[10][10], char ship_code) {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (board[i][j] == ship_code)
				return 0;
	return 1;
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
	int input_i = -1, column_s, column_e, row_s_int, row_e_int;

	do {
		printf("What's the starting coordinate for the ship %s?\n", ship_name);
		scanf(" %c%d", &input_c, &input_i);

		row_s = input_c;
		row_s_int = (int)row_s - 65;
		column_s = input_i;

		if (row_s_int < 0 || row_s_int > 10 || column_s < 0 || column_s > 10) {
			printf("\nSomething was wrong with your input, please try again.\n");
			continue;
		}

		printf("Starting coordinate is %c%d\n", row_s, column_s);

		printf("Would you like to place this 1. Horizontally or 2. Vertically?\n");
		scanf("%d", &input_i);

		if (input_i == 1) {
			column_e = column_s;
			if ((row_s_int + size) > 10) {
				printf("\nSomething was wrong with your input, please try again.\n");
				continue;
			}
			row_e_int = row_s_int + size;
			row_e = (char)((int) row_s + size);
		} else if (input_i == 0) {
			row_e = row_s;
			if ((column_s + size) > 10) {
				printf("\nSomething was wrong with your input, please try again.\n");
				continue;
			}

			column_e = column_s + size;
		} else {
			printf("\nSomething was wrong with your input, please try again.\n");
			continue;
		}

		if (check_collision(board, size, row_s_int, row_e_int, column_s, column_e) == 0) {
			printf("\nSomething was wrong with your input, please try again.\n");
			continue;
		}

		if (row_s == row_e) {
			for (int i = 0; i < size; i++)
				board[row_s_int + i][column_s] = ship_code;
			break;
		} else if (column_s == column_e) {
			for (int i = 0; i < size; i++)
				board[row_s_int][column_s + i] = ship_code;
			break;
		} else {
			continue;
		}

		if (input_c == '!')
			printf("\nSomething was wrong with your input, please try again.\n");
	} while (input_c == '!');

	return board;
}

char * place_ship_auto(char board[10][10], int size, char ship_code) {
	int horizontal_or_vertical = -1, row_s = 0, column_s = 0, column_e = 0, row_e = 0;
	char error = 'x';
	size--;
	do {
		horizontal_or_vertical = rand() % 2; // 0 = H, 1 = V
		row_s = rand() % 10;
		column_s = rand() % 10;

		if (horizontal_or_vertical == 0) { //Horizontal
			row_e = row_s;
			if (column_s < (size - 1))
				column_e = column_s + size;
			else
				column_e = column_s - size;
		}
		else if (horizontal_or_vertical == 1) { //Vertical
			column_e = column_s;
			if (row_s < (size - 1))
				row_e = row_s + size;
			else
				row_e = row_s - size;
		}

		if (row_e == -1) {
			row_e = 0;
			row_s--;
		}
		else if (row_s == -1) {
			row_s = 0;
			row_e++;
		}
		else if (column_e == -1) {
			column_e = 0;
			column_s--;
		}
		else if (column_s == -1) {
			column_s = 0;
			column_e++;
		}

		error = 'x';
		if (check_collision(board, size, row_s, row_e, column_s, column_e) == 0)
			continue;

	} while (error == '!');

	size++;
	if (row_s == row_e)
		for (int i = 0; i < size; i++)
			board[row_s][column_s + i] = ship_code;
	else if (column_s == column_e)
		for (int i = 0; i < size; i++)
			board[row_s + i][column_s] = ship_code;
	else
		printf("Something is seriously fucky here Ben!");

	return board;
}

int check_collision(char board[10][10], int size, int row_s, int row_e, int column_s, int column_e) {
	if (row_s == row_e) { //horizontal
		for (int i = 0; i < size; i++)
			if (board[column_s + i][row_s] != '-')
				return 0;
	} else {
		for (int i = 0; i < size; i++)
			if (board[column_s][row_s + i] != '-')
				return 0;
	}
	return 1;
}

// Carrier first, Battleship second, Cruiser third, Submarine fourth, and the Destroyer last.
char * manually_place_ships(char board[10][10]) {
	board = place_ship(board, 5, "Carrier", 'c');
	display_board(board);
	board = place_ship(board, 4, "Battleship", 'b');
	board = place_ship(board, 3, "Cruiser", 'r');
	board = place_ship(board, 3, "Submarine", 's');
	board = place_ship(board, 2, "Destroyer", 'd');

	return board;
}

char * randomly_place_ships(char board[10][10]) {
	board = place_ship_auto(board, 5, 'c');
	board = place_ship_auto(board, 4, 'b');
	board = place_ship_auto(board, 3, 'r');
	board = place_ship_auto(board, 3, 's');
	board = place_ship_auto(board, 2, 'd');

	/*
	printf("\n\n%c\n\n", board[0][2]);
	board[0][2] = 'F';
	printf("\n\n%c\n\n", board[0][2]);
	*/
	return board;
}