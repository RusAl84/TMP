// pract-4-1-var-55-queue-STL.cpp 

//https://www.geeksforgeeks.org/cpp/queue-cpp-stl/
#include <iostream>
#include <queue>
using namespace std;

class myQueue {

private:
	queue <int>* q;
public:
	myQueue()
	{
		q = new queue<int>();
	}
	void push(int element) {
		q->push(element);
	}
	int front(int element) {
		return q->front();
	}
	int back(int element) {
		return q->back();
	}

};


int main()
{
   cout << "queue<int>* STL\n";
}
