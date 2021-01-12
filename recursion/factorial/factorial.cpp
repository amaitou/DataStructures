
#include <iostream>

using namespace std ;

int factorial(int v)
{
	if(v == 0 || v == 1)
		return 1;
	else
		return v * factorial(v - 1) ;
}

int main(void)
{
	// 5 = 5 * 4 * 3 * 2 * 1 = 120
	cout << "Factorial : " << factorial(5) << endl ;
	return 0 ;
}