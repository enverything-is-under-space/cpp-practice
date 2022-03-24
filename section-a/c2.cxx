#include <iostream>

using namespace std;

int gX=0;
int main()
{
  int gX = 100;
  cout << gX << endl;

  cout << "global gX = " << ::gX << endl;
}


