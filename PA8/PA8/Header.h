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

//Credit: Andrew O'Fallon
typedef struct occurrences {
	char character; //addition by me, so it's easier to track what character correlates to the Occurence struct's data
	int num_occurrences;
	double frequency;
} Occurrences;

/*Utilities*/
int len_str(char *s);

/*Questions*/
char * my_str_n_cat(char *destination, char *source);		//Question 1
int binary_search(int target, int sorted[], int size);		//Question 2
void bubble_sort(char *strings[], int size);				//Question 3
int is_palindrome(char *str, int size);						//Question 4
int is_palindrome_helper(char *str, int size, int shift);	//Question 4
int sum_primes(unsigned int n);								//Question 5
int sum_primes_helper(unsigned int n, int sum, int index);	//Question 5
Occurrences maximum_occurences(char *str, Occurrences *occr, int *num, char *args); //Question 6