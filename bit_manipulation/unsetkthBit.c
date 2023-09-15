#include <stdio.h>

int unsetKthBit(int num, int k)
{
    int mask = ~(1 << (k -1));

    return (num & mask);
}

int main()
{
    int num, k;

    printf("ENter the number nad the kth bit\n");
    scanf("%d%d", &num, &k);

    printf("Number after setting kth bit is %d\n", unsetKthBit(num, k));

    return 0;
}