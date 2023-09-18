#include <stdio.h>

void invertAlpha(char * str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] ^ ' ';
        }
        else if(str[i] >= 'A' && str [i] <= 'Z')
        {
            str[i] = str[i] ^ ' ';
        }
        i++;
    }

    printf("The inverter string is %s\n", str);

}
int main()
{
    char str[256];

    printf("enter the string\n");
    fgets(str, sizeof(str), stdin);

    printf("input string is %s\n",str);
    invertAlpha(str);
    return 0;
}