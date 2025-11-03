#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char val) : data(val), prev(nullptr), next(nullptr) {}
};

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    while (head != tail && head->prev != tail) {
        if (head->data != tail->data)
            return false;
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

void insertEnd(Node*& head, char val) {
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

int main() {
    Node* head = nullptr;

    string word = "madam";
    for (char ch : word) {
        insertEnd(head, ch);
    }

    if (isPalindrome(head))
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is NOT a palindrome." << endl;

    return 0;
}
