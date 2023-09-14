#pragma once
#include <iostream>
#include <stack>

using namespace std;

// ����� ��� ������������� stack
// https://www.geeksforgeeks.org/stack-in-cpp-stl/
class stackStl
{
private:
    stack<int>* st = new stack<int>();
public:

    // ��������������� ������� ��� ���������� �������� `x` � stack
    void push(int data)
    {
        st->push(data);
    }
    // ��������������� ������� ��� ���������� �������� �������� �� stack
    void pop()
    {
        this->st->pop();
    }
    // ��������������� ������� ��� �������� �������� �������� stack
    int peek()
    {
        int data = st->top();
        return data;
    }
    int top()
    {
        int data = st->top();
        return data;
    }
    // ��������������� ������� ��� �������� ������� stack
    int size() {
        return st->size();
    }
    // ��������������� ������� ��� ��������, ���� stack ��� ���
    bool isEmpty() {
        return st->empty();             // ��� return size() == 0;
    }
    void Display() {
        
        stack<int>* tmp_st = new stack<int>();
        while (!st->empty()) {
            tmp_st->push(st->top());
            cout << st->top() << " ";
            st->pop();
        }
        while (!tmp_st->empty()) {
            st->push(tmp_st->top());
            tmp_st->pop();
        }
    }

};

