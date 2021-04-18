<?php
    /*
		Time complexity  : O(n^2)
		Space complexity : O(1)
    */

    function bubblesort($array, $size)
    {
        for($i = 0; $i < $size; $i++)
        {
            for($j = 0; $j < $size; ++$j)
            {
                if($array[$j] > $array[$j + 1])
                {
                    $temp = $array[$j] ;
                    $array[$j] = $array[$j + 1] ;
                    $array[$j + 1] = $temp ;
                }
            }
        }
        return $array ;
    }

    $a = array(8 , 2 , 5 , 7 , 0 , 9 , 4 , 6 , 1 , 3) ;
    print_r(bubblesort($a, count($a))) ;
?>
