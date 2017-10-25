#include <stdio.h>
int main(void) {
	int dice_values[] = { 4, 4, 4, 5, 5 };
	int dice_tracker[6] = {0};

	for (int i = 0; i < 5; i++)
		dice_tracker[dice_values[i] - 1] += 1;

	int counter = dice_tracker[0];
	for (int i = 0; i <= 5; i++)
		if (i == 4 && dice_tracker[4] < dice_tracker[5])
			counter = dice_tracker[5];
		else if (dice_tracker[i] < dice_tracker[i + 1])
			counter = dice_tracker[i + 1];

	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 5; j++) {
			if (dice_tracker[i] == 3 && dice_tracker[j] == 2)
				counter = -1;
		}
	}
	
	printf("%d", counter);
}