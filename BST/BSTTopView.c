#include<stdio.h>
#include<unordered_map>
#include<queue>

// Create a tree structure

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root=NULL;


// Empty node in heap
node* getNode(int data)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

// Insert node to the tree
void insert(node* root, int data)
{
    if(root==NULL)
    {
        node* newNode=getNode(data);
        root=newNode;
    }
    else if(data < root->data) root->left=insert(root->left, data);
    else root->right=insert(root->right, data);
}

// Level order traversal
void Level_Traversal(node* root);


// Top view of the binary tree
void topView(node* root)
{
    if(root == NULL) return;

    unordered_map<int,int> m;

}

int main()
{


    return 0;
}
