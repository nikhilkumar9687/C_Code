/*
 * This Program is to calculate e^x using talor Series
 * e^x = 1 + (x)/1 + (x^2)/2! + (x^3)/3! . . . . . . + (x^n)/n!
 */

#include <stdio.h>

double e(double x, double n)
{
	static double p = 1;
	static double f = 1;

	double val = 0;

	if (n == 0)
		return 1;
	else
	{
		val = e(x, n - 1);
		p = p * x;
		f = f * n;
		return (val + (p / f));
	}
}

int main()
{
	double val_e_to_x = 0;
	double x, n;

	printf("Enter the power of e and precision\n");
	scanf("%lf%lf", &x,&n);

	val_e_to_x = e(x,n);

	printf("The Value of e^%lf upto %lf precision is : %lf\n",
			x, n, val_e_to_x);

	return 0;
}

