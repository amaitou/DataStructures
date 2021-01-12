
#include <iostream>

using namespace std ;

template <typename T>

class dll
{
	private :

		struct node
		{
			T d ;
			node *next = nullptr ;
			node *prev = nullptr ;
		} ;

		node *head = nullptr ;

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

void dll<T>::_display()
{
	if(head == nullptr)
		return ;
	else
	{
		node *temp = head ;
		cout << "[ " ;
		while(temp != nullptr)
		{
			cout << temp->d << " " ;
			temp = temp->next ;
		}
		cout << "]" << endl ;
	}
}

template <typename T>

void dll<T>::_append(T v)
{
	node *newnode = new node ;
	newnode->d = v ;
	if(head == nullptr)
		head = newnode ;
	else
	{
		node *temp = head ;
		while(temp->next != nullptr)
		{
			temp = temp->next ;
		}
		temp->next = newnode ;
		newnode->prev = temp ;
	}
}

template <typename T>

int dll<T>::_size()
{
	int s = 0 ;
	if(head == nullptr)
		return s ;
	else
	{
		node *temp = head ;
		while(temp != nullptr)
		{
			temp = temp->next ;
			s++ ;
		}
	}
	return s ;
}

template <typename T>

void dll<T>::_insert(int p , T v)
{
	node *newnode = new node ;
	newnode->d = v ;

	if(head == nullptr)
	{
		head = newnode ;
		return ;
	}

	if(p == 0)
	{
		newnode->next = head ;
		head->prev = newnode ;
		head = newnode ;
	}
	else
	{
		node *temp = head ;
		for(int i = 0 ; i < p && temp != nullptr ; i++)
		{
			temp = temp->next ;
		}

		if(temp == nullptr)
			this->_append(v) ;
		else
		{
			newnode->prev = temp->prev ;
			temp->prev->next = newnode ;
			temp->prev = newnode ;
			newnode->next = temp ;
		}
	}
}
template <typename T>

void dll<T>::_remove(T v)
{
	if(head == nullptr)
		return ;
	else
	{
		node *temp = head ;
		if(temp->d == v)
		{
			head = temp->next ;
			if(head != nullptr)
				head->prev = nullptr ;
				delete temp ;
				return ;
		}
		while(temp != nullptr && temp->d != v)
		{
			temp = temp->next ;
		}
		if(temp == nullptr)
			return ;
		else
		{
			temp->prev->next = temp->next ;
			if(temp->next != nullptr)
				temp->next->prev = temp->prev ;
			delete temp ;
		}
	}
}

template <typename T>

void dll<T>::_removeat(int p)
{
	if(head == nullptr)
		return ;

	else
	{
		node *temp = head ;
		if(p == 0)
		{
			head = temp->next ;
			if(head != nullptr)
				head->prev = nullptr ;
				delete temp ;
				return ;
		}
		for(int i = 0 ; i < p and temp != nullptr ; i++)
		{
			temp = temp->next ;
		}
		if(temp == nullptr)
			return ;
		else
		{
			temp->prev->next = temp->next;
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			delete temp;
		}
	}
}

template <typename T>

void dll<T>::_reverse()
{
	if(head == nullptr)
		return ;
	else
	{
		node *temp = head ;
		while(temp->next != nullptr)
		{
			temp = temp->next ;
		}
		cout << "[ " ;
		while(temp != nullptr)
		{
			cout << temp->d << " " ;
			temp = temp->prev ;
		}
		cout << "]" << endl ;
	}
}

int main(void)
{
	dll<char> d ;

	d._append('A') ;
	d._append('B') ;
	d._append('C') ;
	d._append('D') ;
	d._insert(0 , 'E') ;
	d._display() ;
	d._remove('B') ;
	d._removeat(4) ;
	d._display() ;
	d._reverse() ;
	d._display() ;

	cout << "Size : " << d._size() << endl ;
	return 0 ;
}