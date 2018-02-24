#include <iostream>
#include <string>
using namespace std;

class myClass
{
public:
  void addStudent(string);
  void removeStudent(string);
  string getStudents();
private:
  string names;
};
void myClass::addStudent(string str)
{
    names += str + " ";
}
void myClass::removeStudent(string str)
{
  string search = str + ' ';
  size_t i = names.find(search);
  //scope resolution operator ::
  if (i != string::npos)
    names.erase(i, search.length());
}
string myClass:getStudents()
{
  return names;
}


int main()
{
  myClass cs202;
  cs202.addStudent("Rob");
  cs202.addStudent("Tim");
  cs202.addStudent("Sue");
  cs202.addStudent("Sam");
  cout << cs202.getStudents() << endl;

  cs202.removeStudent("Tim");
  cout << cs202.getStudents() << endl;
  return 0;
}
