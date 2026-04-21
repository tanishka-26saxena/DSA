#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

    node(int d)
    {
        this->data=d;
        this->left = NULL;
        this->right=NULL;

    }
};

node* buildTree(node* root)
{
    cout<<"enter the data : "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"enter the tree to be inserted in left: "<<endl;
    root->left = buildTree(root->left);
    cout<<"enter the data to be inserted in right: "<<endl;
    root->right = buildTree(root->right);

    return root;
}


node* buildFromLevelTree(node* root)
{
    queue<node*> q;
    cout<<"enter data for root node: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right node for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }




    }
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
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

void inorderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = NULL;
    buildFromLevelTree(root);

    cout<<"printing the level order traversal of tree"<<endl;
    levelOrderTraversal(root);
    
    /*
    //creating a tree
    root=buildTree(root);

    //level order traversal

    cout<<"printing the inorder traversal of tree "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"printing the inorder traversal of tree "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"printing the inorder traversal of tree "<<endl;
    postorderTraversal(root);
    */


    return 0;
}