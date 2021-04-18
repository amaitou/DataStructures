
<?php
    function sequentialsearch($array, $value)
    {
        foreach($array as $item)
        {
            if($item === $value)
                return "Element Found At Index: " . array_search($value, $array, true);
        }
        return "Element Not Found" ;
    }

    $a = array(10, 3, 6, 8, 2, 9, 2, 1, 0, 4, 5) ;
    echo sequentialsearch($a, 9) ;
?>
