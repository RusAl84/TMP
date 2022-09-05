#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// ���������� ������� stack �� ���������
#define SIZE 10*1000*1000

// ����� ��� ������������� stack
class StackMas
{
    int* arr;
    int top;
    int capacity;
    bool debug;
public:
    // ����������� ��� ������������� stack
    StackMas(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
        debug = false;
    }
    StackMas()
    {
        int size = SIZE;
        arr = new int[size];
        capacity = size;
        top = -1;
        debug = false;
    }
    // ���������� ��� ������������ ������, ���������� ��� stack
    ~StackMas() {
        delete[] arr;
    }
    // ��������������� ������� ��� ���������� �������� `x` � stack
    void push(int x)
    {
        if (isFull())
        {
            cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        if (debug)
            cout << "Inserting " << x << endl;
        arr[++top] = x;
    }
    // ��������������� ������� ��� ���������� �������� �������� �� stack
    int pop()
    {
        // �������� �� ����������� stack
        if (isEmpty())
        {
            if (debug)
                cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        if (debug)
            cout << "Removing " << peek() << endl;

        // ��������� ������ stack �� 1 � (�������������) ���������� ����������� �������
        return arr[top--];
    }
    // ��������������� ������� ��� �������� �������� �������� stack
    int peek()
    {
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            exit(EXIT_FAILURE);
        }
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

