#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int x = (low- 1); 
	for (int y = low; y <= high - 1; y++) {
		
		if (arr[y] < pivot) {
			x++; 
			swap(arr[x],arr[y]);
		}
	}
	swap(arr[x + 1],arr[high]);
	return (x + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		
		int array_partition = partition(arr, low, high);
		quickSort(arr, low, array_partition - 1);
		quickSort(arr, array_partition + 1, high);
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int arr[] = { 9,4,8,3,7,1,6,2,5 };
	int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
	cout << "Sorted array: ";
	printArray(arr, size);
    return 0;
}
