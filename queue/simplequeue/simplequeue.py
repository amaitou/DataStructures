
'''
	Time complexity :

		access    : O(n)
		search    : O(n)
		insertion : O(1)
		delete    : o(1) 
'''

class queue :

	def __init__(self) :
		self.array = []

	def _empty(self) :
		return True if len(self.array) == 0 else False

	def _size(self) :
		return len(self.array)

	def _enqueue(self , value) :

		self.array.append(value)

	def _dequeue(self) :

		return self.array.pop(0) if not self._empty() else "Empty Queue"

	def _front(self) :

		return self.array[0] if not self._empty() else "Empty Queue"

	def _display(self) :

		for i in self.array :
			print(i , end = " ")
		print("")

q = queue()
q._enqueue(3)
q._enqueue(4)
q._enqueue(5)
q._enqueue(6)
q._dequeue()
q._enqueue(7)
q._dequeue()

print(f"Size : {q._size()}")

q._display()
