
#include <iostream>

using namespace std ;

#define ms 100
class stack
{
	private :
		int arr[ms] ;
		int top = -1 ;
	public :
		bool empty()
		{
			if(top == -1)
				return true ;
			else
				return false ;
		}
		bool full()
		{
			if(top == ms - 1)
				return true ;
			else
				return false ;
		}
		void push(int v)
		{
			if(full())
				cout << "full stack" << endl ;
			else
				top += 1 ;
			arr[top] = v ;
		}
		void pop()
		{
			if(empty())
				cout << "empty stack" << endl ;
			else
				top -= 1 ;
		}
		int peek()
		{
			if(empty())
				return -1 ;
			else
				return arr[top] ;
		}
} ;

stack s ;

bool parentheses(char a , char b)
{
	if((a == '(' and b == ')') or (a == '[' and b == ']') or (a == '{' and b == '}'))
		return true ;
	else
		return false ;
}

bool operation(string e)
{
	for(int i = 0 ; i < e.length() ; i++)
	{
		if(e[i] == ' ')
			continue ;
		else if(e[i] == '(' or e[i] == '[' or e[i] == '{')
			s.push(e[i]) ;
		else
		{
			if (s.empty())
				return false ;
			else if((parentheses(s.peek() , e[i])) == false)
				return false ;
			else
				s.pop() ;
		}
	}

	if (s.empty())
		return true ;
	else
		return false ;
}

int main(void)

{
	string expression ;
	cout << "Enter parentheses : " ;
	getline(cin , expression) ;

	if(operation(expression))
		cout << "Balanced" << endl ;
	else
		cout << "Not Balanced" << endl ;

	return 0 ;
}
