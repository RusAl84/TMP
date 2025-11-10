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

int partitionStackMas(Adapter4stackMas* a, int start, int end, int* nop)
{// 2+n(3+2n+6+6n+3+4n)+3+2n+6+6n+3+4n 
    int pivot = a->getElement(end);  *nop += 1; // 2
    int pIndex = start; *nop += 1;
    for (int i = start; i < end; i++)  //n
    {
        if (a->getElement(i) <= pivot)
        {
            int tmp = a->getElement(i); *nop += 1; //3+2n
            a->setElement(i, a->getElement(pIndex)); *nop += 1; //6+6n
            a->setElement(pIndex, tmp); *nop += 1; //3+4n
            pIndex++; *nop += 1;
        }
    }
    int tmp = a->getElement(end); *nop += 1; //3+2n
    a->setElement(end, a->getElement(pIndex)); *nop += 1; //6+6n
    a->setElement(pIndex, tmp); *nop += 1; //3+4n
    return pIndex;
}

void quicksortStackMas(Adapter4stackMas* a, int start, int end, int* _nop)
{
    if (start >= end) {
        return;
    }
    int pivot = partitionStackMas(a, start, end, _nop); //log2(n)*(2 + n(3 + 2n + 6 + 6n + 3 + 4n) + 3 + 2n + 6 + 6n + 3 + 4n)
    quicksortStackMas(a, start, pivot - 1, _nop);
    quicksortStackMas(a, pivot + 1, end, _nop);
}
void example_work_quickSortStackMas(int* _nop) {
    Adapter4stackMas* st = new Adapter4stackMas();
    st->setNOP(_nop);
    for (int n = 300; n <= 3000; n += 300)
    {
        int* p1 = st->getNOP();
        *p1 = 0;
        //int n = 300;
        for (int i = 0; i < n; i++)
            st->push(rand()); *_nop += 1;
        int size = st->size(); *_nop += 1;
        const clock_t begin_time = clock();
        quicksortStackMas(st, 0, size - 1, _nop);
        cout << endl << " n = " << n << " time (ms): ";
        cout << endl;
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
        cout << endl << " NOP: " << *st->getNOP() << endl;
        for (int i = 0; i < n; i++)
            st->pop();

    }
}
int main()
{
    // var 38
    int* nop = new int;
    *nop = 0;
    //example_work_stackMas();
    //example_work_adapter4stackMas();
    example_work_quickSortStackMas(nop);

    //    n = 300 time(ms) :
    //    0.137
    //    NOP : 59586104

    //    n = 600 time(ms) :
    //    0.529
    //    NOP : 235660892

    //    n = 900 time(ms) :
    //    1.234
    //    NOP : 674793880

    //    n = 1200 time(ms) :
    //    1.595
    //    NOP : 1141864334

    //    n = 1500 time(ms) :
    //    2.743
    //    NOP : 1990216642

    //    n = 1800 time(ms) :
    //    3.865
    //    NOP : -1424239708

    //    n = 2100 time(ms) :
    //    5.443
    //    NOP : -273528386

    //    n = 2400 time(ms) :
    //    7.226
    //    NOP : 1343098684

    //    n = 2700 time(ms) :
    //    8.138
    //    NOP : 2112128298

    //    n = 3000 time(ms) :
    //    10.891
    //    NOP : 114136684
}
