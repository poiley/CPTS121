/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 121, Fall 2017, Lab Section 14
* Programming Assignment: PA 9
* Date: Dec 5th, 2017
* Description: Series of Functions
* Credits: Andrew O'Fallon for instructions and struct code
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct occurrences {
	char character;
	int num_occurrences;
	double frequency;
} Occurrences;

int len_str(char *s);
double frequency(int charSymbol, int charTotal);
char * my_str_n_cat(char *destination, char *source);
int binary_search(int target, int sorted[], int size);
void bubble_sort(char *strings[], int size);
int is_palindrome(char *str, int size);
int sum_primes(unsigned int n);
int sum_primes_helper(unsigned int n, int sum, int index);
Occurrences maximum_occurences(char *str, Occurrences *occr, int *num, char *args);