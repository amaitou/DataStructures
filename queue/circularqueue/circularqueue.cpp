
#include <iostream>
#define mx 100

using namespace std ;

template <typename T>

class queue
{
	private :

		T *arr = new T(mx) ;
		int rear = -1 ;
		int head = -1 ;
		int s = 0 ;

	public :

		bool _empty() ;
		bool _full() ;
		void _enqueue(T v) ;
		void _dequeue() ;
		T _front() ;
		int _size() ;
		void _display() ;
} ;

template <typename T>

bool queue<T>::_empty()
{
	if(head == -1 && rear == -1)
		return true ;
	else
		return false ;
}

template <typename T>

bool queue<T>::_full()
{
	if((rear + 1) % mx == head)
		return true ;
	else
		return false ;
}

template <typename T>

void queue<T>::_enqueue(T v)
{
	if(_full())
	{
		cout << "Full queue" << endl ;
		return ;
	}
	else if(_empty())
	{
		rear = 0 ;
		head = 0 ;
	}
	else
	{
		rear = (rear + 1) % mx ;
	}

	arr[rear] = v ;
	s++ ;
}

template <typename T>

void queue<T>::_dequeue()
{
	if(_empty())
	{
		cout << "Empty queue" << endl ;
		return ;
	}
	else if(head == rear)
	{
		rear = head = -1 ; 
	}
	else
		head = (head + 1) % mx ;
	s-- ;
}

template <typename T>

T queue<T>::_front()
{
	if(_empty())
		return -1 ;
	else
		return arr[head] ;
}

template <typename T>

int queue<T>::_size()
{
	return s ;
}

template <typename T>

void queue<T>::_display()
{
	if(_empty())
		cout << "empty queue" << endl ;
	cout << "[ " ;
	while(! _empty())
	{
		cout << _front() << " " ;
		_dequeue() ;
	}
	cout << "]" << endl ;
}

int main(void)
{
	queue<int> q ;

	q._enqueue(80) ;
	q._enqueue(90) ;
	q._enqueue(50) ;
	q._dequeue() ;
	q._enqueue(56) ;

	cout << q._size() << endl ;
	cout << q._empty() << endl ;
	cout << q._full() << endl ;

	q._display() ;

	return 0 ;
}