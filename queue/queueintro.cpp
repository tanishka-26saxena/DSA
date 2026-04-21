#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int main()
{
    //create a deque
     deque<int> d;
    d.push_front(11);
     d.push_back(14);

     cout<<d.back()<<endl;
     cout<<d.front()<<endl;

     d.pop_front();

      cout<<d.back()<<endl;
     cout<<d.front()<<endl;

     if(d.empty())
     {
        cout<<"deque is empty"<<endl;
     }
     else{
        cout<<"deque is not empty"<<endl;
     }

    //create a queue
    /*
    queue<int> q;

    q.push(11);
    cout<<"front of q is : "<<q.front()<<endl;
    q.push(13);
    q.push(15);

    cout<<"size of queue is: "<<q.size()<<endl;

    q.pop();
    cout<<"front of q is : "<<q.front()<<endl;

    cout<<"size of queue is: "<<q.size()<<endl;

    if(q.empty())
    {
        cout<<"q is empty"<<endl;
    }
    else{
        cout<<"q is not empty"<<endl;
    }
    */
}