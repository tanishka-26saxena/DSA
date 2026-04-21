#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;

    //constructor
    node(int d)
    {
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }

    //destructor
    ~node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with data"<<val<<endl;
    }
};
void print(node* &head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp=temp -> next;
    }
    cout<<endl;
}
int getlength(node* &head)
{
    node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;

    }
    return cnt;
}
void insertAtHead(node* &head,int d)
{
    if(head==NULL)
    {
        node* temp=new node(d);
        head=temp;
    }
    else{
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}

void insertAtTail(node* &tail,int d)
{
    if(tail==NULL)
    {
        node* temp=new node(d);
        tail=temp;
    }
    else{
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
}
void insertAtPosition(node* &head,node* &tail,int pos,int d)
{
    node* temp=head;
    int cnt=1;
    //inserting at start
    if(pos==1)
    {
        insertAtHead(head,d);
        return;
    }
    while(cnt<=pos-1)
    {
        temp=temp->next;
        cnt++;

    }
    //inserting at last
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    //inserting at given position
    node* nodeToInsert=new node(d);

    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}

void deletenode(node* &head,int pos)
{
    if(pos==1)
    {
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        node* curr=head;
        node* prev=NULL;

        int cnt=1;
        while(cnt<=pos)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    node* node1 = new node(10);
    node* head=node1;
    node* tail=node1;

    print(head);

    insertAtHead(head,11);
    print(head);

    cout<<"length of linked list when inserted at head is: "<<getlength(head)<<endl; 

    insertAtTail(tail,18);
    print(head);

    insertAtTail(tail,16);
    print(head);

    insertAtPosition(head,tail,3,4);
    print(head);

    deletenode(head,2);
    print(head);

    

    return 0;
}