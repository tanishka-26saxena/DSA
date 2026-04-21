
//**********function overloding**********




/*#include<iostream>
using namespace std;
class A
{
    int a;
    float b;
    public:
    void disp(int x,float y)
    {
        b=y;
    a=x;
        cout<<"addition is:"<<a+b<<endl;
    }
    void disp(float x,int y)
    {
        b=x;
        a=y;
        cout<<"multiply is:"<<x*y<<endl;
    }
};
int main()
    {
        int a,b;
        cin>>a>>b;
        A obj;
        obj.disp(a,b);
        obj.disp();
        return 0;
        
    }*/




    //*************operator overloading***********



    #include <iostream>
    using namespace std;
    /*class number
    {
        private:
        int x;
        public:
        Number(int p)
        {
            x=p;
        }
        void operator -()
        {
            x=-x;

        }
        cout<<"x="<<x;
    }*/

/*#include <iostream>
using namespace std;

    //****************INLINE FUNCTION***************

 float mul(float a ,float b)
{
    return(a*b);

}
 double div(double x,double y)
{
    return(x/y);
}
int main()
{
    float s=21.66;
    float t=43.99;
    cout<<"multiplication is "<<mul(s,t)<<endl;
    cout<<"divition is "<<div(s,t)<<endl;
    return 0;
}*/




//***********POINTER***********



/*int main()
{
    int a=20;
    int*b;
    b=&a;
    cout  <<a<<  endl;
    cout<<&a<<endl;
    cout<<b<<endl;
    cout<<&b<<endl;
    cout<<*b<<endl;
    return 0;
}*/




//**************NULL POINTER***********
/*int main()
{
    int*a=NULL;
    cout<<"the value of a is "<<a;
    return 0;
}*/




//***********POINTER TO POINTER**********

/*int main()
    {
        int m=66,*a,**b;
        a=&m;
        b=&a;
        cout<<"value of a is "<<a<<endl;
        cout<<m<<endl;
        cout<<&m<<endl;
        cout<<a<<endl;
        cout<<*a<<endl;
        cout<<b<<endl;
        cout<<*b<<endl;
        cout<<&b<<endl;
        return 0;
    }*/





    //*****************ARRAY OF POINTER**************

/*int main()
{
    int arr[5];
    int *ptr[5];
    cout<<"enter the five values:"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
        ptr[i]=&arr[i];
    } 
    cout<<"the values are "<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<&ptr[i]<<endl;
        cout<<ptr[i]<<endl;
        cout<<*ptr[i]<<endl;
    } return 0;

}*/


//******FUNCTION POINTER**********

/*int add(int , int);
int add(int a,int b)
{
    return a+b;

}
int main()
{
    int (*ptr)(int,int);
    ptr=add;
    int sum=ptr(5,5);
    cout<<"value of sum is:"<<sum<<endl;
    return 0;

}*/









//**************POINTER TO CLASS MEMBER***********

/*class simple
{
    public:
    int a=134;

};
int main()
{
    simple obj;
    simple* ptr;
    ptr=&obj;
    cout<<obj.a<<endl;
    cout<<ptr->a;
    return 0;
}*/









    



