#include <stdio.h>

void swap(int *num1, int *num2)
{
    if (*num1 != *num2)
    {
        *num1 = *num1 ^ *num2;
        *num2 = *num1 ^ *num2;
        *num1 = *num1 ^ *num2;
    }
}

int main()
{
    int num1 = 0;
    int num2 = 0;

    printf("Enter two numbers\n");
    scanf("%d%d", &num1, &num2);

    swap(&num1, &num2);

    printf("Numbers after swaping %d, %d\n", num1, num2);
    return 0;
}