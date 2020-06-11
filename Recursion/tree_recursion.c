#include <stdio.h>

void fun(int a)
{
	if (a > 0)
	{
		printf("%d\n",a);
		fun (a - 1);
		fun (a - 1);
	}
}

void main()
{
	fun(3);
}

