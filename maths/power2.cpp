#include <iostream>
using namespace std;
int check(int n)
{
    int count=0,p;
    while(n>0)
    {
        p=n%2;
        count ++;
        
    }
    if (count>0)
    {
        cout<<"entered number caan be expressed in the form of 2 to the power "<<count<<endl;
    }
    else{
        cout<<"number cannot be expresssed in the power of 2";
    }
}
int main()
{
    int num;
    cout<<"enter the number";
    cin>>num;
    check(num);
    return 0;
}