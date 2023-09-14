#include <stdio.h>

int checkEvenOdd(int num)
{
    int ret = num & 1;
    printf("ret = %d\n",ret);

    return ret;
}

int main()
{
    int num = 0;
    int ret = 0;

    printf("Enter the number to check for even or odd\n");
    scanf("%d", &num);

    ret = checkEvenOdd(num);

    if (ret == 0)
    {
        printf("%d is even\n", num);
    }
    else
    {
        printf("%d is odd\n", num);

    }

    return 0;
}