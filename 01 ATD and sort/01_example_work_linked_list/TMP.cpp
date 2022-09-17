#include <iostream>
#include "StackPtr.h"
#include "Adapter4stackPtr.h"
#include "StackMas.h"
#include "Adapter4stackMas.h"
#include <stack>
#include <queue>
#include "Adapter4queueStl.h"
#include "QueueMas.h"
#include "adapter4queueMas.h"
#include "QueuePtr.h"
#include "QueueStl.h"
#include "adapter4queuePtr.h"
#include "QueuePtr1head.h"
#include "Adapter4queuePtr1head.h"
#include "Adapter4stackStl.h"
//#include <windows.h>
using namespace std;

//WORD time_ms(void)
//{
//    SYSTEMTIME st, lt;
//    GetSystemTime(&st);
//    GetLocalTime(&lt);
//    return st.wMilliseconds;
//}


// var 76 
void example_work_stack() {
    std::cout << "Example work with stack!\n";
    StackPtr st = StackPtr();
    st.push(1000);
    st.push(2000);
    st.push(3000);
    st.push(4000);
    st.push(5000);
    int st_size = st.size();
    cout << "Size of Stack " << st.size() << endl;
    for (int i = 0; i < st_size; i++){
        cout << st.pop() << endl;
        //cout << st.peek() << endl;
    }
    st.push(999);
    cout << endl << st.peek() << endl;
    cout << "Size of Stack " << st.size() << endl;
}
void example_work_adapter4stack() {
    Adapter4stackPtr* ast = new Adapter4stackPtr();
    ast->push(1000);
    ast->push(2000);
    ast->push(3000);
    ast->push(4000);
    ast->push(5000);
    ast->push(6000);
    ast->display();
    cout << endl;
    cout << ast->getElement(3);
    cout << endl;
    ast->setElement(3,999);
    cout << endl;
    ast->display(); 
    cout << endl;
    cout << ast->getElement(3);
}
void bubbleSort4stackptr() {
    Adapter4stackPtr* ast = new Adapter4stackPtr();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->display();
    int size = ast->size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (ast->getElement(j) > ast->getElement(j + 1)) {
                int b = ast->getElement(j); // создали дополнительную переменную
                ast->setElement(j,ast->getElement(j + 1)); // меняем местами
                ast->setElement(j + 1, b); // значения элементов
            }
        }
    }
    cout << endl;
    ast->display();
    cout << endl;
}

// var 78
void example_work_stackMas() {
    cout << "Example work with stack!\n";
    StackMas *st = new StackMas();
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
    Adapter4stackMas* ast = new Adapter4stackMas();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->push(5);
    ast->push(6);
    ast->display();
    cout <<"getElement(0) " << ast->getElement(0);
    cout << endl;
    ast->setElement(2, 999);
    ast->display();
    cout << endl;
    cout << ast->getElement(2);
}
void bubbleSort4stackMas() {
    Adapter4stackMas* ast = new Adapter4stackMas();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->display();
    int size = ast->size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (ast->getElement(j) > ast->getElement(j + 1)) {
                int b = ast->getElement(j); // создали дополнительную переменную
                ast->setElement(j, ast->getElement(j + 1)); // меняем местами
                ast->setElement(j + 1, b); // значения элементов
            }
        }
    }
    cout << endl;
    ast->display();
    cout << endl;
}

