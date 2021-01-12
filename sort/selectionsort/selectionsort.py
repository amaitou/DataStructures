
'''
	Time complexity  : O(n^2)
	Space complexity : O(1)
'''

def selectionsort(array) :

	m = None
	for i in range(len(array)) :
		m = i
		for j in range(i + 1 , len(array)) :
			if array[m] > array[j] :
				m = j
	
		temp = array[m]
		array[m] = array[i]
		array[i] = temp

	return array

a = [4 , 0 , 9 , 8 , 5 , 1 , 6 , 3 , 2 , 7]
print(selectionsort(a))