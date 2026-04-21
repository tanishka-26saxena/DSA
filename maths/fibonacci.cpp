#include <iostream>
using namespace std;
int fibonacci(int n)
{
    int a=-1;
    int b=1;
    int nextnum;
    for(int i =1;i<=n;i++)
    {
        nextnum=a+b; 
        cout<<nextnum;
        a=b;
        b=nextnum; 
    }
    
    //cout<<"fibonacci number : "<<nextnum;
}
int main()
{
    int n;
    cout<<"enetr number"<<endl;
    cin>>n;
    fibonacci(n);
}