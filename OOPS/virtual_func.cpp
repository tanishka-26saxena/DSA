#include<iostream>
using namespace std;
/*
class Base
{
    public:
    virtual void show()
    {
        cout<<"base class\n";
    }
};
class derived:public Base
{
    public:
    void show()
    {
        cout<<"derived class\n";
    }
};
int main()
{
    Base* b;
    derived d;
    b=&d;
    b->show();
    d.show();
    return 0;
}
*/
//abstract base class
class base
{
    public:
    virtual void show()=0;
};
class derived:public base{
    public:
    void show()
    {
        cout<<"implementation of virtual function in derived class\n";

    }
};
int main()
{
    base* b;
    derived d;
    b=&d;
    b->show();
   
    return 0;
}