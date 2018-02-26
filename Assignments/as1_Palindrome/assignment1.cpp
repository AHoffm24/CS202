#include <iostream>
#include <string>
#include <cctype>

using namespace std;
bool isPalindrome(string, int);

int main()
{
  int length;
  string pal;

  cin >> pal;
  while(cin)
  {
    length = pal.length();
    for (int i = 0; i < length; i++)
      {
        if (isupper(pal[i]))
          {
            pal[i] = tolower(pal[i]);
          }
      }
    if (isPalindrome(pal,length))
    {
    cout << pal << " is a palindrome" << endl;
    cin >> pal;
    }
    else
    {
    cout << pal << " is not a palindrome" << endl;
    cin >> pal;
    }
  }


return 0;
}//end of main

bool isPalindrome(string pal, int length)
{
  string temp;
  temp = pal;
  for (int i = 0; i < length; i++)
    {
    pal[i] = temp[length - 1];
    length--;
    }
    cout << temp;
    cout << pal;
  if (pal == temp)
    return true;
  else
    return false;
}//end of bool isPalindrome
