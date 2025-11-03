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

class DoublyLinkedList {
    DNode* head = nullptr;

public:
    void insertFirst(int val);
    void insertLast(int val);
    void insertBefore(int key, int val);
    void insertAfter(int key, int val);
    void deleteNode(int key);
    void search(int key);
    void display();
};

class CircularLinkedList {
    CNode* head = nullptr;

public:
    void insertFirst(int val);
    void insertLast(int val);
    void insertBefore(int key, int val);
    void insertAfter(int key, int val);
    void deleteNode(int key);
    void search(int key);
    void display();
};

void DoublyLinkedList::insertFirst(int val) {
    DNode* newNode = new DNode(val);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::insertLast(int val) {
    DNode* newNode = new DNode(val);
    if (!head) {
        head = newNode;
    } else {
        DNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void DoublyLinkedList::insertBefore(int key, int val) {
    if (!head) return;
    DNode* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return;
    DNode* newNode = new DNode(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev) temp->prev->next = newNode;
    else head = newNode;
    temp->prev = newNode;
}

void DoublyLinkedList::insertAfter(int key, int val) {
    DNode* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return;
    DNode* newNode = new DNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void DoublyLinkedList::deleteNode(int key) {
    DNode* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return;
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
}

void DoublyLinkedList::search(int key) {
    DNode* temp = head;
    while (temp) {
        if (temp->data == key) {
            cout << "Found node with value " << key << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node not found." << endl;
}

void DoublyLinkedList::display() {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void CircularLinkedList::insertFirst(int val) {
    CNode* newNode = new CNode(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void CircularLinkedList::insertLast(int val) {
    CNode* newNode = new CNode(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
    } else {
        CNode* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void CircularLinkedList::insertBefore(int key, int val) {
    if (!head) return;
    CNode* temp = head, *prev = nullptr;
    do {
        if (temp->data == key) break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    if (temp->data != key) return;
    CNode* newNode = new CNode(val);
    newNode->next = temp;
    if (temp == head) {
        CNode* last = head;
        while (last->next != head) last = last->next;
        last->next = newNode;
        head = newNode;
    } else {
        prev->next = newNode;
    }
}

void CircularLinkedList::insertAfter(int key, int val) {
    if (!head) return;
    CNode* temp = head;
    do {
        if (temp->data == key) {
            CNode* newNode = new CNode(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void CircularLinkedList::deleteNode(int key) {
    if (!head) return;
    CNode* temp = head, *prev = nullptr;
    do {
        if (temp->data == key) break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    if (temp->data != key) return;
    if (temp == head) {
        CNode* last = head;
        while (last->next != head) last = last->next;
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            last->next = head->next;
            CNode* del = head;
            head = head->next;
            delete del;
        }
    } else {
        prev->next = temp->next;
        delete temp;
    }
}

void CircularLinkedList::search(int key) {
    if (!head) return;
    CNode* temp = head;
    do {
        if (temp->data == key) {
            cout << "Found node with value " << key << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node not found." << endl;
}

void CircularLinkedList::display() {
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
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, val, key;

    while (true) {
        cout << "\nChoose List Type:\n1. Doubly Linked List\n2. Circular Linked List\n3. Exit\nChoice: ";
        cin >> listType;
        if (listType == 3) break;

        cout << "\nMenu:\n1. Insert First\n2. Insert Last\n3. Insert Before\n4. Insert After\n5. Delete Node\n6. Search Node\n7. Display\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                (listType == 1) ? dll.insertFirst(val) : cll.insertFirst(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                (listType == 1) ? dll.insertLast(val) : cll.insertLast(val);
                break;
            case 3:
                cout << "Enter key and value: "; cin >> key >> val;
                (listType == 1) ? dll.insertBefore(key, val) : cll.insertBefore(key, val);
                break;
            case 4:
                cout << "Enter key and value: "; cin >> key >> val;
                (listType == 1) ? dll.insertAfter(key, val) : cll.insertAfter(key, val);
                break;
            case 5:
                cout << "Enter value to delete: "; cin >> val;
                (listType == 1) ? dll.deleteNode(val) : cll.deleteNode(val);
                break;
             case 6:
                cout << "Enter value to search: "; cin >> val;
                (listType == 1) ? dll.search(val) : cll.search(val);
                break;
            case 7:
                (listType == 1) ? dll.display() : cll.display();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Program exited." << endl;
    return 0;
}
