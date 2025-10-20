// Pract04_1.cpp Вариант 80
#include <stack>
#include <iostream>
#include <Windows.h>
#include <conio.h>

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
		stack <int>* tmp_st = new stack <int>();
		while (not st->empty()) {
			int x = st->top();
			st->pop();
			cout << x << endl;
			tmp_st->push(x);
		}
		while (not tmp_st->empty()) {
			int x = tmp_st->top();
			tmp_st->pop();
			st->push(x);
		}
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Вариант 80 практ. 4 ч1\n";
	myStack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.display();
	cout << "___\n";
	st.display();
	_getch();
}

