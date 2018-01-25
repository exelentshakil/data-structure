#include<iostream>
#include<queue>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* FindMin(node* root)
{
    while(root->left != NULL) root=root->left;
    return root;
}

node* Insert(node* root, int data)
{
    if(root==NULL)
    {
        node* newNode=new node();
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;

        root=newNode;

    }
    else if(data < root->data)root->left=Insert(root->left, data);
    else root->right=Insert(root->right, data);

    return root;
}

node* Delete(node* root, int data)
{
    if(root==NULL) return root;
    else if(data < root->data) root->left=Delete(root->left, data);
    else if(data > root->data) root->right=Delete(root->right, data);
    else{

        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left == NULL)
        {
            node* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node* temp=root;
            root=root->left;
            delete temp;
        }
        else{

            node* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right, temp->data);
        }
    }

    return root;
}

void InOrder(node* root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        cout<<root->data<<" ";
        InOrder(root->right);
    }
}

node* LevelOrder(node* root)
{
    if(root==NULL) return root;
    else{

        queue<node*> q;
        q.push(root);

        while(!q.empty())
        {
            node* frontNode=q.front();
            q.pop();
            cout<<frontNode->data<<" ";

            if(frontNode->left != NULL) q.push(frontNode->left);
            if(frontNode->right != NULL) q.push(frontNode->right);
        }
    }
}

int main()
{
    /*
        29
        / \
       10  47
       /   /
      5   40

    */
    node* root=NULL;

    root=Insert(root, 29);
    root=Insert(root, 47);
    root=Insert(root, 10);
    root=Insert(root, 5);
    root=Insert(root, 40);

    InOrder(root);
    Delete(root, 10);
    cout<<"\n";
    InOrder(root);

	return 0;
}
