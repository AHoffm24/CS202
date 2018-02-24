#include <iostream>
using namespace std;
//Link List
/*
recursive def: linked list: 2types
1.empty linked list
2.node that points to a linked list
item     link      --item is below item, link is below link
[10][points to 3]->[3][points to 5]->[5][/(empty)]
last node is always empty/null so you know its the last element
*/
struct node //list of nodes(nodes are part of link list)
{
    int item;
    node *link;
};
int main()
{                //head points to the entire block. 13 node is first and last
node *head;      //{[13][NULL] ->
head = new node;
head ->item = 13;
head->link = NULL;  //} // end of first element

node *tmp;
tmp = new node;  //{ tmp - [10][]->[13][null] - head now points to 10 item
tmp->link = head;
tmp->item = 10;
head = tmp;
tmp = NULL;     //} end of front insert of new item in linked list

tmp = new node;
tmp->link = head;
tmp->item = 5;
head = tmp;
tmp = NULL;    //[head]->[5][]->[10][]->[13][NULL]

tmp = head;  //removes 10
tmp = tmp->link;
head->link = tmp->link;
delete tmp;
tmp = NULL;

node *t;
t = head;


while(t!=NULL) //imagin 5 was added in code above
{
    cout << t->item << " ";
    t = t->link;  // t will then point to 13link then 5link then finall null
}

return 0;

//cant jump to a single part of link list. Must navigate like above.
}
/*
n

{
    node *t;
    t = head;
    while(t->link !=NULL) //better than the while loop above
    {
        t = t->link; // t -> [10][]->[13][null]->5[/] t now points to last
        //element. t is essentially a tail pointer here.
    }
    node *insert;
    insert = new node;     //[][]
    insert->item = 15      //[15][]
    t->link = insert;
    insert->link=NULL;
}
*/
