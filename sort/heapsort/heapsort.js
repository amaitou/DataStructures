
/*
	Time Complexity : O(Logn)
*/

function heapify(array , size , i)
{
	let left = 2 * i + 1 ;
	let right = 2 * i + 2 ;
	let max = i ;

	if(left < size && array[left] > array[max])
		max = left ;
	if(right < size && array[right] > array[max])
		max = right ;
	if(max !== i)
	{
		let temp = array[i] ;
		array[i] = array[max] ;
		array[max] = temp ;
		heapify(array , size , max);
	}
}

function builheap(array , size)
{
	for(let i = size / 2 - 1 ; i >= 0 ; i--)
		heapify(array , size , i) ;
}

function heapsort(array , size)
{
	builheap(array , size) ;
	for(let i = size - 1 ; i >= 0 ; i--)
	{
		let temp = array[0] ;
		array[0] = array[i] ;
		array[i] = temp ;
		heapify(array , i , 0) ;
	}
	return array ;
}

let a = [4 , 7 , 0 , 1 , 3 , 5 , 9 , 8 , 2 , 6] ;
console.log(heapsort(a , a.length)) ;