#include "head.h"

void main(void) {
	FILE *in = NULL;
	FILE *out = NULL;
	int student_id[5], class_standing[5];
	double GPA[5], ages[5];

	//Opens an input file "input.dat" for reading;
	in = fopen("input.dat", "r"); 

	//Opens an output file "output.dat" for writing;
	out = fopen("output.dat", "w+"); 

	//Reads five records from the input file(input.dat); You will need to use a combination of read_double() and read_integer() function calls here!
	for(int i = 0; i < 5; i++) {
		student_id[i] = read_integer(in);
		GPA[i] = read_double(in);
		class_standing[i] = read_integer(in);
		ages[i] = read_double(in);
	}
	
	//Calculates the sum of the GPAs
	double sum_gpa = calculate_sum(GPA[0], GPA[1], GPA[2], GPA[3], GPA[4]);
	
	//Calculates the sum of the class standings;

	double sum_class_standings = calculate_sum(class_standing[0], class_standing[1], class_standing[2], class_standing[3], class_standing[4]);
	
	//Calculates the sum of the ages;
	double sum_ages = calculate_sum(ages[0], ages[1], ages[2], ages[3], ages[4]);
	
	//Calculates the mean of the GPAs, writing the result to the output file (output.dat);
	double mean_gpa = calculate_mean(sum_gpa, 5);
	
	//Calculates the mean of the class standings, writing the result to the output file (output.dat);
	double mean_class_standings = calculate_mean(sum_class_standings, 5);

	//Calculates the mean of the ages, writing the result to the output file (output.dat);
	double mean_ages = calculate_mean(sum_ages, 5);

	//Calculates the deviation of each GPA from the mean (Hint: need to call calculate_deviation ( ) 5 times)
	double deviation_gpa[5];
	for (int j = 0; j < 5; j++)
		deviation_gpa[j] = calculate_deviation(GPA[j],mean_gpa);
	
	//Calculates the variance of the GPAs
	double variance_gpa = calculate_variance(deviation_gpa[0], deviation_gpa[1], deviation_gpa[2], deviation_gpa[3], deviation_gpa[4], 5);

	//Calculates the standard deviation of the GPAs, writing the result to the output file (output.dat);
	double standard_deviation_gpa = calculate_standard_deviation(variance_gpa);
	
	//Determines the min of the GPAs, writing the result to the output file (output.dat);
	double max_gpa = find_max(GPA[0], GPA[1], GPA[2], GPA[3], GPA[4]);

	//Determines the max of the GPAs, writing the result to the output file (output.dat);
	double min_gpa = find_min(GPA[0], GPA[1], GPA[2], GPA[3], GPA[4]);

	//	Closes the input and output files (i.e. input.dat and output.dat)
}