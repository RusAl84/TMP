#include <iostream>
#include "Stack.h"
using namespace std;

void example_work_stack() {
    std::cout << "Example work with stack!\n";
    Stack st = Stack();
    st.push(7);
    st.push(3);
    st.push(5);
    st.push(4);
    st.push(8);
    int st_size = st.size();
    cout << "Size of Stack " << st.size() << endl;
    for (int i = 0; i < st_size; i++)
        cout << st.pop() << endl;
    cout << "Size of Stack " << st.size() << endl;
}

int main()
{
    example_work_stack();
    
}
