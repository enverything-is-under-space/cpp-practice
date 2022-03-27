//#include <iostream>

//using std::cout;
//using std::cin;
//using std::endl;

//const int maxar = 5-1;

//class amar
//{

//public:
//    float data[maxar+1];
//    float x[maxar+1], f[maxar+1], r[maxar+1], g[maxar+1];


//    //global functions
//        void getinput();
//        int N();
//        void printdata(float*);
//        void copyarray(float*,float*); //copy second to first values

//        //sort data
//        void swap(float *xp, float *yp);
//        void bubbleSort(float arr[], int n);



//        void Xi(float*); // remove duplicated data from array
////        int Fi();
////        void r();
////        void g();
//};



//void amar::getinput()
//{
//    for(int j=0;j<=maxar;j++)
//    {
//        cout << "Enter data: ";
//        cin >> data[j];
//    }

//}
//void amar::swap(float *xp, float *yp)
//{
//    int temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}
//void amar::bubbleSort(float arr[], int n)
//{
//    int i, j;
//    for (i = 0; i < n; i++)

//    // Last i elements are already in place
//    for (j = 0; j < n-i; j++)
//        if (arr[j] > arr[j+1])
//            swap(&arr[j], &arr[j+1]);
//}
//void amar::printdata(float *ar)
//{
//    cout << "\t----------------- array values -----------------" << endl;
//    for(int j=0;j<=maxar;j++)
//    {
//        cout << ar[j] << "\t";
//    }

//    cout << endl;
//}
//int amar::N()
//{
//    return maxar;
//}



//void amar::Xi(float*a)
//{
//    for(int k=0;k<=maxar;k++)
//    {
//        cout<<"xi=" << a[k] << endl;
//    }
//}

//void amar::copyarray(float *a, float *b)
//{
//    for(int k=0;k<=maxar;k++)
//        a[k] = b[k];
//}


//void cal(float*a)
//{
//    int i,j,k,n;
//    n= maxar+1; //array len

//    for(i=0;i<n-1;i++)
//    {
//        for(j=i+1;j<n;)
//        {
//            if(a[i]==a[j])
//            {
//                for(k=j;k<n-1;k++)
//                {
//                    cout << "\t" << k << endl;
//                    a[k]=a[k+1];

//                }
//                n--;
//            }
//            else
//                j++;
//        }
//    }
//}



//int main()
//{
//    cout << "Hello World!" << endl;
//    amar obj;

//    obj.getinput();
//    obj.printdata(obj.data);

//    obj.bubbleSort(obj.data,maxar);
//    obj.printdata(obj.data);

//    obj.copyarray(obj.x,obj.data);
//    obj.Xi(obj.x);

//    cout << endl << endl;
//    cal(obj.x);
//        obj.printdata(obj.data);
//            obj.printdata(obj.x);
//    return 0;
//}



