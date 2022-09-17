#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 4*1000
class StackMas
{
    int* arr;
    int top;
    int data[SIZE];
    int capacity;
    bool debug;
public:
    StackMas()
    {
        int size = SIZE;
        capacity = size;
        top = -1;
    }
    ~StackMas() {
        //delete[] arr;
    }
    void display() {
        int st_size = size();
        StackMas* st1 = new StackMas();
        for (int i = 0; i < st_size; i++) {
            st1->push(peek());
            cout << " " << pop();
        }
        cout << endl;
        for (int i = 0; i < st_size; i++) {
            push(st1->pop());
        }
    }
    void push(int element)
    {
        if (not isFull())
        {
            top++;
            data[top] = element;
        }
    }
    int pop()
    {
        int element = data[top];
        top--;
        return element;
    }
    int peek()
    {
        return data[top];
    }
    int size() {
        return top + 1;
    }
    bool isEmpty() {
        return top == -1;               
    }
    bool isFull() {
        return top == capacity - 1;     
    }
};