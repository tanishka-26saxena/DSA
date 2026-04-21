#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};


node* build_tree(node* root)
{
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new node (data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"enter data for inserting in left"<<endl;
    root->left=build_tree(root->left);
    cout<<"enter data for inserting in right"<<endl;
    root->right=build_tree(root->right);

}


void levelOrderTraversal(node* root)
{
    queue <node*> q;
    q.push(root);
    q.push(NULL);

while(!q.empty())
{
    node* temp=q.front();
    q.pop();

    if(temp==NULL)
    {
        cout<<endl;
        cout<<temp -> data<<" ";
        if(!q.empty())
        {
            q.push(NULL);
        }
    }
    else{
    if(temp->left)
    {
        q.push(temp->left);
    }
    if(temp->right)
    {
        q.push(temp->right);
    }
}
}
}

int main()
{
    node* root;
    root = build_tree(root);
    //1,3,7,-1,-1,11,-1,5,17,-1,-1,-1
    levelOrderTraversal(root);
}