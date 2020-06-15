/*
 * This file contains all the operations on Array
 * Operations like
 * 1. Display
 * 2. Add(elem)/Append(elem)
 * 3. Insert(@index)
 * 4. Delete(@index)
 * 5. Linear Search
 * 6. Binary Search
 * 7. Get(index)
 * 8. Set(index, elem)
 * 9. Max()/Min()
 * 10.Reverse()
 * 11.Shift()/Rotate()
 */

#include <stdio.h>
#include <stdlib.h>


struct Array
{
	int *A;    // Dynamic Array
	int size;  // The size of Array
	int length;// the number of elements filled can only be <= size
};

void Display(struct Array arr)
{
	int i;
	printf(" arr.length = %d\n", arr.length);

	for (i = 0; i < arr.size; i++)
		printf("value at index %d of array is: %d\n", i, *(arr.A + i));
	printf("\n");
}

void Append(struct Array *arr, int elem)
{
	printf("Append: arr->length = %d\n",arr->length);
	arr->A[arr->length] = elem;
}

void Insert(struct Array *arr, int index, int elem)
{
	int i;

	if(arr->length == 0)
		Append(arr, elem);
	else if (arr->length <= arr->size)
	{
		for (i = arr->length; i >= index; i--)
			arr->A[i + 1] = arr->A[i];
		
		arr->A[index] = elem;
		arr->length++;
	}
}

void Delete(struct Array *arr, int index)
{
	int i;
	if(arr->length == 0 || arr->size == 0)
		printf("Cannot Delet %d index from an empty Array\n", index);
	else
	{
		for (i = index; i < arr->length; i++)
			arr->A[i] = arr->A[i + 1];

		arr->length--;
	}
}

int Linear_search(struct Array arr, int key)
{
	int i;

	for (i = 0; i < arr.length;i++)
	{
		if (arr.A[i] == key)
			return i;
	}
	return -1;
}

int Binary_search(struct Array array, int key)
{
	int low, high, mid;

	low = array.A[0];
	high = array.A[array.length - 1];
	while ( low <= high )
	{
	        mid = (low + high)/2;
	        if(array.A[mid] == key)
	        	return mid;
	        else if (key < array.A[mid])
	               high = mid - 1;
	        else if (key > array.A[mid])
	        	low = mid + 1;
	}
	return -1;
}

int Recursive_bin_ser(int arr[], int low, int high, int key)
{
	int mid;

	if (low <= high)
	{
		mid = (low + high)/2;
		if (key == arr[mid])
			return mid;
		else if (key < arr[mid])
			return Recursive_bin_ser(arr, low, mid - 1, key);
		else if (key > arr[mid])
			return Recursive_bin_ser(arr, mid + 1, high, key);
	}
	return -1;
}

void Get(struct Array array, int index)
{
	if (index >= 0 && index < array.length)
	{
		printf("The value at index %d is %d\n",
				index, array.A[index]);
	}
}

void Set(struct Array *arr, int index, int value)
{
	if ( index >= 0 && index < arr->length)
	{	
		arr->A[index] = value;

		printf("The Value at array index %d is changed to %d\n",
				index, arr->A[index]);
	}	
}

int Max(struct Array arr)
{
	int max, i;

	max = arr.A[0];
	if (arr.length == 0 || arr.size == 0)
		return -1;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	
	return max;
}

int Min (struct Array arr)
{
	int min, i;

	min = arr.A[0];

	for (i = 1; i < arr.length; i++)
	{
		if(min > arr.A[i])
			min = arr.A[i];
	}
	return min;
}

int Sum(int arr[], int length)
{
	int i, sum = 0;

	for (i = 0; i < length; i++)
		sum = sum + arr[i];

	return sum;
}

int Avg(struct Array arr)
{
	int avg = 0;

	avg = (Sum(arr.A, arr.length)/(arr.length - 1));

	return avg;
}

void Reverse(struct Array *arr, int start, int end)
{
	int i, j;

	for (i = start, j = (end - 1); i < j; i++, j--)
	{
		arr->A[i] = arr->A[i] + arr->A[j];
		arr->A[j] = arr->A[i] - arr->A[j];
		arr->A[i] = arr->A[i] - arr->A[j];
	}

}
void left_rotate_by_one(struct Array *arr, int size);
void Left_rotate(struct Array *arr, int no_of_rotations)
{
	int i;
	
	for (i = 0; i < no_of_rotations; i++)
		left_rotate_by_one(arr, arr->length);
}

void left_rotate_by_one(struct Array *arr, int size)
{
	int i, temp = arr->A[0];
	for ( i = 0; i < size - 1; i++)
		arr->A[i] = arr->A[i + 1];
	arr->A[i] = temp;
}

void Left_rotate_by_revese(struct Array *arr, int no_of_rotations,int size )
{
	Reverse(arr, 0, no_of_rotations);
	Reverse(arr, no_of_rotations , size);
	Reverse(arr, 0, size);
}




void main()
{
	struct Array array;
	int elem_to_append, elem;
	int index, key;
	int arr_indx, elem_to_ins;
	int value;

	
	array.length = 0;
	
	printf("Enter the size of array\n");
	scanf("%d", &array.size);

	/* 
	 * Get memory from heap for array.size element
	 * array
	 */

	printf("The size of array is %d\n", array.size);
        array.A = (int *) calloc (array.size, (array.size * sizeof(int)));

	printf("Enter the number of elements to add/append\n");
	scanf("%d",&elem_to_append);

	for (index = 0; index < elem_to_append; index++)
	{
		printf("Enter the value for index %d\n", index);
		scanf("%d",&elem);

		Append(&array, elem);
		array.length++;
	}
       
	printf("Enter the array index and value to insert in array\n");
	scanf("%d%d", &arr_indx, &elem_to_ins);

	Insert(&array, arr_indx, elem_to_ins);
	Display(array);

	printf("Enter the array index to delete in array\n");
	scanf("%d", &arr_indx);

	Delete(&array, arr_indx);
	Display(array);

	printf("Enter the Value to Search got Linear search\n");
	scanf("%d",&key);

	index = Linear_search(array, key);
	if (index == -1)
		printf("Value %d not found in given array\n", key);
	else
		printf("Value %d found at index %d\n", key, index);

	printf("Enter the Value to Search for Binary Search\n");
	scanf("%d",&key);

	index = Binary_search(array, key);
	if (index == -1)
		printf("Value %d not found in given array\n", key);
	else
		printf("Value %d found at index %d\n", key, index);

	printf("Enter the Value to Search for Recursive Binary Search\n");
	scanf("%d",&key);

	index = Recursive_bin_ser(array.A, 0, array.length, key);
	if (index == -1)
		printf("Value %d not found in given array\n", key);
	else
		printf("Value %d found at index %d\n", key, index);

	value = Max(array);
	printf("The maximum value in the given array is %d\n", value);

	value = Min(array);
	printf("The minimum value in the given array is %d\n", value);

	value = Sum(array.A, array.length);
	printf("The sum of all elements in the given array is %d\n", value);

	value = Avg(array);
	printf("The Avg of all elements in the given array is %d\n", value);

	Reverse(&array, 0, array.length);
	printf("The Reverse of the given array is\n");
	Display(array);
/*
	printf("Enter the no of rotations\n");
	scanf("%d",&value);
	Left_rotate(&array,value);
        Display(array);	

*/	printf("Enter the no of rotations\n");
	scanf("%d",&value);
	Left_rotate_by_revese(&array,value, array.length);
        Display(array);	



	
}

