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

void deletion(node* &head) {
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

    for (int i = 0; i < 5; i++) {
        cin >> num;
        insert(head, num);
    }

    cout << "Main linked list: ";
    show(head);

    deletion(head);

    cout << "\nNew : ";
    show(head);

    return 0;
}
