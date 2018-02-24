#include <iostream>
#include <string>
using namespace std;

class myClass
{
public:
  void addStudent(string str)
  {
    names += str + ' '; /* names = names + str + ' '; */
  }
  void removeStudent(string str)
  {
    string search = str + ' ';
    size_t i = names.find(search);
    //scope resolution operator ::
    if (i != string::npos)
      names.erase(i, search.length());
      
  }

  string getStudents()
  {
    return names;
  }
private:
  string names;
};
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

}
