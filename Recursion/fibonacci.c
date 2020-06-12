/* 
 * This code is for Fibonacci Series using Resusion
 */

#include <stdio.h>

int F[10];

int fibo(int n)
{
	/*
	 * This type of recursion is called Excesive Recursion
	 * as there are number of calls to the same function
	 */

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibo(n - 2) + fibo(n - 1);
}

/*
 * int fibo(int n)
 *{
 *	int num1 = 0, num2 = 1;
 *	int sum = 0;
 *	int i;
 *
 * 	if (n == 0)
 *		return 0;
 *	else if (n == 1)
 *		return 1;
 *	else
 *	{
 *		for (i = 2; i <= n; i++)
 *		{
 *			sum = num1 + num2;
 *			num1 = num2;
 *			num2 = sum;
 *		}
 *		return sum;
 *	}
 *}
*/

/*
 * Fibonacci series using Memoization i.e. storing the result of function calls
 * in a global array.
 * These values can be used if the same function is called again without 
 * actually calling the function, hence elimanating excesive calls
 *
 * int fibo (int n)
 * {
 * 	if (n <= 1)
 * 	{
 * 		F[n] = n;
 * 		return n;
 * 	}
 * 	else
 * 	{
 * 		if (F[n - 2] == -1)
 * 			F[n - 2] = fibo(n - 2);
 * 		if (F[n - 1] == -1)
 * 			F[n -1] = fibo(n - 1);
 * 		return (F[n - 2] + F[n - 1]);
 * 	}
 * }
 *
 */	



int main()
{
	int num, val = 0;
	int i;

	printf("Enter the position till which Fibo series is needed\n");
	scanf("%d",&num);

	for ( i = 0; i < 10; i++)
		F[i] = -1;

	for (i = 0; i <= num; i++)
	       printf("%d\t",fibo(i));

	printf("\n");
}	

