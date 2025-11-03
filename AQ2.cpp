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

void removeEvenFromDLL(DNode*& head) {
    DNode* curr = head;
    while (curr) {
        if (curr->data % 2 == 0) {
            DNode* toDelete = curr;
            if (curr->prev) curr->prev->next = curr->next;
            else head = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            curr = curr->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
}

void removeEvenFromCLL(CNode*& head) {
    if (!head) return;

    while (head && head->data % 2 == 0) {
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        CNode* last = head;
        while (last->next != head) last = last->next;
        CNode* toDelete = head;
        head = head->next;
        last->next = head;
        delete toDelete;
    }

    if (!head) return;

    CNode* curr = head;
    while (curr->next != head) {
        if (curr->next->data % 2 == 0) {
            CNode* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
}

void printDLL(DNode* head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void printCLL(CNode* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    CNode* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

int main() {
    DNode* dHead = new DNode(10);
    dHead->next = new DNode(15);
    dHead->next->prev = dHead;
    dHead->next->next = new DNode(20);
    dHead->next->next->prev = dHead->next;
    dHead->next->next->next = new DNode(25);
    dHead->next->next->next->prev = dHead->next->next;
    dHead->next->next->next->next = new DNode(30);
    dHead->next->next->next->next->prev = dHead->next->next->next;

    CNode* cHead = new CNode(5);
    cHead->next = new CNode(10);
    cHead->next->next = new CNode(15);
    cHead->next->next->next = new CNode(20);
    cHead->next->next->next->next = new CNode(25);
    cHead->next->next->next->next->next = cHead; // circular link

    cout << "Original Doubly Linked List:\n";
    printDLL(dHead);
    removeEvenFromDLL(dHead);
    cout << "After removing even nodes:\n";
    printDLL(dHead);

    cout << "\nOriginal Circular Linked List:\n";
    printCLL(cHead);
    removeEvenFromCLL(cHead);
    cout << "After removing even nodes:\n";
    printCLL(cHead);

    return 0;
}
