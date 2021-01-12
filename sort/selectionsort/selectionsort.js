

/*
		Time complexity  : O(n^2)
		Space complexity : O(1)
*/

function selectionsort(array)
{
	let m = null ;
	for(let i = 0 ; i < array.length ; i++)
	{
		m = i ;
		for(let j = i + 1 ; j < array.length ; j++)
		{
			if(array[j] < array[m])
				m = j ;
		}
		if (m != i)
		{
			let temp = array[m] ;
			array[m] = array[i] ;
			array[i] = temp ;
		}
	}	
	return array ;
}

let a = [4 , 0 , 9 , 8 , 5 , 1 , 6 , 3 , 2 , 7] ;
console.log(selectionsort(a)) ;