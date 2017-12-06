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
	char *s1 = "Foo";
	char *s2 = "Bar";

	printf("%s\n", my_str_n_cat(s1, s2));

	/*Question 2*/
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("%d\n", binary_search(7, arr, 9));

	/*Question 3*/
	int size = 4;
	char *strings[] = { "Yellow", "Apple", "Banana", "Zip" };
	bubble_sort(strings, size);

	/*Question 4*/
	char *word = "race car";
	if(is_palindrome(word, 8) == 1)
		printf("%s is a palindrome.\n", word);
	else 
		printf("%s is not a palindrome.\n", word);

	/*Question 5*/
	unsigned int maximum = 3;
	printf("%d\n", sum_primes(maximum));

	/*Question 6*/
	char *str = "hello world";
	Occurrences occr[37] = { '\0', 0, 0.0 };
	Occurrences frequent = maximum_occurences("hello world", occr, 0, 'c');

	printf("The most frequent character in \"%s\" is '%c' occuring #%d times, or %0.5lf%% of the time.\n", str, frequent.character, frequent.num_occurrences, frequent.frequency);
	
}

