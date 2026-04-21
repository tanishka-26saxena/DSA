#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &s,int count,int size)
{
    if(count==size/2)
    {
        s.pop();
        return ;
    }
    int num=s.top();
    s.pop();

    //recursive call mardo
    solve(s,count+1,size);

    s.push(num);

}
void delete_middle(stack<int> &s,int n)
{
    int c=0;
    solve(s,c,n);
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    delete_middle(s,5);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    

}