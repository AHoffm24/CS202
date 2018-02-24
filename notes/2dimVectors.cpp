#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
  vector< vector<int> > v2D; //declare two dimensional vector
  v2D.resize(5); //we will have 5 rows
  for (int i = 0; i < v2D.size(); i++)
    v2D[i].resize(5); //we set each row to 5 columns

  //v2D will be a 5 x 5 vector

  for (int i = 0; i < v2D.size(); i++)
    for (int j = 0; j < v2D[i].size(); j++)
      v2D[i][j] = rand() % 20;

  for (int i = 0; i < v2D.size(); i++)
    {
      for (int j = 0; j < v2D[i].size(); j++)
        {
          cout << v2D[i][j] << " ";
        }
      cout << endl;
    }
}
