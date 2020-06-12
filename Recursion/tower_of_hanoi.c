/*
 * This file contains the code to solve Tower of Hanoi Problem
 */

#include <stdio.h>

void TOH(int n, char from, char using, char to)
{
	if (n > 0)
	{
		TOH(n - 1, from, to, using);
		printf("from %c to %c\n", from, to);
		TOH(n - 1, using, from, to);
	}
}

void main()
{
	/* 
	 * from tower 1 move n disks to tower 3 using tower 2
	 */
	int n;
	printf("Enter the number of disks\n");
	scanf("%d",&n);

	TOH(n, 'A','B','C');
}

