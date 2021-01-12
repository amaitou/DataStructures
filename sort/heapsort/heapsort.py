
'''
	Time Complexity : O(Logn)
'''

def heapify(array , size , i) :

	left = 2 * i + 1
	right = 2 * i + 2
	mx = i

	if left < size and array[left] > array[mx] : mx = left
	if right < size and array[right] > array[mx] : mx = right
	if mx != i :
		temp = array[i]
		array[i] = array[mx]
		array[mx] = temp
		heapify(array , size , mx)


def buildheap(array , size) :

	for i in range(size // 2 - 1 , -1 , -1) :
		heapify(array, size, i)

def heapsort(array , size) :

	buildheap(array, size)
	for i in range(size - 1 , -1 , -1) :
		array[i], array[0] = array[0], array[i]
		heapify(array, i, 0)
	return array

a = [4 , 7 , 0 , 1 , 3 , 5 , 9 , 8 , 2 , 6]
print(heapsort(a, len(a)))
