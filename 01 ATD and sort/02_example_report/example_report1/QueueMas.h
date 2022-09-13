#pragma once
#include <iostream>
using namespace std;

#define SIZE 10*1000  

class QueueMas
{
    int* queue;
    int* nop;
    int frnt, rear;
public:  
    QueueMas() {
        queue = new int[SIZE];
        frnt = rear = 0;
        nop = new int;
    }
    void setNOP(int* _nop) {
        nop = _nop;
    }
    int* getNOP() {
        return nop;
    }
    void display() {
        QueueMas* queTmp1 = new QueueMas();
        int c_size = size();
        for (int i = 0; i < c_size; i++) {
            queTmp1->push(front());
            cout << " " << front();
            pop();
        }
        for (int i = 0; i < c_size; i++) {
            push(queTmp1->front());
            queTmp1->pop();
        }

    }

    void push(int num) {   //3
        rear++;   *nop = *nop + 1;
        *nop = *nop + 1;
        if (rear == SIZE) rear = 0;
        {
            *nop = *nop + 1;
            queue[rear] = num; 
        }
    }

    void pop() {
        if (frnt == rear) {
            cout << "î÷åðåäü ïóñòà" << endl;
            return;
        }
        frnt++;
        if (frnt == SIZE) frnt = 0;
    }

    int size() {
        int s = 0;
        for (int i = frnt; i < rear; i++)
            s++;
        return s;
    }

    int back() {
        return queue[rear];
    }

    int front() {
        return queue[frnt + 1];
    };
};
