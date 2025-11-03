#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isCircular(Node* head) {
    if (!head) return false;

    Node* temp = head->next;
    while (temp && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = head1;

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    cout << "List 1 is " << (isCircular(head1) ? "Circular" : "Not Circular") << endl;
    cout << "List 2 is " << (isCircular(head2) ? "Circular" : "Not Circular") << endl;

    return 0;
}
