#include <stdio.h>

int flipbits(int num1, int num2)
{
    int res = num1 ^ num2;

    int count = 0;

    while(res)
    {
        res = res & (res - 1);
        count++;
    }

    return count;
}

void bin(unsigned int num)
{
    for (unsigned int i = 1 << 7; i > 0; i = i/2 )
        (num & i) ? printf("1") : printf("0");

    printf("\n");
}
int main()
{
    int num1, num2;
    
    printf("Enter the nums to check\n");
    scanf("%d%d",&num1, &num2);


    printf("Binary rep of %d is\n", num1);
    bin(num1);

    printf("Binary rep of %d is\n", num2);
    bin(num2);

    printf("Num of bits to flip are %d\n", flipbits(num1, num2));

    return 0;

}