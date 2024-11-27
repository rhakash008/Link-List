#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
        node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void deleteatlast(node* &head) {
    if (head == NULL) return; 
    
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    node* toDelete = temp->next;
    temp->next = NULL;
    delete toDelete;
}

void deletehead(node* &head)
{
    node* todelete=head;
    head = head->next;
    delete todelete;
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

void show(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << "->NULL" << endl;
}

int main() {
    node* head = NULL;
    int num;

    for (int i = 0; i < 6; i++) {
        cin >> num;
        insert(head, num);
    }

    cout << "Main linked list: ";
    show(head);
    deletehead(head);
    cout << "\nDeleting first node : ";
    show(head);
    deleteatlast(head);
    cout<<"\nDeleting last node: ";
    show(head);
    deletion(head,44);
    cout<<"\nDeleting between 2 nodes: ";
    show(head);
    return 0;
}

