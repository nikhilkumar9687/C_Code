#include <stdio.h>

int checkIfGivenNumsHaveOppSign(int num1, int num2)
{
    int ret = 0;

    return ret = num1 ^ num2;
}

int main()
{
    int num1, num2;
    int ret;

    printf("Enter 2 nums\n");
    scanf("%d%d",&num1, &num2);

    ret = checkIfGivenNumsHaveOppSign(num1, num2);
    if (ret > 0)
        printf("%d and %d have same sign\n", num1, num2);
    else
        printf("%d and %d have opp sign\n", num1, num2);
    
    return 0;
}