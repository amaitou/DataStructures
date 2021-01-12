
/*
		Time complexity  : O(n^2)
		Space complexity : O(1)
*/

function insertionsort(array)
{
	let key = null ;
		j = null ;

	for(let i = 0 ; i < array.length ; i++)
	{
		key = array[i] ;
		j = i - 1 ;

		while(j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j] ;
			j-- ;
		}
		array[j + 1] = key ;
	}
	return array ;
}

let a = [3 , 9 , 7 , 6 , 0 , 1  , 5 , 4 , 2 , 8 , 10] ;
console.log(insertionsort(a)) ;