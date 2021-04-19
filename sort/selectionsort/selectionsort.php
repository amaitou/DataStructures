
<?php
	/*
		Time complexity  : O(n^2)
		Space complexity : O(1)
	*/
	function selectionsort($array)
	{
		$m = null ;
		for($i = 0; $i < count($array); ++$i)
		{
			$m = $i ;
			for($j = $i + 1; $j < count($array); ++$j)
			{
				if($array[$j] < $array[$m])
					$m = $j ;
			}
			if($m !== $i)
			{
				$temp = $array[$m] ;
				$array[$m] = $array[$i] ;
				$array[$i] = $temp ;
			}
		}
		return $array ;
	}
	$a = array(4 , 0 , 9 , 8 , 5 , 1 , 6 , 3 , 2 , 7) ;
	$r = selectionsort($a) ;
	print_r($r) ;
?>