#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node* next;

  node(int val)
  {
      data=val;
      next=NULL;
  }
};

void insert(node* &head,int val){
    node* n=new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    node* temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void athead(node* &head,int val)
{
    node* n = new node(val);
    n->next=head;
    head=n;
}

void show(node* head)
{
    node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        if (temp->next != NULL) { 
            cout << "->";
        }
        temp = temp->next;
    }
    cout <<"->NULL"<<endl;
}

int main()
{
    node* head=NULL;
    int num;
    for(int i=0;i<5;i++){
        cin>>num;
        insert(head,num);
    }
    cout<<"Main link list: ";
    show(head);
    athead(head,44);
    cout<<"\nInserting at the first: ";
    show(head);
    insert(head,55);
    cout<<"\nInserting at the last: ";
    show(head);
    
    return 0;
}
