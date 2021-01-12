
def sequentialsearch(array , value) :

	for i in array :
		if i == value :
			return "Element Found at Index : " + str(array.index(i))
	return "Element Not Found"

a = [10 , 3 , 6 , 8 , 2 , 9 , 2 , 1 , 0 , 4 , 5]
print(sequentialsearch(a , 2))