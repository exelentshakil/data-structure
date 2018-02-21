#include<iostream>

using namespace std;

// BST node

struct node{
    int data;
    node* left;
    node* right;
};

/**
 * Insert a node
 */

 node* insertNode(node* root, int data)
 {
     node* newNode=new node;
     newNode->data=data;
     newNode->left=NULL;
     newNode->right=NULL;

     if(root == NULL)
     {
         root=newNode;

     }
     else{

        while(1)
        {
            if(data < root->data)
            {
                if(root->left == NULL)
                {
                    root->left=newNode;

                    return root;
                }
                else{
                    root->right=newNode;
                }
            }
            else
            {
                if(root->left == NULL)
                {
                    root->left=newNode;
                }
                else{
                    root->right=newNode;
                }
            }

            return root;
        }
     }

     return root;

 }

 /**
  * In Order Traversal
  */

  void inOrderTraversal(node* root)
  {
      if(root != NULL)
      {
          inOrderTraversal(root->left);
          cout<<root->data<<" ";
          inOrderTraversal(root->right);
      }
  }

  /**
   * In Order Successor
   */

// C function to search a given key in a given BST
node* searchNode(node* root, int data)
{
	// Base case
	if(root == NULL || root->data == data) return root;

	if(data < root->data) return searchNode(root->left, data);
	else{

        return searchNode(root->right, data);
	}

}


node* findMin(node* root)
{
    if(root==NULL) return NULL;
    while(root->left != NULL)
        root=root->left;
    return root;
}

node* inOrderSuccessor(node* root, int data)
{

    node* current=searchNode(root, data);

    if(current == NULL) return NULL;

    if(current->right != NULL)
    {
        return findMin(current->right);
    }
    else{

        node* successor=NULL;
        node* ancestor=root;

        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
                ancestor=ancestor->right;

        }

        cout<<successor->data<<endl;
        return successor;
    }
}



int main()
{
    node* root=NULL;

    root=insertNode(root,80);
    root=insertNode(root,70);
    root=insertNode(root,60);
    root=insertNode(root,65);
    root=insertNode(root,90);


    inOrderTraversal(root);
    node* successor=inOrderSuccessor(root, 60);

    cout<<"\nIn Order Successor: "<<successor->data;
    return 0;
}
