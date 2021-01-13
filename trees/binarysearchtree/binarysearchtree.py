
class node :

	def __init__(self , data = None) :

		self.data  = data
		self.left  = None
		self.right = None


class binarysearchtree :

	def __init__(self) :

		self.root = node()


	def _append(self , value) :
	
		newnode = node(value)
		if self.root.data == None :
			self.root = newnode
			return

		temp = self.root
		parent = None

		while temp != None :

			parent = temp
			if value <= temp.data :
				temp = temp.left
			else :
				temp = temp.right

		if value <= parent.data :
			parent.left = newnode
		else :
			parent.right = newnode

	def _max(self) :

		temp = self.root
		while temp.right != None :
			temp = temp.right

		return temp.data

	def _min(self) :

		temp = self.root
		while temp.left != None :
			temp = temp.left

		return temp.data

	def _breathfirst(self) :

		if self.root == None :
			return

		q = []
		array = []
		q.append(self.root)

		while len(q) != 0 :
			current = q[0]
			array.append(current.data)

			q.pop(0)

			if current.left != None :
				q.append(current.left)
			if current.right != None :
				q.append(current.right)

		return array


	def _search(self , value) :

		if self.root == None :
			return
		temp = self.root
		while temp != None :
			if temp.data == value :
				return True
			else :
				if value <= temp.data :
					temp = temp.left
				else :
					temp = temp.right

		return False

	def _hight(self) :

		def _highthelper(temp) :
			if temp == None:
				return -1
			else :
				leftsubtree  = _highthelper(temp.left)
				rightsubtree = _highthelper(temp.right)

			return 1 + max(leftsubtree, rightsubtree)

		if self.root == None :
			return -1
		else :
			return _highthelper(self.root)

	def _postorder(self) :

		s1 = []
		s2 = []
		array = []

		temp = self.root

		s1.append(temp)

		while len(s1) != 0 :

			temp = s1[-1]
			s1.pop()
			s2.append(temp)

			if temp.left :
				s1.append(temp.left)
			if temp.right :
				s1.append(temp.right)

		while len(s2) != 0 :

			temp = s2[-1]
			s2.pop()
			array.append(temp.data)

		return array

	def _inorder(self) :

		if self.root == None :
			return

		temp = self.root
		stack = []
		array = []

		while temp != None or not len(stack) == 0 :

			while temp != None :

				stack.append(temp)
				temp = temp.left

			temp = stack[-1]
			stack.pop()
			array.append(temp.data)
			temp = temp.right

		return array

	def _preorder(self) :

		if self.root == None :
			return

		stack = []
		array = []
		temp = self.root

		while temp != None or not len(stack) == 0 :
			while temp != None :
				array.append(temp.data)
				if temp.right :
					stack.append(temp.right)
				temp = temp.left
			if not len(stack) == 0 :
				temp = stack[-1]
				stack.pop()

		return array 

bst = binarysearchtree()

bst._append(15)
bst._append(6)
bst._append(3)
bst._append(9)
bst._append(8)
bst._append(20)
bst._append(25)
bst._append(30)
bst._append(40)



print(f"Max    : {bst._max()}")
print(f"Min    : {bst._min()}")
print(f"Hight  : {bst._hight()}")
print(f"Search : {bst._search(6)}")

print(bst._breathfirst())
print(bst._postorder())
print(bst._inorder())
print(bst._preorder())

