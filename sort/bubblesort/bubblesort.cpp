
#include <bits/stdc++.h>

using namespace std ;

void bubblesort(int arr[] , int n)
{
	/*
		Time complexity  : O(n^2)
		Space complexity : O(1)
	*/

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n - 1 ; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap(arr[j] , arr[j +1]) ;
			}
		}
	}

	cout << "[ " ;
	for(int i = 0 ; i < n ; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << "]" << endl ;
}

int main(void)
{
	int arr[] = {4 , 8 , 6 , 1 , 0 , 5 , 9 , 7 , 3 , 2} ;
	bubblesort(arr , sizeof(arr) / sizeof(arr[0])) ;
}