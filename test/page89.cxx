#include <iostream>
#include <string>


using namespace std;

void print(float a)
{
cout << a << endl;
}

int main()
{
/* page89    int num[2*2] = {0,1,2,3};
for(int i=0; i <= 2*2-1; i++)
{
print(num[i]);
}*/





//page91

//short int ar[1][2][3] = {0,1,3};
//print(sizeof(ar[0][0][0]));
//int ar2[5][5][5][5][5][5][5][5][5][5][5][5][5] = {ar[0][0][]};
//print(sizeof(ar2[]));



/*swithc if
int x = 9;
switch(x)
{

// if(x==9) cout << "if" << endl;

	case 0: print(x); break;
//if(x==9) print(2);
//else print(3);break;
default:
 cout << "def" << endl;
break;

//if(1==1) print(x);
}*/




//-------------------enum page111
/*int xp = 0;
enum help2fejiughjur
{
    a,b,c,d,"x",2
//qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
//xp,

};
*/


//-----page 120


int x = 10;
int &r = x;
cout << r<<endl;
cout << &r << endl;
cout << endl;
cout << &x <<endl;
cout << x << endl;




}
