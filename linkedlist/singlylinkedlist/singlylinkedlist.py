
'''
		Time complexity :

			access    : O(n)
			delete    : O(1)
			insertion : O(1)
			search    : O(n) 
'''

class node :
	def __init__(self , data = None) :
		self.data = data
		self._next = None


class linkedlist :

	def __init__(self) :
		self.head = node()

	def _append(self , value) :

		newnode = node(value)
		if(self.head == None) :
			self.head = value
			return
		temp = self.head
		while(temp._next != None) :
			temp = temp._next
		temp._next = newnode

	def _display(self) :

		array = []
		temp = self.head
		while(temp._next != None) :
			temp = temp._next
			array.append(temp.data)
		return array

	def _size(self) :

		s = 0
		temp = self.head
		while(temp._next != None) :
			s += 1
			temp = temp._next
		return s

	def _insert(self , index , value) :

		newnode = node(value)
		if(self.head == None) :
			self.head = newnode
		else :
			temp = self.head
			for i in range(0 , index) :
				if temp._next == None :
					break
				else :
					temp = temp._next
			newnode._next = temp._next
			temp._next = newnode


	def _remove(self , value) :

		if self.head == None :
			return
		
		temp = self.head
		prev = self.head

		if self.head.data == value :
			self.head = self.head.next
		else :
			while(temp.data != value and temp._next != None) :
				prev = temp
				temp = temp._next

			if temp == None :
				return
			prev._next = temp._next

	def _removeat(self , index) :

		if self.head == None :
			return
		if index == 0 :
			self.head = self.head._next
		temp = self.head
		for i in range(0 , index) :
			if temp._next == None :
				break
			else :
				temp = temp._next
		if temp._next == None :
			return
		temp._next = temp._next._next

	def _reverse(self) :

		if self.head == None :
			return
		prev = None
		curr = self.head._next
		_next = None

		while curr != None :
			_next = curr._next
			curr._next = prev
			prev = curr
			curr = _next
		self.head._next = prev


l = linkedlist()

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

print(l._display())
print(l._size())