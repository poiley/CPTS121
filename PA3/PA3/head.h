/*********************************************************************
* Programmer: Benjamin Poile
* Class: CptS 121, Fall 2017, Lab Section 14
* Programming Assignment: PA 3
* Date: Sept 19th, 2017
* Description: This program calculates student data from a file, and 
* prints it to a different file
**********************************************************************/

#include <stdio.h>
#include <math.h>

double read_double(FILE *infile);
int read_integer(FILE *infile);

double calculate_sum(double num1, double num2, double num3, double num4, double num5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double dev1, double dev2, double dev3, double dev4, double dev5, int number);
double calculate_standard_deviation(double variance);

double find_max(double num1, double num2, double num3, double num4, double num5);
double find_min(double num1, double num2, double num3, double num4, double num5);

void print_double(FILE *outfile, double number);

