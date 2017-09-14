
#include <math.h>
#include <stdio.h>

void main() {
	double x1, x2, y1, y2;

	printf("4 points:\n");
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	double slope = (y2 - y1) / (x2 - x1);

	double midX = (x1 + x2) / 2;
	double midY = (y1 + y2) / 2;

	double slopePB = -1 * (1 / slope);

	double yIntPB = midY - slopePB * midX;

	printf("y = %lfx + %lf\n", slopePB, yIntPB);
}