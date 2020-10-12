#include <iostream>
using namespace std;

bool Termin(char c)
{
  if (!isupper(c) && c != '\0' && c != '|')
    return true;
  else
    return false;
}

int Prod(char NT, char **strings, int currPos, int n)
{
  for (int i = 0; i < n; ++i)
  {
    if (i == currPos)
      continue;
    if (strings[i][0] == NT)
      return i;
  }
}

void StringChk(char *string, char **strings, int currPos, int n)
{
  int i = 2;
  for (; i < 50; ++i)
  {
    if (Termin(string[i]))
    {
      cout << string[i] << " ";
      while (string[i] != '|' && string[i] != '\0')
        i++;
    }
    else if (string[i] == '|' || string[i] == '\0')
    {
      int productionNo = Prod(string[i - 1], strings, currPos, n);
      StringChk(strings[productionNo], strings, productionNo, n);
    }
    if (string[i] == '\0')
      break;
  }
}

int main()
{
  cout << "Enter the number of non-terminals: ";
  int n = 0;
  cin >> n;

  cout << "Enter the productions: " << endl;

  char **strings = new char *[n];
  for (int i = 0; i < n; ++i)
  {
    strings[i] = new char[50];
    cin >> strings[i];
  }

  cout << endl
       << "Leadings are: " << endl;

  for (int i = 0; i < n; ++i)
  {
    cout << "{ ";
    StringChk(strings[i], strings, i, n);
    cout << "}" << endl;
  }

  return 0;
}