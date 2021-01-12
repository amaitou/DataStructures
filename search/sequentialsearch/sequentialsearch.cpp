
#include <iostream>

using namespace std ;

void sequentialsearch(int arr[] , int s , int v)
{
	for(int i = 0 ; i < s ; i++)
	{
		if(v == arr[i])
		{
			cout << "Element found at position : " << i << endl ;
			return ;
		}
	}
	cout << "Element not found" << endl ;
}

int main(void)
{
	int arr[] = {10 , 3 , 6 , 8 , 2 , 9 , 2 , 1 , 0 , 4 , 5} ;
	sequentialsearch(arr , sizeof(arr) / sizeof(int) , 4) ;
	return 0 ;
}