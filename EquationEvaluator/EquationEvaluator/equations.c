/*********************************************************************
* Programmer: Benjamin Poile										 *
* Class: CptS 121, Fall 2017, Lab Section 14						 *
* Programming Assignment: PA 2										 *
* Date: Sept 11th, 2017												 *
* Description: This program calculates a scope of equations.		 *
**********************************************************************/

#include "equations.h"

/*Newton's Second Law*/
double calculate_newtons_2nd_law(double mass, double acceleration) {
	return mass * acceleration;
}

/*Volume of a Cylinder*/
double calculate_volume_cylinder(double radius, double height) {
	return (M_PI * pow(radius, 2)) * height;
}

/*Encode a character*/
char perform_character_encoding(char character) {
	return (char)(10 + (character - 'a') + 'A');
}

/*Gravity*/
double calculate_gravity_force(double mass1, double mass2, double distance) {
	return (M_G * mass1 * mass2) / pow(distance, 2);
}

/*Tangent*/
double calculate_tangent(double theta) {
	return tan(theta);
}

/*Total Parallel Resistance*/
double calculate_parallel_resistance(int r1, int r2, int r3) {
	return 1 / ((1 / (double)r1) + (1 / (double)r2) + (1 / (double)r3));
}

/*Distance between two points*/
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

/*General Equation*/
double calculate_general_equation(int a, double z, double x) {
	return ((double)7 / 5) * x / a + z - a / (a % 2) + M_PI;
}