#include<iostream>
using namespace std;
/*
int main()
{
    int n;
    cout<<"enter length of row of first array\n";
    cin>>n;
    cout<<"enter length of coloumn of first array\n";
    int l;
    cin>>l;
    cout<<"enter first array\n";
    int aa[n][l];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            cin>>aa[i][j];
        }
    }
    int l2;
    cout<<"enter length of row of first array\n";
    cin>>l2;
    cout<<"enter length of coloumn of first array\n";
    int m;
    cin>>m;
    cout<<"emter second array"<<endl;
    int ab[l2][m];
    for(int i=0;i<l2;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ab[i][j];
        }
    }
  cout<<"first array is"<<endl;
  for(int i=0;i<n;i++)
    {
        for(int j=0;j<l;j++)
        {
            cout<<aa[i][j]<<"\t";
        }
        cout<<endl;
    }
  cout<<"second array is"<<endl;
  for(int i=0;i<l2;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ab[i][j]<<"\t";
        }
        cout<<endl;
    }
    if(l==l2)
    {
    cout<<"multiplication of the above matrixes is"<<endl;
    int mul[n][m];
  
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
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
else
{
    cout<<"multiplication not possible";
}
}
*/
/*
void multiply(int n)
{
    int rem;
    int mul=1;
    
    while(n>0)
    {
        rem=n%10;
        mul=mul*rem;
        n=n/10;
    }
    cout<<mul;
}
int main()
{
    cout<<"enter a number\n";
    int num;
    cin>>num;
    multiply(num);
    return 0;

}
*/
/*
int disp(int a,int b)
{
    cout<<a+b<<endl;
}
int disp(int a)
{
    cout<<a*a;

}
int main()
{
    int c,d;
    cout<<"enter two numbers\n";
    cin>>c>>d;
    disp(c,d);
    disp(c);
   return 0;
}
*/