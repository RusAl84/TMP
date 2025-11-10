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
    int* nop;
public:
    StackMas()
    {
        int size = SIZE;
        capacity = size;
        top = -1;
        nop = nullptr;
    }
    ~StackMas() {
        //delete[] arr;
    }
    void setNOP(int* _nop) {
        nop = _nop;
    }
    int* getNOP() {
        return nop;
    }
    void display() { //2 + 4n
        int st_size = size(); *nop += 1;
        StackMas* st1 = new StackMas(); *nop += 1; //2
        for (int i = 0; i < st_size; i++) { //2n
            st1->push(peek()); *nop += 1; //2
            cout << " " << pop(); *nop += 1;
        }
        cout << endl;
        for (int i = 0; i < st_size; i++) {
            push(st1->pop()); //2 
            *nop += 2;
        }
    }
    void push(int element) //3
    {
        *nop += 1;
        if (not isFull())
        {
            top++; *nop += 1;
            data[top] = element; *nop += 1;
        }
    }
    int pop() //3
    {
        int element = data[top]; *nop += 1;
        top--; *nop += 1; *nop += 1;
        return element; 
    }
    int peek()
    {
        *nop += 1;
        return data[top];
    }
    int size() {
        *nop += 1;
        return top + 1;
    }
    bool isEmpty() {
        *nop += 1;
        return top == -1;               
    }
    bool isFull() {
        *nop += 1;
        return top == capacity - 1;     
    }
};