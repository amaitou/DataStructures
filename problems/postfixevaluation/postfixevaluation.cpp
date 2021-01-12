
#include <iostream>

using namespace std ;

#define size 100

typedef struct operation

{
	float array[size] ;
	int top = -1 ;

	bool empty()

	{
		if (top == -1) return true ;
		else return false ;
	}

	void push(float value)

	{
		if (top == size -1) return ;
		top += 1 ;
		array[top] = value ;
	}

	void pop()

	{
		if (empty()) return ;
		top -= 1 ;
	}

	float peek()

	{
		return array[top] ;
	}

} stack ;


int digitalpha(int character)

{
	if ((character >= 48 && character <= 57) || (character >= 65 && character <= 90) || (character >= 97 && character <= 122)) return true ;
	else return false ;
}

int priority(char symbol)

{
	if (symbol == '+' || symbol == '-') return 1 ;
	else if (symbol == '/' || symbol == '*') return 2 ;
	else if (symbol == '^') return 3 ;
	else return 0 ;
}

stack s ;

string infixt2postfix(string infix)

{
	string output = "" ;

	for (int i = 0 ; i < infix.length() ; i++)

	{
		if (infix[i] == ' ') 
			continue ;

		else if (infix[i] == '(')
			
			s.push(infix[i]) ;

		else if(digitalpha(infix[i]) || digitalpha(infix[i]))
			
			output += infix[i] ;

		else if(infix[i] == ')')

		{
			while (s.peek() != '(')

			{
				output += s.peek() ;
				s.pop() ;
			}
			
			s.pop() ;

		}

		else

		{
			while(!s.empty() && priority(infix[i]) <= priority(s.peek()))

			{
				output += s.peek() ;
				s.pop() ;
			}

			s.push(infix[i]) ;
		}
	}

	while(!s.empty())

	{
		output += s.peek() ;
		s.pop() ;
	}

	return output ;
}

float math(float firstoperand , float secondoperand , char _oprator)

{
	if (_oprator == '+') return firstoperand + secondoperand ;
	else if (_oprator == '-') return firstoperand - secondoperand ;
	else if (_oprator == '*') return firstoperand * secondoperand ;
	else if (_oprator == '/') return firstoperand / secondoperand ;
	else return 0 ;
}

float evaluation(string _postfix)

{
	for (int i = 0 ; i < _postfix.length() ; i++)

	{
		if (_postfix[i] == ' ')
			continue ;

		if (digitalpha(_postfix[i]))
			s.push(_postfix[i] - '0') ;
		
		else

		{
			float secondoperand = s.peek() ;
			s.pop() ;
			float firstoperand = s.peek() ;
			s.pop() ;

			float result = math(firstoperand , secondoperand , _postfix[i]) ;

			s.push(result) ;
		}
	}

	return s.peek() ;
}


int main(void)

{	
		
	string infix = "(3+2)+7/2*((7+3)*2)" ;	
	string _postfix = infixt2postfix(infix) ;
	float postfixvalue = evaluation(_postfix) ;

	cout << "Infix   : " << infix << endl ;
	cout << "Postfix : " << _postfix << endl ;
	cout << "Value   : " << postfixvalue << endl ;
	return 0 ;

}
