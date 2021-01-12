


function binarysearch(array , value)
{
	let left  = 0 ;
	let right = array.length - 1 ;

	while(left <= right)
	{
		let middle = parseInt((right - left) / (array[right] - array[left]) * (value - array[left])) ;
		if(array[middle] === value)
			return middle ;
		else if(array[middle] < value)
			left = middle + 1
		else
			right = middle - 1
	}
	return "Element Not Found" ;
}

let a = [1 , 3 , 5 , 8 , 9 , 12 , 14 , 15] ;
console.log(binarysearch(a , 9)) ;