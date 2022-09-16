#pragma once
#include "QueueMas.h"
class adapter4queueMas
{
	QueueMas* qu;
	int* nop;
public:
	adapter4queueMas() {
		qu = new QueueMas();
	}
	void setNOP(int* _nop) {
		nop = _nop;
		qu->setNOP(_nop);
	}
	int* getNOP() {
		return nop;
	}
	void display() {
		qu->display();
	}
	void push(int num) {
		qu->push(num);
	}
	void pop() {
		qu->pop();
	}
	int size() {
		return qu->size();
	}
	int front() {
		return qu->front();
	}

	int getElement(int ind) {//1 +4n+3n
		int size = qu->size(); 
		int element = -1; *nop += 1;
		if ((ind >= 0) and (ind < size)) {
			QueueMas* queTmp1 = new QueueMas();
			for (int i = 0; i <= ind; i++) { //4
				queTmp1->push(front()); *nop += 2;
				element = front(); *nop += 1;
				pop(); *nop += 1;
			}
			for (int i = ind + 1; i < size; i++) { //3
				queTmp1->push(front()); *nop += 2;
				pop(); *nop += 1;
			}
			for (int i = 0; i < size; i++) { //3
				push(queTmp1->front()); *nop += 2;
				queTmp1->pop(); *nop += 1;
			}
		}
		return element;
	}

	void setElement(int ind, int element) {//1 + 6n 
		int size = qu->size(); *nop += 1;
		if ((ind >= 0) and (ind < size)) {
			QueueMas* queTmp1 = new QueueMas();
			for (int i = 0; i < ind; i++) { //3
				queTmp1->push(front()); *nop += 2;
				pop(); *nop += 1;
			}
			queTmp1->push(element); *nop += 1;
			pop(); *nop += 1;
			for (int i = ind + 1; i < size; i++) { //3
				queTmp1->push(front()); *nop += 2;
				pop(); *nop += 1;
			}
			for (int i = 0; i < size; i++) {  // 3
				push(queTmp1->front()); *nop += 2;
				queTmp1->pop(); *nop += 1;
			}
		}
	}
};
