#pragma once
#include "StackPtr.h"
class Adapter4stackPtr
{
	StackPtr* st;
public:
	Adapter4stackPtr() {
		st = new StackPtr();
	}
	int size() {
		return st->size();
	}
	/// <summary>
	/// �������� ���� �� ����?
	/// </summary>
	/// <returns>True - ������</returns>
	bool isEmpty() {
		return st->isEmpty();               // ��� return size() == 0;
	}
	bool isFull() {
		return st->isFull();     // ��� return size() == capacity;
	}
	/// <summary>
	/// �������� �������
	/// </summary>
	/// <param name="ind"> ������</param>
	/// <returns></returns>
	int getElement(int ind) {
		int size = st->size();
		if ((ind >= 0) and (ind < size)){
			StackPtr* tmpSt1 = new StackPtr();
			int element;
			for (int i = 0; i <= ind; i++) {
				element = st->pop();
				tmpSt1->push(element);
			}
			for (int i = 0; i <= ind; i++) {	
				st->push(tmpSt1->pop());
			}
			delete tmpSt1;
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
			StackPtr* tmpSt1 = new StackPtr();
			for (int i = 0; i < ind; i++) {
				tmpSt1->push(st->pop());
			}
			tmpSt1->push(element);
			int del_element= st->pop();
			for (int i = ind+1; i < size; i++) {
				tmpSt1->push(st->pop());
			}
			delete(st);
			StackPtr* tmpSt2 = new StackPtr();
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
		StackPtr *tmpSt1 = new StackPtr();
		int size = st->size();
		for (int i = 0; i < size; i++) {
			int element = st->pop();
			cout << " " << element;
			tmpSt1->push(element);
		}
		delete(st);
		StackPtr* tmpSt2 = new StackPtr();
		for (int i = 0; i < size; i++)
			tmpSt2->push(tmpSt1->pop());
		delete(tmpSt1);		
		st = tmpSt2;
	}
};

