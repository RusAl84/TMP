#pragma once
#include "QueueMas.h"
class adapter4queueMas
{
	QueueMas  *qu;
public:
	adapter4queueMas() {
		qu = new QueueMas();
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

	int getElement(int ind) {
		int size = qu->size();
		int element = -1;
		if ((ind >= 0) and (ind < size)) {
			QueueMas* queTmp1 = new QueueMas();
			for (int i = 0; i <= ind; i++) {
				queTmp1->push(front());
				element = front();
				pop();
			}
			for (int i = ind+1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
		}
		return element;
	}
	/// <summary>
	/// ���������� �������
	/// </summary>
	/// <param name="ind">������</param>
	/// <param name="element">��������</param>
	void setElement(int ind, int element) {
		int size = qu->size();
		if ((ind >= 0) and (ind < size)) {
			QueueMas* queTmp1 = new QueueMas();
			for (int i = 0; i < ind; i++) {
				queTmp1->push(front());
				pop();
			}
			queTmp1->push(element);
			pop();
			for (int i = ind +1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
		}
	}
};

