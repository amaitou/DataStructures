
'''
	Time complexity  : O(n^2)
	Space complexity : O(1)
'''

def insertionsort(array) :

	key = None
	j = None

	for i in range(len(array)) :
		key = array[i]
		j = i - 1

		while j >= 0 and array[j] > key :
			array[j + 1] = array[j]
			j -= 1

		array[j + 1] = key

	return array

a = [3 , 9 , 7 , 6 , 0 , 1  , 5 , 4 , 2 , 8]
print(insertionsort(a))