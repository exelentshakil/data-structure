#include<iostream>
#include<unordered_map>
#include<queue>



using namespace std;

// Create a tree structure

struct node{
    int data;
    node* left;
    node* right;
};


// Empty node in heap
node* getNode(int data)
{
    node* newNode=new node();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

// Insert node to the tree
node* insertNode(node* root, int data)
{

    node* newNode=getNode(data);

    if(root==NULL)
    {
        root=newNode;
    }
    else if(data <= root->data) root->left=insertNode(root->left, data);
    else root->right=insertNode(root->right, data);

    return root;
}

// Level order traversal
void Level_Traversal(node* root)
{
    if(root==NULL)return;

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* n=q.front();
        q.pop();

        cout<<n->data<<" ";

        if(n->left != NULL) q.push(n->left);
        if(n->right != NULL) q.push(n->right);
    }


}

void p(node* root)
{
    if(root!=NULL)
    {
        p(root->left);
        cout<<root->data<<" ";
        p(root->right);
    }
}


// Top view of the binary tree
void topView(node* root)
{
    if(root == NULL) return;

    unordered_map<int,int> m;
    queue<pair<node*, int>> q;

    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<node*,int> p=q.front();
        node* n=p.first;
        int val=p.second;
        q.pop();

        if(m.find(val) == m.end())
        {
            m[val]=n->data;
            cout<<n->data<<" ";
        }

        if(n->left != NULL) q.push(make_pair(n->left, val-1));
        if(n->right != NULL) q.push(make_pair(n->right, val+1));
    }

}

int main()
{
    node* root=NULL;
    root=insertNode(root,40);
    root=insertNode(root,35);
    root=insertNode(root,50);
    root=insertNode(root,30);
    root=insertNode(root,38);

    // level order traversal
    Level_Traversal(root);
    cout<<endl;
    // top view of BST
    topView(root);



    return 0;
}
