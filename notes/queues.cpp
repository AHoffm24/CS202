//queue
void enqueue(item);
void dequeue();
type front();
bool isEmpty();
bool isFull();

//variables
size: int
front: int
back: int
full: bool
empty: bool
list: array that holds queue

enqueue(item) //think of this like a circle line. the back can reach the front.
{
    if(full)
    { //resize queue
      resize();
    }
    list[back] = item; //insert item to back of the queue
    back = (back + 1) % size;
    if(front = back)
    {
        full = true;
    }
    empty = false;
}

dequeue()
{
    if(!empty)
    {
        front = (front + 1) % size;
        if(front = back)
        {
            empty = true;
        }
        full = false;
    }
}

queue()
{
    enqueue(item);
        line.insert_back(item);
    dequeue()
        line.delete_front();
   type front();
   return line.front();
}
//will have test questions on queues
//check photos on phone for information.

// MORE ON QUEUES FROM PRINT OUT
//this part goes with 2.6 on handout
/*  circular Linked List Queues
- pointer that points to the end node
- end node point to the front of the queue
[1][*2][2][*3][3][*1]    q points to 3
*/
circular queue<char> myqueue;  // q points to NULL before this
myqueue.enqueue('a');
// q points to null, tmp points to ->[a][], q points[a][*a] //a node points to a
// q points to the last node. q->link points to the first node
myqueue.enqueue('b')
// q points to [a][], tmp points to [b][]
tmp ->link = q ->link;
q-link=tmp
//look at pictures from class.
//sent in email to school email subject: "queues"
// ********************IMPORTANT NEXT 2 LINES*****************************
//*********     q-link always points to first node.
//*********     q always points to last node.
//for exam must be able to draw photos, and having and understanding of which picture goes with what. so draw enqueue a, enqueue b, and enqueue c


//pictures sent to school email with subject: "dequeue"
myqueue.dequeue();
if(q = q->link)
{
delete q;
q = NULL;
}
else
{
tmp = q->link;
q-> link = q->link->link;
delete tmp;
}
//deallocated [a][->]
//left with [b][->][c][->b]
myqueue.dequeue(); //removes b
myqueue.dequeue(); //removes c
