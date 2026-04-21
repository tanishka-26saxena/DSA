#include<iostream>
using namespace std;

//reference variable
/*
int main()
{
    int i=5;
    int &j=i;
    cout<<i<<endl;
    cout<<j<<endl;
    i++;
    cout<<i<<endl;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    cout<<j<<endl;

    return 0;
}*/

//using dynamic memory allocations
/*
int sums(int *arr,int num)
{
    int s=0;
    for(int i=0;i<num;i++)
    {
    s+=arr[i];
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<endl;
    }
    cout<<"sum is "<<sums(arr,n);
}
*/

int main()
{
    int n;
    cout<<"enter rows\n";
    cin>>n;
    int m;
    cout<<"enter columns\n";
    cin>>m;
    int **a=new int *[n];
    cout<<"enter sizes \n";
    int size[100];
    for(int i=0;i<n;i++)
    {
        cin>>sizes[i];
    }
    for(int i=0;i<m;i++)
    {
        a[i]=new int[sizes[i]];
    }
    cout<<"enter array\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
