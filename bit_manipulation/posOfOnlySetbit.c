#include <stdio.h>
#include <math.h>

float posOfOnlySetBit(int num)
{
    if(num & (num - 1))
    {
        printf("Wront input\n");
        return -1;
    }

    return log2(num) + 1;
}
int main()
{
    int num;

    printf("Enter a num\n");
    scanf("%d",&num);

    printf("The bit us set at %f\n", posOfOnlySetBit(num));

    return 0;
}