#include<iostream>
using namespace std;
int sum(int num,int arr[])
{
    
    int sums=0;
    for(int i=0;i<=num;i++)
    {
        sums=sums+arr[i];
    }
    cout<<"sum of numbers is "<<sums;
}
int main()
{
    int arr[100];
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<"enter array";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sum(n,arr);
    return 0;
}