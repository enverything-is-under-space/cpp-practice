#include <iostream> //for use cout, cin, endl
#include <queue> //for use queue
#include <iomanip> //for use setprecision
#include <cmath> //for use log10

using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::setprecision;
using std::round;

const int dataCount=30; //count of data for input and calculate

class amar
{
    public:

        //-------------- blow functions are made for formul steps
        void section1(amar);
        void section2(amar);


        //-------------- used in commen sections
        void giveInput();
        queue<float> data,x,f,g,r;
        queue<float> classLevels,classAgents;

        void printQueue(queue<float>);
        void swapQueue(queue<float>,queue<float>);
        void copyQueue(queue<float>,queue<float>); //copy first to second
        void sortQueue(queue<float>);  // ************************************NOTE BUG or Problem sometime happen: trash value pushed inside queue
        void cleanQueue(queue<float>&);
        void sSwap(float*,float*); //sort (sub-function)
        void sBubbleSort(float[],int); //sort (sub-function)




        //-------------- section 1 --------------
        void printTable(queue<float>,queue<float>,queue<float>,queue<float>);
        int ni(); //N = data count [tedad kole data]
        void ri(queue<float>); //ri = faravani nesbi (formul : N[teadad kol data] / f[faravni] )
        void gi(queue<float>f,queue<float>x); //gi = faravni tajamoE (formul : f[faravni] + last indexes[tabaghehaye balaye khodesh])
        void fi(); //fi = faravani (formul : count repeat data)
        float xi(queue<float>); //xi = tedade kol data ha [count data]
        void xiRemoveDuplicate(float[]); //is K [tedade tabaghehaye jadvale faravani] =  xi.size



        //-------------- section 2 --------------
        void printTableClass(queue<float>,queue<float>,queue<float>,queue<float>,queue<float>);
        float R(queue<float>); //R = (formul : biggest data - smallest data)
        float L(float,float); //L = space between classes (formul : R[function R] / K[xi.size] )
        int K(); //K = length classes(formul: 1+3.32*log10(N))  *****NOTE-> used ceil but is not best choise [bcz maybe make bigger data then false answers]


        void fi2(queue<float>,float); //Fi section2 (formul: count data == x && data < y) y=karan UP, x=karan DOWN AND fi2 have to  use data.front[means minumum number] till classLevel front
        void classLevel(queue<float>,float); // 2x 2x numbers saved for exmaple: 2.0-2.4 , next class is 2.4-2.8 and ...
        void classAgent(queue<float>);

        //section 2 part 2
//        float mAvrage(queue<float>); // avrage = (formul : n[j] =  x[j] * f[j]  'then  plus all n indexes insert into ave'  ave = n[j->n.size]  -> ave / N
//        float mode(float
//        float miane();
//        float charak();




};

