#include<iostream>

using namespace std;

// Linked List

struct node{
    int data;
    node* next;
};

// Create A NULL node
node* getNode(int data)
{
    node* newNode=new node();
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

// Insert At Head
node* InsertAtHead(node* head, int data)
{
    node* newNode=getNode(data);

    if(head==NULL)
    {
        head=newNode;
        return head;
    }

    newNode->next=head;
    head=newNode;
}


// Insert At Tail
node* InsertAtTail(node* head, int data)
{
    node* newNode=getNode(data);
    if(head == NULL)
    {
        head=newNode;
        return head;
    }

    node* temp=head;

    while(temp->next != NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
}

node* InsertAtNth(node* head, int data, int pos)
{
    node* newNode=getNode(data);

    if(head == NULL)
    {
        head=newNode;
        return head;
    }

    if(pos == 0 || pos==1)
    {
        newNode->next=head;
        head=newNode;

        return head;
    }

    node* temp=head;

    for(int i=0; i<pos-2; i++)temp=temp->next;

    node* nPost=temp->next;
    newNode->next=nPost;
    temp->next=newNode;

    return head;

}


node* DeleteNth(node* head, int pos)
{
    if(head == NULL)
    {
        return head;
    }

    if(pos == 0 || pos==1)
    {
        node* nHead=head;
        head=nHead->next;

        delete nHead;

        return head;
    }

    node* temp=head;
    for(int i=0; i<pos-2; i++)
    {
        temp=temp->next;
    }

    node* nPre=temp;
    node* n=temp->next;
    node* nPost=n->next;

    nPre->next=nPost;

    delete n;

    return head;
}

void traversal(node* head)
{
    node* temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}


int main()
{

    node* head=NULL;
    head=InsertAtNth(head, 10,1);
    head=InsertAtNth(head, 85,2);
    head=InsertAtNth(head, 71,3);
    head=InsertAtNth(head, 57,4);
    head=InsertAtNth(head, 68,5);
    head=InsertAtNth(head, 78,6);

    traversal(head);
    cout<<"\nDeleted Position 2\n";

    head=DeleteNth(head, 2);
    traversal(head);

    cout<<"\nDeleted Position 1\n";
    head=DeleteNth(head, 1);
    traversal(head);

    return 0;
}
