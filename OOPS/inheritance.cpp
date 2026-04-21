#include<iostream>
using namespace std;
/*class A
{
    public:
    int a,b;
    void get()
    {
        cout<<"enter any two integeer values"<<endl;
        cin>>a>>b;
    }

    
};
class B:public A{
    int c;
public:
void add()
{
    c=a+b;
    cout<<a<<"+"<<b<<"="<<c;
}
};
int main()
{
    B b;
    b.get();
    b.add();
    return 0;
}*/
//multilevel

/*class A
{
    public:
    int a;
    void getA()
    {
        cout<<"enter integer"<<endl;
        cin>>a;
    }

};
class B
{
    public:
    int b;
    void getB()
    {
        cout<<"enter an integer"<<endl;
        cin>>b;
    }
};
class C:public A,public B
{
    public:
    int c;
    void add()
    {
        c=a+b;
        cout<<c;
    }
};
int main()
{
    C obj;
    obj.getA();
    obj.getB();
    obj.add();
    return 0;
}*/
//using scope resolution operator
/*class A
{
    public:
    int a;
    void getA();
};
void A::getA();
{
        cout<<"enter integer"<<endl;
        cin>>a;
    

}
class B
{
    public:
    int b;
    void getB();
    
    
};
void B::getB()
{
    cout<<"enter an integer"<<endl;
        cin>>b;
}
class C:public A,public B
{
    public:
    int c;
    void add();
};
void C::add()
{
        c=a+b;
        cout<<c;
    }
int main()
{
    C obj;
    obj.getA();
    obj.getB();
    obj.add();
    return 0;
}
*/
// hybrid inheritance
/*class arithmetic
{
    protected:
    int num1,num2;
    public:
    void getdata()
    {
        cout<<"for addition:"<<endl;
        cout<<"enter first number"<<endl;
        cin>>num1;
        cout<<"enter second number"<<endl;
        cin>>num2;
        
    }
};
class plus1:public arithmetic{
    protected:
    int sum;
    public:
    void add()
    {
        sum=num1+num2;
    }
};
class minus1
{
    protected:
    int n1,n2,diff;
    public:
    void sub()
    {
        cout<<"for subtraction"<<endl;
         cout<<"enter first number"<<endl;
        cin>>n1;
        cout<<"enter second number"<<endl;
        cin>>n2;
        diff=n1-n2;
        cout<<diff;
    }
};
class result:public plus1,public minus1{
    public:
    void display()
    {
        cout<<"sum of "<<num1<<"and"<<num2<<"is "<<sum<<endl;
        cout<<"diff of "<<n1<<"and"<<n2<<"is "<<diff;
    }

};
int main()
{
    result z;
    z.getdata();
    z.add();
    z.sub();
    z.display();
    return 0;
}
*/
//heirarical inheritance
#include<iostream>
using namespace std;
class A //BASE CLASS
{
    public:
    int a,b;
    void getnumber()
    {
        cout<<"\nEnter number:\t";
        cin>>a;
    }
};
class B:public A    //DERIVED CLASS
{
    public:
    void square()
    {
        getnumber();
        cout<<"\nSquare of the number: \t"<<(a*a);
    }
};
class C:public A//DERIVED CLASS 2
{
    public:
    void cube()
    {
        getnumber();
        cout<<"\ncube of number is: \t"<<(a*a*a);
    }
};
int main()
{
    B b1;
    b1.square();
    C c1;
    c1.cube();
    return 0;
}
