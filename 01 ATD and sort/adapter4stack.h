#pragma once
#include "Stack.h"
class Adapter4stack
{
	Stack* st;
    bool debug;
public:
	Adapter4stack() {
		st = new Stack();
	}
	int size() {
		return st->size();
	}
	bool isEmpty() {
		return st->isEmpty();               // ��� return size() == 0;
	}
	bool isFull() {
		return st->isFull();     // ��� return size() == capacity;
	}
	int getElement(int ind) {
		if ((ind >= 0) and (ind < st->size())){
			int element;
			for (int i = 0; i < ind; i++) {
				element = st->pop();
			}
			return element;
		}
		return -1;
	}

};

