<?php

    /*
        Time complexity :

			access    : O(n)
			delete    : O(1)
			insertion : O(1)
			search    : O(n) 
    */

    class node
    {
        function __construct($data = null)
        {
            $this->_data = $data ;
            $this->_next = null ;
        }
    }

    class sll
    {
        function __construct()
        {
            $this->head = new node() ;
        }

        public function _empty()
        {
            return ($this->head == null) ? true: false ;
        }

        public function _size()
        {
            $temp = $this->head ;
            $s = 0 ;
            while($temp->_next != null)
            {
                $s++ ;
                $temp = $temp->_next ;
            }
            return $s ;
        }

        public function _append($value)
        {
            $newnode = new node($value) ;
            if($this->_empty())
            {
                $this->head = $newnode ;
                return ;
            }
            $temp = $this->head ;
            while(! $temp->_next == null)
            {
                $temp = $temp->_next ;
            }
            $temp->_next = $newnode ;
        }

        public function _remove($value)
        {
            if($this->_empty())
                return ;
            
            $temp = $this->head ;
            $prev = $this->head ;

            if($temp->_data == $value)
                $this->head = $this->head->_next ;
            
            else
            {
                while($temp->_data != $value && $temp->_next != null)
                {
                    $prev = $temp ;
                    $temp = $temp->_next ;
                }
                if($temp->_next == null)
                    return ;
                $prev->_next = $temp->_next ;
            }
        }

        public function _insert($index, $value)
        {
            $newnode = new node($value) ;
            if($this->_empty())
                $this->head = $newnode ;
            else
            {
                $temp = $this->head ;
                for($i = 0; $i < $index; ++$i)
                {
                    if($temp == null)
                        break ;
                    else
                        $temp = $temp->_next ;
                }
                $newnode->_next = $temp->_next ;
                $temp->_next = $newnode ;
            }
        }

        public function _removeat($index)
        {
            if($this->head == null)
                return ;
            if($index == 0)
                $this->head = $this->head->_next ;
            else
            {
                $temp = $this->head ;
                for($i = 0; $i < $index; ++$i)
                {
                    if($temp->_next == null)
                        break ;
                    else
                        $temp = $temp->_next ;
                }
                if($temp->_next == null)
                    return ;
                $temp->_next = $temp->_next->_next ;
            }
        }

        public function _reverse()
        {
            if($this->_empty())
               return ;
            $temp = $this->head->_next ;
            $prev = null ;
            $next = null ;

            while($temp != null)
            {
                $next = $temp->_next ;
                $temp->_next = $prev ;
                $prev = $temp ;
                $temp = $next ;
            }
            $this->head->_next = $prev ;
        }

        public function _traversal()
        {
            if($this->_empty())
                return ;
            $temp = $this->head ;
            $array = array() ;
            while($temp->_next != null)
            {
                $temp = $temp->_next ;
                array_push($array, $temp->_data) ;
            }
            return $array ;
        }
    }

    $l = new sll() ;
    
    $l->_append(10) ;
    $l->_append(15) ;
    $l->_append(12) ;
    $l->_append(20) ;
    $l->_append(11) ;
    $l->_remove(15) ;
    $l->_insert(0, 16) ;
    $l->_removeat(2) ;
    
    print_r($l->_traversal()) ;
    
    $l->_reverse() ;

    print_r($l->_traversal()) ;
    echo "Size: " . $l->_size() . "\n" ;
?>
