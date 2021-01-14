
class node
{
	constructor(data = null)
	{
		this.data  = data ;
		this.left  = null ;
		this.right = null ; 
	}
}

class binarysearchtree
{
	constructor()
	{
		this.root = new node() ;
	}

	_append(value)
	{
		let newnode = new node(value) ;

		if(this.root.data === null)
			this.root = newnode ;
		else
		{
			let temp = this.root ;
			let parent = null ;

			while(temp !== null)
			{
				parent = temp ;
				if(value <= temp.data)
					temp = temp.left ;
				else
					temp = temp.right ;
			}

			if(value <= parent.data)
				parent.left = newnode ;
			else
				parent.right = newnode ;
		}
	}

	_min()
	{
		let temp = this.root ;
		while(temp.left !== null)
		{
			temp = temp.left ;
		}
		return temp.data ;
	}

	_max()
	{
		let temp = this.root ;
		while(temp.right !== null)
		{
			temp = temp.right ;
		}
		return temp.data ;
	}

	_breathfirst()
	{
		if(this.root === null)
			return ;

		let q = [] ,
			array = [] ;

		q.push(this.root) ;

		while(q.length !== 0)
		{
			let current = q.shift() ;
			array.push(current.data) ;
			
			if(current.left !== null)
				q.push(current.left) ;
			if(current.right !== null)
				q.push(current.right) ;
		}

		return array ;
	}

	_search(value)
	{
		if(this.root === null)
			return ;

		let temp = this.root ;

		while(temp !== null)
		{
			if(temp.data === value)
				return true ;
			else
			{
				if(value <= temp.data)
					temp = temp.left ;
				else
					temp = temp.right ;
			}
		}

		return false ;
	}

	_hight()
	{
		let _highthelper = temp =>
		{
			if(temp === null)
				return -1 ;
			else
			{
				var leftsubtree  = _highthelper(temp.left)  ;
				var rightsubtree = _highthelper(temp.right) ;
			}

			return 1 + Math.max(leftsubtree , rightsubtree) ;
		}

		if(this.root === null)
			return -1 ;
		else
			return _highthelper(this.root) ;
	}

	_postorder()
	{
		let s1 = [] ,
			s2 = [] ,
			array = [] ,
			temp = this.root ;

		s1.push(temp) ;

		while(s1.length !== 0)
		{
			temp = s1[s1.length - 1] ;
			s1.pop() ;
			s2.push(temp) ;

			if(temp.left)
				s1.push(temp.left) ;
			if(temp.right)
				s1.push(temp.right) ;
		}

		while(s2.length !== 0)
		{
			temp = s2[s2.length - 1] ;
			s2.pop() ;
			array.push(temp.data) ;
		}

		return array ;
	}

	_inorder()
	{
		if(this.root === null)
			return ;

		let temp  = this.root ,
			stack = [] ,
			array = [] ;

		while(temp !== null || stack.length !== 0)
		{
			while(temp !== null)
			{
				stack.push(temp) ;
				temp = temp.left ;
			}

			temp = stack[stack.length - 1] ;
			stack.pop() ;
			array.push(temp.data) ;
			temp = temp.right ;
		}

		return array ;
	}

	_preorder()
	{
		if(this.root === null)
			return ;

		let temp = this.root ,
			array = [] ,
			stack = [] ;

		while(temp !== null || stack.length !== 0)
		{
			while(temp !== null)
			{
				array.push(temp.data) ;
				if(temp.right)
					stack.push(temp.right) ;
				temp = temp.left ;
			}

			if(stack.length !== 0)
			{
				temp = stack[stack.length - 1] ;
				stack.pop() ;
			}
		}

		return array ;
	}
}

let bst = new binarysearchtree()

bst._append(15) ;
bst._append(6) ;
bst._append(3) ;
bst._append(9) ;
bst._append(8) ;
bst._append(20) ;
bst._append(25) ;
bst._append(30) ;
bst._append(40) ;

console.log(`Max    : ${bst._max()}`) ;
console.log(`Min    : ${bst._min()}`) ;
console.log(`Hight  : ${bst._hight()}`) ;
console.log(`Search : ${bst._search(30)}`) ;

console.log(bst._breathfirst()) ;
console.log(bst._postorder()) ;
console.log(bst._inorder()) ;
console.log(bst._preorder()) ;