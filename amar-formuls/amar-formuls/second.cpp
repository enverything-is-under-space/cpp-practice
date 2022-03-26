#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>

using std::queue;
using std::cin;
using std::cout;
using std::endl;

using namespace std;
class amar
{
    private:
        queue<float> data,x,f,g,r;
    public:
        void sortQueue(queue<float>);
        void getinput();
        void removeDuplicatedValue(queue<float>);
        void copyQueue(queue<float>,queue<float>); //copy first to second
        void printQueue(queue<float>);
        void swapQueue(queue<float>,queue<float>);
        int N();

};

void amar::swapQueue(queue<float>q1, queue<float>q2)
{
    swap(q1,q2);
}
void amar::printQueue(queue<float>q)
{
    cout << "- - - - - printQueue:" << endl;
    for(float a=0; a<=q.size(); a++)
    {
        cout << q.front() << "\t";
        q.pop();
    }
    cout << "- - - - -" << endl;
}
int amar::N()
{
    return data.size();
}
void amar::getinput()
{
    int rounds=0;
    cout << "enter numbers count: ";
    cin >> rounds;

    for(int a=1;a<=rounds;a++)
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

void amar::sortQueue(queue<float>a)
{
    std::sort( a.begin(), a.end() );
}
void amar::removeDuplicatedValue(queue<float>a)
{
    if(!a.empty())
    {

    }
    else
        cout << "queue was empty!" << endl;

}

int main()
{

}
