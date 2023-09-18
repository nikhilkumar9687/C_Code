#include <stdio.h>

int positionOfRightMostSetbit(int num)
{
    int pos = 0;

    if (num & 1)
        return 1;
    
    num = num ^ (num & (num - 1));

    while (num)
    {
        num = num >> 1;
        pos++;
    }

    return pos;
}

void bin (unsigned num)
{
    for (unsigned i = 1 << 7; i > 0; i = i / 2)
        (num & i) ? printf("1") : printf("0");
    
    printf("\n");
}

int main()
{
    int num;

    printf("Enter the number\n");
    scanf("%d",&num);

    printf("Pos of right most set bit of %d is %d\n", num, positionOfRightMostSetbit(num));

    bin(num);
   
    return 0;
}