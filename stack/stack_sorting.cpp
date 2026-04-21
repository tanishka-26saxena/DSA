#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s,int num)
{
    if((s.empty()) || ((!s.empty() && s.top()<num)))
    {
        s.push(num);
        return;
    }

    int x=s.top();
    s.pop();

    sortedInsert(s,num);

    s.push(x);


}
void ssort(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int num=s.top();
    s.pop();

    ssort(s);

    sortedInsert(s,num);
}

int main()
{
    stack<int> s;
    s.push(12);
    s.push(1);
    s.push(10);
    s.push(5);
    s.push(13);
    ssort(s);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    return 0;
}