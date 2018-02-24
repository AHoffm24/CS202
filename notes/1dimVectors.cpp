#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
  vector<int> v(10); //vector of 10 elements

  for (int i = 0; i < v.size(); i++)
    v[i] = rand() % 10;

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;

  v.resize(20);	//resize the vector from 10 to 20 elements

  cout << "v has been resized" << endl;

  for (int i = 10; i < v.size(); i++)
    v[i] = rand() % 10;

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;

  vector<int> v2; //empty vector

  cout << "v2" << endl;

  for (int i = 0; i < 12; i++)
    v2.push_back(rand() % 15); //push_back inserts elements to the back of the vector and resizes automatically if needed

  for (int i = 0; i < v2.size(); i++)
    cout << v2[i] << " ";
  cout << endl;

  return 0;
}
