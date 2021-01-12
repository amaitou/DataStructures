
#include <iostream>

using namespace std ;

template <typename T>

class queue
{
	private :

		struct node
		{
			T d ;
			node *next ;
		} ;

		node *head = nullptr ;
		node *tail = nullptr ;

		int i = 0 ;

	public :

		bool _empty() ;
		void _enqueue(T v) ;
		void _dequeue() ;
		T _front() ;
		void _display() ;
		int _size() ;
} ;

template <typename T>

bool queue<T>::_empty()
{
	if(head == nullptr && tail == nullptr)
		return true ;
	else
		return false ;
}

template <typename T>

void queue<T>::_enqueue(T v)
{
	node *newnode = new node ;
	(*newnode).d = v ;
	(*newnode).next = nullptr ;

	if(_empty())
		head = tail = newnode ;
	else
	{
		tail->next = newnode ;
		tail = newnode ;
	}
	i++ ;
}

template <typename T>

void queue<T>::_dequeue()
{
	if(_empty())
	{
		cout << "Empty Queue" << endl ;
		return ;
	}

	if(tail == head)
		head = tail = nullptr ;
	else
	{
		node *temp = head ;
		head = head->next ;
		delete temp ;
	}
	i-- ;
}

template <typename T>

T queue<T>::_front()
{
	if(_empty())
		return -1 ;
	else
		return head->d ;
}

template <typename T>

void queue<T>::_display()
{
	if(_empty())
		cout << "Empty Queue" << endl ;
	else
	{
		cout << "[ " ;
		while(!_empty())
		{
			cout << _front() << " " ;
			_dequeue() ;
		}
		cout << "]" << endl ;
	}
}

template <typename T>

int queue<T>::_size()
{
	return i ;
}

int main(void)
{
	queue<int> q ;

	q._dequeue() ;
	q._enqueue(12) ;
	q._enqueue(10) ;
	q._enqueue(30) ;
	q._dequeue() ;

	cout << "Size : " << q._size() << endl ;
	
	q._display() ;
	return 0 ;
}