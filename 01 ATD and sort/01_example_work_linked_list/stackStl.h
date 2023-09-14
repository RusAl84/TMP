#pragma once
#include <iostream>
#include <stack>

using namespace std;

// Класс для представления stack
// https://www.geeksforgeeks.org/stack-in-cpp-stl/
class stackStl
{
private:
    stack<int>* st = new stack<int>();
public:

    // Вспомогательная функция для добавления элемента `x` в stack
    void push(int data)
    {
        st->push(data);
    }
    // Вспомогательная функция для извлечения верхнего элемента из stack
    void pop()
    {
        this->st->pop();
    }
    // Вспомогательная функция для возврата верхнего элемента stack
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
    // Вспомогательная функция для возврата размера stack
    int size() {
        return st->size();
    }
    // Вспомогательная функция для проверки, пуст stack или нет
    bool isEmpty() {
        return st->empty();             // или return size() == 0;
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

