#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

unsigned int nop = 0;

struct Node {
    int data;
    Node* next;
};
class QueuePtr1head {

    Node* front;
public:
    QueuePtr1head() : front(nullptr)
    {
    }
    void enqueue(int x)
    {
        Node* newNode = new Node{ x, nullptr }; nop++;
        if (isEmpty()) {
            front = newNode; nop++;
        }
        else {
            Node* current = front->next; nop++;
            Node* pred = front; nop++;
            while (current != nullptr)
            {
                pred = current; nop++;
                current = current->next; nop++;
            }
            pred->next = newNode; nop++;
        }
    }
    void dequeue()
    {
        nop++;
        if (front == nullptr)
            return;
        Node* temp = front; nop++;
        front = front->next; nop++;
        delete temp; nop++;
    }
    int peek()
    {
        nop++;
        if (!isEmpty()) {
            nop++;
            return front->data;
        }
    }
    bool isEmpty()
    {
        nop++;
        return front == nullptr;
    }


    void display() { // O(2*n)
        QueuePtr1head* pq = new QueuePtr1head(); nop++;
        int tmp = 0; nop++;
        while (!isEmpty())
        {
            tmp = peek(); nop++;
            cout << tmp << " "; nop++;
            pq->enqueue(tmp); nop++;
            dequeue(); nop++;
        }
        while (!pq->isEmpty())
        {
            tmp = pq->peek(); nop += 2;
            enqueue(tmp); nop++;
            pq->dequeue(); nop++;
        }
        delete pq; nop++;
        cout << endl; nop++;
    }
};

class Adapter4QueuePtr1head
{
    QueuePtr1head* pq;
public:
    Adapter4QueuePtr1head() {
        pq = new QueuePtr1head();
    }
    void enqueue(int x)
    {
        nop++;
        pq->enqueue(x);
    }
    void dequeue()
    {
        nop++;
        pq->dequeue();
    }
    int peek()
    {
        nop++;
        return pq->peek();
    }
    bool isEmpty()
    {
        nop++;
        return pq->isEmpty();
    }

    void display() {
        nop++;
        return pq->display();
    }
    int getElement(int ind) {
        int element = -1; nop++;
        QueuePtr1head* queTmp1 = new QueuePtr1head(); nop++;
        for (int i = 0; i <= ind; i++) {
            queTmp1->enqueue(peek()); nop++;
            element = peek(); nop++;
            dequeue(); nop++;
        }
        while (!isEmpty()) {
            queTmp1->enqueue(peek()); nop++;
            dequeue(); nop++;
        }
        while (!queTmp1->isEmpty()) {
            enqueue(queTmp1->peek()); nop++;
            queTmp1->dequeue(); nop++;
        }
        return element;
    }
    void  setElement(int ind, int element) {
        int temp = element; nop++;
        QueuePtr1head* queTmp1 = new QueuePtr1head(); nop++;
        for (int i = 0; i < ind; i++) {
            queTmp1->enqueue(peek()); nop++;
            element = peek(); nop++;
            dequeue(); nop++;
        }
        queTmp1->enqueue(temp); nop++;
        dequeue(); nop++;
        while (!isEmpty()) {
            queTmp1->enqueue(peek()); nop++;
            dequeue(); nop++;
        }
        while (!queTmp1->isEmpty()) {
            enqueue(queTmp1->peek()); nop++;
            queTmp1->dequeue(); nop++;
        }
    }
};

void example_work_queue() {
    cout << "Example work with queue!\n";
    QueuePtr1head* que = new QueuePtr1head();
    que->enqueue(1);
    que->enqueue(2);
    que->enqueue(3);
    que->enqueue(4);
    que->enqueue(5);
    que->display();

    que->dequeue();
    que->display();

    que->dequeue();
    que->display();

    que->dequeue();
    que->display();
};

void example_work_queueadapter() {
    cout << "Example work with Adapter for queue!\n";
    Adapter4QueuePtr1head Adq;
    Adq.enqueue(10);
    Adq.enqueue(20);
    Adq.enqueue(30);
    Adq.enqueue(40);
    Adq.enqueue(50);
    Adq.display();

    Adq.dequeue();
    Adq.display();

    Adq.dequeue();
    Adq.display();

    Adq.setElement(1, 8);
    Adq.display();
    Adq.setElement(0, 111);
    Adq.display();
    Adq.setElement(2, 77);
    Adq.display();
    cout << endl << "QueuePtr1head 1 " << Adq.getElement(1);
    cout << endl << "QueuePtr1head 2 " << Adq.getElement(0);
    cout << endl << "QueuePtr1head 0 " << Adq.getElement(2);
};

void merge(Adapter4QueuePtr1head & arr, int left,
    int mid, int right)    //15n + 7
{
    int n1 = mid - left + 1;  nop += 3;  // 3
    int n2 = right - mid; nop += 2;  // 2

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++) {  // 2*N
        L[i] = arr.getElement(left + i); nop += 2; // 2
        //L[i] = arr[left + i]; nop += 2; // 2
    }
    for (int j = 0; j < n2; j++) { // 3*N
        R[j] = arr.getElement(mid + 1 + j); nop += 3; // 3
    }
    int i = 0, j = 0; nop += 2; // 2
    int k = left; nop++; // 1

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        nop++;                     //4 N
        if (L[i] <= R[j]) {
            arr.setElement(k,L[i]); nop++;
            //arr[k] = L[i]; nop++;
            i++; nop++;
        }
        else {
            arr.setElement(k, R[j]); nop++;
            //arr[k] = R[j]; nop++;
            j++; nop++;
        }
        k++; nop++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    nop++;
    while (i < n1) {   // 3*N
        arr.setElement(k, L[i]); nop++;
        //arr[k] = L[i]; nop++;
        i++; nop++;
        k++; nop++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    nop++;
    while (j < n2) { // 3*N
        arr.setElement(k, R[j]);
        //arr[k] = R[j]; nop++;
        j++; nop++;
        k++; nop++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(Adapter4QueuePtr1head & arr, int left, int right)
{   //log(N)(15n + 7)
    nop++;
    if (left >= right)
        return;

    int mid = left + (right - left) / 2; nop += 4;
    mergeSort(arr, left, mid); nop++;
    mergeSort(arr, mid + 1, right); nop += 2;
    merge(arr, left, mid, right); nop++;
}



void example_work_Sort() {
    Adapter4QueuePtr1head Adq;
    //for (int n = 10; n <= 10; n += 10)
    for (int n = 300; n <= 1300; n += 100)
    {
        for (int i = 0; i < n; i++){
            Adq.enqueue(rand()); 
        }
        const clock_t begin_time = clock();
        nop = 0;
        mergeSort(Adq, 0, n - 1);
        cout << endl << " n = " << n << " time (ms): ";
        cout << endl;
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
        cout << endl << " NOP: " << nop << endl;
        //Adq.display();
        for (int i = 0; i < n; i++)
            Adq.dequeue();
    }
}

int main() {
    //example_work_queue();
    //example_work_queueadapter();
    example_work_Sort();

    return 0;
}