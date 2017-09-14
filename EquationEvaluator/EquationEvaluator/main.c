/*********************************************************************
* Programmer: Benjamin Poile										 *
* Class: CptS 121, Fall 2017, Lab Section 14						 *
* Programming Assignment: PA 2										 *
* Date: Sept 11th, 2017												 *
* Description: This program calculates a scope of equations.		 *
**********************************************************************/

#include "equations.h"

int main(void) {
	while(0 == 0) { // Loop forever, or at least until quit
		// Print main menu
		printf("\nMenu:\n"
			"1.\tNewton's Second Law of Motion\n"
			"2.\tVolume of a Cylinder\n"
			"3.\tCharacter Encoding\n"
			"4.\tGravity\n"
			"5.\tTangent\n"
			"6.\tTotal Parallel Resistance\n"
			"7.\tDistance Between Two Points\n"
			"8.\tGeneral Equation\n"
			"0.\tQuit\n"
			"Input Menu Item (0-8): ");

		int input; // menu selection
		scanf("%d", &input);

		if (input == 1) { // Menu item 1
			double mass, acceleration;

			printf("Input Mass and Acceleration:");
			scanf("%lf%lf", &mass, &acceleration);

			printf("Newton's Second Law: force = mass * acceleration : %lf * %lf : %.2lf\n", mass, acceleration, calculate_newtons_2nd_law(mass, acceleration));
		} else if (input == 2) { // Menu item 2
			double radius, height;

			printf("Input Radius and Height:");
			scanf("%lf%lf", &radius, &height);

			printf("Volume of a Cylinder: volume = PI * radius^2 * height : %lf * %lf^2 * %lf : %.2lf\n", M_PI, radius, height, calculate_volume_cylinder(radius, height));
		} else if (input == 3) { // Menu item 3
			char character;

			printf("Input character:\n");
			scanf(" %c", &character);

			printf("Character Encoding: 10 + ('character' + 'a') - 'A' : 10 + ('%c' + 'a') - 'A' : %c\n", character, perform_character_encoding(character));
		} else if (input == 4) { // Menu item 4
			double mass1, mass2, distance;

			printf("Input the masses of the two objects, and their distance:");
			scanf("%lf%lf%lf", &mass1, &mass2, &distance);

			printf("Force of Gravity: force = G * mass1 * mass2 / distance^2 : G * %lf * %lf / %lf^2 : %.2lf\n", mass1, mass2, distance, calculate_gravity_force(mass1, mass2, distance));
		} else if (input == 5) { // Menu item 5
			double theta;

			printf("Input the angle theta:\n");
			scanf("%lf", &theta);

			printf("Tangent : tan(theta) : tan(%lf) : %lf.2\n", theta, calculate_tangent(theta));
		} else if (input == 6) { // Menu item 6
			int r1, r2, r3;

			printf("Input the resistor strengths:\n");
			scanf("%d%d%d", &r1, &r2, &r3);

			printf("Resistance : 1/((1 / r1) + (1 / r2) + (1 / r3)) : 1/((1 / %d) + (1 / %d) + (1 / %d)) : %.2lf\n", r1, r2, r3, calculate_parallel_resistance(r1, r2, r3));
		} else if (input == 7) { // Menu item 7
			double x1, x2, y1, y2;

			printf("Input the two points, in order x1, x2, y1, y2.\n");
			scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

			printf("Distance : (x1 - x2)^2 + (y1 - y2)^2 : (%lf - %lf)^2 + (%lf - %lf)^2 : %.2lf\n", x1, x2, y1, y2, calculate_distance_between_2pts(x1, x2, y1, y2));
		} else if (input == 8) { // Menu item 8
			double z, x;
			int a;

			printf("Input a, z and x:\n");
			scanf("%d%lf%lf", &a, &z, &x);

			printf("General Equation: (7/5) * x / a + z - a / (a %% 2) + PI : (7/5) * %lf / %d + %lf - %d / (%d %% 2) + %lf : %.2lf\n", x, a, z, a, a, M_PI, calculate_general_equation(a, z, x));
		} else if (input == 0) { // Menu item 0 -- quit
			break;
		} else { // Error checking
			printf("\nError: Invalid Input.\n");
			break;
		}
	}
}