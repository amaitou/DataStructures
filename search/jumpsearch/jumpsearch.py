from math import sqrt

'''
	Time complexity : O(√n)
'''

def jumpsearch(array , size , value) :
	
	step = sqrt(size)
	prev = 0

	while array[int(min(step , size) - 1)] < value  :
		prev = step
		step += sqrt(size)
		if prev >= size :
			return "Element Not Found"

	while array[int(prev)] < value :
		prev += 1
		if  prev == min(step, size) :
			return "Element Not Found"

	if array[int(prev)] == value :
		return int(prev)

	return "Element Not Found"


a = [12 , 20 , 33 , 45 , 78 , 99]

index = jumpsearch(a , len(a) , 20)

if isinstance(index, int) :
	print(f"Element Found At Index : {index}")
else :
	print(index)