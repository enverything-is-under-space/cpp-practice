#include <iostream>

using namespace std;


namespace xyz
{
 class person
{
 public:
   void ff(void)
{
 cout << "nmfgioernjgioer" << endl;
}

};

}

using xyz::person;
using namespace xyz;
namespace zyx = xyz::person;



int main()
{

// xyz::person s;
//person s;
zyx::person s;
s.ff();
 return 0;

}
