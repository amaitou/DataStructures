
<?php
    /*
		Time complexity  : O(n^2)
		Space complexity : O(1)
    */

    function insertionsort($array, $size)
    {
        $key ; $j ;
        for($i = 1; $i < $size; ++$i)
        {
            $key = $array[$i] ;
            $j = $i - 1 ;

            while($j >= 0 && $array[$j] > $key)
            {
                $array[$j + 1] = $array[$j] ;
                $j-- ;
            }
            $array[$j + 1] = $key ;
        }
        return $array ;
    }

    $a = array(23 , 22 , 29 , 21 , 26 , 24 , 28 , 27 , 25) ;
    print_r(insertionsort($a, count($a))) ;
?>
