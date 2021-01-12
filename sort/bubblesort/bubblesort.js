
/*
		Time complexity  : O(n^2)
		Space complexity : O(1)
*/

function bubblesort(array)
{
	for(let i = 0 ; i < array.length ; i++)
	{
		for(let j = 0 ; j < array.length ; j++)
		{
			if(array[j] > array[j + 1])
			{
				let temp = array[j] ;
				array[j] = array[j + 1] ;
				array[j + 1] = temp ;
			}
		}
	}
	return array ;
}

let a = [8 , 2 , 5 , 7 , 0 , 9 , 4 , 6 , 1 , 3] ;
console.log(bubblesort(a)) ;