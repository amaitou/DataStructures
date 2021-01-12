
/*
	Time complexity  : O(n log n)
	Space complexity : O(n) 
*/

function merge(arr1, arr2)
{
  let result = [];
  let i = 0; 
  let j = 0;


  while(i < arr1.length && j < arr2.length)
  {
    if(arr1[i] > arr2[j])
    {
       result.push(arr2[j]);
       j++;
    } 
    else 
    {
       result.push(arr1[i]);
       i++;
    }
  }

  
  while(i < arr1.length)
  {
     result.push(arr1[i]);
     i++;
  }

  while(j < arr2.length)
  {
     result.push(arr2[j]);
     j++;
  }

  return result;
}

function mergesort(array)
{
	if(array.length <= 1) 
		return array;

   let halfPoint = Math.ceil(array.length / 2) ,
       firstHalf = mergesort(array.splice(0, halfPoint)) ,
       secondHalf = mergesort(array.splice(-halfPoint));

   return merge(firstHalf, secondHalf);
}

let a = [3 , 6 , 9 , 4 , 1 , 0 , 5 , 8 , 2 , 7 ] ;
console.log(mergesort(a)) ;