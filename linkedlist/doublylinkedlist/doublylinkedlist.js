


class node
{
	constructor(data = null)
	{
		this.data = data ;
		this.prev = null ;
		this._next = null ;
	}
}

class doublylinkedlist
{
	constructor()
	{
		this.head = new node() ;
	}

	_append(value)
	{
		let nenwnode = new node(value) ;
		if(this.head === null)
		{
			this.head = nenwnode ;
			return ;
		}

		let temp = this.head ;

		while(temp._next !== null)
			temp = temp._next ;
		temp._next = nenwnode ;
		nenwnode.prev = temp ;
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

	_size()
	{
		let s = 0 ;
		let temp = this.head ;
		while(temp._next != null)
		{
			s++ ;
			temp = temp._next ;
		}

		return s ;
	}

	_insert(index , value)
	{
		let newnode = new node(value) ;
		if(this.head === null)
			this.head = newnode ;
		else
		{
			let temp = this.head ;
			for(let i = 0 ; i < index + 1 && temp !== null ; i++)
			{
				temp = temp._next ;
			}
			if(temp === null)
				this._append(value) ;
			else
			{
				newnode.prev = temp.prev ;
				temp.prev._next = newnode ;
				temp.prev = newnode ;
				newnode._next = temp ;
			}
		}
	}

	_remove(value)
	{
		if(this.head === null)
			return ;
		else
		{
			let temp = this.head ;
			while(temp.data != value && temp !== null)
			{
				temp = temp._next ;
			}

			if(temp == null)
				return ;
			else
			{
				temp.prev._next = temp._next ;
				if(temp._next != null)
					temp._next.prev = temp.prev ;
			}
		}
	}

	_removeat(index)
	{
		if(this.head === null)
			return ;
		else
		{
			let temp = this.head ;
			for(let i = 0 ; i < index + 1 && temp !== null ; i++)
			{
				temp = temp._next ;
			}

			if(temp === null)
				return ;
			else
			{
				temp.prev._next = temp._next ;
				if(temp._next != null)
					temp._next.prev = temp.prev ;
			}
		}
	}

	_revetse()
	{
		let array = [] ;
		if(this.head === null)
			return ;
		let temp = this.head ;

		while(temp._next !== null)
			temp = temp._next ;
		while(temp.prev !== null)
		{
			array.push(temp.data) ;
			temp = temp.prev ;
		}

		return array ;
	}
}

let dl = new doublylinkedlist() ;

dl._append(2)
dl._append(7)
dl._append(6)
dl._append(5)
dl._append(3)
dl._insert(9, 7)
dl._remove(3)
dl._removeat(1)

console.log(dl._display()) ;
console.log(`Size : ${dl._size()}`) ;
console.log(dl._revetse()) ;