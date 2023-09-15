#include <stdio.h>

int unsetRigthMostSetBit(int num)
{
     return (num & (num -1));
}

void bin(unsigned num)
{
    for (unsigned i = 1 << 7; i > 0; i = i / 2)
        (num & i) ? printf("1") : printf ("0");

    printf("\n");
}

int main()
{
    int num;

    printf("Enter the number\n");
    scanf("%d", &num);

    printf("Value after unsetting right most bit %d\n", unsetRigthMostSetBit(num));
    printf("Bin value returned is \n");
    bin(unsetRigthMostSetBit(num));

    return 0;
}