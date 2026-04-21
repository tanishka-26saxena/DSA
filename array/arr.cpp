#include<iostream>
using namespace std;
int main()
{
    int arr[5];
    int counte=0;
    int counto=0;
    cout<<"enter 5 elements"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the number you want to  search"<<endl;
    int n;
    cin>>n;
    
    for(int i=0;i<5;i++)
    {
        if(arr[i]==n)
        {
            cout<<"number is at "<<i<<"position"<<endl;
        }
        else{
            cout<<"not found";
        }
        /*if(arr[i]%2==0)
        {
            counte+=1;
        }
        else{
            counto+=1;

        }*/
    }
    //cout<<"no. of even numbers "<<counte<<endl;
    //cout<<"no. of odd numbers "<<counto<<endl;
    return 0;
}