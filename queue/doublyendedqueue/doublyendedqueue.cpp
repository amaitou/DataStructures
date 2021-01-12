
#include <iostream>

#define mx 10

using namespace std ;

template <typename T>

class deq
{
	private :

		T *arr = new T(mx) ;
		int head = -1 ;
		int rear = -1 ;

		int s = 0 ;

	public :

		bool _full() ;
		bool _empty() ;
		void _enqfront(T v) ;
		void _enqrear(T v) ;
		T _front() ;
		void _deqfront() ;
		void _deqrear() ;
		void _display() ;
		int _size() ;
} ;

template <typename T>

bool deq<T>::_full()
{
	if ((head == rear + 1) || (head == 0 && rear == mx - 1))
		return true ;
	else
		return false ;
}

template <typename T>

bool deq<T>::_empty()
{
	if(head == -1 && rear == -1)
		return true ;
	else
		return false ;
}

template <typename T>

void deq<T>::_enqfront(T v)
{
	if(_full())
		return ;
	else if(_empty())
	{
		head = rear = 0 ;
		arr[head] = v ;
	}
	else if (head == 0)
	{
		head = mx - 1 ;
		arr[head] = v ;
	}
	else
	{
		head-- ;
		arr[head] = v ;
	}
	s++ ;
}

template <typename T>

void deq<T>::_enqrear(T v)
{
	if(_full())
		return ;
	else if(_empty())
	{
		rear = head = 0 ;
		arr[rear] = v ;
	}
	else if(rear == mx - 1)
	{
		rear = 0 ;
		arr[rear] = v ;
	}
	else
	{
		rear++ ;
		arr[rear] = v ;
	}
	s++ ;
}

template <typename T>

T deq<T>::_front()
{
	if(_empty())
		return -1 ;
	else
		return arr[head] ;
}

template <typename T>

void deq<T>::_deqfront()
{
	if(_empty())
		return ;
	else if(head == rear)
		head = rear = -1 ;
	else if(head == mx - 1)
		head = 0 ;
	else
		head++ ;
	s-- ;
}

template <typename T>

void deq<T>::_deqrear()
{
	if(_empty())
		return ;
	else if(head == rear)
		rear = head = -1 ;
	else if(rear == 0)
		rear = mx -1 ;
	else
		rear-- ;
	s-- ;
}

template <typename T>

void deq<T>::_display()
{
	if(_empty())
		return ;
	else
	{
		int i = head ;
		cout << "[ " ;
		while(i != rear)
		{
			cout << arr[i] << " " ;
			i = (i + 1) % mx ;
		}
		cout << arr[rear] << " ]" << endl ;
	}
}

template <typename T>

int deq<T>::_size()
{
	return s ;
}

int main(void)
{
	deq<int> d ;

	d._enqrear(13) ;
	d._enqrear(12) ;
	d._enqrear(20) ;
	d._deqfront() ;
	d._deqrear() ;
	d._display() ;
	cout << "Size : " << d._size() << endl ;
	return 0 ;
}