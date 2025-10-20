// Pract4-p1-Stack-Array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// https://www.geeksforgeeks.org/dsa/implement-stack-using-array/

#include <iostream>
using namespace std;

class myStack {

    // array to store elements
    int* arr;

    // maximum size of stack
    int capacity;

    // index of top element
    int top;

public:

    // constructor
    myStack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    // push operation
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    // pop operation
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // peek (or top) operation
    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        myStack *tmp_st = new myStack(100);
        while (not isEmpty()) {
            int x = pop();
            tmp_st->push(x);
            cout << x << endl;
        }
        while (not tmp_st->isEmpty()) {
            int x = tmp_st->pop();
            push(x);
        }
        delete tmp_st;
    }
};

int main() {
    myStack st(100);

    // pushing elements
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(7);
    st.push(7);
    st.push(7);

    // popping one element
    cout << "Popped: " << st.pop() << "\n";

    // checking top element
    cout << "Top element: " << st.peek() << "\n";

    // checking if stack is empty
    cout << "Is stack empty: " << (st.isEmpty() ? "Yes" : "No") << "\n";

    // checking if stack is full
    cout << "Is stack full: " << (st.isFull() ? "Yes" : "No") << "\n";
    st.display();

    return 0;
}

