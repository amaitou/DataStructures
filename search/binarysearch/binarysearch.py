
'''
	Time Complexity  : O(log n)
'''

def binarysearch(array , value) :

	left  = 0
	right = len(array) - 1

	while left <= right :
		middle = int((left + right) / 2)
		if array[middle] == value : 
			return middle
		elif array[middle] < value :
			left = middle + 1
		else :
			right = middle - 1

	return "Element Not Found"

a = [1 , 3 , 5 , 8 , 9 , 12 , 14 , 15]

print(binarysearch(a , 5))