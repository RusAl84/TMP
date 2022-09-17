#include <iostream>
#include "StackMas.h"
#include "Adapter4stackMas.h"

using namespace std;

void example_work_stackMas() {
    cout << "Example work with stack!\n";
    StackMas* st = new StackMas();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->display();
    st->display();
    st->display();
    cout << "Size of Stack " << st->size() << endl;

}
void example_work_adapter4stackMas() {
    cout << "Example work with Adapter for stack!\n";
    Adapter4stackMas* ast = new Adapter4stackMas();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->push(5);
    ast->push(6);
    ast->display();
    cout << "getElement(0) " << ast->getElement(0);
    cout << endl;
    ast->setElement(2, 999);
    ast->display();
    cout << endl;
    cout << ast->getElement(2);
}

int partitionStackMas(Adapter4stackMas* a, int start, int end)
{
    int pivot = a->getElement(end);
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a->getElement(i) <= pivot)
        {
            int tmp = a->getElement(i);
            a->setElement(i, a->getElement(pIndex));
            a->setElement(pIndex, tmp);
            pIndex++;
        }
    }
    int tmp = a->getElement(end);
    a->setElement(end, a->getElement(pIndex));
    a->setElement(pIndex, tmp);
    return pIndex;
}

void quicksortStackMas(Adapter4stackMas* a, int start, int end)
{
    if (start >= end) {
        return;
    }
    int pivot = partitionStackMas(a, start, end);
    quicksortStackMas(a, start, pivot - 1);
    quicksortStackMas(a, pivot + 1, end);
}
void example_work_quickSortStackMas() {
    Adapter4stackMas* st = new Adapter4stackMas();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    int size = st->size();
    cout << "Size: " << size << endl;
    cout << endl; st->display();
    quicksortStackMas(st, 0, size - 1);
    cout << endl << "sorted ";
    cout << endl; st->display();
}
int main()
{
    // var 38
    example_work_stackMas();
    example_work_adapter4stackMas();
    example_work_quickSortStackMas();
}
