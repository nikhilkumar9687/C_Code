#include <stdio.h>

int fact(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1 )
		return 1;
	else if (n > 1)
		return (fact(n - 1) * n );

}


void main()
{

	int n, val = 0;

	printf("Enter the number for which factorial is needed\n");
	scanf("%d",&n);
        if (n < 0)
		printf("Factorial of -ve number is not possible\n");
	else
	{
		val = fact(n);
		printf("The %d! is %d\n",n, val);
	}
}