// var 07
//void example_work_queueStl() {
//    queue <int> q1;
//    q1.push(10);
//    q1.push(20);
//    q1.push(30);
//    q1.push(40);
//    q1.push(50);
//    int size = q1.size();
//    cout << "Size of queue: " << size << endl;
//    for (int i = 0; i < size; i++) {
//        cout << q1.front() << " ";
//        q1.pop();
//    }
//    size = q1.size();
//    cout << endl << "Size of queue: " << size << endl;
//}
//void example_work_adapter4queueStl() {
//    Adapter4queueStl* ast = new Adapter4queueStl();
//    ast->push(10);
//    ast->push(20);
//    ast->push(30);
//    ast->push(40);
//    ast->push(50);
//    cout << endl;    ast->display();
//    cout << endl << ast->setElement(3,9999);
//    cout << endl;    ast->display();
//    cout << endl << ast->getElement(3);
//    cout << endl;    ast->display();
//}
void CompCountSort(int* array, int* count, int size)
{
    register int i, j;
    for (i = 0; i < size; i++)
        count[i] = 0;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
                count[j]++;
            else
                count[i]++;
        }
    }
    return;
}

// var 45
void example_work_queueMas() {
    QueueMas *q1 = new QueueMas();
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
    q1->setElement(3,9999);
    int element = q1->getElement(3);
    cout << endl<< element;
    cout << endl; q1->display();
    cout << endl; q1->display();
}
void DoubleMergeSort4queueMas() {
    adapter4queueMas* q1 = new adapter4queueMas();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->display();


}
void DoubleMergeSort(adapter4queueMas* a, int l, int r) {
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    DoubleMergeSort(a, l, mid);
    DoubleMergeSort(a, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    //int* tmp = (int*)malloc(r * sizeof(int)); 
    // дополнительный массив
    adapter4queueMas* tmp = new adapter4queueMas();


    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        //if ((j > r) || ((i <= mid) && (a[i] < a[j])))
        //{
        //    tmp[step] = a[i]; // tmp->setElemrnt(stem,a->getElement(i))
        //    i++;
        //}
        //else
        //{
        //    tmp[step] = a[j];
        //    j++;
        //}
    }
    // переписываем сформированную последовательность в исходный массив
    //for (int step = 0; step < r - l + 1; step++)
    //    a[l + step] = tmp[step];
}

// var 34
void example_work_queuePtr() {
    QueuePtr* q1 = new QueuePtr();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl << "Queue: "; q1->Display();
    cout << endl << "Front: " << q1->front();
    q1->pop();
    q1->pop();
    q1->pop();
    q1->push(6);
    cout << endl << "Queue: "; q1->Display();
    cout <<endl<< "front: " << q1->front();
}
void example_work_adapter4queuePtr() {
    adapter4QueuePtr* q1 = new adapter4QueuePtr();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    q1->setElement(2, 1000);
    int element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display(); 
    element = q1->getElement(2);
    cout << endl << element;     
    element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display();
}
// Функция быстрой сортировки
void quickSortQueuePtr(adapter4QueuePtr* array, int low, int high)
{
    //adapter4QueuePtr* array = arrayq->copy();
    //cout << endl << " low: " << low << " high: " << high << " QueuePtr "; array->Display();
    int i = low;
    int j = high;
    //int pivot = array[(i + j) / 2];
    int pivot = array->getElement((i + j) / 2);
    int temp;
    while (i <= j)
    {
        while (array->getElement(i) < pivot)
        //while (array[i] < pivot)
            i++;
        while (array->getElement(j) > pivot)
            j--;
        if (i <= j)
        {
            //temp = array->getElement(i);
            //array->setElement(i, array->getElement(j));
            //array->setElement(i, temp);
            temp = array->getElement(i);
            array->setElement(i, array->getElement(j));
            array->setElement(j, temp);
            i++;
            j--;
        }
    }
    if (j > low)
        quickSortQueuePtr(array, low, j);
    if (i < high)
        quickSortQueuePtr(array, i, high);
}
void example_work_quickSortQueuePtr() {
    adapter4QueuePtr* q1 = new adapter4QueuePtr();
    q1->push(5);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    quickSortQueuePtr(q1, 0, size - 1);
    cout << endl; q1->Display();
    cout << endl; q1->Display();
}

