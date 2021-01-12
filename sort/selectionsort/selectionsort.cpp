
#include <bits/stdc++.h>

using namespace std ;

void selectionsort(int arr [] , int n)
{
	/*
		Time complexity  : O(n^2)
		Space complexity : O(1)
	*/
	
	int mi ;
	for(int i = 0 ; i < n - 1 ; i++)
	{
		mi = i ;
		for(int j = i + 1 ; j < n ; j++)
		{
			if(arr[j] < arr[mi])
			{
				mi = j ;
			}
		}
		swap(arr[mi] , arr[i]) ;
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
	int arr[] = {12 , 11 , 34 , 22 , 10 , 23 , 8} ;
	selectionsort(arr , sizeof(arr) / sizeof(arr[0])) ;
	return 0 ;
}