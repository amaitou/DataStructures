

class node :

	def __init__(self , data = None) :
	
		self.data = data
		self.prev = None
		self._next = None

class doublylinkedlist :

	def __init__(self) :

		self.head = node()

	def _append(self , value) :

		newnode = node(value)
		if self.head == None :
			self.head = newnode
			return 
		temp = self.head
		while temp._next != None :
			temp = temp._next
		temp._next = newnode
		newnode.prev = temp

	def _display(self) :

		if self.head == None :
			return
		
		array = []
		temp = self.head
		while temp._next != None :
			temp = temp._next
			array.append(temp.data)

		return array

	def _size(self) :

		s = 0
		temp = self.head
		while temp._next != None :
			s += 1
			temp = temp._next

		return s

	def _insert(self , index , value) :

		newnode = node(value)
		if self.head == None :
			self.head = newnode
		else :
			temp = self.head
			for i in range(index + 1) :
				if temp == None :
					break
				else :
					temp = temp._next

			if temp == None :
				self._append(value)
			else :
				newnode.prev = temp.prev
				temp.prev._next = newnode
				temp.prev = newnode
				newnode._next = temp

	def _remove(self , value) : # remove by value

		if self.head == None :
			return
		temp = self.head
		if temp.data == value :
			self.head = temp.next
			if self.head != None :
				self.head.prev = None
				return

		while temp != None and temp.data != value :
			temp = temp._next

		if temp == None :
			return
		else :
			temp.prev._next = temp._next
			if temp._next != None :
				temp._next.prev = temp.prev

	def _removeat(self , index) : # remove by index

		if self.head == None :
			return
		temp = self.head
		for i in range(index + 1) :
			if temp == None :
				break
			else :
				temp = temp._next
		
		if temp == None :
			return
		else :
			temp.prev._next = temp._next
			if temp._next != None :
				temp._next.prev = temp.prev


	def _reverse(self) :

		array = []
		if self.head == None :
			return
		temp = self.head
		while temp._next != None :
			temp = temp._next
		while temp.prev != None :
			array.append(temp.data)
			temp = temp.prev

		return array



dl = doublylinkedlist()

dl._append(2)
dl._append(7)
dl._append(6)
dl._append(5)
dl._append(3)
dl._insert(9, 7)
dl._remove(3)
dl._removeat(1)

print(dl._display())
print(f"Size : {dl._size()}")
print(dl._reverse())