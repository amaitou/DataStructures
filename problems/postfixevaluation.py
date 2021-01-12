class operation() :

	def __init__(self) : 
		self.array = []
	
	def push(self , value) :
		self.array.append(value)
	
	def pop(self) :

		if self.empty() :
			return
		self.array.pop()

	def peek(self) :
		return self.array[-1]
	
	def empty(self) :
		return len(self.array) == 0

stack = operation()

def priority(operator) :

	if operator == '+' or operator == '-' : return 1
	elif operator == '/' or operator == '*' : return 2
	elif operator == '^': return 3
	else : return 0

def digito4alpha(character) :

	if ((ord(character) >= 48 and ord(character) <= 57) or (ord(character) >= 65 and ord(character) <= 90) or (ord(character) >= 97 and ord(character) <= 122)) :
		return True
	
	else :
		return False

def math(firstoperand , secondoperand , symbol) :

	if symbol == '+' : return firstoperand + secondoperand
	elif symbol == '-' : return firstoperand - secondoperand
	elif symbol == '*' : return firstoperand * secondoperand
	elif symbol == '/' : return firstoperand / secondoperand
	else : return 0

def infix2postfix(expression) :

	output = ""

	for i in expression :

		if i == ' ' :
			continue

		elif i == '(' :
			stack.push(i)

		elif digito4alpha(i) :
			output += i

		elif i == ')' :

			while not stack.empty() and (stack.peek() != '(') :

				output += stack.peek()
				stack.pop()

			stack.pop()

		else :

			while not stack.empty() and priority(i) <= priority(stack.peek()) :

				output += stack.peek()
				stack.pop()

			stack.push(i)

	while not stack.empty() :

		output += stack.peek()
		stack.pop()

	return output


def evaluation(postfix) :

	for i in postfix :

		if i == ' ' :
			continue

		elif digito4alpha(i) :
			stack.push(int(i))

		else :

			secondoperand = stack.peek()
			stack.pop()
			firstoperand = stack.peek()
			stack.pop()
			result = math(firstoperand , secondoperand , i)
			stack.push(result)

	return stack.peek()

def main() :

	_expression = "(3+2)+7/2*((7+3)*2)"		# (3+2)+7/2*((7+3)*2)
	_postfix = infix2postfix(_expression)	# 32+72/73+2**+
	_value = evaluation(_postfix)			# 75.0 

	print("Infix   : " , _expression)
	print("Postfix : " , _postfix)
	print("Value   : " , _value)

if __name__ == '__main__':
	main()

