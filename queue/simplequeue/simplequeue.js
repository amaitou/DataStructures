/*
		Time complexity :

			access    : O(n)
			search    : O(n)
			insertion : O(1)
			delete    : o(1) 
*/

class queue
{
    constructor()
    {
        this.array = [] ;
        this.head = this.rear = -1 ;
        this.s = 0 ;
    }

    empty()
    {
        if(this.head === -1 && this.rear === -1)
        	return true ;
        else
        	return false ;
    }

    size()
    {
        return this.s;
    }

    enqueue(v)
    {
        if(this.empty())
            this.head = this.rear = 0 ;
        else
            this.rear++ ;
        this.array[this.rear] = v ;
        this.s++ ;
    }

    dequeue()
    {
        if(this.empty())
        {
            console.log("Empty Queue") ;
            return ;
        }
        else if(this.head === this.rear)
            this.head = this.rear = -1 ;
        else
            this.head++ ;
        this.s-- ;
    }

    front()
    {
        if(this.empty())
        {
            console.log("Empty Queue") ;
            return ;
        }
        return this.array[this.head] ;
    }

    traversal()
    {
        if(this.empty())
        {
            console.log("Empty Queue") ;
            return ;
        }
        while(! this.empty())
        {
            console.log(this.front()) ;
            this.dequeue() ;
        }
    }
}

let q = new queue() ;

q.enqueue(1) ;
q.enqueue(5) ;
q.enqueue(7) ;
q.dequeue() ;
q.enqueue(8) ;
console.log(q.size()) ;
q.traversal() ;
console.log(q.empty()) ;