// var 92 
void merge_adapter4stack(Adapter4stackPtr* array, int const left, int const mid,
    int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    //auto* leftArray = new int[subArrayOne],
    //    * rightArray = new int[subArrayTwo];
    Adapter4stackPtr* leftArray = new Adapter4stackPtr();
    Adapter4stackPtr* rightArray = new Adapter4stackPtr();
    for (int z = 0; z < 7; z++)
    {
        leftArray->push(0);
        rightArray->push(0);
    }

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        //leftArray[i] = array[left + i];
        leftArray->setElement(i, array->getElement(left + i));

    for (auto j = 0; j < subArrayTwo; j++)
        //rightArray[j] = array[mid + 1 + j];
        rightArray->setElement(j, array->getElement(mid + 1 + j));

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray->getElement(indexOfSubArrayOne) <= rightArray->getElement(indexOfSubArrayTwo)) {
            //if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            //array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            array->setElement(indexOfMergedArray, leftArray->getElement(indexOfSubArrayOne));
            indexOfSubArrayOne++;
        }
        else {
            //array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            array->setElement(indexOfMergedArray, rightArray->getElement(indexOfSubArrayTwo));
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        //array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        array->setElement(indexOfMergedArray, leftArray->getElement(indexOfSubArrayOne));
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        //array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        array->setElement(indexOfMergedArray, rightArray->getElement(indexOfSubArrayTwo));
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort_adapter4stack(Adapter4stackPtr* array, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort_adapter4stack(array, begin, mid);
    mergeSort_adapter4stack(array, mid + 1, end);
    merge_adapter4stack(array, begin, mid, end);
}
void mergeSort_start_adapter4stack()
{
    Adapter4stackPtr* a = new Adapter4stackPtr();
    //int* a; int n;
    a->push(1);
    a->push(2);
    a->push(3);
    a->push(4);
    a->push(5);
    a->push(6);
    a->display();
    int n = a->size();
    cout << endl; a->display();
    mergeSort_adapter4stack(a,0,n-1);
    cout << endl; a->display();
}


// var 44
 /**
  * Сортирует массив, используя рекурсивную сортировку слиянием
  * up - указатель на массив, который нужно сортировать
  * down - указатель на массив с, как минимум, таким же размером как у 'up', используется как буфер
  * left - левая граница массива, передайте 0, чтобы сортировать массив с начала
  * right - правая граница массива, передайте длину массива - 1, чтобы сортировать массив до последнего элемента
  * возвращает: указатель на отсортированный массив. Из-за особенностей работы данной реализации
  * отсортированная версия массива может оказаться либо в 'up', либо в 'down'
  **/
Adapter4stackPtr* merge_sort_adapter4stackPtr(Adapter4stackPtr* up, Adapter4stackPtr* down, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        //down[left] = up[left];
        down->setElement(left, up->getElement(left));
        return down;
    }

    unsigned int middle = left + (right - left) / 2;

    // разделяй и сортируй
    Adapter4stackPtr* l_buff = merge_sort_adapter4stackPtr(up, down, left, middle);
    Adapter4stackPtr* r_buff = merge_sort_adapter4stackPtr(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    Adapter4stackPtr* target = l_buff == up ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            //if (l_buff[l_cur] < r_buff[r_cur])
            if (l_buff->getElement(l_cur) < r_buff->getElement(r_cur))
            {
                //target[i] = l_buff[l_cur];
                target->setElement(i, l_buff->getElement(l_cur));
                l_cur++;
            }
            else
            {
                //target[i] = r_buff[r_cur];
                target->setElement(i, r_buff->getElement(r_cur));
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            //target[i] = l_buff[l_cur];
            target->setElement(i, l_buff->getElement(l_cur));
            l_cur++;
        }
        else
        {
            //target[i] = r_buff[r_cur];
            target->setElement(i, r_buff->getElement(r_cur));
            r_cur++;
        }
    }
    return target;
}
void merge_sort_adapter4stackPtr_start() {
    //merge_sort_adapter4stackPtr
    Adapter4stackPtr* ast1 = new Adapter4stackPtr();
    ast1->push(1000);
    ast1->push(2000);
    ast1->push(3000);
    ast1->push(4000);
    ast1->push(5000);
    ast1->push(6000);
    ast1->display();
    int size = ast1->size();
    cout << endl << " size: " << size << endl;
    Adapter4stackPtr* ast2 = new Adapter4stackPtr();
    for (int i=0;i<size;i++)
        ast2->push(-1);
    Adapter4stackPtr* result;
    result = merge_sort_adapter4stackPtr(ast1, ast2, 0, size-1);
    cout << endl;
    result->display();
};

