#include<iostream>
using namespace std;
void rowsum(int a[3][3])

{
    cout<<"row sum is:"<<endl;
    int rsum=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            rsum+=a[i][j];
        }
        cout<<rsum<<" ";
        rsum=0;
    }
    cout<<endl;
    
    
}
void largesum(int a[3][3])
{
    int rsum=0;
    int maxi=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            rsum+=a[i][j];
        }
        if(rsum>maxi)
        {
            maxi=rsum;
        }
        rsum=0;
    }
    cout<<"maximum row sum is "<<maxi;
    cout<<endl;
}
void wave(int a[3][3])
{
    for(int j=0;j<3;j++)
    {
        if(j%2!=0)
        {
            for(int i=2;i>=0;i--)
            {
                cout<<a[i][j]<<" ";
            }
        }
        else{
            for(int i=0;i<3;i++)
            {
                cout<<a[i][j]<<" ";
            }
        }
    }
}
void colsum(int a[3][3])

{
    cout<<"column sum is:"<<endl;
    int csum=0;
    for(int j=0;j<3;j++)
    {
        for(int i=0;i<3;i++)
        {
            csum+=a[i][j];
        }
        cout<<csum<<" ";
        csum=0;
    }
    cout<<endl;
    
}
int main()
{
    int arr[3][3];
    cout<<"enter array"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"array output is"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    rowsum(arr);
    colsum(arr);
    largesum(arr);
    wave(arr);
    return 0;

}
