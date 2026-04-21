#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;

    //constructor
    node(int data)
    {
        this ->data=data;
        this ->next=NULL;
    }
    //node ki memory free krane ke liye
    //destructor bna lia 
    ~node()
    {
        int value=this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data value "<<value<<endl;
    }
};

    insertAtHead(node* &head,int d)
    {
        cout<<"inserting at head"<<endl;
        //new node will be created
        node* temp=new node(d);
        temp -> next=head;
        head=temp;
    }

    insertAtTail(node* &tail,int d)
    {
        cout<<"inserting at tail"<<endl;
        //new node will be created
        node* temp=new node(d);
        tail ->next=temp;
        tail=tail -> next;
    }

    void insertAtAnyPosition(int position,node* &head,node* &tail,int d)
    {
        cout<<"inserting at new position"<<endl;
        node* temp=head;
        int cnt=1;

        //inserting at first position
        if(position==1)
        {
            insertAtHead(head,d);
            return;
        }

        //for any other position
        while(cnt<position-1)
        {
            temp=temp->next;
            cnt++;
        }
        
        //inserting at last position
        if(temp->next==NULL)
        {
            insertAtTail(tail,d);
            return;
        }
        node* nodeToInsert=new node(d);
        nodeToInsert-> next=temp ->next;
        temp->next=nodeToInsert;

    }

    printhead(node* &head)
    {
        node* temp=head;

        while(temp != NULL)
        {
            cout<< temp -> data<<" ";
            temp=temp -> next;
        }
        cout<<endl;
    }

    printtail(node* &tail)
    {
        node* temp=tail;

        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp=temp -> next;
        }
        cout<<endl;
    }

    //deleting node using position
    void deletenode(node* &head,int position)
    {
        cout<<"deleting node"<<endl;

        //deleting starting node
        if(position==1)
        {
            node* temp= head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
        //deleting any middle node or any last node
        else
        {
            //2 pointer bna lenge current aur previous
            //jo delete honi hogi use current m rkhenge
            //jo previous hogi uski next ki value change kr denge

            node* current=head;
            node* previous=NULL;

            int cnt=1;
            while(cnt <= position)
            {
                previous=current;
                current=current->next;
                cnt++;
            }
            previous->next=current->next;
            current->next=NULL;
            delete current;
        }
    }

int main()
{
    node* node1=new node(10);

    //cout<<node1 ->data<<endl;
    //cout<<node1 ->next<<endl;

    node* head=node1;
    printhead(head);

    insertAtHead(head,12);
    printhead(head);

    insertAtHead(head,15);
    printhead(head);

    node* tail=node1;
    printhead(tail);

    insertAtHead(tail,12);
    printhead(tail);

    insertAtHead(tail,15);
    printhead(tail);

    insertAtAnyPosition(4,head,tail,11);
    printhead(head);

    deletenode(head,1);
    printhead(head);

    deletenode(head,2);
    printhead(head);
    return 0;
}