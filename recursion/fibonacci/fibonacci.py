
def fibonacci(value) :

	return value if value <= 1 else fibonacci(value - 1) + fibonacci(value - 2)

print(fibonacci(20))