#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void splitCircularList(Node* head, Node*& head1, Node*& head2) {
    if (!head || head->next == head) {
        head1 = head;
        head2 = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow;
    Node* tail = fast->next == head ? fast : fast->next;

    head1 = head;
    head2 = mid->next;

    mid->next = head1;

    tail->next = head2;
}

void printCircularList(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 6; ++i) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    temp->next = head; 

    Node *head1 = nullptr, *head2 = nullptr;
    splitCircularList(head, head1, head2);

    cout << "First half: ";
    printCircularList(head1);
    cout << "Second half: ";
    printCircularList(head2);

    return 0;
}
