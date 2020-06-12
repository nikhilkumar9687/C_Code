/*
 * This file contains the code for selcecting sub sets
 * i.e  nCr = n!/((r!)(n - r)!)
 * formula for combination in permutation and combination
 * using Pascal's Triangle:-
 *
 *
 *					1
 *				1	0C0	1
 *			1	1C0	2	1C1	1
 *		1	2C0	3	2C1	3	2C2	1
 *	1	3C0	4	3C1	6	3C2	4	3C3	1
 *	4C0		4C1		4C2		4C3		4C4
 *
 * i.e.  4C2 = 3C1 + 3C2
 *
 * hence, nCr = (n-1)C(r-1) + (n -1)Cr
 *
 */

#include <stdio.h>

int fact(int n)
{
	if (n <= 1)
		return 1;
	return (fact(n - 1) * n);
}

int C(int n, int r)
{
	int num, R, n_r;

	if (n <= 1)
		return n;
	else
	{
		num = fact(n);
		R   = fact(r);
		n_r = fact(n -r);

		return (num/(R * n_r));

		/*
		 * nCr = n!/r!(n-r)!
		 */ 
	}
}

int pascal_C(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else
		return (pascal_C(n-1, r-1) + pascal_C(n-1, r));
}

int main()
{
	int num, r;
	int value;

	printf("Enter the value for n and r\n");
	scanf("%d%d", &num,&r);

	value = C(num, r);
	printf("The Value of %dC%d is : %d using factorial\n",num,r, value);

	value = pascal_C(num, r);
	printf("The Value of %dC%d is : %d using recursion\n",num,r, value);

	return 0;
}

