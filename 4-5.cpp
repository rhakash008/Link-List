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

void deletion(node* &head,int val)
{
    node* temp=head;
    while(temp->next->data!=val)
    {
        temp = temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
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
    deletion(head,4);
    cout<<"\nNEW: ";
    show(head);
        return 0;
}
