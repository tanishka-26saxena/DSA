#include<iostream>
using namespace std;
int main()
{
    cout<<"enter first array\n";
    int aa[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>aa[i][j];
        }
    }
    cout<<"emter second array"<<endl;
    int ab[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>ab[i][j];
        }
    }
  cout<<"first array is"<<endl;
  for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<aa[i][j]<<"\t";
        }
        cout<<endl;
    
    }
  cout<<"second array is"<<endl;
  for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<ab[i][j]<<"\t";
        }
        cout<<endl;
    
    }
    cout<<"multiplication of the above matrixes is"<<endl;
    int mul[2][2];
  
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
          mul[i][j]=0;
          for(int k=0;k<2;k++)
            {
              
            
            mul[i][j]=mul[i][j]+aa[i][k]*ab[k][i];
        }
          cout<<mul[i][j]<<"\t";
    }
      cout<<endl;
    
    
    }
  
}