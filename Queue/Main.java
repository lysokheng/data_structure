/** Represents a student.
 * @author Huot Lysokheng
 * @author huot.lysokheng@gmail.com
 * Date: 11/02/2022
 * Homework 6 - Q
 * Year2_Semester1
 */

/**
 * Queue operation
 */
class Queue
{
    private int maxSize;
    private int[] queArray;
    private int front;
    private int rear;
    private int nItems;

    /**
     * constructor
     * @param s
     */
    public Queue(int s)
    {
        maxSize = s;
        queArray = new int[maxSize];
        front = 0;
        rear = -1;      // Since queArray is initially empty
        nItems = 0;
    } // end method Queue

    /**
     * true if queue is empty
     * @return
     */
    public boolean isEmpty()
    {
        return (nItems==0);
    } // end method isEmpty

    /**
     * true if queue is full
     * @return
     */
    public boolean isFull()
    {
        return (nItems==maxSize);
    } // end method isFull

    /**
     * put item at rear of queue
     * @param j
     */
    public void insert(int j)
    {
        if (isFull()) {
            System.out.print("ERROR -- QUEUE OVERFLOW");
        }
        else {
            if(rear == maxSize-1)         // deal with wraparound (Ring Buffer)
                rear = -1;
            rear = rear + 1;
            queArray[rear] = j;           // increment rear and insert
            nItems++;                     // one more item
        }
    } // end method insert

    /**
     * take item from front of queue
     * @return
     */
    public int remove()
    {
        if (isEmpty()) {
            System.out.print("ERROR -- QUEUE UNDERFLOW");
            return -1;
        }
        else {
            int temp = queArray[front];   // get value and increase front
            front = front + 1;
            if(front == maxSize)          // deal with wraparound
                front = 0;
            nItems--;                     // one less item
            return temp;
        }
    } // end method remove

    /**
     * peek at front of queue
     * @return
     */
    public int peekFront()
    {
        return queArray[front];
    } // end method peekFront

    /**
     * number of items in queue
     * @return
     */
    public int size()
    {
        return nItems;
    } // end method size
/////////////////////////////////////////////////////////////////
}  // end class Queue
////////////////////////////////////////////////////////////////

/**
 * driver program
 */
class Main
{
    public static void main(String[] args)
    {
        Queue theQueue = new Queue(5);  // queue holds 5 items
        int x;

        theQueue.insert(10);            // insert 4 items
        theQueue.insert(20);
        theQueue.insert(30);
        theQueue.insert(40);

        x = theQueue.remove();              // remove 3 items
        x = theQueue.remove();              //    (10, 20, 30)
        x = theQueue.remove();

        theQueue.insert(50);            // insert 4 more items
        theQueue.insert(60);            //    (wraps around)
        theQueue.insert(70);
        theQueue.insert(80);

        while( !theQueue.isEmpty() )    // remove and display
        {                            //    all items
            int n = theQueue.remove();   // (40, 50, 60, 70, 80)
            System.out.print(n);
            System.out.print(" ");
        }
    }  // end main()
}  // end class Main