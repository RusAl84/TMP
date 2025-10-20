// Pract04_1.cpp Вариант 80
#include <stack>
#include <iostream>

using namespace std;

class myStack {
private:
	stack <int>* st;

public:
	myStack()
	{ 
		st = new stack <int>;
	}
	void push(int _element) {
		st->push(_element);
	}
	void pop() {
		st->pop();
	}
	int top() {
		return st->top();
	}
	bool empty(){
		return st->empty();
	}
	void display() {
		stack <int>* tmp_st;
	}

};

int main()
{
   cout << "Hello World!\n";
}

