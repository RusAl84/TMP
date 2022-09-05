#pragma once
#include "Stack.h"
class Adapter4stack
{
	Stack* st;
    //bool debug;
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
		int size = st->size();
		if ((ind >= 0) and (ind < size)){
			Stack* tmpSt1 = new Stack();
			int element;
			for (int i = 0; i <= ind; i++) {
				element = st->pop();
				tmpSt1->push(element);
			}
			for (int i = 0; i <= ind; i++) {	
				st->push(tmpSt1->pop());
			}

			return element;
		}
		return -1;
	}
	/// <summary>
	/// ������� ��� ��������� �������� ����� �� ��� �������
	/// </summary>
	/// <param name="ind">������</param>
	/// <param name="element">��������</param>
	bool  setElement(int ind,int element) {
		int size = st->size();
		if ((ind >= 0) and (ind < size)) {
			Stack* tmpSt1 = new Stack();
			for (int i = 0; i < ind; i++) {
				tmpSt1->push(st->pop());
			}
			tmpSt1->push(element);
			int del_element= st->pop();
			for (int i = ind+1; i < size; i++) {
				tmpSt1->push(st->pop());
			}
			delete(st);
			Stack* tmpSt2 = new Stack();
			for (int i = 0; i < size; i++)
				tmpSt2->push(tmpSt1->pop());
			delete(tmpSt1);
			st = tmpSt2;
			return true;
		}
		
		return false;
	}
	// ��������������� ������� ��� ���������� �������� `x` � stack
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
	}
};

