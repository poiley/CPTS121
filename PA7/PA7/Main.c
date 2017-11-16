// Authors: Deitel & Deitel - C How to Program

#include "Header.h"

int main(void) {
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	Card hand[5] = { '!', '!!', 3 };

	srand ((unsigned) time (NULL)); /* seed random-number generator */

	shuffle (deck);
	deal (deck, face, suit, &hand);

	return 0;
}

/* shuffle cards in deck */
void shuffle (int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card *hand[5]) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int cards_dealt = 0;
	
	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++) {
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++) {
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++) {
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card) {
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					printf("%d", cards_dealt);
					*hand[cards_dealt] = getCard(wFace[column], wSuit[row]);

					cards_dealt += 1;
					if (cards_dealt == 5) break;
				}
			}
			if (cards_dealt == 5) break;
		}
		if (cards_dealt == 5) break;
	}
}

Card getCard(char* number, char* suit) {
	Card obj;

	obj.number_full = number;
	if (number == "Ace") obj.number = 1;
	else if (number == "Deuce") obj.number = 2;
	else if (number == "Three") obj.number = 3;
	else if (number == "Four") obj.number = 4;
	else if (number == "Five") obj.number = 5;
	else if (number == "Six") obj.number = 6;
	else if (number == "Seven") obj.number = 7;
	else if (number == "Eight") obj.number = 8;
	else if (number == "Nine") obj.number = 9;
	else if (number == "Ten") obj.number = 10;
	else if (number == "Jack") obj.number = 11;
	else if (number == "Queen") obj.number = 12;
	else if (number == "King") obj.number = 13;

	obj.suit_full = suit;
	obj.suit = tolower(suit[0]);

	return obj;
}

int containsPair(Card hand[5]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (hand[i].number == hand[j].number && i != j)
				return 1;
	return 0;
}

int containsTwoPairs(Card hand[5]) {
	int pairs = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (hand[i].number == hand[j].number && i != j) {
				pairs++;
				if (pairs == 2)
					return 1;
			}
		}
	}
	return 0;
}

int containsThreeKind(Card hand[5]) {
	int kind = 0;
	int other_index = 0;
	for (int i = 0; i < 5; i++) {
		kind = 0;
		for (int j = 0; j < 5; j++) {
			if (hand[i].number == hand[j].number && i != j && i != other_index) {
				other_index = j;
				kind++;
			}
		}
		if (kind >= 3)
			return 1;
	}
	return 0;
}

int containsFourKind(Card hand[5]) {
	int kind = 0;
	int other_index = 0;
	for (int i = 0; i < 5; i++) {
		kind = 0;
		for (int j = 0; j < 5; j++) {
			if (hand[i].number == hand[j].number && i != j && i != other_index) {
				other_index = j;
				kind++;
			}
		}
		if (kind >= 4)
			return 1;
	}
	return 0;
}

int containsFlush(Card hand[5]) {
	for (int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if (hand[i].suit != hand[j].suit)
				return 0;
	return 1;
}

int containsStraight(Card hand[5]) {
	int minimum = hand[0].number;
	for (int i = 1; i < 5; i++)
		if (hand[i].number < minimum)
			minimum = hand[i].number;
	
	int contains = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (hand[i].number == minimum + i + 1)
				++contains;

	if (contains != 5)
		return 0;
	return 1;
}

int returnHighestValue(Card hand[5]) {
	int highestValue = 0;
	if (containsPair(hand) == 1)
		highestValue = 1;
	if (containsTwoPairs(hand) == 1)
		highestValue = 2;
	if (containsThreeKind(hand) == 1)
		highestValue = 3;
	if (containsFourKind(hand) == 1)
		highestValue = 4; 
	if (containsFlush(hand) == 1)
		highestValue = 5;
	if (containsStraight(hand) == 1)
		highestValue = 5;

	return highestValue;
}
