#pragma once
#include <iostream>
using namespace std;

#define SIZE 10*1000

class QueueMas
{
    int* queue;
    int frnt, rear;
    //int data[SIZE];
public:
    QueueMas() {
        queue = new int[SIZE];
        frnt = rear = 0;
    }

    void display() {
        //for (int i = frnt + 1; i < rear + 1; i++)
        //    cout << " " << queue[i];
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

    void push(int num) {

        if (rear + 1 == frnt || (rear + 1 == SIZE && !frnt)) {
            cout << "î÷åðåäü ïîëíà" << endl;
            return;
        }
        rear++;
        if (rear == SIZE) rear = 0;
        {
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
