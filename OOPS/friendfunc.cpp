#include<iostream>
using namespace std;
//friend function
/*
class friendfunc
{
    int x,y;
    public:
    void readdata()
    {
        cout<<"\nenter two no.";
        cin>>x>>y;
    }
    friend void add(friendfunc calc);

};
void add(friendfunc calc)
{
    cout<<"sum is : "<<calc.x+calc.y;
}
int main()
{
    friendfunc calc;
    calc.readdata();
    add(calc);
    return 0;
}*/

//friend class

class B;
class A
{
    public:
    //constructor to initialize numA to 12
    A():numA(12)
    {

    }
    private:
    int numA;
    //friend function declaration
    friend int add(A,B);

};
class B
{
    public:
    //constructor to initialize numB to 1
    B():numB(1)
    {

    }
    private:
    int numB;
    //friend function declaration
    friend int add(A,B);
};
//access members of both classes
int add(A objA,B objB)
{
    return(objA.numA+objB.numB);
}
int main()
{
    A objA;
    B objB;
    cout<<"Sum :\t"<<add(objA,objB);
    return 0;
}