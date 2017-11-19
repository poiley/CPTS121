/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 121, Fall 2017, Lab Section 14
* Programming Assignment: PA 7
* Date: Nov 19th, 2017
* Description: Poker
* Credits: Deitel & Deitel, Andrew O'Fallon for started code
**********************************************************************/

#include "Header.h" //import header

int main(void) {
	/* initialize suit array */
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	// initialize dealer and player hands
	Card player1_hand[5] = { '!', '!!', 3 };
	Card dealer_hand[5] = { '!', '!!', 3 };
	
	srand ((unsigned) time (NULL)); /* seed random-number generator */

	shuffle(deck); // shuffle deck
	deal(deck, face, suit, player1_hand); //deal 5 cards to the player
	deal(deck, face, suit, dealer_hand); //deal 5 cards to the dealer (computer)

	dealer(dealer_hand, deck, face, suit); //have the computer determine what cards need to be re-drawn

	printf("Player hand:\n"); //display player hand
	for (int i = 0; i < 5; i++)
		printf("Card %d: %s of %s\n", i+1, player1_hand[i].number_full, player1_hand[i].suit_full);

	//allow the player to replace cards to beat the dealer/computer
	printf("\nHow many cards would you like to replace?\n"); //get user input for card replacement
	int replace = 0;
	scanf("%d", &replace);
	for (int i = 0; i < replace; i++) { //run loop for the amount of times a card needs to be replaced
		int replace_index;
		printf("Which card?\n");
		scanf("%d", &replace_index);
		player1_hand[replace_index-1] = newCard(deck, face, suit); //replace card i with randomly generated card
	}

	printf("\nFinal Player hand:\n"); //display final user hand
	for (int i = 0; i < 5; i++)
		printf("Card %d: %s of %s\n", i + 1, player1_hand[i].number_full, player1_hand[i].suit_full);


	//determine a win/loss/tie
	if (returnHighestValue(player1_hand) > returnHighestValue(dealer_hand))
		printf("\nYou won!\n");
	else if (returnHighestValue(player1_hand) < returnHighestValue(dealer_hand))
		printf("\nYou lost!\n");
	else
		printf("\nIt's a draw!\n");

	return 0;
}