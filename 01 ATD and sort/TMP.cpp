#include <iostream>
#include "Stack.h"
#include "Adapter4stack.h"
using namespace std;

void example_work_stack() {
    std::cout << "Example work with stack!\n";
    Stack st = Stack();
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
    Adapter4stack* ast = new Adapter4stack();
    ast->push(1);
    ast->push(2);
    ast->push(3);
    ast->push(4);
    ast->display();
    cout << endl;
    cout << ast->getElement(1);

}


int main()
{
    //example_work_stack();
    example_work_adapter4stack();
    //ввод N


    
}
