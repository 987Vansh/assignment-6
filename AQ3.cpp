#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* curr = head;
    Node* newHead = nullptr;
    Node* groupPrev = nullptr;

    while (curr) {
        Node* groupStart = curr;
        Node* temp = curr;
        int count = 0;

        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        Node* prev = temp;
        Node* next = nullptr;
        for (int i = 0; i < count; ++i) {
            next = curr->next;
            curr->next = prev;
            if (prev) prev->prev = curr;
            prev = curr;
            curr = next;
        }

        if (!newHead) newHead = prev;
        if (groupPrev) {
            groupPrev->next = prev;
            prev->prev = groupPrev;
        }

        groupPrev = groupStart;
    }

    return newHead;
}

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int k = 3;
 int arr[] = {10, 20, 30, 40, 50, 60, 70};
    for (int val : arr) insertEnd(head, val);

    cout << "Original List:\n";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}
