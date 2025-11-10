#pragma once
#include "StackMas.h"
class Adapter4stackMas
{
	int* nop;
	StackMas* st;
public:
	Adapter4stackMas() {
		st = new StackMas();
	}
	void setNOP(int* _nop) {
		nop = _nop;
		st->setNOP(_nop);
	}
	int* getNOP() {
		*nop = *nop + *st->getNOP();
		return nop;
	}
	int size() {
		*nop += 1;
		return st->size(); 
	}
	bool isEmpty() {
		*nop += 1;
		return st->isEmpty();              
	}
	bool isFull() {
		*nop += 1;
		return st->isFull();     
	}
	int getElement(int ind) {//3 + 2n
		int size = st->size(); *nop += 1; //1
		if ((ind >= 0) and (ind < size)) {
			StackMas* tmpSt1 = new StackMas(); *nop += 1;
			tmpSt1->setNOP(nop);
			int element; *nop += 1;
			for (int i = 0; i <= ind; i++) {
				element = st->pop(); *nop += 1;
				tmpSt1->push(element); *nop += 1;
			}
			for (int i = 0; i <= ind; i++) {
				st->push(tmpSt1->pop()); *nop += 1; *nop += 1;
			}
			return element;
		}
		return -1;
	}
	bool  setElement(int ind, int element) {//3+4n
		int size = st->size(); *nop += 1;
		if ((ind >= 0) and (ind < size)) {
			StackMas* tmpSt1 = new StackMas(); *nop += 1;
			tmpSt1->setNOP(nop);
			for (int i = 0; i < ind; i++) {
				tmpSt1->push(st->pop()); *nop += 1; *nop += 1;
			}
			tmpSt1->push(element); *nop += 1;
			int del_element = st->pop(); *nop += 1;
			for (int i = ind + 1; i < size; i++) {
				tmpSt1->push(st->pop()); *nop += 1; *nop += 1;
			}
			delete(st);
			StackMas* tmpSt2 = new StackMas();
			tmpSt2->setNOP(nop);
			for (int i = 0; i < size; i++)
				tmpSt2->push(tmpSt1->pop()); *nop += 1; *nop += 1;
			delete(tmpSt1);
			st = tmpSt2;
			return true;
		}

		return false;
	}
	void push(int x)
	{
		st->push(x); *nop += 1;
	}
	int pop() {
		return st->pop();
	}
	void display() {
		st->display(); *nop += 1;
	}
};


