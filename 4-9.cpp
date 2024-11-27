#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node* next;
  node* prev;

    node(int val)
  {
      data=val;
      next= NULL;
      prev= NULL;
  }
};

void insert(node* &head,int val)
{
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void insertathead(node* &head,int val)
{
    node* n = new node(val);
    n->next=head;
    if(head != NULL)
    {
        head->prev=n;
    }
    head=n;
}

void insertat(node* &head,int val)
{
    node* n = new node(val);
    node* temp = head;
    while(temp->data != 5)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    n->prev=temp;
    temp->next->prev=n;
    temp->next=n;
}

void show(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node* head = NULL;
    int i,num;
    cout<<"Enter nodes: ";
    for(i=0;i<7;i++)
    {
        cin>>num;
        insert(head,num);
    }
    cout<<"Main list: ";
    show(head);
    insertathead(head,99);
    cout<<"\nInserting at head: ";
    show(head);
    cout<<"\nInserting at the last: ";
    insert(head,22);
    show(head);
    
    cout<<"\nInserting at a position: ";
    insertat(head,88);
    show(head);
    return 0;
}
