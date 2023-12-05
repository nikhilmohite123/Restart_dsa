#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node() : next(nullptr), prev(nullptr) {}

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}

    ~Node() {
        delete next;
        delete prev;
    }
};

void print(Node *Head) {
    Node *temp = Head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtHead(Node *&Head, Node *&tail, int data) {
    Node *newNode = new Node(data);

    if (Head == nullptr) {
        Head = newNode;
        tail = newNode;
    } else {
        newNode->next = Head;
        Head->prev = newNode;
        Head = newNode;
    }
}

void insertAtTail(Node *&Head, Node *&tail, int data) {
    if (Head == nullptr) {
        insertAtHead(Head, tail, data);
    } else {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int length(Node *Head) {
    int cnt = 0;
    Node *temp = Head;

    while (temp != nullptr) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

void insertAtPosition(Node *&Head, Node *&tail, int position, int data) {
    int len = length(Head);

    if (len < position) {
        insertAtTail(Head, tail, data);
        return;
    }

    if (position == 1) {
        insertAtHead(Head, tail, data);
        return;
    }

    int cnt = 1;
    Node *previous = Head;

    while (cnt < position - 1) {
        cnt++;
        previous = previous->next;
    }

    Node *newNode = new Node(data);
    newNode->next = previous->next;
    newNode->prev = previous;
    previous->next->prev = newNode;
    previous->next = newNode;
}

void deleteAtHead(Node *&Head, Node *&tail) {
    if (Head == nullptr) {
        return;
    }

    Node *temp = Head;
    Head = temp->next;
    temp->next = nullptr;
    Head->prev = nullptr;
    delete temp;
}

void deleteAtTail(Node *&Head, Node *&tail) {
    if (tail == nullptr) {
        return;
    }

    Node *previous = Head;

    while (previous->next->next != nullptr) {
        previous = previous->next;
    }

    Node *temp = previous->next;
    temp->prev = nullptr;
    tail = previous;
    tail->next = nullptr;
    delete temp;
}

void deleteAtPosition(Node *&Head, Node *&tail, int position) {
    int len = length(Head);

    if (len < position) {
        deleteAtTail(Head, tail);
        return;
    }

    if (position == 1) {
        deleteAtHead(Head, tail);
        return;
    }

    int cnt = 1;
    Node *previous = Head;

    while (cnt < position - 1) {
        previous = previous->next;
        cnt++;
    }

    Node *temp = previous->next;
    Node *after = temp->next;
    previous->next = after;
    after->prev = previous;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
}

int main() {
    Node *Head = nullptr;
    Node *tail = nullptr;

    insertAtHead(Head, tail, 5);
    insertAtHead(Head, tail, 4);
    insertAtHead(Head, tail, 3);
    insertAtHead(Head, tail, 2);
    insertAtHead(Head, tail, 1);

    print(Head);
    cout << endl;

    deleteAtPosition(Head, tail, 4);

    print(Head);
    cout << endl;

    return 0;
}
