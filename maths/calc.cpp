#include<iostream>
using namespace std;
int main()
{
    int a,b,res=0;
    char op;
    cout<<"enter a number";
    cin>>a;
    cout<<"enter 2nd number";
    cin>>b;
    cout<<"enetr operator";
    cin>>op;
    switch(op)
    {
        case '+':
        res=a+b;
        break;
        case '-':
        res=a-b;
        break;
        case '*':
        res=a*b;
        break;
        case '/':
        res=a/b;
        break;
        default:
        printf("error");
        break;   
    }
    return 0;
}