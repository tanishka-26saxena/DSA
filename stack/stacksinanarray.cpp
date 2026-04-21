#include<iostream>
using namespace std;
class two_stacks
{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    two_stacks(int s)
    {
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }
    void push1(int num)
    {
        if(top2-top1>1)
        {
            top1++;
            arr[top1]=num;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void push2(int num)
    {
        if(top2-top1>1)
        {
            top2--;
            arr[top2]=num;
        }
        else
        {
            cout<<"stack overflow"<<endl;
        }
    }
    int pop1()
    {
        int ans=0;
        if(top1>=0)
        {
            top1--;
            ans=arr[top1];
           
        }
        else{
            return -1;
        }
         return ans;
    }
    int pop2()
    {
        int ans=0;
        if(top2<size)
        {
            top2++;
            ans=arr[top2];
           
        }
        else{
            return -1;
        }
        return ans;
    }
    
};
int main()
{
    two_stacks s(5);
    s.push1(23);
    s.push2(45);
    s.push1(65);
    s.push2(43);
    s.push1(22);
    cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop1()<<endl;

    return 0;
}