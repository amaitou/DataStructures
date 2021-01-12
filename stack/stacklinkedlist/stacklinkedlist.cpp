
#include <iostream>

using namespace std ;

template <typename T>

class stack
{
	private :

		struct node
		{
			T d ;
			node *next ;
		} ;

		node *top = nullptr ;

	public :

		bool _empty() ;
		void _push(T v) ;
		void _pop() ;
		T _peek() ;
		void _display() ;
		int _size() ;
} ;

template <typename T>

bool stack<T>::_empty()
{
	if(top == nullptr)
		return true ;
	else
		return false ;
}

template <typename T>

void stack<T>::_push(T v)
{
	node *newnode = new node ;
	newnode->d = v ;

	if(_empty())
		newnode->next = nullptr ;
	else
		newnode->next = top ;

	top = newnode ;
}

template <typename T>

void stack<T>::_pop()
{
	if(_empty())
	{
		cout << "Empty stack" << endl ;
	}
	else
	{
		node *temp = top ;
		top = top->next ;
		delete temp ;
	}
}

template <typename T>

T stack<T>::_peek()
{
	if(_empty())
		return -1 ;
	else
	{
		return top->d ;
	}
}

template <typename T>

void stack<T>::_display()
{
	if(_empty())
		cout << "Empty stack" << endl ;
	else
	{
		cout << "[ " ;
		while(! _empty())
		{
			cout << _peek() << " " ;
			_pop() ;
		}
		cout << "]" << endl ;
	}
}

template <typename T>

int stack<T>::_size()
{
	int i = 0 ;
	node *temp = top ;
	while(temp != nullptr)
	{
		temp = temp->next ;
		i++ ;
	}
	return i ;

}

int main(void)
{
	stack<int> s ;
	s._pop() ;
	s._push(20) ;
	s._push(40) ;
	s._push(80) ;
	s._pop() ;
	cout << "Size : " << s._size() << endl ;
	s._display() ;

	return 0 ;
}