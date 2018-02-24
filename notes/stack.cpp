 /*stack Vs queue 100%%%%% a TEST-QUESTIOn **********************************
 Stack = lifo; last in first out
 queue = fifo; first in first out
*/



/////code on stack is in the book. Expect a test question.

#include <stack>

int main()
{
    stack<char> s;
    s.push('c'); //puts c on the stack.
    s.push('m'); //puts m on the top of the stack.
    cout << s.top << endl; //prints out top element "m" in this case
    s.pop(); //takes m off the stack;
    /*test question will give us code and we have to tell what is on the stack after every single operation*/
}
/*******************************************************************/

#include <stack>
class stack
{
public:
    void push(item);
    void pop();
    type top();
    isempty();
    isFull();
private:
    size_t sTop; //points to element at top of stack
    type * stk;
};
void push(item)
{
        push(item)
        stk[sTop] = item;
        sTop++;
        type top();
        return stk[sTop - 1];
}
void pop()
{

}
int main ()
{

}
