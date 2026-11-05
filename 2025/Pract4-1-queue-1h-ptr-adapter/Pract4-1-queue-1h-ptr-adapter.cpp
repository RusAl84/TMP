// https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-queue-using-linked-list/
#include <iostream>
#include <stdexcept>

using namespace std;

class QueuePtr1head
{
protected:                      // было private по умолчанию
    int csize;
    struct list
    {
        int data;
        struct list* next;
    };
    list* head;

public:
    QueuePtr1head() {
        csize = 0;
        head = nullptr;
    }

    void push(int element) {
        list* l = new list();
        if (csize == 0) {
            l->next = nullptr;
            l->data = element;
            head = l;
        }
        else
        {
            l->next = head;
            l->data = element;
            head = l;
        }
        csize++;
    }

    int front() {
        list* l = head;
        list* prev = nullptr;
        while (l->next != nullptr) {
            prev = l;
            l = l->next;
        }
        return l->data;
    }

    int size() {
        return csize;
    }

    void pop() {
        if (csize == 1) {
            delete(head);
            csize = 0;
            head = nullptr;
        }
        else
        {
            list* l = head;
            list* prev = nullptr;
            while (l->next != nullptr) {
                prev = l;
                l = l->next;
            }
            csize--;
            delete(l);
            prev->next = nullptr;
        }
    }

    void Display() {
        QueuePtr1head* queTmp1 = new QueuePtr1head();
        int c_size = size();
        for (int i = 0; i < c_size; i++) {
            queTmp1->push(front());
            cout << " " << front() << "  $" << endl;
            pop();
        }
        for (int i = 0; i < c_size; i++) {
            push(queTmp1->front());
            queTmp1->pop();
        }
    }
};

class QueuePtr1headAdapter : public QueuePtr1head
{

public:
    int getElement(int index) {
        int element = -1;
        int c_size = size();
        if ((index>= 0) and (index< c_size)){
            QueuePtr1headAdapter* queTmp1 = new QueuePtr1headAdapter();
            
            for (int i = 0; i < index; i++) {
                queTmp1->push(front());
                pop();
            }
            element = front();
            c_size = queTmp1->size();
            for (int i = 0; i < c_size; i++) {
                push(queTmp1->front());
                queTmp1->pop();
            }
        }
        return element;
    }

    void setElement(int index, int value) {
        int element = -1;
        int c_size = size();
        if ((index >= 0) and (index < c_size)) {
            QueuePtr1headAdapter* queTmp1 = new QueuePtr1headAdapter();

            for (int i = 0; i < index; i++) {
                queTmp1->push(front());
                pop();
            }
            queTmp1->pop();
            queTmp1->push(value);
            c_size = queTmp1->size();
            for (int i = 0; i < c_size; i++) {
                push(queTmp1->front());
                queTmp1->pop();
            }
        }
    }
};

int main() {
    QueuePtr1headAdapter q;

    q.push(1000);
    q.push(2000);
    q.push(3000);
    q.push(4000);
    q.push(5000);

    q.Display();

    cout << "getElement(0) = " << q.getElement(0) << endl;

    q.setElement(0, 1111);

    cout << "After setElement(0, 1111):" << endl;
    q.Display();

    return 0;
}