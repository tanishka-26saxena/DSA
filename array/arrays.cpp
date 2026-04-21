#include<iostream>
using namespace std;
int main()
{
    int arr[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
  int sums=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
          sums=sums+arr[i][j];
            //cout<<arr[i][j]<<"\t";
        }
      
      //cout<<endl;
    }
  cout<<"sum of the array is"<<sums;
    return 0;
}