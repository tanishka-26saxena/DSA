#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};
void levelOrderTraversal(node* root)
{
    cout<<"level order traversal of the given input is: "<<endl;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp -> data<<" ";
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
void inorderTraversal(node* &root)
{
    if(root == NULL)
    {
        return ;
    }

    inorderTraversal(root->left);
    cout<<root -> data << endl;
    inorderTraversal(root->right);
}

void preorderTraversal(node* &root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root->data<<endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* &root)
{
    if(root == NULL)
    {
        return ;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<endl;

}

node* minval(node* root)
{
    node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;   
    }
    return temp;
}

node* maxval(node* root)
{
    node* temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(node* root, int val)
{
    
    if(root == NULL)
    {
        return false;
    }
    if(root->data == val)
    {
        return true;
    }
    else if(root->data > val)
    {
        return searchInBST(root->left,val);
    }
    else{
        return searchInBST(root->right , val);
    }
    return false;
}
node* deleteInBST(node* root, int val)
{
    //base case
    if(root == NULL)
    {
        return root;
    }

    if(root->data == val)
    {
        //0 child
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        //1  left child
        if(root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        //1 right child
        if(root->left == NULL && root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        //aise case chahe to root ke left sub tree se max 
        //value nikal kr use swapkr do root se aur fr delete
        //kr do root ya fr right sub tree se min val nikal kr 
        //root ki value se swap krke use delete kra do

        //is function m hum root ke right se min value nikalenge
        if(root->left!=NULL && root->right!=NULL)
        {
            int mini = minval(root->right) -> data;
            root->data = mini;
            root->right = deleteInBST(root->right,mini);
            return root;
         }

    }
    else if(root->data > val)
    {
        root->left = deleteInBST(root->left , val);
        return root;
    }
    else
    {
        root->right = deleteInBST(root->right, val);
        return root;
    }

}
node* insert_into_bst(node* root, int d)
{
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insert_into_bst(root->right, d);
    }
    else
    {
        root->left = insert_into_bst(root->left, d);
    }
    return root; 
}
node* takeInput(node* &root)
{
    int data;
    cin>>data;
    

    while(data != -1)
    {
        root = insert_into_bst(root,data);
        cin>>data;
    }
    return root;
}
int main()
{

    node* root = NULL;
    cout<<"enter data"<<endl;
    takeInput(root);

    levelOrderTraversal(root);

    cout<<"inorder traversal of the given input is :"<<endl;
    inorderTraversal(root);

    cout<<"enter the node to be deleted";
    int v;
    cin>>v;
    root = deleteInBST(root,v);

    cout<<"preorder traversal of the given input is: "<<endl;
    preorderTraversal(root);

    cout<<"postorder traversal of the given input is: "<<endl;
    postorderTraversal(root);

    cout<<"min val is:"<<minval(root)->data<<endl;
    cout<<"max val is:"<<maxval(root)->data<<endl;

    cout<<"enter the node to be searched";
    int val;
    cin>>val;
    if(searchInBST(root,val))
    {
        cout<<"entered node is present "<<endl;
    }
    else
    {
        cout<<"entered node is not present "<<endl;
    }

    return 0;
    
}