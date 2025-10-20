// Pract4-1-var65.cpp  
//https://www.geeksforgeeks.org/dsa/implementation-deque-using-doubly-linked-list/
#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* prev, * next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

// Deque implementation using doubly linked list
class myDeque {
    Node* front, * rear;
    int size;

public:
    myDeque() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isEmpty() { return front == nullptr; }
    int getSize() { return size; }

    // Insert at front
    void insertFront(int data) {
        Node* newNode = new Node(data);

        if (isEmpty()) front = rear = newNode;
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        size++;
    }

    // Insert at rear
    void insertRear(int data) {
        Node* newNode = new Node(data);

        if (isEmpty()) front = rear = newNode;
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Delete from front
    void deleteFront() {
        if (isEmpty()) cout << "UnderFlow\n";
        else {
            front = front->next;
            if (front) front->prev = nullptr;
            else rear = nullptr;
            size--;
        }
    }

    // Delete from rear
    void deleteRear() {
        if (isEmpty()) cout << "UnderFlow\n";
        else {
            rear = rear->prev;
            if (rear) rear->next = nullptr;
            else front = nullptr;

            size--;
        }
    }

    // Get front element
    int getFront() { return isEmpty() ? -1 : front->data; }

    // Get rear element
    int getRear() { return isEmpty() ? -1 : rear->data; }

    // Clear the deque
    void erase() {
        while (!isEmpty()) deleteFront();
    }
};

int main() {
    myDeque dq;
    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertRear(3);
    dq.insertRear(4);
    dq.insertRear(5);
    cout << "Rear: " << dq.getRear() << endl;
    dq.deleteRear();
    cout << "New Rear: " << dq.getRear() << endl;
    dq.insertFront(15);
    cout << "Front: " << dq.getFront() << endl;
    cout << "Size: " << dq.getSize() << endl;
    dq.deleteFront();
    cout << "New Front: " << dq.getFront() << endl;
    return 0;
}