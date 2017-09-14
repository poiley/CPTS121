/*
	Name: Benjamin Poile
	Desc: Prompt user for 3 exam scores and return the average
*/

#include <stdio.h>

int main(void) {
	int score1 = 0, score2 = 0, score3 = 0;
	printf("Please input exam scores:\n");
	
	scanf("%d%d%d \n", &score1, &score2, &score3);

	printf("%d %d %d \n", score1 + score2 + score3);

	return 0;
}