
#include <iostream>

using namespace std ;

void sd(int v)
{
	if(v == 0)
		return ;
	else
	{
		cout << v % 10 << endl ;
		sd(v / 10) ;
	}

}

int main(void)
{
	sd(1234) ;
	return 0 ;
}