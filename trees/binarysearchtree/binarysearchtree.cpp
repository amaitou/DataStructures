
#include <bits/stdc++.h>

using namespace std ;

template <typename T>

class bst
{
	private :

		struct node
		{
			T d ;
			node *left ;
			node *right ;
		} ;

		node *root = nullptr ;
		int _highthelper(node *temp)
		{
			if(temp == nullptr) // empty sub tree
				return -1 ;

			int leftsubtree = _highthelper(temp->left) ;
			int rightsubtree = _highthelper(temp->right) ;

			return 1 + max(leftsubtree , rightsubtree) ;
		}

		void _postorderhelper(node *temp)
		{
			if(temp == nullptr)
				return ;
			_postorderhelper(temp->left) ;
			_postorderhelper(temp->right) ;
			cout << temp->d << " " ;
		}

	public :

		void _append(T v) ;
		int _max() ;
		int _min() ;
		int _hight() ;
		void _breathfirst() ;
		void _postorder() ;
		void _inorder() ;
		void _preorder() ;
		bool _search(T v) ;
} ;

template <typename T>

void bst<T>::_append(T v) // leaf node (last node on a tree)
{
	node *newnode = new node ;
	newnode->d = v ;
	newnode->left = nullptr ;
	newnode->right = nullptr ;

	if(root == nullptr)
	{
		root = newnode ;
		return ;
	}
	else
	{
		node *temp = root ;
		node *parent = nullptr ;

		while(temp != nullptr)
		{
			parent = temp ;
			if(v <= temp->d)
				temp = temp->left ;
			else
				temp = temp->right ;
		}

		if(v <= parent->d)
			parent->left = newnode ;
		else
			parent->right = newnode ;
	}
}

template <typename T>

int bst<T>::_max()
{
	node *temp = root ;

	while(temp->right != nullptr)
		temp = temp->right ;

	return temp->d ;
}

template <typename T>

int bst<T>::_min()
{
	node *temp = root ;

	while(temp->left != nullptr)
		temp = temp->left ;

	return temp->d ;
}

template <typename T>

int bst<T>::_hight()
{
	if(root == nullptr)
		return -1 ;
	else
		return _highthelper(root) ;
}

template <typename T>

void bst<T>::_breathfirst()
{
	if(root == nullptr)
		return ;
	else
	{
		queue<node *> q ;
		q.push(root) ;

		cout << "[ " ;
		while(! q.empty())
		{
			node *current = q.front() ;

			cout << current->d << " " ;

			q.pop() ;

			if(current->left != nullptr)
				q.push(current->left) ;
			if(current->right != nullptr)
				q.push(current->right) ;
		}
		cout << "]" << endl ;
	}
}

template <typename T>

void bst<T>::_postorder()

{
	if (root != nullptr)
		cout << "[ " ;
		_postorderhelper(root) ;
		cout << "]" << endl ;
}

template <typename T>

void bst<T>::_inorder()
{
	if(root == nullptr)
		return ;

	node *temp = root ;
	stack<node*> s ;

	cout << "[ " ;
	while(temp != nullptr || ! s.empty())
	{
		while(temp != nullptr)
		{
			s.push(temp) ;
			temp = temp->left ;
		}

		temp = s.top() ;
		s.pop() ;
		cout << temp->d << " " ;
		temp = temp->right ;
	}
	cout << "]" << endl ;
}

template <typename T>

void bst<T>::_preorder()
{
	if(root == nullptr)
		return ;

	stack<node*> s ;
	node *temp = root ;

	s.push(temp) ;

	cout << "[ " ;
	while(temp != nullptr and s.empty() == false)
	{
		while(temp != nullptr)
		{
			cout << temp->d << " " ;
			if(temp->right)
				s.push(temp->right) ;
			temp = temp->left ;
		}

		if(s.empty() == false)
		{
			temp = s.top() ;
			s.pop() ;
		}
	}
	cout << "]" << endl ;
}

template <typename T>

bool bst<T>::_search(T v)
{
	if(root == nullptr)
		return false ;
	else
	{
		node *temp = root ;
		while(temp != nullptr)
		{
			if(temp->d == v)
				return true ;
			else
			{
				if(temp->d >= v)
					temp = temp->left ;
				else
					temp = temp->right ;
			}
		}
	}
	return false ;
}

int main(void)
{
	bst<int> t ;

	t._append(15) ;
	t._append(6) ;
	t._append(3) ;
	t._append(9) ;
	t._append(8) ;
	t._append(20) ;
	t._append(25) ;
	cout << "min    : " << t._min() << endl ;
	cout << "max    : " << t._max() << endl ;
	cout << "hight  : " << t._hight() << endl ;
	cout << "search : " << t._search(25) << endl ;
	t._breathfirst() ;
	t._postorder() ;
	t._inorder() ;
	t._preorder() ;
	return 0 ;
}