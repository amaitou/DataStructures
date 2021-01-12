
/*
		Time complexity :

			access    : O(n)
			delete    : O(1)
			insertion : O(1)
			search    : O(n) 
*/

class node
{
	constructor(data = null)
	{
		this.data = data
		this._next = null ;
	}
}

class linkedlist
{
	constructor()
	{
		this.head = new node() ;
	}

	_display()
	{
		let array = [] ;
		let temp = this.head ;
		while(temp._next !== null)
		{
			temp = temp._next ;
			array.push(temp.data) ;
		}
		return array ;
	}

	_append(value)
	{
		let newnode = new node(value) ;
		if(this.head === null)
		{
			this.head = newnode ;
			return ;
		}
		let temp = this.head ;
		while(temp._next !== null)
		{
			temp = temp._next ;
		}
		temp._next = newnode ;
	}

	_size()
	{
		let temp = this.head ;
		let s = 0 ;

		while(temp._next !== null)
		{
			temp = temp._next ;
			s++ ;
		}
		return s ;
	}

	_insert(index , value)
	{
		let newnode = new node(value) ;
		if(this.head === null)
		{
			this.head = newnode ;
			return ;
		}
		let temp = this.head ;
		for(let i = 0 ; i < index ; i++)
		{
			if( temp.next != null)
				break ;
			else
				temp = temp._next ;
		}
		newnode._next = temp._next ;
		temp._next = newnode ;
	}

	_remove(value)
	{
		if(this.head === null)
			return ;

		let prev = this.head ;
		let temp = this.head ;

		if(this.head.data == value)
		{
			this.head = this.head._next ;

		}
		else
		{
			while(temp.data != value && temp._next != null)
			{
				prev = temp ;
				temp = temp._next ;
			}
			if(temp == null)
				return ;
			prev._next = temp._next ;
		}
	}

	_removeat(index)
	{
		if(this.head === null)
			return ;
		if(index === 0)
		{
			this.head = this.head._next ;
			return ;
		}
		let temp = this.head ;

		for(let i = 0 ; i < index && temp._next != null ; i++)
		{
			temp = temp._next
		}
		if(temp._next === null)
			return ;
		temp._next = temp._next._next ;
	}

	_reverse()
	{
		if(this.head === null)
			return ;
		let prev = null ;
		let curr = this.head._next ;
		let _next = null ;

		while(curr != null)
		{
			_next = curr._next ;
			curr._next = prev ;
			prev = curr ;
			curr = _next ;
		}
		this.head._next = prev ;
	}

}

let l = new linkedlist() ;

l._append("A") ;
l._append("B") ;
l._append("C") ;
l._append("D") ;
l._append("E") ;
l._insert(1 , "F") ;
l._insert(6, "G") ;
l._remove("C") ;
l._removeat(5) ;
l._reverse() ;

console.log(l._display()) ;
console.log(l._size());