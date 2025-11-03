#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void displayCircularList(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << head->data << endl;
}

int main() {
    Node* head = new Node(20);
    head->next = new Node(100);
    head->next->next = new Node(40);
    head->next->next->next = new Node(80);
    head->next->next->next->next = new Node(60);
    head->next->next->next->next->next = head; 

    displayCircularList(head);

    return 0;
}
