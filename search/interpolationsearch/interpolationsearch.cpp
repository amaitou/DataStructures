
#include <bits/stdc++.h>

using namespace std ;

int interpolationsearch(int arr[] , int l , int h , int v)
{
	while(l <= h)
	{
		int middle = l + (((double)h - l) / (arr[h] - arr[l])) * (v - arr[l]) ;

		if(arr[middle] == v)
			return middle ;
		if(arr[middle] > v)
			h = middle - 1 ;
		else
			l = middle + 1 ;
	}
	return -1 ;
}

int main(void)
{
	int arr[] = { 0 , 1 , 3 , 6 , 8 , 9 , 11 , 12 , 20 , 33 , 40 } ;
	int s = sizeof(arr) / sizeof(int) ;
	int l = 0 ;
	int h = s - 1 ;
	
	int position = interpolationsearch(arr , l , s - 1 , 33 ) ;

	if(position == -1)
		cout << "Element not found" << endl ;
	else
		cout << "Element found at position : " << position << endl ;
	return 0 ;
}