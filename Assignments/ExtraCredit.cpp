cin >> amount;
cylinder ** containers; //create array of pointers.
containers[i] = new containers*[amount];
for (int i = 0; i < amount; i++)
{
    containers[0] = new cylinder(3.3, 4.4);
    containers[0]->volume(); //will work to get volume
    //point each to a container object

}
containers[0] = new cylinder(3.3, 4.4);
// use below instead of container[0].volume. this wont work.
containers[0]->volume(); //will work to get volume
(*container[0]).volume(); = the same as above.
