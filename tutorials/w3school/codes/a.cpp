#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <istream>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ifstream;
using std::ofstream;
void functionswap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}

void createfile()
{
    ofstream myfile("/home/mrx/Documents/github/cpp-practice/tutorials/w3school/codes/first_file.txt");
    myfile << "This is text from c plus plus";
    myfile.close();
}


void printfile()
{
    string mytext;

    ifstream myfile("/home/mrx/Documents/github/cpp-practice/tutorials/w3school/codes/first_file.txt");
    while(getline (myfile,mytext))
    {
        cout << mytext;
    }
    myfile.close();
}

// void functionarraytest(int my[5]) EEROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOR
// {
//     for(int x: my)
//     {
//         cout << x << endl;
//     }
        
// }


int main()
{
    /*
    int x=10;
    x&=3;
    cout << x << endl;
    
    x=10;
    x|=3;
    cout << x << endl;

    x=10;
    x^=3;
    cout << x << endl;

    x=10;
    x>>=3;
    cout << x << endl;

    x=10;
    x<<=3;
    cout << x << endl;
    */





    // int y=1,x=2;
    // cout << (x>y) << endl;



    // string name = "Alex Engle";
    // name.append("is good man");
    // cout << name << endl;



    // string a = "10",b="20";
    // cout << a + b << endl;
    


    // string testString = "This is a sample text";
    // cout << testString.size() << endl;
    // cout << testString.length() << endl;



    // string testString = "this is test string";
    // cout << testString[5] << testString[6] << endl;


    // string testString = "this is test string";
    // testString[5] = 'n';
    // testString[6] = 'o';
    // testString[7] = 't';
    // cout << testString;
    


    // string username;
    // int age;
    // cout << "enter name";
    // getline(cin, username);
    // // cin >> username;

    // cout << "enter age";
    // cin >> age;
    // cout << username << "\t" << age << endl;



    // int x=2;
    // int y=10;
    // cout << "is x>=y? " << std::boolalpha << ((x>=y) ? true : false) << endl;


   
    // int myar[5] = {10,20,30};
    // for(int i: myar)
    // {
    //     cout << i << endl;
    // }
    // cout << sizeof(myar);
    
    

   /*
    struct 
    {
        int age;
        string name;
    } player1,player2;


    player1.age=10;
    player1.name = "alex";
    
    player2.age = 20;
    player2.name = "black";

    cout << player1.age << "\t" << player1.name << endl;
    cout << player2.age << "\t" << player2.name << endl;
    */



   /*
   struct players
   {
        int age;
        string name;
   };


   players player1;
   player1.age = 12;
   player1.name = "alex";
   players playerbitch;
   playerbitch.age= 11;

   cout << player1.age << "\t" << player1.name << "\t" << playerbitch.age << endl;
   */



    // string food = "pizza";
    // string &meal = food;
    // cout << food << endl << meal;




    // int x=1,y=2;
    // cout << x << endl << y << endl;
    // functionswap(x,y);
    // cout << x << endl << y << endl;


    // int mya[5] = {1,2,3};
    // functionarraytest(mya); // ERROOOOOOOOOOOOOOOOOOOOOOOOOOOOOR


    // createfile();



    // printfile();




    // try
    // {
    //     int age =10;
    //     if(age>=18)
    //         cout << "you are adult" << endl;
    //     else
    //     {
    //         throw 5005;
    //     }
    // }
    //// catch(...)
    //// {
    ////     cout << "you are not adult" << endl;
    //// }
    // catch (int i) 
    // {
    //     if(i == 505)
    //             cout << "you are not adult" << endl;
    //     else
    //         cout << "error code = " << i << endl;
    // }


    return 0;
}