#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=0;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            c++;
        }
    }
    if(c>0)
    {
        cout<<"number npt prime";
    }
    else{
        cout<<"number is prime";
    }
}