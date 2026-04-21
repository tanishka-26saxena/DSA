#include<iostream>
using namespace std;
int palindrome(int n)
{
    int temp=0;
    temp=n;
    int rem,s=0;
    while(n>0)
    {
    rem=n%10;
    s=(s*10)+rem;
    n=n/10;
    }
    if(temp==s)
    {
        cout<<"is palindrome"<<endl;
    }
    else{
        cout<<"is not palindrome"<<endl;
    }

}
int main()
{
    cout<<"enter a no."<<endl;
    int n;
    cin>>n;
    palindrome(n);
    return 0;
}