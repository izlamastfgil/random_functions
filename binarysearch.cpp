#include <iostream>
using namespace std;


int binarySearch(int arr[], int start, int end, int x)
{
	int mid = (start + end) / 2;
	
	if (arr[mid] == x)
	{
		return mid;
	}

	else if (arr[mid] > x)
	{
		return (binarySearch(arr, start, mid - 1, x));
	}

	else
	{
		return (binarySearch(arr, mid + 1, end, x));
	}

	return (binarySearch(arr, start, end, x));
}

int main()
{
	int arr[3] {1,2,3};
	cout << binarySearch(arr, 0, 2, 3);
}
