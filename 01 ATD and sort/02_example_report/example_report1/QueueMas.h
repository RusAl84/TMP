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
    void display() {  // 2 + 3n + 2n  = 2 + 5n
        QueueMas* queTmp1 = new QueueMas(); *nop += 1;
        int c_size = size(); *nop += 1;
        for (int i = 0; i < c_size; i++) { //3
            queTmp1->push(front()); *nop += 1;
            cout << " " << front(); *nop += 1;
            pop(); *nop += 1;
        }
        for (int i = 0; i < c_size; i++) { //2
            push(queTmp1->front()); *nop += 1;
            queTmp1->pop(); *nop += 1;
        }
    }

    void push(int num) {   //3
        rear++;   *nop += 1;
        *nop += 1;
        if (rear == SIZE) rear = 0;
        {
            *nop += 1;
            queue[rear] = num; 
        }
    }

    void pop() {   //2
        frnt++; *nop += 1;
        *nop += 1;
        if (frnt == SIZE) {
            *nop += 1;
            frnt = 0;
        }
    }

    int size() {//1 + 2n
        int s = 0; *nop += 1; // 1
        for (int i = frnt; i < rear; i++) {
            *nop += 1;
            s++;
        }
        return s;
    }

    int back() {  //1
        *nop += 1;
        return queue[rear];
    }

    int front() { //1
        *nop += 1;
        return queue[frnt + 1];
    };
};
