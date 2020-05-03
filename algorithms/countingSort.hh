#include <iostream>
#include <cfloat>
#include <cmath>

#define precision(n) pow(10,n-1)

double find_max(double arr[], int length)
{
	double max = DBL_MIN;
	for (int i = 0; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int hash(double d)
{
	return d*precision(5);
}

double unhash(int i)
{
	double d = (double)i;
	return d/precision(5);
}

void counting_sort(double arr[], int length)
{
	double max = find_max(arr, length);
	int buckets_length = hash(max) + 1;
	int buckets[buckets_length];
	for (int i = 0; i < buckets_length; i++)
	{
		buckets[i] = 0;
	}
	for (int i = 0; i < length; i++)
	{
		int index = hash(arr[i]);
		buckets[index] += 1;
	}
	int arr_i = 0;
	for (int i = 0; i < buckets_length; i++)
	{
		while (buckets[i] != 0)
		{
			arr[arr_i++] = unhash(i);
			buckets[i] -= 1;
		}
	}
}

/*void print(double d[], int length)
{
	std::cout << "{ ";
	for (int i = 0; i < length-1; i++)
		std::cout << d[i] << ", ";
	std::cout << d[length-1] << " }" << std::endl;
}

int main(int argc, char *argv[])
{
	std::cout << precision(5) << std::endl;
	double d[] = {9.5, 8.3, 74.2, 0.33298742348723, 42.0};
	int length = 5;
	counting_sort(d, length);
	print(d, length);
	return 0;
}*/
