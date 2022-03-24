#include <iostream>

using namespace std;
void dbg (int a)
{
  cout << a <<endl;
}

int soso(int x)
{
cout << "soso" << endl;
dbg(x);
int y=0;
cout << "y"<< endl;
dbg(y);
y+=x;
dbg(y);
  x+=y;
dbg(x);
return x;
}


int sososo(int x)
{
cout << "sososos"<<endl;
dbg(x);
static int y;
y += x;
dbg(y);
x+=y;
dbg(x);

 return x;

}
int main()
{


cout << endl;
cout << endl;
cout <<  soso(1) << "\t" << soso(10) << "\t" << soso(100) << endl; //         1+1  10+10   100+100
cout << sososo(1) << "\t" << sososo(10) << "\t" << sososo(100) << endl;//     1+1  10+10 100+100
  return 0;
}
