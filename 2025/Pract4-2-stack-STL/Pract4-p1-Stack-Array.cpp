// Pract4-p1-Stack-Array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// https://www.geeksforgeeks.org/dsa/implement-stack-using-array/
#include <stack>
#include <iostream>
using namespace std;

class adapter4stackSTL {
    stack<int> * st;
    int i;
public:
    adapter4stackSTL() {
        st = new stack<int>();
    }
    void push(int x) {
        st->push(x);
    }
    void pop() {
        st->pop();
    }
    int peek() {
        return st->top();
    }
    bool isEmpty() {
        return st->empty();
    }

    void display() {
        stack <int>* tmp_st = new stack <int>();
        while (not isEmpty()) {
            int x = peek();
            pop();
            tmp_st->push(x);
            cout << x << endl;
        }
        while (not tmp_st->empty()) {
            int x = tmp_st->top();
            tmp_st->pop();
            push(x);
        }
        delete tmp_st;
    }
    /// <summary>
    /// Функция получения элемента из стека
    /// </summary>
    /// <param name="ind"> индекс</param>
    /// <returns> значение элемента </returns>
    int getElement(int ind) {
        stack <int>* tmp_st = new stack <int>();
        int element = 0;
        int index = 0;
        while (not isEmpty()) {
            int x = peek();
            pop();
            tmp_st->push(x);
            if (ind == index) {
                element = x;
                break;
            }
            index++;
        }
        while (not tmp_st->empty()) {
            int x = tmp_st->top();
            tmp_st->pop();
            push(x);
        }
        delete tmp_st;
        return element;
    }
    /// <summary>
    /// Внести значение в элемент списка
    /// </summary>
    /// <param name="ind"> индекс </param>
    /// <param name="element"> значение </param>
    void setElement(int ind, int element ) {
        stack <int>* tmp_st = new stack <int>();
        int index = 0;
        while (not isEmpty()) {
            int x = peek();
            pop();
            if (ind == index) {
                tmp_st->push(element); 
                break;
            }
            else
            {
                tmp_st->push(x);
            }
            index++;
        }
        while (not tmp_st->empty()) {
            int x = tmp_st->top();
            tmp_st->pop();
            push(x);
        }
        delete tmp_st;
    }
};

int main() {
    adapter4stackSTL st;

    st.push(100);
    st.push(200);
    st.push(300);
    st.push(400);
    st.push(700);
    st.push(700);
    st.push(777);
    cout << "\n";
    st.display();
    cout << " st.getElement(0) = " << st.getElement(0) << endl;
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    cout << " st.getElement(7) = " << st.getElement(7) << endl;
    st.setElement(3, 888);
    st.display();
    cout << " st.getElement(3) = " << st.getElement(3) << endl;
    return 0;
}

