
#include <iostream>

using namespace std ;

template <typename T>

class sll
{

	/*
		Time complexity :

			access    : O(n)
			delete    : O(1)
			insertion : O(1)
			search    : O(n) 
	*/
	
	private :

		struct node
		{
			T d ;
			node *next ; // pointer to node
		} ;

		node *head = NULL ;

	public :

		void _display() ;
		void _append(T v) ;
		void _remove(T v) ;
		void _insert(int p , T v) ;
		void _removeat(int p) ;
		void _reverse() ;
		int _size() ;
} ;

template <typename T>

void sll<T>::_display()
{
	node *temp = head ;
	cout << "[ " ;
	while(temp != NULL)
	{
		cout << temp->d << " " ;
		temp = temp->next ;
	}
	cout << "]" << endl ;
}

template <typename T>

void sll<T>::_append(T v)
{
	node *newnode = new node ;
	newnode->d = v ;
	newnode->next = NULL ;

	if(head == NULL)
	{
		head = newnode ;
	}
	else
	{
		node *temp  = head ;
		while(temp->next != NULL)
		{
			temp = temp->next ;
		}
		temp->next = newnode ;
	}
}

template <typename T>

void sll<T>::_remove(T v)
{

	if (head == NULL)
		return ;

	node *temp ;
	node *prev ;

	prev = temp = head ;

	if(head->d == v)
	{
		head = temp->next ;
		delete temp ;
	}
	else
	{
		while(temp->next != NULL && temp->d != v)
		{
			prev = temp ;
			temp = temp->next ;
		}

		if(temp == NULL)
			return ;
		else
		{
			prev->next = temp->next ;
			delete temp ;
		}
	}
}

template <typename T>

void sll<T>::_insert(int p , T v)
{
	node *newnode = new node ;
	newnode->d = v ;
	newnode->next = NULL ;

	if(p == 0)
	{
		newnode->next = head ;
		head = newnode ;
	}
	else
	{
		node *temp ;
		temp = head ;

		for(auto i = 0 ; i < p -1 && temp->next != NULL ; i++) // skip segmentation fault by checking null temp-> next
		{
			temp = temp->next ;
		}
		newnode->next = temp->next ;
		temp->next = newnode ;
	}
}

template <typename T>

void sll<T>::_removeat(int p)
{
	node *temp = head ;
	if(head == NULL)
		return ;

	if(p == 0)
	{
		head = head->next ;
		delete temp ;
	}
	else
	{
		for(auto i = 0 ; i < p - 1 && temp->next != NULL ; i++)
		{
			temp = temp->next ;
		}

		if(temp->next == NULL)
			return ;

		node *temp2 = temp->next ;
		temp->next = temp->next->next ;
		delete temp2 ;
	}
}

template <typename T>

void sll<T>::_reverse()
{
	if(head == NULL)
		return ;
	else
	{
		node *prev = NULL ;
		node *curr = head ;
		node *next = NULL ;

		while(curr != NULL)
		{
			next = curr->next ;
			curr->next = prev ;
			prev = curr ;
			curr = next ;
		}

		head = prev ;
	}
}

template <typename T>

int sll<T>::_size()
{
	int s = 0 ;
	node *temp = head ;

	while(temp != NULL)
	{
		s += 1 ;
		temp = temp-> next ;
	}
	return s ;
}

int main(void)
{
	sll<char> l ;
	l._append('1') ;
	l._append('B') ;
	l._append('V') ;
	l._append('T') ;
	l._append('7') ;
	l._remove('T') ;
	l._insert(0 , '2') ;
	l._insert(3 , 'N') ;
	l._insert(9 , 'L') ;
	l._removeat(100) ;
	l._removeat(4) ;
	l._display() ;
	l._reverse() ;
	l._display() ;
	cout << "size : " << l._size() << endl ;
	return 0 ;
}
