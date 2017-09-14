/*********************************************************************
* Programmer: Benjamin Poile										 *
* Class: CptS 121, Fall 2017, Lab Section 14						 *
* Programming Assignment: PA 2										 *
* Date: Sept 11th, 2017												 *
* Description: This program calculates a scope of equations.		 *
**********************************************************************/

#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846 // PI
#define M_G (6.67 * pow(10, -11)) // gravity constant

/*Newton's Second Law*/
double calculate_newtons_2nd_law(double mass, double acceleration);

/*Volume of a Cylinder*/
double calculate_volume_cylinder(double radius, double height);

/*Encode a character*/
char perform_character_encoding(char character);

/*Gravity*/
double calculate_gravity_force(double mass1, double mass2, double distance);

/*Tangent*/
double calculate_tangent(double theta);

/*Total Parallel Resistance*/
double calculate_parallel_resistance(int r1, int r2, int r3);

/*Distance between two points*/
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);

/*General Equation*/
double calculate_general_equation(int a, double z, double x);