#pragma once
class QueuePtr
{
	int csize;
	struct list
	{
		int data; // поле данных
		struct list* next; // указатель на следующий элемент
	};
	list *head, *rear;
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

