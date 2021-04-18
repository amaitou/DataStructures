
<?php
    function binarysearch($array, $value)
    {
        $left = 0 ;
        $right = count($array) - 1;

        while($left <= $right)
        {
            $middle = intval(($right - $left) / ($array[$right] - $array[$left]) * ($value - $array[$left])) ;
            if($array[$middle] === $value)
                return $middle ;
            else if($array[$middle] < $value)
                $left = $middle + 1 ;
            else
                $right = $middle - 1 ;
        }

        return "Element Not Found" ;
    }

    $a = array(1, 3, 5, 8, 9, 12, 14, 15) ;
    echo binarysearch($a, 5) ;
?>
