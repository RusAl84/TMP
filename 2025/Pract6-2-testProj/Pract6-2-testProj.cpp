#include <iostream>
#include "adapter4myStack.h"
using namespace std;

int main()
{
    adapter4myStack st(100);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(7);
    st.push(7);
    st.push(7);
    cout << "\n";
    st.display();
    cout << " st.getElement(0) = " << st.getElement(0) << endl;
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    cout << " st.getElement(7) = " << st.getElement(7) << endl;
    st.setElement(3, 8);
    st.display();
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    return 0;
}
