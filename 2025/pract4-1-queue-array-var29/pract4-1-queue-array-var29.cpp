// pract4-1-queue-array-var29.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
using namespace std;

class myQueue {

    // Array to store queue elements.
    int* arr;

    // Maximum number of elements the queue can hold.
    int capacity;

    // Current number of elements in the queue.
    int size;

public:
    myQueue(int c) {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }

    // Adds an element x at the rear of the queue.
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        arr[size] = x;
        size++;
    }

    // Removes the front element of the queue.
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // Returns the front element of the queue.
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }
    // Return the last element of queue
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }

    void display()
    {
        myQueue temp_q(10);
        cout <<  endl;
        while (not isEmpty()) {
            int x = getFront();
            temp_q.enqueue(x);
            dequeue();
            cout << x << " $" << endl;
        }
        while (not temp_q.isEmpty()) {
            int x = temp_q.getFront();
            enqueue(x);
            temp_q.dequeue();
        }
    }


};

int main()
{
    myQueue q(10);

    q.enqueue(1000);      
    q.enqueue(2000);      
    q.enqueue(3000);      
    cout << "Front: " << q.getFront() << endl;

    q.dequeue();
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    q.enqueue(40);
    q.display();
    cout << " ____";
    q.display();

    return 0;
}