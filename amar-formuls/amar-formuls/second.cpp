#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>

using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::setprecision;

const int dataCount=30;

class amar
{
    public:

        //blow functions are made for formul steps
        void section1(amar);
        void section2(amar);


        //used codes for two sections
        void giveInput();
        queue<float> data,x,f,g,r;

        //queue functions
        void printQueue(queue<float>);
        void swapQueue(queue<float>,queue<float>);
        void copyQueue(queue<float>,queue<float>); //copy first to second
        void sortQueue(queue<float>);
        void cleanQueue(queue<float>&);
        //sort sub-functions
        void sSwap(float*,float*);
        void sBubbleSort(float[],int);


        //-------------- section 1 --------------
        void printTable(queue<float>,queue<float>,queue<float>,queue<float>);
        int ni(); //N = data count [tedad kole data]
        void ri(queue<float>f); //ri = faravani nesbi (formul : N[teadad kol data] / f[faravni] )
        void gi(queue<float>f); //gi = faravni tajamoE (formul : f[faravni] + last indexes[tabaghehaye balaye khodesh])
        void fi(); //fi = faravani (formul : count repeat data)
        float xi(queue<float>); //xi = tedade kol data ha [count data]
        void xiRemoveDuplicate(float[]); //is K [tedade tabaghehaye jadvale faravani] =  xi.size

        //-------------- section 2 --------------
        float R(queue<float>); //R = (biggest data - smallest data)
        float L(float,float); //L = space between classes (formul : R[function R] / K[xi.size] )

        //K = length classes (formul : 1 + 3.32  * log(N) )
        //(ceil but not some much good)
        int K();

        void printTableClass(int );

        //Fi section2 (formul: count data == x && data < y) y,x = karan bala and karan payin
        void fi2();
};

//section 1
void amar::gi(queue<float>f)
{
    int len = x.size();
    for(int i=0; i<= len-1; i++)
    {
        float temp=0;
        queue<float> tempF = f;

        for(int j=0; j<= i; j++)
        {
            temp += tempF.front();
            tempF.pop();
        }
        g.push(temp);
    }
}
void amar::ri(queue<float>f)
{
    int len = x.size();
    for(int i=0; i<= len-1; i++)
    {
        r.push(f.front()/ni());
        f.pop();
    }
}
void amar::printTable(queue<float>x,queue<float>f,queue<float>r,queue<float>g)
{

    cout << "\n\n\n";
    cout << "Faravani Table" << endl;
    cout << "X\t| F\t| R\t| G\t|" << endl;
    cout << "___________________________________" << endl;

    int len = x.size();
    for(int i=0; i<= len-1; i++)
    {
        cout << setprecision(2) << x.front() << "\t|" << f.front() << "\t|" << r.front() << "\t|"<< g.front() << "\t|" << endl;
        x.pop();
        f.pop();
        r.pop();
        g.pop();
    }

}
void amar::fi()
{
    queue<float> tempQ = data;

    int counter=0;
    float temp=0;
    for(int i=0; i<=dataCount-1; i++)
    {
        temp = tempQ.front();
        tempQ.pop();
        counter++;
        if(temp == tempQ.front())
            while(temp == tempQ.front())
            {
                counter++;
                tempQ.pop();
            }

        f.push(counter);
        counter=0;
        if(temp == tempQ.back())
            break;
    }
}
void amar::cleanQueue(queue<float>&q)
{
    queue<float> emptyQ;
    swap(emptyQ,q);
}
void amar::sortQueue(queue<float>a)
{
    const int len = a.size();

    float tempA [len];

    if(!a.empty())
    {
        for(int i=0; i<= len-1 ; i++)
        {
            tempA[i] = a.front();
            a.pop();
        }

        sBubbleSort(tempA,len);
    }

}
void amar::sBubbleSort(float arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n-i; j++)
            if (arr[j] > arr[j+1])
                sSwap(&arr[j], &arr[j+1]);


    //insert into queue data
    cleanQueue(data);
    for(j=1;j<n+1;j++)
        data.push(arr[j]);


}
void amar::sSwap(float *xp, float *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void amar::swapQueue(queue<float>q1, queue<float>q2)
{
    swap(q1,q2);
}
void amar::printQueue(queue<float>q)
{
    cout << "- - - - - printQueue: size=" << q.size() << endl;
    const int len = q.size();
    for(int a=0; a<= len-1; a++)
    {
        cout << q.front() << "\t";
        q.pop();
    }
    cout << "\n- - - - - - - - - - - - - - -" << endl;
}
int amar::ni()
{
    return data.size();
}
void amar::giveInput()
{
    for(int a=1;a<=dataCount;a++)
    {
        cout << "enter number: ";
        float temp=0;
        cin >> temp;
        data.push(temp);
    }
}
void amar::copyQueue(queue<float>a,queue<float>b)
{
    b = a;
}
void amar::xiRemoveDuplicate(float a[])
{
    int i,j,k,size;
    size= dataCount; //array len

    for (i = 0; i < size; i++)
    {
       for (j = i + 1; j < size;)
       {
          if (a[j] == a[i])
          {
             for (k = j; k < size; k++)
             {
                a[k] = a[k + 1];
             }
             size--;
          }
          else
             j++;
       }
    }

    for (i = 0; i < size; i++)
    {
       x.push(a[i]);
    }
}
float amar::xi(queue<float>a)
{
    float tempA[a.size()];
    queue<float> tempB = a;
    queue<float> tempResult;
    if(!a.empty())
    {
        for(int i=0; i<= (int)a.size() ; i++)
        {
            tempA[i] = tempB.front();
            tempB.pop();
        }
        xiRemoveDuplicate(tempA);
    }
    else
        cout << "queue was empty!" << endl;

    return 0;
}


float amar::R(queue<float>data)
{
    float min=data.front() , max = data.back();
    return max-min;
}
float amar::L(float R, float K)
{
    return R/K;
}

int amar::K()
{
    int k = ceil(1 + 3.32 * log10(ni()));
    cout << "- - - K without ceil = " << (1 + 3.32 * log10(ni())) << endl;
    return k;
}
void amar::section1(amar o)
{
    o.giveInput();
    o.sortQueue(o.data); //bug: trash value pushed inside queue *******************
    o.xi(o.data);
    o.fi();
    o.ri(o.f);
    o.gi(o.f);
    o.printTable(o.x,o.f,o.r,o.g);
}

void amar::section2(amar)
{

}
int main()
{
    amar o;
    /*-------------- section 1 --------------*/
    //o.section1(o);



    /*-------------- section 2 --------------*/
    o.giveInput();
    o.sortQueue(o.data);
    float L = o.L(o.R(o.data),o.K()); //space between classes















    return 0;
}
