#include <iostream>

using namespace std;

int main()
{
  int x,i,j;
  x=0;
  i=1;
  j=0;

  cout << (i || j) << endl;
  cout << (i && j) << endl;
  cout << (i | j) << endl;
  cout << (i & j) << endl;
//  cout << (i &| j) << endl;
  return 0;
}
