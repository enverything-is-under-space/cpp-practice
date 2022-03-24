#include <iostream>

using namespace std;

#define find_min_num(a,b) (a>b ? b:a)

//#define find_max_num(c,d) (c>d ? c:d)

#define ff 10
#define gg 20

int main()
{
  cout << "max=" << find_min_num(ff,gg) << endl;
  //cout << "min=" << find_max_num(ff,gg) << endl;

cout << endl;
  auto x=2000000000000;
  int y=2;
  long int z= 1;

  static int a = 100;
  static long int b = 100;
  static short int c = 100.20;

  register auto d = 10000.2222;
  cout << sizeof(d)<< "\tval=" << d<<endl;
  cout << sizeof(x) << "\t" << sizeof(y) << "\t" << sizeof(z) << endl;
  cout << "statices size=" <<sizeof(a) << "\t" << sizeof(b) << "\t" << sizeof(c) << endl;
// cout <<"x="<< x << endl << "y=" << y <<endl;



 const int m= 100;
cout << sizeof(m) << "\t" << m<<endl;

  const auto n = 2;
cout << sizeof(n) << "\t" << n << endl;
  return 0;
}
