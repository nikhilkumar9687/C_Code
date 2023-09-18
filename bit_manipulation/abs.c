#include <stdio.h>

int abs(int num)
{
    int mask = num >> ((sizeof(int) * 8) - 1);

    int abs = (num + mask) ^ mask;

    return abs;
}

int main()
{
    int num;

    printf("enter a number\n");
    scanf("%d",&num);

    printf("the abs value of %d is: %d and size of int is  %ld:\n", num, abs(num), sizeof(int));

    return 0;
}