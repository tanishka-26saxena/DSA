#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    //constructor
    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

    //destructor
    ~node()
    {
        int val=this->data;
        while(next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"memory space is free for the node with data"<<val<<endl;
    }
};
bool isCircularList(node* &head)
{
    node*temp=head->next;
    if(head==NULL)
    {
        return NULL;
    }

    while(temp!=NULL &&  temp!=head)
    {
        temp=temp->next;
    }
  
    if(temp==NULL)
    {
        return false;
    }
    return true;
}
void insertnode(node* &tail,int element,int d)
{
    
    //empty list
    if(tail==NULL)
    {
        node* temp=new node(d);
        tail=temp;
        tail->next=tail;
    }
    else{
        node* curr=tail;
        while(curr->next->data!=element)
        {
            curr=curr->next;
        }

        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
        
    }
}
void print(node* &tail)
{
    node* temp=tail;
    do
    {
       cout<<tail->data<<" ";
        tail=tail->next;
    } 
    while(tail->next!=temp);
    cout<<endl;
}

void deletenode(node* &tail,int d)
{
    node* curr=tail->next;
    node* prev=tail;

    if(curr==prev)
    {
        tail=NULL;
    }

    while(curr->data !=d)
    {
        prev=curr;
        curr=curr->next;
    }

    prev->next=curr->next;
    if(tail==curr)
    {
        tail=prev;
    }
    curr->next=NULL;
    delete curr;
}
int main()
{
   
    node* tail=NULL;

    insertnode(tail,2,11);
    //print(tail);

    insertnode(tail,11,10);
    //print(tail);

    insertnode(tail,11,12);
    //print(tail);

    insertnode(tail,10,14);
    print(tail);

    //deletenode(tail,11);
    //print(tail);

    cout<<isCircularList(tail);

    return 0;
}