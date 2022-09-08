#include <iostream>
#include "StackPtr.h"
#include "Adapter4stackPtr.h"
#include "StackMas.h"
#include "Adapter4stackMas.h"
#include <queue>
#include "Adapter4queueStl.h"
#include "QueueMas.h"
#include "adapter4queueMas.h"
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
    DoubleMergeSort4queueMas();
}
