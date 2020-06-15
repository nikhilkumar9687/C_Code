/*
 * This file has string manipulation
 * like:
 * 1.  change the string to upper case 
 * 2.  change the string to lower case
 * 3.  toggle the case of a string
 * 4.  count the number vowels and consonents 
 * 5.  validating a string
 * 6.  Reversing a string
 * 7.  comparing the strings
 * 8.  checking if string is Palindrome
 * 9.  finding Duplicates in a string
 * 10. finding Duplicates in a string using Bitwise operators
 * 11. checking if strings are Anagram (i.e. have distinct letters)
 * 12. finding length of a string
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);
	return i ;
}

void to_upper(char *str)
{
	int i;

	for(i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
}

void to_lower(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void toggle_str(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

void no_of_vol_n_con(char *str)
{
	int i;
	int vol_count = 0, con_count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ( str[i] == 'A' || str[i] == 'a' ||
		     str[i] == 'E' || str[i] == 'e' ||
		     str[i] == 'I' || str[i] == 'i' ||
		     str[i] == 'O' || str[i] == 'o' ||
		     str[i] == 'U' || str[i] == 'u' )
			vol_count++;
		else if (str[i] >= 'a' && str[i] <='z' ||
		         str[i] >= 'A' && str[i] <='Z') 
			con_count++;
	}

	printf(" In the given string %s, vowels = %d,Consonents = %d\n",
		       	str, vol_count, con_count);
}

int no_of_words(char *str)
{
	int i;
	int count = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
			count++;
	}
	return count;
}

int valid(char *str)
{
	int i;

	for ( i = 0; str[i] != '\0'; i++)
	{
		if ( !(str[i] >= 'A' && str[i] <= 'Z') &&
		     !(str[i] >= 'a' && str[i] <= 'z') &&
		     !(str[i] >= '0' && str[i] <= '9'))
			return 1;
	}
	return 0;
}

char *reverse_str(char str[])
{
	int i, j;
	char temp;

	for ( i = 0; str[i] != '\0'; i++);
	i = i - 1;
	for (j = 0; j < i; j++, i--)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
	}

	return (char *)str;
}

void com_str(char *str, char *str2)
{
	int i, j;

	for (i = 0, j = 0; str[i] != '\0' && str2[j] != '\0'; i++, j++)
	{
		if (str[i] != str[j])
			break;
	}

	if (str[i] > str2[j])
		printf(" str %s is greater then str %s\n",
				str, str2);
	else if (str[i] < str2[j])
		printf(" str %s is less then str %s\n",
				str, str2);
	else
		printf(" str %s is equal to str %s\n",
				str, str2);


}

int ispalindrome(char str[])
{
	int i = 0, j;

	for (j = 0; str[j] != '\0'; j++);
	j = strlen(str) - 1;

	while (j > i)
	{
		if (str[i++] != str[j--])
			return 0;
	}

	return 1;
}

void find_dup_using_hash(char *str)
{
	int i, j = 0;
	int hash[26]= {0};

	//for (j = 0; str[j] != '\0'; j++);
	
	for (i = 0; str[i] != '\0'; i++, j++)
	{
		hash[str[i] - 97] += 1;
	}
	
	for (j = 0; j < 26; j++)
	{
		if (hash[j] > 1)
		{
			printf("char '%c' is repeted %d times\n", 
					(j + 97), hash[j] - 1);
		}
	}
}	
	       	
void find_dup_using_bitwise(char *str)
{
	int i;
	int h = 0, x = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		x = 1;
		x = x << (str[i] - 97);

		if ((x & h) > 0)
			printf("char '%c' is a duplicate\n", str[i]);
		else
			h = x | h;
	}

}

void isanagram( char *str1, char *str2)
{
	int i, j;
	int hash[26] = {0};
	
	for (i = 0; str1[i] != '\0'; i++)
		hash[str1[i] - 97] += 1;

	for ( i = 0; str2[i] != '\0'; i++)
	{
		hash[str2[i] - 97] -= 1;
		if (hash[str2[i] - 97] < 0)
		{
			printf("char '%c' is duplicate\n", str2[i]);
		        printf("the given strings are NOT ANAGRAM\n"); 
			break;
		}
	}
	if (str2[i] == '\0')
		printf("the given strings are ANAGRAM\n"); 



}


	
			 	
void main()
{
	char *str, *rev_str, *temp_str;
	int val;
	int length = 20;
	int isvalid = 0;


	str = (char *) malloc (sizeof(char) * (length + 1));

	printf("Enter your string\n");
	fgets(str, length, stdin);

	printf("The entered string is %s \n", str);

	val = Strlen(str);
	printf("The length of given string is %d\n", val);

	to_upper(str);
	printf("The entered string is %s \n", str);

	to_lower(str);
	printf("The entered string is %s \n", str);

	printf("Enter your string\n");
	fgets(str, length, stdin);

	printf("The entered string is %s \n", str);

	toggle_str(str);
	printf("The toggled string is %s \n", str);
        
	no_of_vol_n_con(str);

	val = no_of_words(str);
	printf("Number of words in given string is %d\n", val);
/*
	printf("Enter your string\n");
	fgets(str, length, stdin);


	if(valid(str))
	        printf("Valid String\n");
	else
	        printf("Invalid String\n");
*/
	strcpy(temp_str, str);
	rev_str = reverse_str(temp_str);
	printf("The Reverse of given string %s is %s\n", str, rev_str);

	printf("Enter your  1st string\n");
	fgets(str, length, stdin);

	temp_str = (char *) malloc (sizeof(char) * (length + 1));

	printf("Enter your 2nd string\n");
	fgets(temp_str, length, stdin);

	com_str(str, temp_str);
	
	printf("Enter your string\n");
	fgets(str, length, stdin);
	
	strcpy(temp_str, str);
	val = ispalindrome(temp_str);
	if(val == 1)
		printf("str %s is palindrome\n", str);
	else
		printf("str %s is not palindrome\n", str);


	printf("For Anagram\n");
	printf("Enter your  1st string\n");
	fgets(str, length, stdin);

	printf("Enter your  2nd string\n");
	fgets(temp_str, length, stdin);


	isanagram(str, temp_str);

        find_dup_using_hash(str);
        find_dup_using_bitwise(str);
	free(str);
	free(temp_str);

}



