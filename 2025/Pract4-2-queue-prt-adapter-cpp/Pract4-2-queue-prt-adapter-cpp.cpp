#include <iostream>
using namespace std;


class QueuePtr
{
	int csize;
	struct list
	{
		int data; 
		struct list* next; 
	};
	list* head, * rear;
public:
	QueuePtr() {
		csize = 0;
		head = nullptr;
		rear = nullptr;
	}
	void push(int element) {
		list* l = new list();
		if (csize == 0) {
			l->next = nullptr;
			l->data = element;
			head = l;
			rear = l;
		}
		else
		{
			l->next = head;
			l->data = element;
			head = l;
		}
		csize++;
	}
	int front() {
		return rear->data;
	}
	int size() {
		return csize;
	}
	void pop() {
		if (csize == 1) {
			delete(head);
			csize = 0;
			head = nullptr;
			rear = nullptr;
		}
		else
		{
			list* l = head;
			list* prev = nullptr;
			while (l->next != nullptr) {
				prev = l;
				l = l->next;
			}
			csize--;
			delete(l);
			prev->next = nullptr;
			rear = prev;
		}
	}
	void Display() {
		QueuePtr* queTmp1 = new QueuePtr();
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

class Adapter4queuePtr1head
{
	QueuePtr* qu;
public:
	Adapter4queuePtr1head() {

		qu = new QueuePtr();
	}

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
	Adapter4queuePtr1head* copy() {
		Adapter4queuePtr1head* queTmp1 = new Adapter4queuePtr1head();
		int size = qu->size();
		for (int i = 0; i < size; i++) {
			queTmp1->push(front());
			pop();
		}
		return queTmp1;
	}

};
int main()
{
	Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
	q1->push(10000);
	q1->push(20000);
	q1->push(30000);
	q1->push(40000);
	q1->push(50000);
	int size = q1->size();
	cout << "Size of queue: " << size << endl;
	cout << endl; q1->Display();
	q1->setElement(2, 777);
	q1->setElement(8, 888);
	int element = q1->getElement(2);
	cout << endl << element;
	cout << endl; q1->Display();
	element = q1->getElement(2);
	cout << endl << element;
	element = q1->getElement(2);
	cout << endl << element;
	cout << endl; q1->Display();
}