// var 38
int partitionStackMas(Adapter4stackMas* a, int start, int end)
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
    int tmp = a->getElement(end);
    a->setElement(end, a->getElement(pIndex));
    a->setElement(pIndex, tmp);

    // вернуть `pIndex` (индекс опорного элемента)
    return pIndex;
}
// Процедура быстрой сортировки
void quicksortStackMas(Adapter4stackMas* a, int start, int end)
{
    // базовое условие
    if (start >= end) {
        return;
    }
    // переставить элементы по оси
    int pivot = partitionStackMas(a, start, end);
    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    quicksortStackMas(a, start, pivot - 1);
    // повторяем подмассив, содержащий элементы, превышающие точку опоры
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
    cout << endl<< "sorted ";
    cout << endl; st->display();
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
    for(int n=300; n<=3000; n+=300)
    {
        //int n = 300;
        for(int i=0; i<n; i++)
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

// var 27
void example_work_QueuePtr1head() {
    QueuePtr1head* q1 = new QueuePtr1head();
    q1->push(100);
    q1->push(200);
    q1->push(300);
    q1->push(400);
    q1->push(500);
    q1->push(600);
    q1->push(700);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << "front: " << q1->front() << endl;
    q1->pop();
    //q1->pop();
    //q1->pop();
    q1->push(999);
    cout << "front: " << q1->front() << endl;
    cout << endl; q1->Display();
    cout << endl; q1->Display();
    cout << endl; q1->Display();
    size = q1->size();
    cout << endl << "Size of queue: " << size << endl;
}
void example_work_adapter4queuePtr1head() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    q1->setElement(2, 5000);
    int element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display();
    element = q1->getElement(2);
    cout << endl << element;
    element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display();
}
// Разделение по схеме Lomuto
int partitionQueuePtr1head(Adapter4queuePtr1head* a, int start, int end)
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
void quicksortQueuePtr1head(Adapter4queuePtr1head* a, int start, int end)
{
    // базовое условие
    if (start >= end) {
        return;
    }
    // переставить элементы по оси
    int pivot = partitionQueuePtr1head(a, start, end);

    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    quicksortQueuePtr1head(a, start, pivot - 1);

    // повторяем подмассив, содержащий элементы, превышающие точку опоры
    quicksortQueuePtr1head(a, pivot + 1, end);
}
void example_work_quickSortQueuePtr1head() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    q1->push(5000);
    q1->push(4000);
    q1->push(3000);
    q1->push(2000);
    q1->push(1000);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    quicksortQueuePtr1head(q1, 0, size - 1);

    cout << endl; q1->Display();
}

