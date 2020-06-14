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
	        else
	        	return -1;
	}
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


void main()
{
	struct Array array;
	int elem_to_append, elem;
	int index, key;
	int arr_indx, elem_to_ins;

	
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


}









