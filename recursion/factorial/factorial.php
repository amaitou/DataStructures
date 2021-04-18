
<?php
    function factorial($value)
    {
        if($value <= 1)
            return 1 ;
        else
            return $value * factorial($value - 1) ;
    }

    echo factorial(5) . "<br>" ;
?>
