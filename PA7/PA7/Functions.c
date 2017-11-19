/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 121, Fall 2017, Lab Section 14
* Programming Assignment: PA 7
* Date: Nov 19th, 2017
* Description: Poker
* Credits: Deitel & Deitel, Andrew O'Fallon for started code
**********************************************************************/

#include "Header.h" //import header

/*Logic for the dealer to run to determine how to go about selecting a re-dealing of the cards*/
void dealer(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]) {
	switch (returnHighestValue(hand)) {
	case 1: // a pair, so the wisest choice would be to get 3 cards
		getThreeCards(wDeck, hand, wFace, wSuit);
		break; //GET 3 CARDS
	case 2: // two pairs, so the wisest choice would be to get only one more card
		getOneCard(wDeck, hand, wFace, wSuit);
		break; //GET 1 CARD
	case 3: // a three of a kind, so the wisest choice would be to get 2 cards
		getTwoCards(wDeck, hand, wFace, wSuit);
		break; //GET 2 CARDS
	case 4: // a four of a kind, no more cards would be the best choice
		break; //NOTHING NEEDED
	case 5: // a flush, no more cards would be the best choice
		break; //NOTHING NEEDED
	case 0: // nothing of value, so a complete re-do would be best
		break; //REDEAL 
	}
}

/*When two pairs are found, replace one card*/
void getOneCard(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]) { //ONLY CALLED IF THERES TWO PAIRS, DETEREMINE THE TWO PAIRS
	int pairs = 0, number = -1, index_to_replace;
	int index[5] = { 1 };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (hand[i].number == hand[j].number && i != j && hand[i].number != number) {
				index[i] = -1;
				index[j] = -1;
			}

	for (int i = 0; i < 5; i++)
		if (index[i] != -1)
			index_to_replace = i;

	hand[index_to_replace] = newCard(wDeck, wFace, wSuit);
}

/*When a three of a kind is found, replace two cards*/
void getTwoCards(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]) {
	int index[] = { 1 };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				if (hand[k].number == hand[i].number && hand[k].number == hand[j].number && k != j && k != i) {
					index[k] = -1;
					index[i] = -1;
					index[j] = -1;
				}

	for (int i = 0; i < 5; i++)
		if (index[i] == 1)
			hand[i] = newCard(wDeck, wFace, wSuit);
}

/*When a pair is found, replace three cards*/
void getThreeCards(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]) {
	int index[] = { 1 };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (hand[i].number == hand[j].number && i != j) {
				index[i] = -1;
				index[j] = -1;
			}

	for (int i = 0; i < 5; i++)
		if (index[i] == 1)
			hand[i] = newCard(wDeck, wFace, wSuit);
}

/*randomly generates and returns one card that isn't already in use*/
Card newCard(int wDeck[][13], const char *wFace[], const char *wSuit[]) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++) {
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++) {
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++) {
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card && wDeck[row][column] != -1) {
					wDeck[row][column] = -1;
					return getCard(wFace[column], wSuit[row]);
				}
			}
		}
	}
}

/* shuffle cards in deck */
void shuffle(int wDeck[][13]) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++) {
		/* choose new random location until unoccupied slot found */
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5]) {
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
				if (wDeck[row][column] == card && wDeck[row][column] != -1) {
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					wDeck[row][column] = -1;
					hand[cards_dealt] = getCard(wFace[column], wSuit[row]);

					cards_dealt += 1;
					if (cards_dealt == 5) break;
				}
			}
			if (cards_dealt == 5) break;
		}
		if (cards_dealt == 5) break;
	}
}

/*turn randomly generated card information into a card object*/
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

/*check if the hand contains a pair*/
int containsPair(Card hand[5]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (hand[i].number == hand[j].number && i != j)
				return 1;
	return 0;
}

/*check if the hand contains two pairs*/
int containsTwoPairs(Card hand[5]) {
	int pairs = 0, number = -1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (hand[i].number == hand[j].number && i != j && hand[i].number != number) {
				pairs++;
				number = hand[i].number;
				if (pairs == 2)
					return 1;
			}
		}
	}
	return 0;
}

/*check if the hand contains a three of a kind*/
int containsThreeKind(Card hand[5]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				if (hand[k].number == hand[i].number && hand[k].number == hand[j].number && k != j && k != i)
					return 1;
	return 0;
}

/*check if the hand contains a four of a kind*/
int containsFourKind(Card hand[5]) {
	int kind = -1, counter = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (hand[i].number == hand[j].number && i != j)
				kind = hand[i].number;

	for (int i = 0; i < 5; i++)
		if (hand[i].number = kind)
			counter++;

	if (counter >= 4)
		return 1;
	return 0;
}

/*check if the hand contains a flush*/
int containsFlush(Card hand[5]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (hand[i].suit != hand[j].suit)
				return 0;
	return 1;
}

/*check if the hand contains a straight*/
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

/*return what a hand contains that could return the highest point value*/
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
