

<?php
    function fib($value)
    {
        if($value === 0 || $value === 1)
            return $value ;
        else
            return fib($value - 1) + fib($value - 2) ;
    }

    echo fib(10) . "<br>" ;
?>
