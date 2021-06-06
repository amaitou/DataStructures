<?php

    /*
        Time complexity :

			access    : O(n)
			search    : O(n)
			insertion : O(1)
			delete    : o(1) 
    */

    class queue
    {
        function __construct()
        {
            $this->array = array() ;
            $this->rear = -1 ;
            $this->head = -1 ;
            $this->size = 0 ;
        }

        public function _empty()
        {
            return ($this->rear == -1 && $this->head == -1) ? true: false;
        }

        public function _size()
        {
            return $this->size ;
        }

        public function _enqueue($value)
        {
            if($this->_empty())
            {
                $this->rear = 0 ;
                $this->head = 0 ;
            }
            else
                $this->rear++ ;
            $this->array[$this->rear] = $value ;
            $this->size++ ;
        }

        public function _dequeue()
        {
            if($this->_empty())
                return ;
            if($this->rear == $this->head)
            {
                $this->rear = -1 ;
                $this->head = -1 ;
            }
            else
                $this->head++ ;
            $this->size-- ;
        }

        public function _front()
        {
            if($this->_empty())
                return ;
            return $this->array[$this->head] ;
        }

        public function _traversal()
        {
            if($this->_empty())
                return ;
            $temp = array() ;
            while(! $this->_empty())
            {
                array_push($temp, $this->_front()) ;
                $this->_dequeue() ;
            }
            return $temp ;
        }
    }

    $q = new queue() ;
    
    $q->_dequeue() ;
    $q->_enqueue("s") ;
    $q->_enqueue("H") ;
    $q->_enqueue("e") ;
    $q->_dequeue() ;
    $q->_enqueue("l") ;
    $q->_enqueue("l") ;
    $q->_enqueue("o") ;

    echo "Front: " . $q->_front() . "\n" ;
    echo "Size: " . $q->_size() . "\n" ;
    echo join("", $q->_traversal()) . "\n" ;
?>
