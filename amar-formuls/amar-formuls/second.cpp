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


        void fi2(queue<float>,queue<float>); //Fi section2 (formul: count data == x && data < y) y=karan UP, x=karan DOWN AND fi2 have to  use data.front[means minumum number] till classLevel front
        void classLevel(queue<float>,float); // 2x 2x numbers saved for exmaple: 2.0-2.4 , next class is 2.4-2.8 and ...
        void classAgent(queue<float>);
        float floatPointRounder(float);
        int searchInArray(float[],float,int);// NOTE MAYBE REMOVE THIS
        int fi2NumberCounter(float[],float,float,int);
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
float amar::floatPointRounder(float L)
{
    float tempL = L;
    int temp= (int)tempL;
    tempL = tempL - temp;
    tempL = tempL * 100;
    tempL = tempL / 10;
    tempL = round(tempL);
    tempL = tempL / 10;
    L = temp + tempL;
    return L;
}
float amar::L(float R, float K)
{    
    float L = R/K;
    L = floatPointRounder(L);
    return L;
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
    int len = (int)classLevels.size();
    cleanQueue(classAgents);
    for(int i=1; i<=  len; i++)
    {
        karanDown = classLevels.front();
        classLevels.pop();

        karanUp = classLevels.front();
        classLevels.pop();
        classAgents.push((karanDown + karanUp) / 2);
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
int amar::searchInArray(float ar[],float searching,int arsize)
{
    for(int i=0; i<arsize; i++)
        if(ar[i] == searching)
            return i;

    return -1; //return -1 means element were not found in the array
}
int amar::fi2NumberCounter(float ar[],float kDown,float kUp,int arsize)
{
    int counter=0;

//    for(int i=0; i<arsize; i++)
//                 ar[i] = round(ar[i] * 100) / 100.0;
//        cout << setprecision(9) <<ar[i] << endl;



    for(int i=0; i<arsize; i++)
    {
        float temp = ar[i];

        //for float ar[i]
        int a= temp;
        temp = temp - a;
        temp = temp *10;
        temp = round(temp);
        int b=  temp;
        cout << "b=" << b << endl;
        temp = (float)b/10;
        float resultAB = a + temp;
//        cout << "resutl ab=" << resultAB << endl;

        //for kDown
        temp = kDown;
        int akDown = temp;
        temp = temp - akDown;
        temp = temp *10;
        int bkDown = temp;
        temp = (float)bkDown / 10;
        kDown = akDown + temp;

        //for kUp
        temp = kUp;
        int akUp = temp;
        temp = temp - akUp;
        temp = temp *10;
        int bkUp = temp;
        cout << bkUp << endl;
        temp = (float)bkUp / 10;
        cout << temp << endl;
        kUp = akUp + temp;

        cout << endl << endl;
        cout << "a=" << a << "\tb=" << b << "\td=" << akDown << "." << bkDown <<
                "\tUp=" << akUp << "." <<  bkUp << endl << endl << endl;

        cout << "resAB=" << resultAB << "\tkDown=" << kDown << "\tkUp=" << kUp << endl;
//        if(resultAB >= kDown && resultAB < kUp && resultAB != kUp)
//            counter++;
        if(resultAB)
        {

        }

    }



    cout << "\t\t counter = " << counter << endl;



    return counter;
}
void amar::fi2(queue<float>data,queue<float>classLevels)
{

        //write queue data into an array
        int lendata = data.size();
        float dataArray[lendata];
        for(int j=0;j<=lendata-1; j++)
        {
             dataArray[j] = data.front();
             data.pop();
        }

        int len = classLevels.size()/2; // divid 2 bcz it would work 2x then garbge numbers would join into proccess
        for(int i=0; i<= len-1; i++)
        {
            //set value to karan up and down
            float karanDown = (float)classLevels.front();
            classLevels.pop();
            float karanUp = (float)classLevels.front();
            classLevels.pop();

//            for(int i=0; i<lendata; i++)
//                cout << "- - - - " << setprecision(9) << dataArray[i] << endl;
            f.push(fi2NumberCounter(dataArray,karanDown,karanUp,lendata));
        }
}

//----------function fi2 code :  index system for find the how many number is inside range (class)
//            int indexDown= searchInArray(dataArray,karanDown,lendata);
//            if(indexDown == -1)
//                for(float ops=karanDown; ops< karanUp; ops += 0.1)
//                {
//                    indexDown = searchInArray(dataArray,ops,lendata);
//                    if(indexDown != -1)
//                    {
//                        if(indexDown == 0)
//                            indexDown++;

//                        break;
//                    }

//                }
//        //BUG CANT fIND THE LAST NUMBER LIKE 4 & 4.4 skipped by index = -1 !!!!
//            int  indexUp = searchInArray(dataArray,karanUp,lendata);
//            if(indexUp == -1)
//                for(float ops=karanUp; ops>karanDown; ops -= 0.1)
//                {
//                    indexUp = searchInArray(dataArray,ops,lendata);
//                    if(indexUp != -1)
//                        break;
//                }
//            int counter = indexUp - indexDown;
//            f.push(counter);
//            cout <<  karanDown << " is in: " <<indexDown << "\t" << karanUp << " is in: " << indexUp  << "\tcounter= " << counter << endl;
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


//    for(int i=0; i<30; i++)
//    {
//          arr[i] = round(arr[i] * 100) / 100.0;

//          if(arr[i] == 2.8)
//              cout << "=========================2.8" << endl;

//    }

    for(int te=0;te<=30-1;te++)
        o.data.push(arr[te]);



    o.sortQueue(o.data);
    o.printQueue(o.data);



    float L = o.L(o.R(o.data),o.K()); //space between classes

    o.classLevel(o.data,L);


    cout << "\n\n\n\n";

    o.fi2(o.data,o.classLevels);




//    for(int i=1; i<= (int)o.K(); i++) //bcz gi() will give size from queue x and queue x is empty. we need to fill with '0' as classesLength, classesLength is on K()
//        o.x.push(0);

//    o.ri(o.f);
//    o.gi(o.f,o.x);
//    o.classAgent(o.classLevels);
    o.printTableClass(o.classLevels, o.f, o.r, o.g, o.classAgents);
}
int main()
{
    amar o;
//    o.section1(o);
    o.section2(o);

    return 0;
}
