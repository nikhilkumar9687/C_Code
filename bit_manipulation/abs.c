#include <stdio.h>

int abs(int num)
{
    int mask = num >> sizeof(int) * 8 - 1;
    int val = (num + mask) ^ mask ; 

    return val;
}

void bin (unsigned int num)
{
    for (unsigned int i = 1 << 7; i > 0; i = i/2)
        (num & i) ? printf("1"):printf("0");

    printf("\n");
}

int main()
{
    int num;

    printf("enter a number\n");
    scanf("%d",&num);

    printf("the abs value of %d is: %d and size of int is  %ld:\n", num, abs(num), sizeof(int));
    bin(num);
    bin(abs(num));

    return 0;
}