#include <iostream>
#include "QueueMas.h"
using namespace std;


void example_work_queueMas() {
    QueueMas* q1 = new QueueMas();
    int n_opp = 0;
    q1->push(10);
    q1->push(20);
    q1->push(30);
    q1->push(40);
    q1->push(50);
    cout << n_opp;
    //int size = q1->size();
    //cout << "Size of queue: " << size << endl;
    //cout << endl; q1->display();
    ////cout << endl; q1->display();
    ////cout << endl; q1->display();
    ////cout << endl; q1->display();
    //cout << endl;
    //for (int i = 0; i < size; i++) {
    //    cout << q1->front() << " ";
    //    q1->pop();
    //}    
    //cout << endl; q1->display();
    ////q1->push(100);
    //cout << endl; q1->display();
    //q1->pop();
    //size = q1->size();

    //cout << endl << "Size of queue: " << size << endl;
}

void example_work_adapter4queueMas() {
    adapter4queueMas* q1 = new adapter4queueMas();
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
}

// var 29
// Разделение по схеме Lomuto
int partitionQueueMas(adapter4queueMas* a, int start, int end)
{
    // Выбираем крайний правый элемент в качестве опорного элемента массива
    //int pivot = a[end];
    int pivot = a->getElement(end);
    // элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
    // элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
    // равные элементы могут идти в любом направлении
    int pIndex = start;
    // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
    // увеличивается, и этот элемент будет помещен перед опорной точкой.
    for (int i = start; i < end; i++)
    {
        //if (a[i] <= pivot)
        if (a->getElement(i) <= pivot)
        {
            //swap(a[i], a[pIndex]);
            int tmp = a->getElement(i);
            a->setElement(i, a->getElement(pIndex));
            a->setElement(pIndex, tmp);
            pIndex++;
        }
    }
    // поменять местами `pIndex` с пивотом
    //swap(a[pIndex], a[end]);
    int tmp = a->getElement(end);
    a->setElement(end, a->getElement(pIndex));
    a->setElement(pIndex, tmp);
    // вернуть `pIndex` (индекс опорного элемента)
    return pIndex;
}
// Процедура быстрой сортировки
void quicksortQueueMas(adapter4queueMas* a, int start, int end)
{
    // базовое условие
    if (start >= end) {
        return;
    }
    // переставить элементы по оси
    int pivot = partitionQueueMas(a, start, end);

    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    quicksortQueueMas(a, start, pivot - 1);

    // повторяем подмассив, содержащий элементы, превышающие точку опоры
    quicksortQueueMas(a, pivot + 1, end);
}
void example_work_quickSortQueueMas() {
    adapter4queueMas* q1 = new adapter4queueMas();
    for (int n = 300; n <= 3000; n += 300)
    {
        //int n = 300;
        for (int i = 0; i < n; i++)
            q1->push(rand());
        int size = q1->size();
        //cout << "Size of queue: " << size << endl;
        //cout << endl; q1->display();
        const clock_t begin_time = clock();
        // do something
        quicksortQueueMas(q1, 0, size - 1);
        //cout << endl; q1->display();
        //cout << endl << " n = " << n << " time (ms): ";
        cout << endl;
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
            q1->pop();
    }
    //n = 300 time(ms) : 0.003
    //n = 600 time(ms) : 0.008
    //n = 900 time(ms) : 0.021
    //n = 1200 time(ms) : 0.035
    //n = 1500 time(ms) : 0.049
    //n = 1800 time(ms) : 0.067
    //n = 2100 time(ms) : 0.092
    //n = 2400 time(ms) : 0.115
    //n = 2700 time(ms) : 0.143
    //n = 3000 time(ms) : 0.195
    //300	0,004
    //600	0,008
    //900	0,023
    //1200	0,039
    //1500	0,047
    //1800	0,065
    //2100	0,118
    //2400	0,14
    //2700	0,147
    //3000	0,18
};



int main()
{
    // var 29
    // https://www.techiedelight.com/ru/quicksort/
    // https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
    example_work_queueMas();
    example_work_adapter4queueMas();
    example_work_quickSortQueueMas();
}

