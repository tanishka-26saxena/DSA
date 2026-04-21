#include<iostream>
#include<queue>
using namespace std;
class kqueue
{
    public:
    int n;
    int k;
    int *front;
    int* rear;
    int *arr;
    int freespot;
    int *next;

    public:
    kqueue(int n,int k)
    {
        this->n=n;
        this->k=k;
        front=new int(k);
        rear=new int(k);
        for(int i=0;i<k;i++)
        {
            front[i]=-1;
            rear[i]=-1;
        }

        next=new int(n);
        for(int i=0;i<n;i++)
        {
            next[i]=i+1;
        }
        next[n-1]=-1;

        arr=new int(n);
        freespot=0;


    }
    void enqueue(int data,int qn)
    {
        if(freespot == -1)
        {
            cout<<"no empty space "<<endl;
            return ;
        }

        int index=freespot;

        freespot=next[index];

        if(front[qn-1] == -1)
        {
            front[qn-1]=index;
        }
        else{
            next[rear[qn-1]] =index;
        }

        next[index] = -1;

        rear[qn-1] = index;

        arr[index]=data;
    }

    int dequeue(int qn)
    {
        //underflow ki condition check kro
        if(front[qn-1] == -1)
        {
            cout<<"empty hai poori"<<endl;
            return -1;
        }

        //index find kro pop krne ke liye
        int index = front[qn-1];

        //front ko aage badha do qki pop kr denge front ke current index ko 
        front[qn]=next[index];

        //free spot ko manage kr lo that is link bna do ki popped element ke freespot ke baad agla kaha aayega
        next[index]=freespot;
        freespot=index;
        return arr[index];

    }


};
int main()
{
    kqueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    return 0;

}