// var 39
// Разделение по схеме Lomuto
int partitionQueueStl(Adapter4queueStl* a, int start, int end)
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
    for (int i = start; i < end; i++) //3n 
    {
        //if (a[i] <= pivot)
        if (a->getElement(i) <= pivot)
        {
            //swap(a[i], a[pIndex]);
            int tmp = a->getElement(i); //1
            a->setElement(i, a->getElement(pIndex)); //1
            a->setElement(pIndex, tmp); //1
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
void quicksortQueueStl(Adapter4queueStl* a, int start, int end)
{
    // базовое условие
    if (start >= end) {
        return;
    }
    // переставить элементы по оси
    int pivot = partitionQueueStl(a, start, end);
    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    quicksortQueueStl(a, start, pivot - 1);
    // повторяем подмассив, содержащий элементы, превышающие точку опоры
    quicksortQueueStl(a, pivot + 1, end);
}
void example_work_quickSortQueueStl() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    for(int i=1000; i>20; i-=10)
        q1->push(i);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    //quicksortQueueStl(q1, 0, size - 1);
    cout << endl << "Sorted: ";
    cout << endl; q1->Display();
}

// var 40
void example_work_stackStl() {
    stack <int>* st = new stack<int>();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    int size = st->size();
    cout << "Size: " << size << endl;
    while (!st->empty()) {
        cout << " " << st->top();
        st->pop();
    }
    size = st->size();
    cout << endl << "Size: " << size << endl;
}
void example_work_Adapter4stackStl() {
    Adapter4stackStl* st = new Adapter4stackStl();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    int size = st->size();
    cout << "Size: " << size << endl;
    cout << endl; st->display();
    st->setElement(3, 5555);
    cout << endl; st->display();
    cout << endl; st->display(); 
    cout << endl << st->getElement(0);
}
int partitionStackStl(Adapter4stackStl* a, int start, int end)
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
void quicksortStackStl(Adapter4stackStl* a, int start, int end)
{
    // базовое условие
    if (start >= end) {
        return;
    }
    // переставить элементы по оси
    int pivot = partitionStackStl(a, start, end);
    // повторяем подмассив, содержащий элементы, меньшие опорной точки
    quicksortStackStl(a, start, pivot - 1);
    // повторяем подмассив, содержащий элементы, превышающие точку опоры
    quicksortStackStl(a, pivot + 1, end);
}
void example_work_quickSortStackStl() {
    Adapter4stackStl* st = new Adapter4stackStl();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    int size = st->size();
    cout << "Size: " << size << endl;
    cout << endl; st->display();
    quicksortStackStl(st, 0, size - 1);
    cout << endl; st->display();
}

// var 83
void countSort_queuePtr1head(Adapter4queuePtr1head* arr, int n) {

    //int arr1[10];
    //int count_arr[10];
    Adapter4queuePtr1head* arr1 = new Adapter4queuePtr1head();
    Adapter4queuePtr1head* count_arr = new Adapter4queuePtr1head();
    for (int i = 0; i < n; i++) {
        arr1->push(-1);
        count_arr->push(-1);
    }

    //arr->Display();

    //int x = arr[0];
    int x = arr->getElement(0);

    for (int i = 1; i < n; i++) {
        //if (arr[i] > x)
        if (arr->getElement(i) > x)
            //x = arr[i];
            x = arr->getElement(i);
    }

    for (int i = 0; i <= x; ++i) {
        //count_arr[i] = 0;
        count_arr->setElement(i,0);
    }

    for (int i = 0; i < n; i++) {
        //count_arr[arr[i]]++;
        count_arr->setElement(arr->getElement(i), count_arr->getElement(arr->getElement(i))+1);
    }

    for (int i = 1; i <= x; i++) {
        //count_arr[i] += count_arr[i - 1];
        count_arr->setElement(i, count_arr->getElement(i) + count_arr->getElement(i - 1));
    }

    count_arr->Display();

    for (int i = n - 1; i >= 0; i--) {
        //arr1[count_arr[arr[i]] - 1] = arr[i];
        int arri = arr->getElement(i);
        int pos = count_arr->getElement(arr->getElement(i)) - 1;
        arr1->setElement(pos, arri);
        //count_arr[arr[i]]--;
        int mm = count_arr->getElement(arr->getElement(i)) - 1;
        count_arr->setElement(arr->getElement(i), mm);
    }

    for (int i = 0; i < n; i++) {
        //arr[i] = arr1[i];
        arr->setElement(i, arr1->getElement(i));
    }


}
void example_work_countSort_queuePtr1head() {
    Adapter4queuePtr1head* q1 = new Adapter4queuePtr1head();
    q1->push(900);
    q1->push(200);
    q1->push(300);
    q1->push(400);
    q1->push(500);
    q1->push(600);
    q1->push(700);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    countSort_queuePtr1head(q1, size);
    cout << endl << "sorted:"<<endl; q1->Display();
}

// var 79
void example_work_queueStl() {
    QueueStl* q1 = new QueueStl();
    q1->push(1000);
    q1->push(2000);
    q1->push(3000);
    q1->push(4000);
    q1->push(5000);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << q1->front() << " ";
        q1->pop();
    }    
    cout << endl; q1->Display();
    q1->push(999);
    cout << endl; q1->Display();
    q1->pop();
    size = q1->size();
    //cout << endl << "Size of queue: " << size << endl;
}
void example_work_adapter4queueStl() {
    Adapter4queueStl* q1 = new Adapter4queueStl();
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
void bubbleSort_queueStl(Adapter4stackMas* ast) {
    int size = ast->size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (ast->getElement(j) > ast->getElement(j + 1)) {
                int b = ast->getElement(j); // создали дополнительную переменную
                ast->setElement(j, ast->getElement(j + 1)); // меняем местами
                ast->setElement(j + 1, b); // значения элементов
            }
        }
    }
}
void example_work_bubbleSort_queueStl() {
    Adapter4stackMas* ast = new Adapter4stackMas();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->push(8);
    ast->push(1);
    ast->display();
    cout << endl;
    bubbleSort_queueStl(ast);
    ast->display();
    cout << endl;
}

