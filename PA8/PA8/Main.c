/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 121, Fall 2017, Lab Section 14
* Programming Assignment: PA 9
* Date: Dec 5th, 2017
* Description: Series of Functions
* Credits: Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"

int main(void) {
	/*Question 1*/
	char *s1 = "Foo"; //Sample strings for testing
	char *s2 = "Bar";

	printf("1.\t%s\n", my_str_n_cat(s1, s2)); // Should print FooBar

	/*Question 2*/
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("2.\t%d\n", binary_search(7, arr, 9)); //Returns 6 after performing a binary search for 7

	/*Question 3*/
	int size = 4; //Sample size for the list of Strings to bubble sort
	char *strings[] = { "Yellow", "Apple", "Banana", "Zip" }; //Sample list of Strings for the bubble sort
	bubble_sort(strings, size);

	/*Question 4*/
	char *word = "race car"; //Sample String for palindrome
	if(is_palindrome(word, 8) == 1) //If it is a palindrome
		printf("4.\t%s is a palindrome.\n", word); //print it is a palindrome
	else  //otherwise
		printf("4.\t%s is not a palindrome.\n", word); //print it is not a palindrome

	/*Question 5*/
	unsigned int maximum = 10; 
	printf("5.\t%d\n", sum_primes(maximum));

	/*Question 6*/
	char *str = "hello world"; //Sample string to analyze for the maximum occurences
	Occurrences occr[37] = { '\0', 0, 0.0 }; //sets up empty array of structs
	Occurrences frequent = maximum_occurences("hello world", occr, 0, 'c'); //analyzes the above string for character frequency

	printf("6.\tThe most frequent character in \"%s\" is '%c' occuring #%d times, or %0.5lf%% of the time.\n", str, frequent.character, frequent.num_occurrences, frequent.frequency); //return data in a readable faction
	
}