void amar::gi(queue<float>f,queue<float>x)
{
    int len = x.size();
    for(int i=0; i<= len-1; i++)
    {
        float temp=0;
        queue<float> tempF = f; //bcz value will be pop. needed to refill

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
        //if(temp == tempQ.front())
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
    float temp = *xp;
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
    cout << "R=" << R << "\t K= " << K << endl;
    //-------------------------------------------------------------------------------------------- PROBLEM CLASS IS HERE




                //CLASS  IS NOT WORKING CORRECT BECUZ OF L is not rounded correct
        /




            //F is not working correct bcz of L AND SOMETHING I DONT KNOW RIGHT NOW


    // AGENT IS NOT WORKING CORRECT BCZ of I DONT KNOW RIGHT NOW























    //-------------------------------------------------------------------=
//    cout << "L = " << (R/K) << endl;
//    cout << "LLL= " << round(2.2 / 6) << endl;
//    cout << "LLL= " << floor(2.2 / 6+0.5) << endl;
//    cout << "LLL= " << ceil(2.2 / 6+0.5) << endl;
//    cout << "LLL= " << std::roundf(2.2 / 6) << endl;
//    cout << "LLL= " << std::lroundf(2.2 / 6) << endl;
//    cout << "LLL= " << std::llroundf(2.2 / 6) << endl;
//    float L = R/K;
//    L = 0.4;


    //NOTE BUG HELP NEEEDED TO (round the float point like 0.37 -> 0.4 to closest posible number)
    return R/K;
}
int amar::K()
{
    return round(1 + 3.32 * log10(ni()));
}
void amar::section1(amar o)
{
    //o.giveInput();
    float arr[30] = {5,4,2,1,1,1,3,3,3,2,0,5,0,2,2,2,2,4,4,1,0,1,1,3,2,5,2,1,0,4};
    for(int te=0;te<=30-1;te++)
        o.data.push(arr[te]);

    o.sortQueue(o.data);
    o.xi(o.data);
    o.fi();
    o.ri(o.f);
    o.gi(o.f,o.x);
    o.printTable(o.x,o.f,o.r,o.g);
}
void amar::classAgent(queue<float>classLevels)
{
    float karanDown=0;
    float karanUp =0;
    for(int i=0; i<= (int)classLevels.size()-1 ; i++)
    {
        karanDown = classLevels.front();
        classLevels.pop();

        karanUp = classLevels.front();
        classLevels.pop();

        classAgents.push(karanDown + karanUp / 2);
    }
}
void amar::classLevel(queue<float>data, float L)
{
    float temp=0;
    float karanDown = 0;
    float karanUp = 0;
    temp = data.front();

    for(int i=0; i<=dataCount-1; i++)
    {

        karanDown = temp;
        karanUp = karanDown + L;

        while(temp >= karanDown && temp < karanUp) //NOTE BUG (needed to only 2 float number not more something like setpreciosion)
        {
             data.pop();
             temp = data.front();
        }
        classLevels.push(karanDown);
        classLevels.push(karanUp);
        temp = classLevels.back();
        if(data.empty())
            break;
    }
}
void amar::fi2(queue<float>data,float L)
{
    int counter=0;
    float temp=0;
    float karanDown = 0;
    float karanUp = 0;
    for(int i=0; i<=dataCount-1; i++)
    {
        temp = data.front();

        karanDown = temp;
        karanUp = karanDown + L;

        while(temp >= karanDown && temp < karanUp) //NOTE BUG (needed to only 2 float number not more something like setpreciosion)
        {
             counter++;
             data.pop();
             temp = data.front();
        }

        f.push(counter);
        counter=0;
        if(data.empty())
            break;
    }
}
void amar::printTableClass(queue<float>classLevels,queue<float>f,queue<float>r,queue<float>g,queue<float>classAgents)
{
    cout << "\n\n\n";
    cout << "Faravani Table with Classes" << endl;
    cout << "no\t| c\t| f\t| r\t| g\t| agent" << endl;
    cout << "______________________________________________" << endl;

    int len = K();
    for(int i=1; i<= len; i++)
    {
        cout << setprecision(2) << i << "\t" << classLevels.front() << "-";

        classLevels.pop(); //for remove karanDown to print karanUp in next line

        cout << classLevels.front() << "\t" << f.front() << "\t" << r.front() << "\t" << g.front() << "\t" << classAgents.front() << endl;


        classLevels.pop(); //next class will be in front by this line
        f.pop();
        r.pop();
        g.pop();
        classAgents.pop();
    }
}
void amar::section2(amar o)
{
//    o.giveInput();
    float arr[30] =
    {2.0,2.1,2.3,3.0,3.1,2.7,
     2.8,3.5,3.1,3.7,3.1,2.6,
     3.5,4.0,2.3,3.5,4.2,3.7,
     3.2,2.7,2.5,2.7,3.8,3.0,
     2.8,2.9,4.1,3.2,2.8,2.2};

    for(int te=0;te<=30-1;te++)
        o.data.push(arr[te]);



    o.sortQueue(o.data);

    o.printQueue(o.data);

    float L = o.L(o.R(o.data),o.K()); //space between classes
    o.classLevel(o.data,L);
    o.fi2(o.data,L);
    for(int i=1; i<= (int)o.K(); i++) //bcz gi() will give size from queue x and queue x is empty. we need to fill with '0' as classesLength, classesLength is on K()
        o.x.push(0);
    o.ri(o.f);
    o.gi(o.f,o.x);
    o.classAgent(o.classLevels);
    o.printTableClass(o.classLevels, o.f, o.r, o.g, o.classAgents);
}
int main()
{
    amar o;
//    o.section1(o);
    o.section2(o);


    return 0;
}