int main()
{
    // var 7
    // example_work_adapter4queueStl();

    // var 27 
    //example_work_QueuePtr1head();
    //example_work_adapter4queuePtr1head();
    //example_work_quickSortQueuePtr1head();

    // var 29
    // https://www.techiedelight.com/ru/quicksort/
    // https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
    //example_work_queueMas();
    //example_work_adapter4queueMas();
    //example_work_quickSortQueueMas();

    // var 34 
    //example_work_queuePtr();
    //example_work_adapter4queuePtr();
    //example_work_quickSortQueuePtr();

    // var 38
    // Массив	Стек	Быстрая сортировка Хоару (c медианным (pivot) элемнтом)
    //example_work_stackMas();
    //example_work_adapter4stackMas();
    example_work_quickSortStackMas();

    // var 39
    //example_work_queueStl();
    //example_work_adapter4queueStl();
    //example_work_quickSortQueueStl();

    // var 40
    //Библиотека классов 	Стек	Быстрая сортировка Хоару(c медианным(pivot) элеметом)
    //example_work_stackStl();
    //example_work_Adapter4stackStl();
    //example_work_quickSortStackStl();

    // var 44
    //example_work_stack();
    //example_work_adapter4stack();
    //merge_sort_adapter4stackPtr_start();

    // var 45
    //example_work_queueMas();
    //example_work_adapter4queueMas();
    //DoubleMergeSort4queueMas();

    // 76 variant
    //example_work_stack();  
    //example_work_adapter4stack();
    //bubbleSort4stackptr();  

    // 78 variant 
    //example_work_stackMas();
    //example_work_adapter4stackMas();
    //bubbleSort4stackMas();

    // var 79
    //Библиотека классов 	Очередь	Пузырьковая
    //example_work_queueStl();
    //example_work_adapter4queueStl();
    //example_work_bubbleSort_queueStl();

    //var 83
    //Указатели	Очередь с 1 головой	Распределяющий подсчет
    //example_work_QueuePtr1head();
    //example_work_adapter4queuePtr1head();
    //example_work_countSort_queuePtr1head(); // пока не получилось

    // var 92
    //example_work_stack();
    //example_work_adapter4stack();
    //mergeSort_start_adapter4stack();
}

