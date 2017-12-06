/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 121, Fall 2017, Lab Section 14
* Programming Assignment: PA 9
* Date: Dec 5th, 2017
* Description: Series of Functions
* Credits: Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include "Header.h"

/*Question 1*/
char * my_str_n_cat(char *destination, char *source) {
	const int size = len_str(destination) + len_str(source);

	char finalArr[1000];

	for (int i = 0; i < len_str(destination); i++)
		finalArr[i] = destination[i];

	for (int i = len_str(destination); i < size; i++)
		finalArr[i] = source[i - len_str(destination)];

	finalArr[size] = '\0';

	return finalArr;
}

/*Question 2*/
int binary_search(int target, int sorted[], int size) {
	int start_index = size / 2;
	for (int i = 0; i < (size * size); i++)
		if (target == sorted[start_index])
			return start_index;
		else if (target < sorted[start_index])
			start_index--;
		else if (target > sorted[start_index])
			start_index++;

	return -1;
}

/*Question 3*/
void bubble_sort(char *strings[], int size) {
	int U = size - 1;
	int C = 0;
	while ((size - U) > 0) {
		C = 1;
		while (C < U) {
			if(strcmp(strings[C], strings[C - 1]) < 0) {
				char * temp = strings[C];
				strings[C] = strings[C - 1];
				strings[C - 1] = temp;
			}
			C++;
		}
		U--;
	}
}

/*Question 4*/
int is_palindrome(char *str, int size) {
	return is_palindrome_helper(str, size, 0);
}

int is_palindrome_helper(char *str, int size, int shift) {
	if (((int) size / 2) == shift)
		return 1;

	char lowerChar = str[size - shift - 1];
	char upperChar = str[shift];

	if (lowerChar == ' ')
		lowerChar = str[size - shift - 2];
	else if (upperChar == ' ')
		upperChar = str[shift + 1];

	if (lowerChar == upperChar)
		is_palindrome_helper(str, size, shift + 1);
	else
		return 0;
}

/*Question 5*/
int sum_primes(unsigned int n) {
	int sum = 0, index = 2;
	return sum_primes_helper(n, sum, index) - 4;
}

int sum_primes_helper(unsigned int n, int sum, int index) {
	int prime_or_not = 0;
	for (int i = 2; i < (index / 2); i++)
		if ((index % i) == 0) {
			prime_or_not = 1;
			break;
		}

	if (prime_or_not == 0) //it's prime
		sum += index;

	if (n == index)
		return sum;
	else
		sum_primes_helper(n, sum, index + 1);
}

/*Question 6*/
Occurrences maximum_occurences(char *str, Occurrences *occr, int *num, char *args) {
	int size = strlen(str);
	int differentChars = 0;
	char listOfChars[37] = { '\0' }; //37 = 26 letters, one whitespace and ten numbers
	listOfChars[0] = str[0];

	for (int i = 0; i < size; i++) {
		char a = str[i];
		int addOrNot = 1;
		for (int j = 0; j < 37; j++) {
			if (listOfChars[j] == a)
				addOrNot = 0;
		}

		if (addOrNot == 1)
			for (int j = 0; j < 37; j++)
				if (listOfChars[j] == '\0') {
					listOfChars[j] = a;
					break;
				}
	}
	
	for (int i = 0; i < 37; i++)
		if (listOfChars[i] != '\0') differentChars++;

	for (int i = 0; i < differentChars; i++) {
		occr[i].character = listOfChars[i];
		for (int j = 0; j < size; j++)
			if (str[j] == listOfChars[i])
				occr[i].num_occurrences++;

		occr[i].frequency = (double) occr[i].num_occurrences / size;
	}

	int index_of_highest_freq = 0;
	for (int i = 0; i < differentChars; i++)
		if (occr[i].num_occurrences > occr[index_of_highest_freq].num_occurrences)
			index_of_highest_freq = i;

	return occr[index_of_highest_freq];
}


/*Misc Utilities*/
int len_str(char *s) {
	int counter = 0;
	for (int i = 0; s[i] != '\0'; i++)
		counter++;

	return counter;
}

double frequency(int charSymbol, int charTotal) {
	return charSymbol / charTotal;
}