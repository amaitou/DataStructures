<?php

    class node
    {
        function __construct($data = null)
        {
            $this->_data = $data ;
            $this->_prev = null ;
            $this->_next = null ;
        }
    }

    class dll
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
                $temp = $temp->_next ;
                $s++ ;
            }
            return $s ;
        }

        public function _append($value)
        {
            $newnode = new node($value) ;
            if($this->_empty())
                $this->head = $newnode ;
            else
            {
                $temp = $this->head ;
                while($temp->_next != null)
                    $temp = $temp->_next ;
                $temp->_next = $newnode ;
                $newnode->_prev = $temp ;
            }
        }

        public function _remove($value)
        {
            if($this->_empty())
                return ;
            $temp = $this->head ;
            if($temp->_data == $value)
            {
                $this->head = $temp->_next ;
                if($this->head != null)
                {
                    $this->head->_prev = null ;
                    return ;
                }
            }
            while($temp->_data != $value && $temp != null)
                $temp = $temp->_next ;
            if($temp == null)
                return ;
            $temp->_prev->_next = $temp->_next ;
            if($temp->_next != null)
                $temp->_next->_prev = $temp->_prev ;
        }

        public function _insert($index, $value)
        {
            $newnode = new node($value) ;
            if($this->_empty())
                $this->head = $newnode ;
            else
            {
                $temp = $this->head ;
                for($i = 0; $i < $index + 1 && $temp != null ; ++$i)
                {
                    $temp = $temp->_next ;
                }
                if($temp == null)
                {
                    $this->_append($value) ;
                    return ;
                }
                $newnode->_prev = $temp->_prev ;
                $temp->_prev->_next = $newnode ;
                $temp->_prev = $newnode ;
                $newnode->_next = $temp ;
            }
        }

        public function _removeat($index)
        {
            if($this->_empty())
                return ;
            $temp = $this->head ;
            for($i = 0; $i < $index + 1 && $temp != null; ++$i)
                $temp = $temp->_next ;
            if($temp == null)
                return ;
            $temp->_prev->_next = $temp->_next ;
            if($temp->_next != null)
                $temp->_next->_prev = $temp->_prev ;
        }

        public function _reverse()
        {
            if($this->_empty())
                return ;
            $temp = $this->head ;
            while($temp->_next != null)
                $temp = $temp->_next ;
            $array = array() ;
            while($temp->_prev != null)
            {
                array_push($array, $temp->_data) ;
                $temp = $temp->_prev ;
            }
            return $array ;
        }

        public function _traversal()
        {
            if($this->_empty())
                return ;
            $temp = $this->head ;
            $array = array() ;
            while(! $temp->_next == null)
            {
                $temp = $temp->_next ;
                array_push($array, $temp->_data) ;
            }
            return $array ;
        }
    }

    $d = new dll() ;
    
    $d->_append(14) ;
    $d->_append(25) ;
    $d->_append(69) ;
    $d->_append(32) ;
    $d->_append(17) ;
    $d->_append(45) ;
    $d->_remove(25) ;
    $d->_insert(4, 16) ;
    $d->_removeat(4) ;

    echo "Size: " . $d->_size() . "\n" ;
    print_r($d->_traversal()) ;
    print_r($d->_reverse()) ;
?>
