class stack
{
public:
    void push(item);
    void pop();
    type top();
private:
    linklist<type>;
};

type top
{
    if(!stk.isEmpty())
        return stk.front();
    else
        return NULL;
}
void push(item)
{
stk.insert_front(item);
}
//if you insert from the front remove from the front
//if you inser from the back remove from the back.
// front removal is more efficient than back removal

int main()
 {
push(5); // [5][node] - head and tail pointing at node
push(3); // [3][->][5][tail] - head points to the front node. tail points
// after5
cout << top()<<endl; // 3
pop();





 }
 /*stack Vs queue 100%%%%% a TEST-QUESTIOn **********************************
 Stack = lifo; last in first out
 queue = fifo; first in first out
*/
