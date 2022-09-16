#include <iostream>
#include "QueueMas.h"
#include "adapter4queueMas.h"
using namespace std;


void example_work_queueMas(int* _nop) {
    QueueMas* q1 = new QueueMas();
    q1->setNOP(_nop);
    q1->push(10);
    q1->push(20);
    q1->push(30);
    q1->push(40);
    q1->push(50);
    
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->display();
    cout << endl; q1->display();
    //cout << endl; q1->display();
    //cout << endl; q1->display();
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << q1->front() << " ";
        q1->pop();
    }    
    cout << endl; q1->display();
    //q1->push(100);
    cout << endl; q1->display();
    q1->pop();
    size = q1->size();

    //cout << endl << "Size of queue: " << size << endl;
    cout << endl << *q1->getNOP() << endl;
}

void example_work_adapter4queueMas(int* _nop) {
    adapter4queueMas* q1 = new adapter4queueMas();
    q1->setNOP(_nop);
    q1->push(1000);
    q1->push(2000);
    q1->push(3000);
    q1->push(4000);
    q1->push(5000);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->display();
    q1->setElement(3, 9999);
    int element = q1->getElement(3);
    cout << endl << element;
    cout << endl; q1->display();
    cout << endl; q1->display();
    cout << endl << *q1->getNOP() << endl;
}

// var 29
// Разделение по схеме Lomuto
int partitionQueueMas(adapter4queueMas* a, int start, int end, int* _nop)
{
    // Выбираем крайний правый элемент в качестве опорного элемента массива
    //int pivot = a[end];
    int pivot = a->getElement(end); *_nop += 1;
    // элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
    // элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
    // равные элементы могут идти в любом направлении
    int pIndex = start; *_nop += 1;
    // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
    // увеличивается, и этот элемент будет помещен перед опорной точкой.
    for (int i = start; i < end; i++)
    {
        //if (a[i] <= pivot)
        if (a->getElement(i) <= pivot)
        {
            //swap(a[i], a[pIndex]);
            int tmp = a->getElement(i); *_nop += 1;
            a->setElement(i, a->getElement(pIndex)); *_nop += 1;
            a->setElement(pIndex, tmp); *_nop += 1;
            pIndex++; *_nop += 1;
        }
    }
    // поменять местами `pIndex` с пивотом
    //swap(a[pIndex], a[end]);
    int tmp = a->getElement(end); *_nop += 1;
    a->setElement(end, a->getElement(pIndex)); *_nop += 1;
    a->setElement(pIndex, tmp); *_nop += 1;
    // вернуть `pIndex` (индекс опорного элемента)
    return pIndex;
}
// Процедура быстрой сортировки
void quicksortQueueMas(adapter4queueMas* a, int start, int end, int* _nop)
{
    // базовое условие
    if (start >= end) {
        return;
    }
    // переставить элементы по оси
    int pivot = partitionQueueMas(a, start, end, _nop);

    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    quicksortQueueMas(a, start, pivot - 1, _nop);

    // повторяем подмассив, содержащий элементы, превышающие точку опоры
    quicksortQueueMas(a, pivot + 1, end, _nop);
}
void example_work_quickSortQueueMas(int* _nop) {
    adapter4queueMas* q1 = new adapter4queueMas();
    q1->setNOP(_nop);
    for (int n = 300; n <= 3000; n += 300)
    {
        int* p1 = q1->getNOP();
        *p1 = 0;
        //int n = 300;
        for (int i = 0; i < n; i++)
            q1->push(rand()); *_nop += 1;
        int size = q1->size(); *_nop += 1;
        //cout << "Size of queue: " << size << endl;
        //cout << endl; q1->display();
        const clock_t begin_time = clock();
        // do something
        quicksortQueueMas(q1, 0, size - 1, _nop);
        //cout << endl; q1->display();
        cout << endl << " n = " << n << " time (ms): ";
        cout << endl;
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
        cout << endl << " NOP: " << *q1->getNOP() << endl;
        for (int i = 0; i < n; i++)
            q1->pop();

    }

    //    n = 300 time(ms) :
    //    0.007
    //    NOP : 734395

    //    n = 600 time(ms) :
    //    0.012
    //    NOP : 2611607

    //    n = 900 time(ms) :
    //    0.027
    //    NOP : 5774465

    //    n = 1200 time(ms) :
    //    0.043
    //    NOP : 10221598

    //    n = 1500 time(ms) :
    //    0.074
    //    NOP : 15868492

    //    n = 1800 time(ms) :
    //    0.119
    //    NOP : 22822192

    //    n = 2100 time(ms) :
    //    0.175
    //    NOP : 31008594

    //    n = 2400 time(ms) :
    //    0.189
    //    NOP : 40413595

    //    n = 2700 time(ms) :
    //    0.219
    //    NOP : 51135295

    //    n = 3000 time(ms) :
    //    0.315
    //    NOP : 63077991
};



int main()
{
    // var 29
    // https://www.techiedelight.com/ru/quicksort/
    // https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
    int* nop = new int;
    *nop = 0;
    //example_work_queueMas(nop);
    //example_work_adapter4queueMas(nop);
    example_work_quickSortQueueMas(nop);
}

