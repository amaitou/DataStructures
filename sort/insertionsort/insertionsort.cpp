
#include <iostream>

using namespace std ;

void insertionsort(int arr[] , int n)
{
	/*
		Time complexity  : O(n^2)
		Space complexity : O(1)
	*/

	int key ;
	int j ;

	for(int i = 1 ; i < n ; i++)
	{
		key = arr[i] ;
		j = i - 1 ;

		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j] ;
			j-- ;
		}
		arr[j + 1] = key ;
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
	int arr[] = {23 , 22 , 29 , 21 , 26 , 24 , 28 , 27 , 25} ;
	insertionsort(arr , sizeof(arr) / sizeof(arr[0])) ;
	return 0 ;
}