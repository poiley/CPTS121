/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 121, Fall 2017, Lab Section 14
* Programming Assignment: PA 7
* Date: Nov 19th, 2017
* Description: Poker
* Credits: Deitel & Deitel, Andrew O'Fallon for started code
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct card {
	char suit;
	char *suit_full;
	int number;
	char *number_full;
} Card;

void dealer(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]);

void getOneCard(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]);

void getTwoCards(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]);

void getThreeCards(int wDeck[][13], Card hand[5], const char *wFace[], const char *wSuit[]);

Card newCard(int wDeck[][13], const char *wFace[], const char *wSuit[]);

void shuffle(int wDeck[][13]);

void deal(int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[5]);

Card getCard(char* number, char* suit);

int containsPair(Card hand[5]);

int containsTwoPairs(Card hand[5]);

int containsThreeKind(Card hand[5]);

int containsFourKind(Card hand[5]);

int containsFlush(Card hand[5]);

int containsStraight(Card hand[5]);

int returnHighestValue(Card hand[5]);
