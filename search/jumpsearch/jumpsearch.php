

<?php
    function jumpsearch($array, $size, $value)
    {
        $step = sqrt($size) ;
        $prev = 0 ;

        while($array[intval(min($step, $size) - 1)] < $value)
        {
            $prev = $step ;
            $step += sqrt($size) ;
            if($prev >= $size)
                return 'Element Not Found' ;
        }

        while($array[intval($prev)] < $value)
        {
            $prev++ ;
            if($prev === min($step, $size))
                return "Element Not Found" ;
        }

        if($array[intval($prev)] === $value)
        {
            return intval($prev) ;
        }

        return "Element Not Found" ;
    }

    $a = array(12, 20, 44, 46, 70, 99) ;

    echo jumpsearch($a, count($a), 70) ;
?>
