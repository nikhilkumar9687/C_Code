#include <stdio.h>

int faster_pow(int m, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return faster_pow(m * m, (n / 2));
	else
		return (m * faster_pow( m * m, (( n - 1 ) / 2 )));
}

int my_pow(int m, int n)
{
	if (n == 0)
		return 1;
	return (my_pow(m, (n - 1)) * m);
}

int main()
{
	int num, exp, val = 0;

	printf("Enter num and its exp\n");
	scanf("%d%d",&num, &exp);

	val = my_pow(num, exp);
	printf("%d ^ %d = %d\n", num, exp, val);
	
	val = faster_pow(num, exp);
	printf("%d ^ %d = %d\n", num, exp, val);

	return 0;
}

