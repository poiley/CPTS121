#include <stdio.h>
#include <time.h>

int welcome_screen(int menu_selection);

void play_game(void);
void initialize_board(char board[10][10]);
char * manually_place_ships(char board[10][10]);
char * randomly_place_ships(char board[10][10]);
int check_shot(char board[10][10]);
int check_if_ship_sunk(char board[10][10]);
int is_winner(char board[10][10]);
int ship_sunk(char board[10][10], char ship_code);
void update_board(char board[10][10]);
void display_board(char board[10][10]);



void output_current_move(char board[10][10], char x, int y, int move_status);
void output_stats(int winner, int player1_stats[], int player2_stats[]);

char * place_ship(char board[10][10], int size, char ship_name[], char ship_code);