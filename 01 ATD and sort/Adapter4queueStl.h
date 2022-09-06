#pragma once
#include <queue>
using namespace std;

class Adapter4queueStl
{
	queue <int> qu;
public:
	void push(int x)
	{
		qu.push(x);
	}
	int size() {
		return qu.size();
	}
	bool isEmpty() {
		return qu.empty();               // или return size() == 0;
	}
	int getElement(int ind) {
		int size = qu.size();
		if ((ind >= 0) and (ind < size)) {
		//	queue <int> quTmp1;
		//	int element;
		//	for (int i = 0; i <= ind; i++) {
		//		element = st->pop();
		//		tmpSt1->push(element);
		//	}
		//	for (int i = 0; i <= ind; i++) {
		//		st->push(tmpSt1->pop());
		//	}
			//return element;
			return 0;
		}
		return -1;
	}

};

