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
		return st->isEmpty();               // или return size() == 0;
	}
	bool isFull() {
		return st->isFull();     // или return size() == capacity;
	}

	int getElement(int ind) {
		if ((ind >= 0) and (ind < st->size())){
			int element;
			for (int i = 0; i <= ind; i++) {
				element = st->pop();
			}
			return element;
		}
		return -1;
	}
	/// <summary>
	/// Функция для изменения элемента стека по его индексу
	/// </summary>
	/// <param name="ind">индекс</param>
	/// <param name="element">эелемент</param>
	bool  setElement(int ind,int element) {
		Stack* tmpSt1 = new Stack();
		if ((ind >= 0) and (ind < st->size())) {
			int size = st->size();
			for (int i = 0; i < ind; i++) {
				tmpSt1->push(st->pop());
			}
			tmpSt1->push(element);
			for (int i = ind; i < size; i++) {
				tmpSt1->push(st->pop());
			}

			return true;
		}
		
		return false;
	}
	// Вспомогательная функция для добавления элемента `x` в stack
	void push(int x)
	{
		st->push(x);
	}
	void display() {
		Stack *tmpSt1 = new Stack();
		int size = st->size();
		for (int i = 0; i < size; i++) {
			int element = st->pop();
			cout << " " << element;
			tmpSt1->push(element);
		}
		delete(st);
		Stack* tmpSt2 = new Stack();
		for (int i = 0; i < size; i++)
			tmpSt2->push(tmpSt1->pop());
		delete(tmpSt1);		
		st = tmpSt2;
		delete(tmpSt2);
	}
};

