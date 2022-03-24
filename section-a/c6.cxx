#include <iostream>

using namespace std;

//#define tstmicro(a,b) (a>b ? b:a)
template<class toto>
int maxx (int a, int b)
{
//  auto xx = (a>b ? a:b);
//  cout << a + b;
return a+b;
}



int main()
{
//cout <<  maxx<int>(2,4);
cout << maxx<int>(20,1);
//cout <<  tstmicro(1,10) << endl;



  return 0;
}

