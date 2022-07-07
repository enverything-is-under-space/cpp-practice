#include "my.h"
// #include <iostream>

// using namespace std;

int add(int,int);

void donothing(int&)
{

}

int five()
{
    return 5;
}
int main()
{
    // int x={2};
    // cout << x;

    // int x,y;
    // cout << " enter numbs " ;
    // cin >> x >> y;

    // int x{};
    // cout << x << endl;
    // int y;
    // cout << y << endl;
    // int z=0;
    // cout << z << endl;

    // int x;
    // donothing(x);

    // cout << "Hello"
    //         "world";



    // cout << "hello 
    // world";


    // int a{2*5+(66/5)};
    // cout << a;
    // int b{five()};
    // cout << b;

    // int x=2,y=2;
    // cout << add(x,y);





    // #define version1
    // #define version2
    // #ifdef version1
    //     cout << "this is verison 1" << endl;
    // #endif

    // #ifdef version2
    //     cout << "this is version 2 " << endl;
    // #endif



    // #define version1
    // #define version2
    // #ifdef version1
    //     cout << "version 1 is defined" << endl;
    // #endif

    // #ifndef version2
    //     cout << "version 2 is not difenied but its automaticily from ifndef code preproccseosr"<< endl;
    // #endif



    // #if 0
    //     cout << "never print this hooh" << endl;
    // #endif

    // cout << "helo" << retme(50) <<endl;


    //#pragma once ERRORRRR
    //#progma


    // int x=2;
    // cout << x/0 << endl;



    // #include <plog/Log.h>
    // PLOG << "something called";
    // main {plog::init(plog::debug, "des");}



    // int a;
    // short b;
    // long c;
    // long long d;
    // short int e;
    // long int f;
    // long long int g;
    // signed short h;
    // signed int i;
    // signed long sl;
    // signed long long sll;
    // int8_t aa;
    // uint8_t bb;
    // int16_t cc;
    // uint16_t dd;
    // int32_t ee;
    // int64_t ff;



    // cout << std::setprecision(16);


    // bool test{!true};



    // return (x==y);


    //if(4) //->true anyway

    //cout << "\a \b \f \n \r \t \v \' \" \\ \? \(number) \x(number)" << endl;



    // static_cast<int>(5.5)



    // unsigned int you {5u};
    // int xy {static_cast<int>(you)};


    //cant print int8_t into console so use static_cast<int>(var)



    //const double gravity {55};
    //int const something {10};


    // const double kGravity{2}; //k means konst
    //const int MARS_GRAVITY {44}; 



    //compile and run-time constants
    // const int something {2}; //compile time
    // const int somethingelse {1+1}; // run time const
    //const int soemthingelsebuytnothing {myfunction()}; //run time 


    // constexpr  is for better performance to compiler know and convert run-time consts into compile-time consts for exmaple
    // int age;
    // constexpr int myage{age}; //error cant assaing unvalued into constexpr
    // constexpr double gravity {9.8};
    // constexpr int sum {1+2};// compiler will ocnvert into compiletime const
    // constexpr int see {sum};

    //FUNCTION PARAMETERE can be const but cant use constexpr !!!!!!


    //literal type 
    // int a {10U};
    // int b{10L};
    // int c {10UL};
    // int d {10LL};
    // int e {10ULL};
    // double f{10.0F};
    // double g{10.0L};
    // string s{"something"s};
    // string ff {"somethingviewonly"sv}; //std::string::view



    // cout << 5 ;
    // cout << 5L;
    // cout << 5.4F;




    //convert from double into float may losss precision.



    // double electron {1.6e-19};
    // double notron {3.14e23};



    //decimal and octal
    //decmial is 0123456789 10 11
    //octal is 01234567 10 11 12 13
    // int x {012}; //octal
    // cout << x;


    //decimal and hexadecimal
    //decimal  = 0->17
    //hex = 0->9 A B C D E F 10 11
    // int x {0xF}; //hex
    // cout << x;




    //BINARY
    // int bin{}; //assume 16-bit int 
    // bin = 0x0001; //means 0000 0000 0000 0001 
    // bin = 0b1; //means 0000 0000 0000 0001



    // int bin{0b1011'0010}; //dont use before first digit of value like 0b'1011'0010 -> be error 
    // long vlaue {2'132'673'462};



    // cout << std::hex << x;
    // cout << std::oct << x;
    // cout << std:dec << x;



    // #include <bitset>
    // using std::bitset;
    // bitset<8> bin1 {0b1100'0101};
    // bitset<8> bin2 {0xC5};
    // cout << bitset<4> {0b1010};

    return false;
}