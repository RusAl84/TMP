#pragma once
#include "QueuePtr.h"
class adapter4QueuePtr
{
	QueuePtr* qu;
public:
	adapter4QueuePtr() {
		//cout << "\nОбычный конструктор\n";
		qu = new QueuePtr();
	}
	//adapter4QueuePtr(const adapter4QueuePtr& obj)
	//{
	//	cout << "\nКонструктор копирования\n";
	//}
	void Display() {
		qu->Display();
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
	/// <summary>
	/// Функция для получения элемента по индексу
	/// </summary>
	/// <param name="ind">идекс элемената</param>
	/// <returns>элемент</returns>
	int getElement(int ind) {
		int size = qu->size();
		int element = -1;
		if ((ind >= 0) and (ind < size)) {
			QueuePtr* queTmp1 = new QueuePtr();
			for (int i = 0; i <= ind; i++) {
				queTmp1->push(front());
				element = front();
				pop();
			}
			for (int i = ind + 1; i < size; i++) {
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
	void  setElement(int ind, int element) {
		int size = qu->size();
		if ((ind >= 0) and (ind < size)) {
			QueuePtr* queTmp1 = new QueuePtr();
			for (int i = 0; i < ind; i++) {
				queTmp1->push(front());
				pop();
			}
			queTmp1->push(element);
			pop();
			for (int i = ind + 1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
		}
	}
	adapter4QueuePtr* copy() {
		adapter4QueuePtr* queTmp1 = new adapter4QueuePtr();
		int size = qu->size();
		for (int i = 0; i < size; i++) {
			queTmp1->push(front());
			pop();
		}
		return queTmp1;
	}

};

