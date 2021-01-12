
class stack() :

	def __init__ (self) :

		self.array = []

	def push(self , value) :

		self.array.append(value)
 
	def pop(self) :

		if (self.isempty()) : return
		self.array.pop()

	def peek(self) :

		return self.array[-1]

	def isempty(self) :

		return len(self.array) == 0

	def show(self) :

		if self.isempty() : print("Empty stack")
		else :

			while (not self.isempty()) :

				print(self.peek() , end = " ")
				self.pop()

		print(" ")


def main() :

	def pair(open , close) :

		if open == '(' and close == ')' : return True
		elif open == '[' and close == ']' : return True
		elif open == '{' and close == '}' : return True
		else : return False

	def balanced(string) :

		_object = stack()

		for i in string :

			if i == '(' or i == '[' or i == '{' : _object.push(i)
			elif i == ')' or i == ']' or i == '}' :

				if (_object.isempty()) : return False
				elif not pair(_object.peek() , i) : return False
				else : _object.pop()

		if (_object.isempty()) : return True
		else : return False

	s = str(input("Enter Parenthese : "))

	return "Balanced" if balanced(s) else "Not Balanced"

if __name__ == '__main__': 

	print(main())
