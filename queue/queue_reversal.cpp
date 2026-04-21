#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    cout<<q.front()<<endl;
    q.pop();

    cout<<q.front()<<endl;
    q.pop();

    cout<<q.front()<<endl;
    q.pop();

    cout<<q.front()<<endl;
    q.pop();

    cout<<q.front()<<endl;
    q.pop();

    cout<<q.front()<<endl;
    q.pop();




    return 0;
}