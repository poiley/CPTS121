/*********************************************************************
* Programmer: Benjamin Poile										 *
* Class: CptS 121, Fall 2017, Lab Section 14						 *
* Programming Assignment: PA 4										 *
* Date: Oct 5th, 2017												 *
* Description: Craps												 *
**********************************************************************/

# include "equations.h"

/* A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6
 * spots. After the dice have come to rest, the sum of the spots on the two upward faces is 
 * calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3,
 * or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins). If 
 * the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's 
 * "point." To win, you must continue rolling the dice until you "make your point." The 
 * player loses by rolling a 7 before making the point.*/
void main(void) {
	int run = 1, roll_counter = 1, point_value = 0, wln;
	double wager;

	print_game_rules();
	double balance = get_bank_balance();
	printf("Current Balance: %.2lf", balance);

	do {
		do {
			wager = get_wager_amount();
		} while (check_wager_amount(wager, balance) != 1);

		int d1 = roll_die();
		int d2 = roll_die();

		int dice_sum = calculate_sum_dice(d1, d2);

		printf("You rolled %d from %d and %d.\n", dice_sum, d1, d2);

		if (roll_counter == 1) {
			wln = is_win_loss_or_point(dice_sum);
			if (wln == -1) {
				point_value = dice_sum;
				printf("Your point value is %d.\n", point_value);
			}
		} else {
			wln = is_point_loss_or_neither(dice_sum, point_value);
		}
		
		int temp_balance = balance;

		balance = adjust_bank_balance(balance, wager, wln);

		chatter_messages(roll_counter, wln, temp_balance, balance);

		roll_counter++;

		printf("Press 1 to keep playing, 0 to quit.");
		scanf("%d", &run);
	} while(run == 1);


}