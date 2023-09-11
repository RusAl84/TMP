#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;



// Класс для представления stack
class StackPtr
{
private:
    struct node {
        int data;
        struct node* next;
    };
    struct node* myHead;
    int top = -1;;
    int capacity;
    bool debug;
public:

    // Деструктор для освобождения памяти, выделенной для stack
    ~StackPtr() {
        struct node* current = myHead;
        struct node* tmp;
        cout << endl;
        while (current) {
            tmp = current;
            current = current->next;
            delete tmp;
        }
    }
    // Вспомогательная функция для добавления элемента `x` в stack
    void push(int data)
    {
        struct node* newItem = new node();
        newItem->data = data;
        if (top == -1)
            newItem->next = NULL;
        else
            newItem->next = myHead;
        myHead = newItem;
        top++;
    }
    // Вспомогательная функция для извлечения верхнего элемента из stack
    int pop()
    {
        int data = 0;
        if (top < 0)
        {
            cout << "Error get empty element\n";
        }
        else
        { 
            struct node* current = myHead;
            struct node* old;   
            old = myHead;
            myHead = current->next;
            data = current->data;
            delete old;
            top--;
        }
        return data;
    }
    // Вспомогательная функция для возврата верхнего элемента stack
    int peek()
    {
        if (top < 0)
        {
            cout << "Error get empty element\n";
            exit(EXIT_FAILURE);
        }
        int data = myHead->data;
        return data;
    }
    // Вспомогательная функция для возврата размера stack
    int size() {
        return top + 1;
    }
    // Вспомогательная функция для проверки, пуст stack или нет
    bool isEmpty() {
        return top == -1;               // или return size() == 0;
    }
    // Вспомогательная функция для проверки, заполнен ли stack или нет
    bool isFull() {
        return top == capacity - 1;     // или return size() == capacity;
    }
    void Display() {
        if (top < 0)
        {
            cout << "Stack empty\n";
        }
        else
        {
            struct node* current = myHead;
            cout << endl;
            while (current) {
                cout << " " << current->data;
                current = current->next;
            }
        }
    }
};

