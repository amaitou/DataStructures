<?php

    /*
        Time copmlexity :
		    access    : O(n)
		    delete    : O(1)
		    search    : O(n)
		    insertion : O(1) 
    */
    class stack
    {
        private $array = array() ;

        public function _empty()
        {
            return (count($this->array) == 0) ? true: false ;
        }

        public function _size()
        {
            return count($this->array) ;
        }

        public function _push($value)
        {
            array_push($this->array, $value) ;
        }

        public function _pop()
        {
            if($this->_empty())
                return ;
            array_pop($this->array) ;
        }

        public function _peek()
        {
            if($this->_empty())
                return ;
            return end($this->array) ;
        }

        public function _traversal()
        {
            if($this->_empty())
                return ;
            $temp = array() ;
            while(! $this->_empty())
            {
                array_push($temp, $this->_peek()) ;
                $this->_pop() ;
            }

            return $temp ;
        }
    }

    $s = new stack() ;
    
    $s->_push("L") ;
    $s->_push("e") ;
    $s->_push("l") ;
    $s->_push(" ") ;
    $s->_pop() ;
    $s->_push("o") ;
    $s->_push("u") ;
    $s->_push("(") ;
    $s->_pop() ;
    $s->_push("c") ;
    $s->_push("h") ;
    $s->_push("e") ;

    echo "top: " . $s->_peek() . "\n" ;
    echo "Size: " . $s->_size() . "\n" ;
    if(! $s->_empty())
        echo join("", $s->_traversal()) . "\n" ;
?>
