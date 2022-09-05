#include <iostream>
#include "Stack.h"
using namespace std;

void example_work_stack() {
    std::cout << "Example work with stack!\n";
    Stack st = Stack();
    st.push(137);
    st.push(133);
    st.push(135);
    st.push(134);
    st.push(138);
    int st_size = st.size();
    cout << "Size of Stack " << st.size() << endl;
    for (int i = 0; i < st_size; i++){
        cout << st.pop() << endl;
        //cout << st.peek() << endl;
    }
    cout << "Size of Stack " << st.size() << endl;
}



int main()
{
    example_work_stack();
    //ввод N


    
}
