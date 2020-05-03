#include <iostream>
#include <ctime>

using namespace std; bool isSorted(int arr[], int length) { for (int i = 1; i < length; i++) if (arr[i] < arr[i-1]) return false; return true; } void shuffle(int arr[], int length) { for (int n = 0; n < length*2; n++) { int a = rand()%length; int b = rand()%length; int temp = arr[a]; arr[a] = arr[b]; arr[b] = temp; } } void bogoSort(int arr[], int length) { while(!isSorted(arr,length)) shuffle(arr,length); } void printarr(int arr[], int length) { cout << "[ "; for (int i = 0; i < length-1; i++) cout << arr[i] << ", "; cout << arr[length-1] << " ]"; }
