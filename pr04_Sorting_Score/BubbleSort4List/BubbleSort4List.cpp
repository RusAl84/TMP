#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

unsigned int nop = 0;

class Adapter4List {
private:
    list<int> *lis;
public:
    Adapter4List() {
        lis = new list<int>();
    }
    ~Adapter4List() {
        delete lis;
        // TODO
    }
    void push(int data) {
        lis->push_front(data);
    }
    void clear() {
        lis->clear();
    }
    int size() {
        return lis->size();
    }
    void display() {
        list<int> *tlis = new list<int>();
        int size = lis->size();
        for (int i = 0; i < size; i++) {
            cout << lis->front() << " ";
            tlis->push_front(lis->front());
            lis->pop_front();
        }
        for (int i = 0; i < size; i++) {
            lis->push_front(tlis->front());
            tlis->pop_front();
        }
        //TODO DELETE
    }
    int getElement(int ind) {
        ind++;
        list<int>* tlis = new list<int>();
        int element;
        for (int i = 0; i < ind; i++) {
            element = lis->front();
            tlis->push_front(element);
            lis->pop_front();
            nop += 3;
        }
        for (int i = 0; i < ind; i++) {
            lis->push_front(tlis->front());
            tlis->pop_front();
            nop += 3;
        }
        return element;
    }
    void setElement(int ind, int element) {   
        list<int>* tlis = new list<int>();
        for (int i = 0; i < ind; i++) {
            tlis->push_front(lis->front());
            lis->pop_front();
            nop += 3;
        }
        lis->pop_front();
        tlis->push_front(element);
        ind++;
        nop += 3;
        for (int i = 0; i < ind; i++) {
            lis->push_front(tlis->front());
            tlis->pop_front();
            nop += 3;
        }
    }
    void genData(int n) {
    srand(unsigned(time(nullptr)));
    for(int i=0;i<n;i++){
        lis->push_front(rand());
    }
    //generate(arr.begin(), arr.end(), );
    }
};


void bubbleSort(Adapter4List* a)
{
    int i, j;
    int n = a->size();
    for (i = 0; i < n - 1; i++) {
        nop++; // 1
        for (j = 0; j < n - i - 1; j++) {
            nop++; //1
            //if (arr[j] > arr[j + 1]) {
            if (a->getElement(j) > a->getElement(j+1)) {
                int tmp = a->getElement(j);
                a->setElement(j, a->getElement(j + 1));
                a->setElement(j+1, tmp);
                nop+=3; //3
            }
        }
    }
}

int main()
{

    cout <<  endl;
    vector<int> presets = { 50, 100, 150, 200, 250, 300};
    
    Adapter4List *a = new Adapter4List();
    //a->push(1);
    //a->push(2);
    //a->push(3);
    //a->push(4);
    //a->push(5);
    //a->display();
    //cout << "\n" << a->getElement(0);
    //a->setElement(3, 777);
    //a->setElement(4, 888);
    //a->setElement(0, 111);
    //cout << "\n";
    //a->display();

    for (int i = 0; i < presets.size(); i++)
    {
        int N = presets[i];
        cout << "N = " << N;
        a->clear();
        a->genData(N);
        nop = 0;
        bubbleSort(a);
        cout << " nop = " << nop << endl;
    }

    return 0;
}

