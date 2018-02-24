//removing the middle nodes [a][] - [b][] - [c][] - will be on test
{ // attemping to remove b and link a to c and deallocating information
node * tmp;
tmp = head->link;
head->link = tmp;
delete tmp;
}
//example with [a][]-[b][]-[c][]-[d][/]
{ //removes c
    node * temp1;
    node * temp2;
    temp1 = temp2 = head;
    temp1 = temp->link;
    temp2 = temp2->link->link;
    temp1->link =temp2->link;
    delete temp2;
}

//bool search(int a[]), int length; int d)
{
    for (int i = 0); i < length; i++;
    if (a[i] == s)
    return true;
    return false;
}
