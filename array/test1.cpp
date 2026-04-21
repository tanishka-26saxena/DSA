#include<iostream>
using namespace std;
int main()
{
    int a[100][100];
    cout<<"enter no. of rows for 1st array\n";
    int n;
    cin>>n;
    cout<<"enter no. of coloumns for 1st array\n";
    int l;
    cin>>l;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }
    int b[100][100];
    cout<<"enter no. of rows for 2nd array\n";
    int m;
    cin>>m;
    cout<<"enter no. of coloumns for 2nd array\n";
    int t;
    cin>>t;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<t;j++)
        {
            cin>>a[m][t];
        }
        cout<<endl;
    }
    cout<<"multiplication of 2 arrays is\n";
    int mul[n][t];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<t;j++)
        {
          mul[i][j]=0;
          for(int k=0;k<2;k++)
            {
              
            
            mul[i][j]=mul[i][j]+a[i][k]*b[k][i];
        }
          cout<<mul[i][j]<<"\t";
    }
      cout<<endl;
    
    return 0;
}
}