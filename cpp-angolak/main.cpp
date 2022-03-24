#include <iostream>

using namespace std;

void myvoid(float ar[],float i=5<<5)
{
    cout << i <<endl;
        for(int a=0; a<=i-1; cout << "the a = " << ar[a] << endl,a++){}
        cout << ar[3];
}

    int main()
    {
        for(int i=1;i<=3;cout << "the i = " << i++ << endl){}

        float arr2[] = {2,4};
        float arr[0+2] = {1,arr2[0]};
        cout << "len a = " << sizeof(arr);
        cout << "len aa = " << sizeof(arr[1-1]);
        cout << "len aaa = " << sizeof(arr)/sizeof(arr[0])<<endl;
        myvoid(arr,sizeof(arr)/sizeof(arr[0]));

        return 0;
    }
