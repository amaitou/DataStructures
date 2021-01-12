
'''

	Note : Array in python can be used as stack

	Time copmlexity :

		access    : O(n)
		delete    : O(1)
		search    : O(n)
		insertion : O(1) 

'''

class stack :

	def __init__(self) :

		self.array = []

	def _empty(self) :

		return True if len(self.array) == 0 else False

	def _push(self , value) :

		self.array.append(value)

	def _pop(self) :

		if self._empty() :
			print("Empty Stack")
		else :
			return self.array.pop()

	def _peek(self) :

		return self.array[-1] if not self._empty() else "Error : Empty Stack"

	def _size(self) :

		return len(self.array)

	def _display(self) :

		if self._empty() :
			print("Empty Stack")
		else :
			while not self._empty() :
				print(self._peek())
				self._pop()

s = stack()

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

print(f"Size : {s._size()}")

s._display() ;