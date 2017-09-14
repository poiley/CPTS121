#include <math.h>
#include <stdio.h>

void main(void) {
	double weight, height_feet;

	printf("Input weight, and your height (in feet):");

	scanf("%lf%lf", &weight, &height_feet);

	printf("\nBMI: %lf", BMI(weight, height_feet * 12));
}

double BMI(double weight, double height_inches) {
	return (weight / pow(height_inches, 2)) * 703;
}
