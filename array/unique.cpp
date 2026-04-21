#include<iostream>
using namespace std;
int check(int a[],int num)
{
    int ans=0;
    for(int i=0;i<num;i++)
    {
        ans=ans^a[i];
    }
    cout<<"answer is ";
    cout<<ans;
}
int main()
{
    int n;
    cout<<"enter the lengh of array"<<endl;
    cin>>n;
    cout<<"enter array";
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    check(arr,n);
    return 0;
}