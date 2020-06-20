/* 
 * This File contains code for bit manipulation
 *
 * Operations like:
 * 1.  setting nth bit
 * 2.  clearing/unsetting nth bit
 * 3.  toggling nth bit
 * 4.  checking nth bit is set or not
 * 5.  inverting every bit of a number (1's Complement)
 * 6.  2's complement
 * 7.  Stripping off the lowest set bit of a number
 * 8.  getting lowest set bit of a number
 * 9.  
 *
 */  


#include <stdio.h>
#include <stdbool.h>


int set_nth_bit(int num, int pos)
{
	int x;
	int result;

	x = 1 << pos;

	result = num | x;

	return result;
}

int unset_bit(int num, int pos)
{
	int x;
	int result;

	x = ~(1 << pos);
	result = num & x;

	return result;
}

int toggle_bit(int num, int pos)
{
	int x;
	int result;

	x = 1 << pos;

	result = num ^ x;
	return result;
}

bool check_bit(int num, int pos)
{
	int x;
	int result;

	x = 1 << pos;
	result = num & x;
	
	if (result)
		return true;
	else
		return false;
}

int ones_complement(int num)
{
	return ~num;
}

int twos_complement(int num)
{
	return ones_complement(num) + 1;
}

int strip_last_set_bit(int num)
{
	return (num & (num -1));
}

int get_lowest_set_bit(int num)
{
	int x = (num & twos_complement(num));
	int count = 0;

	while (x != 0)
	{
		x = x/2;
		count++;
	}

	return count;
	
}

void main()
{
	int num, pos, result;
	bool check;


	printf("Enter the number\n");
	scanf("%d",&num);

	printf("Enter the position to set\n");
	scanf("%d",&pos);


	result = set_nth_bit(num, pos);
	printf("After setting %dth bit of %d the result is : %d\n", pos, num, result);

	result = unset_bit(num, pos);
	printf("After unsetting %dth bit of %d the result is : %d\n", pos, num, result);

	result = toggle_bit(num, pos);
	printf("After toggling %dth bit of %d the result is : %d\n", pos, num, result);

	check = check_bit(num, pos);
	printf("the bit %d of number %d is : %d\n", pos, num, check);

	result = ones_complement(num);
	printf("1's complement of %d is %d\n", num, result);

	result = twos_complement(num);
	printf("2's complement of %d is %d\n", num, result);

	result = strip_last_set_bit(num);
	printf("After striping last set bit of %d result is %d\n", num, result);

	result = get_lowest_set_bit(num);
	printf("the lowest set bit of %d is %d\n", num, result);

}




