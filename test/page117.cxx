#include <iostream>
#include <string>

using namespace std;

int main()
{
   int * a ;
a = new int[2] {0,1};
   cout << a[0] << endl;
//cout << *a[0] << endl;
//cout << &a << endl;


string *b;
string c="hello";
c = *b;
cout << b <<endl;
}

