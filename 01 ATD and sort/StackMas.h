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
    int capacity;
    bool debug;
public:
    // ����������� ��� ������������� stack
    StackMas()
    {
        int size = SIZE;
        capacity = size;
        top = -1;
        int numbers[SIZE];
        //arr = new int[size];
    }
    // ���������� ��� ������������ ������, ���������� ��� stack
    ~StackMas() {
        //delete[] arr;
    }
    // ��������������� ������� ��� ���������� �������� `x` � stack
    void push(int x)
    {
        //if (isFull())
        //{
        //    cout << "Overflow\nProgram Terminated\n";
        //    exit(EXIT_FAILURE);
        //}
        //if (debug)
        //    cout << "Inserting " << x << endl;
        //arr[++top] = x;
    }
    // ��������������� ������� ��� ���������� �������� �������� �� stack
    int pop()
    {

    }
    // ��������������� ������� ��� �������� �������� �������� stack
    int peek()
    {

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

