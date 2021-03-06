# include "header.h"

int menu(int menu_val) {
	printf("Main menu:\n1.\tRules\n2.\tStart Game\n3.\tExit\n\nInput: ");
	scanf("%d", &menu_val);

	switch (menu_val) {
		case 1:
			rules();
			break;
		case 2:
			start_game();
			break;
		case 3:
			printf("Goodbye!\n");
			break;
		default:
			printf("Error: Invalid Option!");
			menu(menu_val);
	}

	return menu_val;
}

void rules(void) {
	printf("\nThe scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n");
}

int roll_dice(void) {
	return (rand() % 6) + 1;
}

void start_game(void) {
	int player1_score = 0, player2_score = 0;
	for (int i = 0; i < 14; i++) {
		printf("\nPlayer 1, it's your turn!\n");
		player1_score += turns();

		printf("\nPlayer 2, it's your turn!\n");
		player2_score += turns();
	}

	if (player1_score >= 63)
		player1_score += 35;
	else if (player2_score >= 63)
		player2_score += 35;

	if (player1_score > player2_score)
		printf("\nPlayer 1 won with a score of %d to player 2's score of %d", player1_score, player2_score);
	else if (player2_score > player1_score)
		printf("\nPlayer 2 won with a score of %d to player 1's score of %d", player2_score, player1_score);
	else
		printf("\nPlayer 1 and 2 have tied with a score of %d.", player1_score);
}

int turns(void) {
	printf("Press [Enter] to roll the dice\n");
	getchar(); getchar(); // Two getchar()'s are needed here, as it reads the newline in from the previous method.

	int dice_values[5], rolls = 0;
	
	for (int i = 0; i < 5; i++)
		dice_values[i] = roll_dice();

	do {
		if (rolls < 3) {
			char yn = 'N';
			for(int i = 0; i < 5; i++)
				printf("Dice #%d. %d\n", (i + 1), dice_values[i]);

			printf("Do you want to use this roll for one of the game combos? [Y/N]\n");
			scanf(" %c", &yn);
			if (yn == 'Y' || yn == 'y') {
				break;
			} else {
				for (int i = 0; i < 5; i++) {
					char answer = 'N';
					printf("Would you like to re-roll dice #%d?\n", (i + 1));
					scanf(" %c", &answer);
					if (answer == 'Y' || answer == 'y')
						dice_values[i] = roll_dice();
				}
				rolls++;
			}
		} else if (rolls == 3) {
			break;
		}
	} while (rolls <= 3);
	
	//DICE VALUES ARE NOW FINAL
	for (int i = 0; i < 5; i++)
		printf("Dice #%d. %d\n", (i + 1), dice_values[i]);

	int points = determine_score(dice_values);
	printf("Points from this round: %d", points);

	return points;
}

int determine_score(int *dice_values) {

	int selection;
	printf("1.\tSum of 1's\t7.\tThree-of-a-kind\n2.\tSum of 2's\t8.\tFour-of-a-kind\n3.\tSum of 3's\t9.\tFull house\n4.\tSum of 4's\t10.\tSmall straight\n5.\tSum of 5's\t11.\tLarge straight\n6.\tSum of 6's\t12.\tYahtzee\n\t13. Chance\n");
	scanf("%d", &selection);

	int auxillary_arr[5], counter, sum = 0, a = 0, b = -1;
	int dice_tracker[6] = { 0 };

	for (int i = 0; i < 5; i++)
		sum += dice_values[i];

	switch (selection) {
		case 1:
			return sum_calculator(1, dice_values);
		case 2:
			return sum_calculator(2, dice_values);
		case 3:
			return sum_calculator(3, dice_values);
		case 4:
			return sum_calculator(4, dice_values);
		case 5:
			return sum_calculator(5, dice_values);
		case 6:
			return sum_calculator(6, dice_values);
			break;
		case 7:
		case 8: // 3 and 4 of a kind
			for (int i = 0; i < 5; i++)
				dice_tracker[dice_values[i] - 1] += 1;

			int counter = dice_tracker[0];
			for (int i = 0; i <= 5; i++)
				if (i == 4 && dice_tracker[4] < dice_tracker[5])
					counter = dice_tracker[5];
				else if (dice_tracker[i] < dice_tracker[i + 1])
					counter = dice_tracker[i + 1];
			
			if (counter >= 3)
				return sum;
			return 0;
		case 9:
			for (int i = 0; i < 5; i++)
				dice_tracker[dice_values[i] - 1] += 1;

			for (int i = 0; i <= 5; i++)
				for (int j = 0; j <= 5; j++)
					if (dice_tracker[i] == 3 && dice_tracker[j] == 2)
						return 25;
			return 0;
		case 10:
			counter = 0;

			for (int i = 0; i < 5; i++)
				dice_tracker[dice_values[i] - 1] += 1;

			for (int i = 0; i <= 5; i++) {
				if (dice_tracker[i] >= 3) return 0;
				if (i > 1 && i < 4 && counter == 0) return 0;
				if (i == 4 && dice_tracker[5] > 0) counter++;
				if ((i != 4 || i != 5) && dice_tracker[i] == dice_tracker[i + 1]) counter++;
				if (counter == 4) return 30;
			}
			return 0;
		case 11:
			counter = 0;

			for (int i = 0; i < 5; i++)
				dice_tracker[dice_values[i] - 1] += 1;

			for (int i = 0; i <= 5; i++) {
				if (dice_tracker[i] >= 3) return 0;
				if (i > 1 && i < 4 && counter == 0) return 0;
				if (i == 4 && dice_tracker[5] > 0) counter++;
				if ((i != 4 || i != 5) && dice_tracker[i] == dice_tracker[i + 1]) counter++;
				if (counter == 5) return 40;
			}
			return 0;
		case 12:
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					if (dice_values[i] != dice_values[j])
						return 0;
			return 50;
		case 13:
			return sum;
		default:
			printf("Please select an option");
			determine_score(dice_values);
	}
}

int sum_calculator(int x, int dice_values[]) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (dice_values[i] == x)
			counter++;
	}
	return counter * x;
}