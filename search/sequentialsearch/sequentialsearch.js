
function sequentialsearch(array , value)
{
	for(let i = 0 ; i < array.length ; i++)
	{
		if(array[i] === value)
		{
			return `Element found at Index : ${i}` ;
		}
	}
	return "Element not found" ;
}

let a = [10 , 3 , 6 , 8 , 2 , 9 , 2 , 1 , 0 , 4 , 5] ;
console.log(sequentialsearch(a , 9)) ; 