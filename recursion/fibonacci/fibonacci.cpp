
#include <iostream>

using namespace std ;

int fib(int v)
{
	if(v == 0 || v == 1)
		return v;
	else
		return fib(v - 1) + fib(v - 2) ;
}

int main(void)
{
	cout << "Fibnacci : " << fib(3) << endl ;
	return 0 ;
}