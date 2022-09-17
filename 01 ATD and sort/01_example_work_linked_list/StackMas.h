#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// Определяем емкость stack по умолчанию
#define SIZE 100*1000

// Класс для представления stack
class StackMas
{
    int* arr;
    int top;
    int data[SIZE];
    int capacity;
    bool debug;
public:
    // Конструктор для инициализации stack
    StackMas()
    {
        int size = SIZE;
        capacity = size;
        top = -1;
        //arr = new int[size];
    }
    // Деструктор для освобождения памяти, выделенной для stack
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
    // Вспомогательная функция для добавления элемента `x` в stack
    void push(int element)
    {
        if (not isFull())
        {
            top++;
            data[top] = element;
        }
    }
    // Вспомогательная функция для извлечения верхнего элемента из stack
    int pop()
    {
        int element = data[top];
        top--;
        return element;
    }
    // Вспомогательная функция для возврата верхнего элемента stack
    int peek()
    {
        return data[top];
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
};

