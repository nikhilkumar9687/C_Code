#include <stdio.h>
#include <stdbool.h>

bool checkParity(int num)
{
    bool parity = false;
    while(num)
    {
        parity = !parity;
        num = num & (num - 1);
    }

    return parity;
}

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d",&num);

    bool parity = checkParity(num);
    if(parity)
        printf("Odd Parity\n");
    else
        printf("Even Parity\n");

    return 0;
}