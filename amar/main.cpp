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
        void section2_2(amar);


        //-------------- used in commen sections
        void giveInput(); //to-fill data
        void giveInput(queue<float>&q);//to-fill parameter queue

        queue<float> data,x,f,g,r;
        queue<float> classLevels,classAgents;
        queue<float> simpleAvrageValues;
        queue<float> charkValues; //data push syntax: q1,q2,q3
        queue<float> modes;


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
        void gi(queue<float>,queue<float>); //gi = faravni tajamoE (formul : f[faravni] + last indexes[tabaghehaye balaye khodesh])
        void fi(queue<float>); //fi = faravani (formul : count repeat data)
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
        int fi2NumberCounter(float[],float,float,int);


        //-------------- section 2 part 2
        float simpleAvrage(queue<float>);
        void printTableSection2_2(queue<float>,queue<float>);
        float avrageFromTableFaravani(queue<float>,queue<float>);
        float simpleMiane(queue<float>); //also Chark
        void chark(queue<float>);
        bool checkValueInQueue(queue<float>,float);
        float mianeFromTableFaravani();
        void simpleMode(queue<float>);
        int howManyRepeated(float,queue<float>);


};
int amar::howManyRepeated(float value , queue<float>data)
{
    int len=data.size();
    int counter=0;
    for(int i=1; i<=len; i++)
    {

        queue<float> tempD = data;
        for(int j=1; j<=len; j++)
        {
            if(tempD.front() == value)
                counter++;
            tempD.pop();
        }

    }

    return counter;
}
void amar::simpleMode(queue<float>fQ)
{
    const int len= fQ.size();


    //count max number
    float counter[len];
    queue<float> tempQ = fQ;
    for(int k=1; k<= len; k++)
    {
        float value = howManyRepeated(tempQ.front(),te
        tempQ.pop();
    }


}
float amar::mianeFromTableFaravani()
{

    float y = ni()/2;


    //for calculate Gi and Fi
    float l = L(R(data),K()); //space between classes
    classLevel(data,l);
    fi2(data,classLevels);

    for(int i=1; i<= (int)K(); i++) //bcz gi() will give size from queue x and queue x is empty. we need to fill with '0' as classesLength, classesLength is on K()
        x.push(0);
    gi(f,x);

    float giMinusOne = 0;
    int lookingForindex=0;
    queue<float> tempData = g;

    for(int i=1; i<=K(); i++)
        if(tempData.front()>=y)
        {
            lookingForindex = i;
            break;
        }
        else
            tempData.pop();

    tempData=g;//re-fill from G
    for(int i=1; i<=K(); i++)
        if(i==lookingForindex-1)
        {
            giMinusOne = tempData.front();
            break;
        }
        else
            tempData.pop();


    //fetch Fi
    tempData=f;
    float fiValue=0;
    for(int i=1; i<=K(); i++)
        if(i==lookingForindex)
        {
            fiValue = tempData.front();
            break;
        }
        else
            tempData.pop();



    //fetch ai or same class KaranDown
    tempData=classLevels;
    float ai=0; //is same kdown that level
    for(int i=1; i<=K()*2; i++)
        if(i==(lookingForindex*2)-1)
        {
            ai = tempData.front();
            break;
        }
        else
            tempData.pop();


    //LESGO formul is: m=  (((y - gi[-1]) / fi )* l )+ ai
    return (((y-giMinusOne)/fiValue) * l) + ai;
}
bool amar::checkValueInQueue(queue<float>data,float value)
{
    int len = data.size();
    for(int i=1;i<=len;i++)
    {
        if(data.front() != value)
            data.pop();
        else
            return true;
    }
    return false;
}
void amar::chark(queue<float>data)
{
    queue<float> tempData;
    int len = data.size();
    float q1=0; float q2=0; float q3=0;
    q2 = simpleMiane(data);

    if(!checkValueInQueue(data,q2))
    {
        for(int t=0; t<= (len/2-1); t++)
        {
            tempData.push(data.front());
            data.pop();
        }
        q1 = simpleMiane(tempData);

        //q2 is here
        data.pop();
        data.pop();

        cleanQueue(tempData);
        for(int t=0; t<= (len/2-1); t++)
        {
            tempData.push(data.front());
            data.pop();
        }
        q3 = simpleMiane(tempData);
    }
    else
    {
        for(int i=1; i<= 2; i++)
        {
            cleanQueue(tempData);
            for(int t=1; t<= len/2; t++)
            {
                tempData.push(data.front());
                data.pop();
            }
            data.pop();
            if(i==1)
                q1 = simpleMiane(tempData);
            else
                q3 = simpleMiane(tempData);
        }
    }

     charkValues.push(q1);
     charkValues.push(q2);
     charkValues.push(q3);
     cout << "q1=" << q1 << "\tq2=" << q2 << "\tq3=" << q3 << endl;
}
float amar::simpleMiane(queue<float>data)
{
    int len = data.size();
    float sum=0;

    if(len%2)
    {
        for(int i=1; i<= (len/2); i++)
            data.pop();
        return data.front();
    }
    else
    {
        len = (int)len/2;
        for(int i=1; i<= (len+1); i++)
        {
            if(i == len || i == len+1)
                sum += data.front();

            data.pop();
        }
    }
    return sum/2;
}
float amar::avrageFromTableFaravani(queue<float>x,queue<float>f)
{
    int len = x.size();
    float n=0;
    float sum=0;

    for(int i=1; i<= len; i++)
    {
        sum += (x.front() * f.front());
        n += f.front();
        x.pop();
        f.pop();
    }

    sum = sum/n;


    return sum;
}
void amar::giveInput(queue<float>&q)
{
    cout << "enter length: ";
    int len=0;
    cin >> len;

    float ar[len];
    for(int i=0; i<=len-1; i++)
    {
        cout << "enter #" << i << " number: ";
        cin >> ar[i];
        q.push(ar[i]);
    }
}
float amar::simpleAvrage(queue<float>q)
{
    int len = q.size();
    float sum=0;
    for(int i=1;i<=len;i++)
    {
        sum += q.front();
        q.pop();
    }


    return sum/len;
}
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
void amar::fi(queue<float>tempQ)
{
    int counter=0;
    float temp=0;
    for(int i=0; i<=dataCount-1; i++)
    {
        temp = tempQ.front();
        tempQ.pop();
        counter++;
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
       x.push(a[i]);

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
        cout << "queue were empty!" << endl;

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
    o.giveInput();
//    float arr[30] = {5,4,2,1,1,1,3,3,3,2,0,5,0,2,2,2,2,4,4,1,0,1,1,3,2,5,2,1,0,4};
//    for(int te=0;te<=30-1;te++)
//        o.data.push(arr[te]);

    o.sortQueue(o.data);
    o.xi(o.data);
    o.fi(o.data);
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
int amar::fi2NumberCounter(float ar[],float kDown,float kUp,int arsize)
{
    int counter=0;

    for(int i=0; i<arsize; i++)
    {
        float temp = ar[i];
//        cout << "\n\nar[" << i << "]="  << ar[i] << endl;
        //for float ar[i]
        int a= temp;
        temp = temp - a;
        temp = temp *10;
        temp = round(temp);
        int b=  temp;
        temp = (float)b/10;
        float resultAB = a + temp;

//        cout << "resultAB=" << resultAB << endl;
        //for kDown
        temp = kDown;
        int akDown = temp;
        temp = temp - akDown;
        temp = temp *10;
        temp = round(temp);
        int bkDown = temp;
        temp = (float)bkDown / 10;
        kDown = akDown + temp;

//        cout << "KDOWN=" << kDown << endl;
        //for kUp
        temp = kUp;
        int akUp = temp;
        temp = temp - akUp;
        temp = temp *10;
        temp = round(temp);
        int bkUp = temp;
        temp = (float)bkUp / 10;
        kUp = akUp + temp;


//        cout << "KUP=" << kUp << endl;
        if(resultAB >= kDown && resultAB < kUp)
        {
//            cout << "- - - ab=" << resultAB << " is >= kdown " << kDown << " and AB="  << resultAB << " is < kup " <<kUp << endl;
            counter++;
        }

    }

//    cout << "****************************** counter=" << counter << endl;
    return counter;
}
void amar::fi2(queue<float>data,queue<float>classLevels)
{
//    cout <<"data from fi2=\n";
//        printQueue(data);
//        cout <<"classLevels from fi2=\n";
//            printQueue(classLevels);


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
//            cout << "\nkdown=" << karanDown;
//            cout << "kup=" << karanUp;

            f.push(fi2NumberCounter(dataArray,karanDown,karanUp,lendata));
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
    o.giveInput();
//    float arr[30] =
//    {2.0,2.1,2.3,3.0,3.1,2.7,
//     2.8,3.5,3.1,3.7,3.1,2.6,
//     3.5,4.0,2.3,3.5,4.2,3.7,
//     3.2,2.7,2.5,2.7,3.8,3.0,
//     2.8,2.9,4.1,3.2,2.8,2.2};


//    for(int te=0;te<=30-1;te++)
//        o.data.push(arr[te]);

    o.sortQueue(o.data);

    float L = o.L(o.R(o.data),o.K()); //space between classes
    o.classLevel(o.data,L);
    cout << "\n\n\n\n";
    o.fi2(o.data,o.classLevels);
    for(int i=1; i<= (int)o.K(); i++) //bcz gi() will give size from queue x and queue x is empty. we need to fill with '0' as classesLength, classesLength is on K()
        o.x.push(0);

    o.ri(o.f);
    o.gi(o.f,o.x);
    o.classAgent(o.classLevels);
    o.printTableClass(o.classLevels, o.f, o.r, o.g, o.classAgents);
}
void amar::printTableSection2_2(queue<float> x, queue<float> f)
{
    int len = x.size();
    cout << "xi|\tfi" << endl;
    for(int i=1; i<=len; i++)
    {
        cout << x.front() << "\t" << f.front() << endl;
        x.pop();
        f.pop();
    }
}
void amar::section2_2(amar o)
{
    // - - - - simple Avrage - - - -
    /*
    o.giveInput(o.simpleAvrageValues);
    o.sortQueue(o.simpleAvrageValues);
    float avrage = o.simpleAvrage(o.simpleAvrageValues);
    cout << "avrage= " << avrage << endl;
    */





    // - - - - Avrage from Table simple Faravani - - - -

    /* //for fast test automatically fill data queue
     * float auto_data[30] = {
                           2,2,2,2,2,2,2,2,
                           1,1,1,1,1,1,1,
                           4,4,4,4,
                           3,3,3,3,
                           5,5,5,
                           0,0,0,0
                          };
    for(int i=0;i<=30-1;i++)
        o.data.push(auto_data[i]);*/

    /*
    o.giveInput(o.data);
    o.sortQueue(o.data);
    o.xi(o.data);
    o.fi();
    o.printTableSection2_2(o.x,o.f);
    float avrage = o.avrageFromTableFaravani(o.x,o.f);
    cout << "------ Avrage = " << avrage << endl;
    */


    // - - - - simple Miane - - - -
//    cout << "simple Miane= " << o.simpleMiane(o.data);



    // - - - - Chark - - - -
    /*
     *     float auto_data[11] = {35,30,33,39,
                          41,29,30,36,
                          45,40,31};
    for(int i=0;i<=11-1;i++)
        o.data.push(auto_data[i]);
     */

/*  o.giveInput(o.data);
    o.sortQueue(o.data);
    o.chark(o.data);*/







    // - - - - miane From Table Faravani - - - -
    /*const int len = 30;
        float arr[len] =
        {
            2.0,2.1,2.3,3.0,3.1,2.7,2.8,3.5,3.1,3.7,3.1,2.6,3.5,
            4.0,2.3,3.5,4.2,3.7,3.2,2.7,2.5,2.7,3.8,3.0,2.8,2.9,
            4.1,3.9,2.8,2.2

        };
    for(int i=0;i<=len-1;i++)
        o.data.push(arr[i]);
    */

    /*
    o.giveInput(o.data);
    o.sortQueue(o.data);
    cout << o.mianeFromTableFaravani() << endl;
    */




    // - - - - Mode/Nama From Faravani Table - - - -
    //formul M =  ((d1 / (d1+d2)) * L)+ ai
    const int len = 8;
        float arr[len] =
        {
             17,13,11,9,7,4,3,2
        };
    for(int i=0;i<=len-1;i++)
        o.data.push(arr[i]);

    o.simpleMode(o.data);
    printQueue(o.modes);
    if(o.modes.size() == 0)
        cout << "these numbers dont have MODE." << endl;



    queue<float> tempD;
    float arr2[9] =
            {
                 15,17,16,14,15,16,18,15,12
            };
    for(int i=0;i<=9-1;i++)
        tempD.push(arr2[i]);

    printQueue(tempD);

    o.simpleMode(tempD);
    printQueue(o.modes);



//    float arr3[9] =
//            {
//                 67,67,67,65,65,65,63,62,65
//            };

//    for(int i=0;i<=9-1;i++)
//        o.data.push(arr3[i]);
//    o.simpleMode(o.data);
//    printQueue(o.modes);
}
int main()
{
    amar o;
//    o.section1(o);
//    o.section2(o);
    o.section2_2(o);

    return 0;
}
