#include <iostream>
#include <string>
using namespace std;
struct student
{
  string first;
  string last;
  double gpa;
  string major;
  void print_name()
  {
    cout << first << " " << last;
    cout << endl;
  }
};
struct canidate
{
  string first;
  string last;
  double gpa;
  string major;
  void print_name()
  {
    cout << first << " " << last;
    cout << endl;
  }
};

int main()
{
  student adam;
  adam.first = "Adam";
  adam.last = "Hoffman";
  adam.gpa = 4.0/1.0;
  adam.major = "Computer Science";
  cout << adam.first << endl;
  cout << adam.last << endl;
  cout << adam.gpa << endl;
  cout << adam.major << endl;
  canidate ben;
  ben.first = "Ben";
  ben.last = "Button";
  ben.gpa = 2.0;
  ben.major = "CS";
  adam.print_name();
  ben.print_name();
}
