
#include <bits/stdc++.h>

using namespace std ;

int jumpsearch(int arr[] , int s , int v)
{
	/*
		Time complexity : O(√n)
	*/
	
	int step = sqrt(s) ;
	int prev = 0 ;

	while(arr[min(step , s) - 1] < v)
	{
		prev = step ;
		step += sqrt(s) ;
		if(prev >= s)
			return -1 ;
	}

	while(arr[prev] < v)
	{
		prev++ ;
		if(prev == min(step , s))
			return -1 ;
	}
	if(arr[prev] == v)
		return prev ;

	return -1 ;
}

int main(void)
{
	int arr[] = {0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 } ;
	int s = sizeof(arr) / sizeof(int) ;
	int position = jumpsearch(arr , s , 6) ;

	if(position == -1)
		cout << "Element not found" << endl ;
	else
		cout << "Element found at position : " << position << endl ;
	return 0 ;
}