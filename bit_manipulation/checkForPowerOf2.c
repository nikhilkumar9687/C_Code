#include <stdio.h>

int checkIfPowerOf2(int num)
{
    return (num & (num - 1));
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

    if (num == 0)
    {
        printf("the num %d is not a power of 2\n", num);
        bin(num);
        return 0;
    }

    if(checkIfPowerOf2(num))
    {
        printf("the num %d is not a power of 2\n", num);
        bin(num);
    }
    else
    {
        printf("the num %d is a power of 2\n", num);
        bin(num);
    }
    
    return 0;
}