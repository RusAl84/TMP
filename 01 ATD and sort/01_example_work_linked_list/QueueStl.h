#pragma once
#include <queue>
#include <iostream>
using namespace std;
class QueueStl
{
	queue <int>* qu;
public:
	QueueStl() {
		qu = new queue<int>();
	}
	void push(int element) {
		qu->push(element);
	}
	int front() {
		return qu->front();
	}
	int size() {
		return qu->size();
	}
	void pop() {
		qu->pop();
	}
	void Display() {
		QueueStl* queTmp1 = new QueueStl();
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
};

