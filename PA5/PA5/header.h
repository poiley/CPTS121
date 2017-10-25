#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void rules(void);
void start_game(void);
int menu(int menu_val);

int roll_dice(void);
int sum_calculator(int x, int dice_values[]);
int determine_score(int *dice_values);
