#include<iostream>
using namespace std;
/*default constructor
class cons
{
    int m,n;
    public:
    cons()  //constructor made..constructor should be of same name as class
    {
        cout<<"default constructor invoked\n";
    }
    void display()
    {
        cout<<"value of x is "<<m<<endl;
        cout<<"value of y is "<<n<<endl;

    }
};
int main()
{
    cons s;
    s.display();
    return 0;

}*/
/*parameterized constructor
class cons
{
    int m,n;
    public:
    cons(int x,int y)
    {
        cout<<"parametterized constructor\n";
        m=x; n=y;
    }
    
    void put();

};
void cons::put()
{
    cout<<m<<" "<<n;
}
int main()
{
    int a,b;
    cout<<"enter value x,y\n";
    cin>>a>>b;
    cons t1(a,b);
    
    
    t1.put();
    return 0;
}*/
/*copy constructor
class sample
{
    int n;
    public:
    sample()
    {
        n=0;
    }
    sample(int a)
    {
        n=a;
    }
    sample(sample &x)
    {
        n=x.n;
    }
    void display()
    {
        cout<<n<<endl;
    }
};
int main()
{
    sample A(100);
    sample B(A);

    sample C=A;
    sample D;
    D=A;
    A.display();
    B.display();
    C.display();
    D.display();
    return 0;
}
*/
/*destructor
class marks
{
    public:

    marks()
    {
        cout<<"inside constructor"<<endl;
        cout<<"c++ object created\n";
    }
    ~marks()
    {
        cout<<"inside destructor\n ";
        cout<<"c++ destructor created\n";
    }
};
    int main()
    {
        marks m1;
        
        return 0;
    }
*/
class student
{
    public:

}
