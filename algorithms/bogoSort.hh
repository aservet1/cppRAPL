#include <iostream>
#include <ctime>

bool isSorted(int arr[], int length)
{
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i-1])
		{
			return false;
		}
	}
	return true;
}

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void shuffle(int arr[], int length)
{
	for (int n = 0; n < length*2; n++)
	{
		int i = rand()%length
		int j = rand()%length;
		swap(arr, i, j);
	}
}

void bogoSort(int arr[], int length)
{
	while(!isSorted(arr,length))
	{
		shuffle(arr,length);
	}
}
