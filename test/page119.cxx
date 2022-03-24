#include <iostream>

using namespace std;
void funca(int * para1)
{
  (*para1) = 10;
  cout << *para1 << endl;
}

int main()
{
	int *a=0;
	funca(a);

}
