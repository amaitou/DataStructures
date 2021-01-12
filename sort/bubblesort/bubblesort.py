
'''
		Time complexity  : O(n^2)
		Space complexity : O(1)
'''

def bubblesort(array) :

	for i in range(len(array) + 1) :
		for j in range(0 , len(array) - i - 1) :
			if array[j] > array[j + 1] :
				array[j], array[j+1] = array[j+1], array[j]
	return array

a = [8 , 2 , 5 , 7 , 0 , 9 , 4 , 6 , 1 , 3]
print(bubblesort(a))