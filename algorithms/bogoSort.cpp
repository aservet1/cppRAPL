#include <iostream>
#include <ctime>

using namespace std;

bool isSorted(int arr[], int length) { for (int i = 1; i < length; i++) if (arr[i] < arr[i-1]) return false; return true; }

void swap(int* x, int* y) { *x = *x ^ *y; *y = *x ^ *y; *x = *x ^ *y; }

void shuffle(int arr[], int length) { for (int n = 0; n < 100; n++) swap(&(arr[rand()%length]), &(arr[rand()%length])); }

void bogoSort(int arr[], int length) { while(!isSorted(arr,length)) shuffle(arr,length); }

void printarr(int arr[], int length) { cout << "[ "; for (int i = 0; i < length-1; i++) cout << arr[i] << ", "; cout << arr[length] << " ]"; }

int main(int argc, char *argv[]) { srand(time(NULL)); int length = 3; int arr[] = {3, 1, 2}; bogoSort(arr, length); printarr(arr, length); return 0; }
