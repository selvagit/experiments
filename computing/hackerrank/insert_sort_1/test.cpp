#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

void my_print(vector<int> ar)
{
  int size = ar.size();
  for (int i = 0; i < size; i++)
  {
    cout << ar[i] << " ";
  }
}

void insertionSort(vector<int> ar)
{
  int size  = ar.size();
  int check = ar[size - 1];
  int i     = 0;
  for (i = size - 2; i >= 0; i--)
  {
    if (ar[i] > check)
    {
      ar[i + 1] = ar[i];
      my_print(ar);
      cout << "\n";
      if (i == 0)
      {
        ar[i] = check;
        my_print(ar);
        cout << "\n";
      }
    }
    else
    {
      ar[i + 1] = check;
      my_print(ar);
      cout << "\n";
      break;
    }
  }
}

int main(void)
{
  vector<int> _ar;
  int _ar_size;
  cin >> _ar_size;
  for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++)
  {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp);
  }

  insertionSort(_ar);

  return 0;
}
