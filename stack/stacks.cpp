#include<iostream>
#include<stack>
using namespace std;
//a class that will implement stack functions without using stl
class stack_implementation_in_array
{
    public:
    int top;
    int *arr;
    int size;

    stack_implementation_in_array(int size)
    {
        this->size=size;
        arr=new int(size);
        top=-1;
    }
    void push( int element)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=element;
        }
        else
        {
            cout<<"stack overflow"<<endl;
        }
    }
    void pop()
    {
        if(top>=0)
        {
            top--;
        }
    }
    int peek()
    {   
        if(top>=0 && top<size)
        {
        return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return false;
        }
        else{
            return true;
        }
    }

};
int main()
{
    stack_implementation_in_array s(5);
        s.push(22);
        s.push(43);
        s.push(56);
        s.push(78);
        cout<<s.top<<endl;
        
        s.pop();
        cout<<s.top<<endl;
        s.pop();
       cout<< s.peek()<<endl;
        if(s.isEmpty())
        {
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<"stack is not empty"<<endl;
        }
    /*
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"printing top element "<<s.top()<<endl;

    s.pop();
    s.pop();
    cout<<"printing top element "<<s.top()<<endl;

    if(s.empty())
    {
        cout<<"it is empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    return 0;
    */

    
}