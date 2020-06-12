/*
 * This Program is to calculate e^x using talor Series
 * e^x = 1 + (x)/1 + (x^2)/2! + (x^3)/3! . . . . . . + (x^n)/n!
 * using Horner's Rule i.e. 
 * e^x = 1 + x/1 [ 1 + x/2 [ 1 + x/3 [1 + x/4[...] ] ] ]
 */

#include <stdio.h>

/*
 * taylor series using loop
 * double e (double x, double n)
 * {
 * 	double sum = 1;
 * 	int i;
 * 	double numerator = 1;
 * 	double denominator = 1;
 *
 * 	for (i = 1; i <= n; i++)
 * 	{
 * 		numerator = numerator * x;
 * 		denominator *= i;
 * 		sum += numerator/ denominator;
 *
 * 	return sum;
 * }	


double e(double x, double n)
{
	static double sum = 1;

	if (n == 0)
		return sum;
	sum = 1 + ((x/n) * sum);
	
	return e(x, n -1);
	
}

int main()
{
	double x, n;
	double val_e_to_x;

	
	printf("Enter the power of e and precision\n");
	scanf("%lf%lf", &x,&n);

	val_e_to_x = e(x,n);

	printf("The Value of e^%lf upto %lf precision is : %lf\n",
			x, n, val_e_to_x);

	return 0;
}






