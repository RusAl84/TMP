#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

// Node of a doubly linked list
struct Node {
    int data;
    Node* prev, * next;
    // Function to get a new node
    static Node* getnode(int data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

// A structure to represent a deque
class Deque {
    Node* front;
    Node* rear;
    int Size;

public:
    Deque()
    {
        front = rear = NULL;
        Size = 0;
    }

    // Operations on Deque
    void insertFront(int data);
    void insertRear(int data);
    void deleteFront();
    void deleteRear();
    int getFront();
    int getRear();
    int size();
    bool isEmpty();
    void erase();
};

// Function to check whether deque
// is empty or not
bool Deque::isEmpty() { return (front == NULL); }

// Function to return the number of
// elements in the deque
int Deque::size() { return Size; }

// Function to insert an element
// at the front end
void Deque::insertFront(int data)
{
    Node* newNode = Node::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else {
        // If deque is empty
        if (front == NULL)
            rear = front = newNode;

        // Inserts node at the front end
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        // Increments count of elements by 1
        Size++;
    }
}

// Function to insert an element
// at the rear end
void Deque::insertRear(int data)
{
    Node* newNode = Node::getnode(data);
    // If true then new element cannot be added
    // and it is an 'Overflow' condition
    if (newNode == NULL)
        cout << "OverFlow\n";
    else {
        // If deque is empty
        if (rear == NULL)
            front = rear = newNode;

        // Inserts node at the rear end
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        Size++;
    }
}

// Function to delete the element
// from the front end
void Deque::deleteFront()
{
    // If deque is empty then
    // 'Underflow' condition
    if (isEmpty())
        cout << "UnderFlow\n";

    // Deletes the node from the front end and makes
    // the adjustment in the links
    else {
        Node* temp = front;
        front = front->next;

        // If only one element was present
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        free(temp);

        // Decrements count of elements by 1
        Size--;
    }
}

// Function to delete the element
// from the rear end
void Deque::deleteRear()
{
    // If deque is empty then
    // 'Underflow' condition
    if (isEmpty())
        cout << "UnderFlow\n";

    // Deletes the node from the rear end and makes
    // the adjustment in the links
    else {
        Node* temp = rear;
        rear = rear->prev;

        // If only one element was present
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        free(temp);

        // Decrements count of elements by 1
        Size--;
    }
}

// Function to return the element
// at the front end
int Deque::getFront()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return front->data;
}

// Function to return the element
// at the rear end
int Deque::getRear()
{
    // If deque is empty, then returns
    // garbage value
    if (isEmpty())
        return -1;
    return rear->data;
}

// Function to delete all the elements
// from Deque
void Deque::erase()
{
    rear = NULL;
    while (front != NULL) {
        Node* temp = front;
        front = front->next;
        free(temp);
    }
    Size = 0;
}



class Adapter4queueStl
{
    Deque* du;
public:
    Adapter4queueStl() {
        du = new Deque();
    }
    void push(int x)
    {
        du->insertFront(x);
    }
    int size() {
        return du->size();
    }

    int front() {
        return du->getFront();
    }
    void pop(){
        du->deleteFront();
    }
    void display() {
        int size = du->size();
        Adapter4queueStl* quTmp1 = new Adapter4queueStl();
        for (int i = 0; i < size; i++) {
            cout << du->getFront() << " ";
            quTmp1->push(du->getFront());
            du->deleteFront();
        }
        for (int i = 0; i < size; i++) {
            du->insertFront(quTmp1->front());
            quTmp1->pop();
        }
        //delete(quTmp1);
    }
    int getElement(int ind) {
        int size = du->size();
        int element = -1;
        if ((ind >= 0) and (ind < size)) {
            Deque *quTmp1 = new Deque();

            for (int i = 0; i <= ind; i++) {
                element = du->getFront();
                du->deleteFront();
                quTmp1->insertFront(element);

            }
            for (int i = ind; i < size - 1; i++) {
                quTmp1->insertFront(du->getFront());
                du->deleteFront();
            }
            for (int i = 0; i < size; i++) {
                du->insertFront(quTmp1->getFront());
                quTmp1->deleteFront();
            }
            return element;
        }
        return -1;
    }
    int setElement(int ind, int element) {
        int size = du->size();
        if ((ind >= 0) and (ind < size)) {
            Deque* quTmp1 = new Deque();
            for (int i = 0; i < ind; i++) {
                int elTmp = du->getFront();
                du->deleteFront();
                quTmp1->insertFront(elTmp);
            }
            quTmp1->insertFront(element);
            du->deleteFront();
            for (int i = ind; i < size - 1; i++) {
                quTmp1->insertFront(du->getFront());
                du->deleteFront();
            }
            for (int i = 0; i < size; i++) {
                du->insertFront(quTmp1->getFront());
                quTmp1->deleteFront();
            }
            return element;
        }
        return -1;
    }
};



int main()
{
    Deque dq;
    cout << "Insert element '5' at rear end\n";
    dq.insertRear(5);

    cout << "Insert element '10' at rear end\n";
    dq.insertRear(10);

    cout << "Rear end element: " << dq.getRear() << endl;

    dq.deleteRear();
    cout << "After deleting rear element new rear"
        << " is: " << dq.getRear() << endl;

    cout << "Inserting element '15' at front end \n";
    dq.insertFront(15);

    cout << "Front end element: " << dq.getFront() << endl;

    cout << "Number of elements in Deque: " << dq.size()
        << endl;

    dq.deleteFront();
    cout << "After deleting front element new "
        << "front is: " << dq.getFront() << endl;

    Adapter4queueStl st;

    st.push(100);
    st.push(200);
    st.push(300);
    st.push(400);
    st.push(700);
    st.push(700);
    st.push(777);
    cout << "\n";
    st.display();
    cout << " st.getElement(0) = " << st.getElement(0) << endl;
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    cout << " st.getElement(7) = " << st.getElement(7) << endl;
    st.setElement(3, 888);
    st.display();
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    return 0;
}

