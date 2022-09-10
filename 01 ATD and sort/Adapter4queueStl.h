#pragma once
#include <queue>
#include <iostream>
using namespace std;

class Adapter4queueStl
{
	queue <int> *qu;
public:
	Adapter4queueStl() {
		qu = new queue<int>();
	}
	void push(int x)
	{
		qu->push(x);
	}
	int size() {
		return qu->size();
	}
	bool isEmpty() {
		return qu->empty();               // или return size() == 0;
	}
	void Dislay() {
		int size = qu->size();
		queue <int> *quTmp1 = new queue<int>();
		for (int i = 0; i < size; i++) {
			cout << qu->front() << " ";
			quTmp1->push(qu->front());
			qu->pop();
		}
		for (int i = 0; i < size; i++) {
			qu->push(quTmp1->front());
			quTmp1->pop();
		}
		//delete(quTmp1);
	}
	int getElement(int ind) {
		int size = qu->size();
		int element = -1;
		if ((ind >= 0) and (ind < size)) {
			queue <int>* quTmp1 = new queue<int>();
			
			for (int i = 0; i <= ind; i++) {
				element = qu->front();
				qu->pop();
				quTmp1->push(element);
				
			}
			for (int i = ind; i < size-1; i++) {
				quTmp1->push(qu->front());
				qu->pop();
			}
			for (int i = 0; i < size; i++) {
				qu->push(quTmp1->front());
				quTmp1->pop();
			}
			return element;
		}
		return -1;
	}
	int setElement(int ind, int element) {
		int size = qu->size();
		if ((ind >= 0) and (ind < size)) {
			queue <int>* quTmp1 = new queue<int>();
			for (int i = 0; i < ind; i++) {
				int elTmp = qu->front();
				qu->pop();
				quTmp1->push(elTmp);
			}
			quTmp1->push(element);
			qu->pop();
			for (int i = ind; i < size - 1; i++) {
				quTmp1->push(qu->front());
				qu->pop();
			}
			for (int i = 0; i < size; i++) {
				qu->push(quTmp1->front());
				quTmp1->pop();
			}
			return element;
		}
		return -1;
	}
};

