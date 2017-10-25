#include <stdio.h>
#include <stdlib.h>

void print(char a[]) {
	for (int i = 0; i < 6; i++) {
		printf("%c", a[i]);
	}
	printf("\n");
}

int main(void) {
	char word[] = "alexis";
	int guessed = 0, to_guess = 6;

	char censored[6] = "******";

	print(censored);

	while (guessed < to_guess) {
		printf("Guess?\n");
		char g;
		scanf("%c", &g);
		
		for (int i = 0; i < to_guess; i++) {
			if (word[i] == g) {
				censored[i] = g;
				guessed++;
			}
		}
	}
	print(word);
}