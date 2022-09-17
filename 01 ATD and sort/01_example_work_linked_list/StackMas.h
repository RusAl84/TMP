#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// ���������� ������� stack �� ���������
#define SIZE 100*1000

// ����� ��� ������������� stack
class StackMas
{
    int* arr;
    int top;
    int data[SIZE];
    int capacity;
    bool debug;
public:
    // ����������� ��� ������������� stack
    StackMas()
    {
        int size = SIZE;
        capacity = size;
        top = -1;
        //arr = new int[size];
    }
    // ���������� ��� ������������ ������, ���������� ��� stack
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
    // ��������������� ������� ��� ���������� �������� `x` � stack
    void push(int element)
    {
        if (not isFull())
        {
            top++;
            data[top] = element;
        }
    }
    // ��������������� ������� ��� ���������� �������� �������� �� stack
    int pop()
    {
        int element = data[top];
        top--;
        return element;
    }
    // ��������������� ������� ��� �������� �������� �������� stack
    int peek()
    {
        return data[top];
    }
    // ��������������� ������� ��� �������� ������� stack
    int size() {
        return top + 1;
    }
    // ��������������� ������� ��� ��������, ���� stack ��� ���
    bool isEmpty() {
        return top == -1;               // ��� return size() == 0;
    }
    // ��������������� ������� ��� ��������, �������� �� stack ��� ���
    bool isFull() {
        return top == capacity - 1;     // ��� return size() == capacity;
    }
};

