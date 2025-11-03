#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

int sizeOfDoublyLinkedList(DNode* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeOfCircularLinkedList(CNode* head) {
    if (!head) return 0;
    int count = 1;
    CNode* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    DNode* dHead = new DNode(10);
    dHead->next = new DNode(20);
    dHead->next->prev = dHead;
    dHead->next->next = new DNode(30);
    dHead->next->next->prev = dHead->next;

    CNode* cHead = new CNode(5);
    cHead->next = new CNode(15);
    cHead->next->next = new CNode(25);
    cHead->next->next->next = cHead; // circular link

    cout << "Size of Doubly Linked List: " << sizeOfDoublyLinkedList(dHead) << endl;
    cout << "Size of Circular Linked List: " << sizeOfCircularLinkedList(cHead) << endl;

    return 0;
}
