#include "head.h"

double read_double(FILE *infile) {
	double value = -1.0;
	fscanf(infile, "%lf", &value);
	return value;
}

int read_integer(FILE *infile) {
	int value = -1;
	fscanf(infile, "%d", &value);
	return value;
}

double calculate_sum(double num1, double num2, double num3, double num4, double num5) {
	return num1 + num2 + num3 + num4 + num5;
}

double calculate_mean(double sum, int number) {
	if ( number != 0 )
		return sum / number;
	return -1.0;
}

double calculate_deviation(double number, double mean) {
	return number - mean;
}

double calculate_variance(double dev1, double dev2, double dev3, double dev4, double dev5, int number) {
	return calculate_mean(calculate_sum(pow(dev1, 2), pow(dev2, 2), pow(dev3, 2), pow(dev4, 2), pow(dev5, 2)), number);
}

double calculate_standard_deviation(double variance) {
	return sqrt(variance);
}

double find_max(double num1, double num2, double num3, double num4, double num5) {
	double arr[5] = { num1, num2, num3, num4, num5 };
	double largest = num1;
	for (int i = 0; i <= 5; i++)
		if (largest < arr[i])
			largest = arr[i];

	return largest;
}

double find_min(double num1, double num2, double num3, double num4, double num5) {
	double arr[5] = { num1, num2, num3, num4, num5 };
	double smallest = num1;
	for (int i = 0; i <= 5; i++)
		if (smallest > arr[i])
			smallest = arr[i];

	return smallest;
}

void print_double(FILE *outfile, double number) {

}