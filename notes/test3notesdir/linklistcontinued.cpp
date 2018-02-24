[3][]->[10][]->[5][]->[12][]->[1][]

node *c1, *c2;
c1 = head ;// c1 points to head
c1 = c1 ->link; //now points to the 10 block
c1 = c1 -> link;  //c2 now points to the 5 block
c2 = new node;  //creates new block [][] and c2 points to it
c2 -> link = c1 -> link; //causes c2 link to point to the same place c1 link is
c1 -> link = c2;         //c1-link now points to 15 or c2 block
c2 -> item = 15;         // c2 item is filled with 15
now [3][]->[10][]->[5][]->[15][ ]->[12][]->[1][]
//15 was added to the middle of the link list.


example like this will be on test 3

//head pointing to 3
[3][]->[2][]->[5][]->[7][]->[8][]

node * d;
d = head;
head = head ->link;
delete d;
//deletes first block [3][]

//head now points to 2 //now we will remove the 7
[2][]->[5][]->[7][]->[8][]
node *c1, *c2;
c1 = c2 == head; //c1 and c2 pointing at the 2 node
c1 = c1->link; //c1 now points at 5 node
c2 = c2->link; //c2 now points at 5 node
c1 = c1->link; //c1 now points at 7;
c2->link = c1->link; //5 node now points to 8.
//7 is now removed from the linked list.
delete c1; //will delete/dealocate the [7][];
