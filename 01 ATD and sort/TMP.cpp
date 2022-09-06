#include <iostream>
#include "StackPtr.h"
#include "Adapter4stackPtr.h"
#include "StackMas.h"
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

int main()
{
    //example_work_stack(); // 76 variant
    //example_work_adapter4stack();
    //bubbleSort4stackptr();  

    // 78 variant 
    example_work_stackMas();

}
