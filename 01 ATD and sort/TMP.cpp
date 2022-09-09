﻿#include <iostream>
#include "StackPtr.h"
#include "Adapter4stackPtr.h"
#include "StackMas.h"
#include "Adapter4stackMas.h"
#include <queue>
#include "Adapter4queueStl.h"
#include "QueueMas.h"
#include "adapter4queueMas.h"
#include "QueuePtr.h"
#include "adapter4queuePtr.h"
using namespace std;

// var 76 
void example_work_stack() {
    std::cout << "Example work with stack!\n";
    StackPtr st = StackPtr();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int st_size = st.size();
    cout << "Size of Stack " << st.size() << endl;
    for (int i = 0; i < st_size; i++){
        cout << st.pop() << endl;
        //cout << st.peek() << endl;
    }
    cout << "Size of Stack " << st.size() << endl;
}
void example_work_adapter4stack() {
    Adapter4stackPtr* ast = new Adapter4stackPtr();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->display();
    cout << endl;
    cout << ast->getElement(0);
    cout << endl;
    ast->setElement(2,999);
    cout << endl;
    ast->display(); 
    cout << endl;
    cout << ast->getElement(2);
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
    std::cout << "Example work with stack!\n";
    StackMas st = StackMas();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    int st_size = st.size();
    cout << "Size of Stack " << st.size() << endl;
    for (int i = 0; i < st_size; i++) {
        cout << st.pop() << endl;
        //cout << st.peek() << endl;
    }
    cout << "Size of Stack " << st.size() << endl;
}
void example_work_adapter4stackMas() {
    Adapter4stackMas* ast = new Adapter4stackMas();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->display();
    cout << endl;
    cout << ast->getElement(0);
    cout << endl;
    ast->setElement(2, 999);
    cout << endl;
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
void example_work_queueStl() {
    queue <int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    int size = q1.size();
    cout << "Size of queue: " << size << endl;
    for (int i = 0; i < size; i++) {
        cout << q1.front() << " ";
        q1.pop();
    }
    size = q1.size();
    cout << endl << "Size of queue: " << size << endl;
}
void example_work_adapter4queueStl() {
    Adapter4queueStl* ast = new Adapter4queueStl();
    ast->push(1000);
    ast->push(2000);
    ast->push(3000);
    ast->push(4000);
    ast->push(5000);
    cout << endl;    ast->Dislay();
    cout << endl << ast->setElement(4,9999);
    cout << endl;    ast->Dislay();
    cout << endl << ast->getElement(4);
    cout << endl;    ast->Dislay();
}
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
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Dislay();
    cout << endl; q1->Dislay();
    cout << endl; q1->Dislay();
    cout << endl; q1->Dislay();
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << q1->front() << " ";
        q1->pop();
    }    
    cout << endl;
    q1->push(100);
    q1->push(100);
    q1->push(100);
    q1->push(100);
    q1->push(100);
    q1->push(100);
    q1->push(100);
    q1->push(100);
    q1->push(100);
    q1->Dislay();

    size = q1->size();
    cout << endl << "Size of queue: " << size << endl;
}
void example_work_adapter4queueMas() {
    adapter4queueMas* q1 = new adapter4queueMas();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Dislay();
    q1->setElement(4,1000);
    int element = q1->getElement(4);
    cout << endl<< element;
    cout << endl; q1->Dislay();
    cout << endl; q1->Dislay();
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
    cout << endl; q1->Dislay();


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

int main()
{
    // 76 variant
    //example_work_stack();  
    //example_work_adapter4stack();
    //bubbleSort4stackptr();  

    // 78 variant 
    //example_work_stackMas();
    //example_work_adapter4stackMas();
    //bubbleSort4stackMas();

    //var 7
    // example_work_adapter4queueStl();

    // var 45
    //example_work_queueMas();
    //example_work_adapter4queueMas();
    //DoubleMergeSort4queueMas();

    // var 34 
    //example_work_queuePtr();
    //example_work_adapter4queuePtr();
    //example_work_quickSortQueuePtr();

    //var 92
    //example_work_stack();
    //example_work_adapter4stack();
    mergeSort_start_adapter4stack();

}
