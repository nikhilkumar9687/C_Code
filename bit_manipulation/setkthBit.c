#include <stdio.h>

int setkthBit(int num, int k)
{
    int mask = 1 << (k - 1);

    return (num | mask);
}

void bin(unsigned num)
{
    for (unsigned i = 1 << 7; i > 0; i = i /2)
        (num & i) ? printf("1") : printf("0");
    
}

int main()
{
    int num, k;

    printf("Enter the num and kth bit\n");
    scanf("%d%d",&num,&k);

    printf("The num %d after setting %dth bit is %d\n", num, k, setkthBit(num,k));
    bin(setkthBit(num,k));
    return 0;
}