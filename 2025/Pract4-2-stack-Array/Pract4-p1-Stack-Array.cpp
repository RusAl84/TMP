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

class adapter4myStack {
    myStack* st;
public:
    adapter4myStack(int cap) {
        st = new myStack(cap);
    }
    void push(int x) {
        st->push(x);
    }
    int pop() {
        return st->pop();
    }
    int peek() {
        return st->peek();
    }
    bool isEmpty() {
        return st->isEmpty();
    }
    bool isFull() {
        return st->isFull();
    }
    void display() {
        st->display();
    }
    int getElement(int ind) {
        myStack* tmp_st = new myStack(100);
        int element = 0;
        int index = 0;
        while (not isEmpty()) {
            int x = pop();
            tmp_st->push(x);
            if (ind == index) {
                element = x;
                break;
            }
            index++;
        }
        while (not tmp_st->isEmpty()) {
            int x = tmp_st->pop();
            push(x);
        }
        delete tmp_st;
        return element;
    }
    int setElement(int ind, int element ) {
        myStack* tmp_st = new myStack(100);
        int index = 0;
        while (not isEmpty()) {
            int x = pop();
            if (ind == index) {
                tmp_st->push(element); 
                break;
            }
            else
            {
                tmp_st->push(x);
            }
            index++;
        }
        while (not tmp_st->isEmpty()) {
            int x = tmp_st->pop();
            push(x);
        }
        delete tmp_st;
        return element;
    }
};

int main() {
    adapter4myStack st(100);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(7);
    st.push(7);
    st.push(7);
    cout << "\n";
    st.display();
    cout << " st.getElement(0) = " << st.getElement(0) << endl;
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    cout << " st.getElement(7) = " << st.getElement(7) << endl;
    st.setElement(3, 8);
    st.display();
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    return 0;
}

