
/*

	Note : Array in Javascript can be used as stack

	Time copmlexity :

		access    : O(n)
		delete    : O(1)
		search    : O(n)
		insertion : O(1) 

*/

class stack
{
	constructor()
	{
		this.array = [] ;
		this.top = -1 ;
	}

	_empty()
	{
		if(this.top === -1)
			return true ;
		return false ;
	}

	_push(value)
	{
		this.top++ ;
		this.array[this.top] = value ;

	}

	_pop()
	{
		if(this._empty())
		{
			console.log("Empty Stack") ;
		}
		else
		{
			this.top-- ;
		}
	}

	_peek()
	{
		return this.array[this.top] ;
	}

	_display()
	{
		var c = this.top ;
		while(c >= 0)
		{
			console.log(this.array[c]) ;
			c-- ;
		}
	}

	_length()
	{
		return this.top + 1 ;
	}
}

var s = new stack() ;

s._push(1) ;
s._push(2) ;
s._pop() ;
s._push(3) ;
s._push(4) ;
s._pop() ;
s._push(5) ;
s._push(6) ;
s._push(7) ;
s._pop() ;
s._display() ;

console.log("Size : " + s._length()) ;
