

/*
	Time complexity : O(√n)
*/

function jumpsearch(array , size , value)
{
	let step = Math.sqrt(size) ;
		prev = 0 ;

	while(array[parseInt(Math.min(step , size)  - 1)] < value)
	{
		prev = step ;
		step += Math.sqrt(size) ;
		if(prev >= size)
			return "Element Not Found" ;
	}

	while(array[parseInt(prev)] < value)
	{
		prev++ ;
		if(prev === Math.min(step , size))
			return "Element Not Found" ;
	}

	if(array[parseInt(prev)] == value)
	{
		return parseInt(prev) ;
	}
	return "Element Not Found" ;
}

let a = [12 , 20 , 33 , 45 , 78 , 99] ;

console.log(jumpsearch(a , a.length , 78)) ;