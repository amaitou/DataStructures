
#include <bits/stdc++.h>

using namespace std ;

/*
	Time complexity  : O(n log n)
	Space complexity : O(n) 
*/

void merge(int arg[] , int l , int m , int r)
{
	int n1 = m - l + 1 ;
	int n2 = r - m ;

	int *left = new int[n1] ;
	int *right = new int[n2] ;

	for (int i = 0; i < n1; i++)
		left[i] = arg[l + i];
	for (int j = 0; j < n2; j++)
		right[j] = arg[m + 1 + j];

	int i = 0 ;
	int j = 0 ;
	int k = l ;

	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
		{
			arg[k] = left[i] ;
			i++ ;
		}
		else
		{
			arg[k] = right[j] ;
			j++ ;
		}
		k++ ;
	}

	while(i < n1)
	{
		arg[k] = left[i] ;
		i++ ;
		k++ ;
	}

	while(j < n2)
	{
		arg[k] = right[j] ;
		j++ ;
		k++ ;
	}
}

void mergesort(int arr[] , int l , int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2 ;
		
		mergesort(arr , l , m) ;
		mergesort(arr , m + 1 , r) ;

		merge(arr , l , m , r) ;
	}
}

int main(void)
{
	int arr[] = {3 , 6 , 9 , 4 , 1 , 0 , 5 , 8 , 2 , 7 } ;
	int s = sizeof(arr) / sizeof(int) ;
	mergesort(arr , 0 , s) ;
	
	cout << "[ " ;
	for(int i = 0 ; i < s ; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << "]" << endl ;
	
	return 0 ;
}