
#include <iostream>
#define mx 100

using namespace std ;

template<typename T>

class stack
{

	/*

	Time copmlexity :

		access    : O(n)
		delete    : O(1)
		search    : O(n)
		insertion : O(1) 

	*/
	
	private :

		T *arr = new T(mx) ;
		int top = -1 ;

	public :

		bool _empty() ;
		bool _full() ;
		void _push(T v) ;
		void _pop() ;
		int _size() ;
		T _peek() ;
		void _display() ;
} ;

template<typename T>

bool stack<T>::_empty()
{
	if(top == -1)
		return true ;
	else
		return false ;
}

template<typename T>

bool stack<T>::_full()
{
	if(top == mx - 1)
		return true ;
	else
		return false ;
}

template<typename T>

void stack<T>::_push(T v)
{
	if(_full())
	{
		cout << "Full stack" << endl ;
	}
	else
	{
		top++ ;
		arr[top] = v ;
	}
}

template<typename T>

void stack<T>::_pop()
{
	if(_empty())
	{
		cout << "Empty stack" << endl ;
	}
	else
	{
		top-- ;
	}
}

template<typename T>

T stack<T>::_peek()
{
	return arr[top] ;
}

template<typename T>

int stack<T>::_size()
{
	return top + 1 ;
}

template <typename T>

void stack<T>::_display()
{
	if (_empty())
		return ;
	cout << "[ " ;
	while(! _empty())
	{
		cout << _peek() << " " ;
		_pop() ;
	}
	cout << "]" << endl ;
}

int main(void)
{
	stack<char> s ;

	s._pop() ;
	cout << s._empty() << endl ;
	cout << s._full() << endl ;

	s._push('c') ;
	s._push('b') ;
	s._push('1') ;
	s._pop() ;
	s._push('F') ;
	s._push('4') ;

	cout << s._size() << endl ;

	s._display() ;
	return 0 ;
}