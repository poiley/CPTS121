# include "equations.h"

/* A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6
 * spots. After the dice have come to rest, the sum of the spots on the two upward faces is 
 * calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3,
 * or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins). If 
 * the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's 
 * "point." To win, you must continue rolling the dice until you "make your point." The 
 * player loses by rolling a 7 before making the point.*/

void main(void) {
	int run = 1, roll_counter = 1, winlossneither;
	double wager;

	print_game_rules();
	double balance = get_bank_balance();
	printf("Current Balance: %lf", balance);


	while (run == 1) {
		double wager = get_wager_amount();
		if (check_wager_amount(wager, balance) == 0)
			continue;
		break;
	}

	double d1 = roll_die();
	double d2 = roll_die();
	double sum = calculate_sum_dice(d1, d2);
	double previous_balance = balance;

	winlossneither = is_win_loss_or_point(sum);
	balance = adjust_bank_balance(balance, wager, winlossneither);

	chatter_messages(roll_counter, winlossneither, previous_balance, balance);
	
	while(run == 1) {
		wager = get_wager_amount();
		if (check_wager_amount(wager, balance) == 0)
			continue;

		d1 = roll_die();
		d2 = roll_die();
		sum = calculate_sum_dice(d1, d2);
		roll_counter++;
		
		winlossneither = is_point_loss_or_point(sum);
		balance = adjust_bank_balance(balance, wager, winlossneither);

		chatter_messages(roll_counter, winlossneither, previous_balance, balance);
	}

}