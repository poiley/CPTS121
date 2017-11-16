
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
	char suit;
	char *suit_full;
	int number;
	char *number_full;
} Card;

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card *hand[5]);
Card getCard(char* number, char* suit);
