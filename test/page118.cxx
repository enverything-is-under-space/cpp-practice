#include <iostream>
#include <string>


using namespace std;
int main()
{
  int *d; 
int x=2;
d= &x;
cout << d<<endl;
delete d;
cout << d;
}
