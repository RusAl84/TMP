#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// Определяем емкость stack по умолчанию
#define SIZE 10*1000*1000

// Класс для представления stack
class StackMas
{
    int* arr;
    int top;
    int capacity;
    bool debug;
public:
    // Конструктор для инициализации stack
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
    // Деструктор для освобождения памяти, выделенной для stack
    ~StackMas() {
        delete[] arr;
    }
    // Вспомогательная функция для добавления элемента `x` в stack
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
    // Вспомогательная функция для извлечения верхнего элемента из stack
    int pop()
    {
        // проверка на опустошение stack
        if (isEmpty())
        {
            if (debug)
                cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        if (debug)
            cout << "Removing " << peek() << endl;

        // уменьшаем размер stack на 1 и (необязательно) возвращаем извлеченный элемент
        return arr[top--];
    }
    // Вспомогательная функция для возврата верхнего элемента stack
    int peek()
    {
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            exit(EXIT_FAILURE);
        }
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

