#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

const int maxar = 5-1;

class amar
{

public:
    float data[maxar];
    float x[maxar], f[maxar], r[maxar], g[maxar];



    //global functions
        void getinput();
        int N();
        void printdata(float*);

        //sort data
        void swap(float *xp, float *yp);
        void bubbleSort(float arr[], int n);



        void Xi(); // remove duplicated data from array
//        int Fi();
//        void r();
//        void g();
};

void amar::getinput()
{
    for(int j=0;j<=maxar;j++)
    {
        cout << "Enter data: ";
        cin >> data[j];
    }

}
void amar::swap(float *xp, float *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void amar::bubbleSort(float arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
void amar::printdata(float *ar)
{
    cout << "\t----------------- array values -----------------" << endl;
    for(int j=0;j<=maxar;j++)
        cout << ar[j] << "\t";

    cout << endl;
}
int amar::N()
{
    return maxar;
}



void amar::Xi()
{

}

int main()
{
    cout << "Hello World!" << endl;
    amar obj;

    obj.getinput();
    obj.printdata(obj.data);

    obj.bubbleSort(obj.data,maxar);
    obj.printdata(obj.data);



    return 0;
}
