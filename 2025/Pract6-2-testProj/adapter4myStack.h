#pragma once
#include <iostream>
#include "myStack.h"

using namespace std;

class adapter4myStack {
    myStack* st;
public:
    adapter4myStack(int _capacity) {
        st = new myStack(_capacity);
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
    /// <summary>
    /// Функция получения элемента из стека
    /// </summary>
    /// <param name="ind"> индекс</param>
    /// <returns> значение элемента </returns>
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
    /// <summary>
    /// Внести значение в элемент списка
    /// </summary>
    /// <param name="ind"> индекс </param>
    /// <param name="element"> значение </param>
    void setElement(int ind, int element) {
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
    }
};