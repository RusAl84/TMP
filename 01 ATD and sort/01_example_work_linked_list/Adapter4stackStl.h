#pragma once
#include <stack>
#include <iostream>
using namespace std;
class Adapter4stackStl
{
	stack<int>* st;
public:
	Adapter4stackStl() {
		st = new stack<int>();
	}
	int size() {
		return st->size();
	}
	/// <summary>
	/// �������� ���� �� ����?
	/// </summary>
	/// <returns>True - ������</returns>
	bool isEmpty() {
		return st->empty();               // ��� return size() == 0;
	}
	/// <summary>
	/// �������� �������
	/// </summary>
	/// <param name="ind"> ������</param>
	/// <returns></returns>
	int getElement(int ind) {
		int size = st->size();
		if ((ind >= 0) and (ind < size)) {
			stack<int>* tmpSt1 = new stack<int>();
			int element;
			for (int i = 0; i <= ind; i++) {
				element = st->top();
				st->pop();
				tmpSt1->push(element);
			}
			for (int i = 0; i <= ind; i++) {
				st->push(tmpSt1->top());
				tmpSt1->pop();
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
	bool  setElement(int ind, int element) {
		int size = st->size();
		if ((ind >= 0) and (ind < size)) {
			stack<int>* tmpSt1 = new stack<int>();
			for (int i = 0; i < ind; i++) {
				tmpSt1->push(st->top());
				st->pop();
			}
			tmpSt1->push(element);
			int del_element = st->top();
			st->pop();
			for (int i = ind + 1; i < size; i++) {
				tmpSt1->push(st->top());
				st->pop();
			}
			delete(st);
			stack<int>* tmpSt2 = new stack<int>();
			for (int i = 0; i < size; i++) {
				tmpSt2->push(tmpSt1->top());
				tmpSt1->pop();
			}
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
		stack<int>* tmpSt1 = new stack<int>();
		int size = st->size();
		for (int i = 0; i < size; i++) {	
			int element = st->top();
			cout << " " << element;
			st->pop();
			tmpSt1->push(element);
		}
		delete(st);
		stack<int>* tmpSt2 = new stack<int>();
		for (int i = 0; i < size; i++) {
			tmpSt2->push(tmpSt1->top());
			tmpSt1->pop();
		}
		delete(tmpSt1);
		st = tmpSt2;
		//for (int i = 0; i < size; i++) {
		//	st->push(tmpSt2->top());
		//	tmpSt2->pop();
		//}


	}

};

