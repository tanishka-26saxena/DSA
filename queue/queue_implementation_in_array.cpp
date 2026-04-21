#include<iostream>
using namespace std;
class queue
{
    private:
    int* arr;
    int front;
    int rear;
    int size;

    public:
    queue()
    {
        size=100000;
        arr=new int(size);
        front =0;
        rear=0;
    }
    bool isEmpty()
    {
        if(front==rear)
        {
            return true;
        }
        return false;
    }
    void enque(int data)
    {
        if(rear==size)
        {
            cout<<"stack overflow"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    int deque()
    {
        if(front==rear)
        {
            cout<<"nothing to pop out"<<endl;
            return -1;
        }  
        else{
            int ans=arr[front];
            arr[front] = -1;
            front++;
            if(front==rear)
            {
                front=0;
                rear=0;

                return ans;
            }
        }
    }
    int front_element()
    {
        if(front==rear)
        {
            cout<<"nothing is in queue"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

};
int main()
{
    queue q;

    q.enque(12);
    q.enque(13);
    q.enque(14);

    cout<<"element in front is :"<<q.front_element()<<endl;
    cout<<"popping an element out: "<<q.deque()<<endl;
    cout<<"checking if queue is empty: "<<q.isEmpty();
}