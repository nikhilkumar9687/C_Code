#include <stdio.h>

int sum(int n)
{
	if (n == 0)
		return 0;
	else
		return sum(n - 1) + n;

}


void main()
{
	int n, value;
	printf("Enter the number of Natural Numbers\n");
	scanf("%d",&n);

	value = sum(n);

	printf("The Sum of %d Natrual Number is %d\n", n, value);
}
