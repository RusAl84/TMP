﻿#pragma once
#include "StackMas.h"
class Adapter4stackMas
{
	StackMas* st;
public:
	Adapter4stackMas() {
		st = new StackMas();
	}
	int size() {
		return st->size();
	}
	bool isEmpty() {
		return st->isEmpty();              
	}
	bool isFull() {
		return st->isFull();     
	}
	int getElement(int ind) {
		int size = st->size();
		if ((ind >= 0) and (ind < size)) {
			StackMas* tmpSt1 = new StackMas();
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
	bool  setElement(int ind, int element) {
		int size = st->size();
		if ((ind >= 0) and (ind < size)) {
			StackMas* tmpSt1 = new StackMas();
			for (int i = 0; i < ind; i++) {
				tmpSt1->push(st->pop());
			}
			tmpSt1->push(element);
			int del_element = st->pop();
			for (int i = ind + 1; i < size; i++) {
				tmpSt1->push(st->pop());
			}
			delete(st);
			StackMas* tmpSt2 = new StackMas();
			for (int i = 0; i < size; i++)
				tmpSt2->push(tmpSt1->pop());
			delete(tmpSt1);
			st = tmpSt2;
			return true;
		}

		return false;
	}
	void push(int x)
	{
		st->push(x);
	}
	void display() {
		st->display();
	}
};


