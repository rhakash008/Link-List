#include<iostream>
using namespace std;

int main() {
    struct node {
        int data;
        node* link;
    };
    
    int item;
    node *nptr, *eptr, *fptr;
    fptr = NULL;
    
    cout << "Enter node numbers: ";
    
    for(int i = 0; i < 5; i++) {
        cin >> item;
        nptr = new node;
        nptr->data = item;
        nptr->link = NULL;
        
        if (fptr == NULL) {
            fptr = nptr;
            eptr = nptr;
        } else {
            eptr->link = nptr;
            eptr = nptr;
        }
        

    }
    
    cout << "\nLinked List: ";
    node* temp = fptr;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;

    return 0;
}
