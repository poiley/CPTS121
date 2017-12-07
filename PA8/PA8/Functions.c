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
	const int size = len_str(destination) + len_str(source); //Gets the overall size of both Strings together

	char finalArr[1000]; //sets the buffer array to copy into 

	for (int i = 0; i < len_str(destination); i++)
		finalArr[i] = destination[i]; //writes the first characters to the buffer array, which is the destination string

	for (int i = len_str(destination); i < size; i++)
		finalArr[i] = source[i - len_str(destination)]; //then, where the destination string ends, write the source string

	finalArr[size] = '\0'; //end the buffer string

	return finalArr; //return the buffer string
}

/*Question 2*/
int binary_search(int target, int sorted[], int size) {
	int start_index = size / 2; //where to begine the binary search
	for (int i = 0; i < (size * size); i++)
		if (target == sorted[start_index]) //if the mid point is the target, return the target
			return start_index;
		else if (target < sorted[start_index]) //otherwise look left if it's less than the midpoint
			start_index--;
		else if (target > sorted[start_index]) //otherwise look right (upwards) if it's mroe than the midpoint
			start_index++;

	return -1; //if it isn't in the sorted array, return -1
}

/*Question 3*/
void bubble_sort(char *strings[], int size) {
	int U = size - 1;
	int C = 0;
	while ((size - U) > 0) { //for the amount of the data that isn't sorted, 
		C = 1;//set the counter in the unsorted range to 1
		while (C < U) {  //and run while there is still unsorted data
			if(strcmp(strings[C], strings[C - 1]) < 0) { //if the data to the right is less than the left, move the data upwards
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
	return is_palindrome_helper(str, size, 0); //call the recursive helper to complete the function
}

int is_palindrome_helper(char *str, int size, int shift) {
	if (((int) size / 2) == shift) //if the user has hit the center of the word without mismatching characters, return 1
		return 1;

	char lowerChar = str[size - shift - 1]; //set the lower character to check
	char upperChar = str[shift]; //set the upper character to check

	//if one of the two characters is a space, skip the character
	if (lowerChar == ' ')
		lowerChar = str[size - shift - 2];
	else if (upperChar == ' ')
		upperChar = str[shift + 1];

	if (lowerChar == upperChar) //check if the two characters are equal
		is_palindrome_helper(str, size, shift + 1); //if they are, move one inwards in the string and do it recursively until reaches center
	else
		return 0; //if they don't match, return 0. it is not a palindrome.
}

/*Question 5*/
int sum_primes(unsigned int n) {
	return sum_primes_helper(n, 0, 2) - 4; //values: sum starts at 0 and index starts at 2. Subtract 4 because result is always 4 over 
}

int sum_primes_helper(unsigned int n, int sum, int index) {
	int prime_or_not = 0; //checks if current index is prime
	for (int i = 2; i < (index / 2); i++) //loop for all numbers under index
		if ((index % i) == 0) { //if it ever finds a value in which it can be evenly divided
			prime_or_not = 1; //set it to not prime
			break;
		}

	if (prime_or_not == 0) //it's prime
		sum += index; //add the index to the sum

	if (n == index) //if you've iterated enough to reach the current index
		return sum; //return the sum
	else
		sum_primes_helper(n, sum, index + 1); //otherwise, add one to the sum and recurse
}

/*Question 6*/
Occurrences maximum_occurences(char *str, Occurrences *occr, int *num, char *args) {
	int size = strlen(str); //gets the length of the string
	int differentChars = 0; //initializes the value that will store how many individual characters there are in the string
	char listOfChars[37] = { '\0' }; //37 = 26 letters, one whitespace and ten numbers
	listOfChars[0] = str[0]; //clears the list of characters, sets the first value to the first value in the string

	for (int i = 0; i < size; i++) { //for the entire strings length
		char a = str[i]; //check the next character
		int addOrNot = 1;
		for (int j = 0; j < 37; j++) {
			if (listOfChars[j] == a)
				addOrNot = 0; //if it is a duplicate, or already exists in the catalog list of chars, return 0 to not add
		}

		if (addOrNot == 1) //if it is to be added, add it
			for (int j = 0; j < 37; j++)
				if (listOfChars[j] == '\0') { //go to the first available NULL element in the list and log the character
					listOfChars[j] = a;
					break;
				}
	}
	
	for (int i = 0; i < 37; i++) //flip back through the individual character list and see how many there are
		if (listOfChars[i] != '\0') differentChars++;

	for (int i = 0; i < differentChars; i++) { //for the amount of individual characters, log the data into it's occurence struct
		occr[i].character = listOfChars[i]; //store its character
		for (int j = 0; j < size; j++)
			if (str[j] == listOfChars[i])
				occr[i].num_occurrences++; //store the amount of times it appears

		occr[i].frequency = (double) occr[i].num_occurrences / size; //calculate and store it's frequency
	}

	int index_of_highest_freq = 0; //return the char with the highest frequency
	for (int i = 0; i < differentChars; i++)
		if (occr[i].num_occurrences > occr[index_of_highest_freq].num_occurrences)
			index_of_highest_freq = i;

	return occr[index_of_highest_freq]; //return struct
}


/*Misc Utilities*/
int len_str(char *s) { //returns the length of the string 
	int counter = 0;
	for (int i = 0; s[i] != '\0'; i++)
		counter++;

	return counter;
}
