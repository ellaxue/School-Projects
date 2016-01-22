///*
// * extra_credit.cpp
// *
// *  Created on: 2014/10/22
// *      Author: Ella
// */
//#include <iostream>
//#include <stdio.h>
//void swap (int a, int b, int arr[]);
//int lowest(int start, int end, int arr[]);
//void sort(int arr[], int size);
//void printArr(int arr[], int size);
//bool check_sorted(int arr[], int size);
//void fillArr(int arr[], int size);
//
//int main(void)
//{
//	int size = 0, *arr;
//
//	//get array size from user input and create a new array.
//	printf("input the size.\n");
//	scanf("%d", &size);
//	arr = new int[size];
//
//	fillArr(arr, size);
//	printf("Original Array: \n");
//	printArr(arr, size);
//	sort(arr, size);
//
//	if (check_sorted(arr, size))
//	{
//		printf("Sorted Array: \n");
//		printArr(arr, size);
//	}
//	else
//	{
//		printf("array is not sorted properly");
//	}
//
//	delete []arr;
//	return 0;
//}
//
//void swap (int a, int b, int arr[])
//{
//	int temp;
//	temp = arr[a];
//	arr[a] = arr[b];
//	arr[b] = temp;
//}
//
//int lowest(int start, int end, int arr[])
//{
//	int lowest_index = start;
//	for (int i = start; i < end; i++)
//	{
//		if ( arr[lowest_index] > arr[i+1])
//		{
//			lowest_index = i + 1;
//		}
//	}
//	return lowest_index;
//}
//
//void sort(int arr[], int size)
//{
//	int tracker = 0;
//	int lowest_index = 0;
//
//	//when tracker reaches size, all elements in the array should have been properly sorted
//	while( tracker < size)
//	{
//		lowest_index = lowest(tracker, size -1,arr);
//		swap (tracker, lowest_index, arr);
//		tracker ++; //update the tracker to the next element in the array
//	}
//}
//
//void printArr(int arr[], int size)
//{
//	for ( int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//bool check_sorted(int arr[], int size)
//{
//	for (int i = 0; i < size - 1; i++)
//	{
//		//if any of the preceding element in the array is greater than the next element,
//		//array is not properly sorted.
//		if (arr[i] > arr[i+1])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//void fillArr(int arr[], int size)
//{
//		int value;
//		printf("fill in the array with integers.\n");
//		for(int i = 0; i < size; i++)
//		{
//			scanf("%d", &value);
//			arr[i] = value;
//		}
//}
