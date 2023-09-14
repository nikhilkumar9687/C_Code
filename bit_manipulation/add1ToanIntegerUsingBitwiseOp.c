#include <stdio.h>

int add1(int num)
{
    int ret = 0;

    return ret = -~num ;
}

int main()
{
    int num;

    printf("Enter a number\n");
    scanf("%d", &num);

    printf("%d is the result after adding 1 to %d\n", add1(num), num);

    return 0;
}
