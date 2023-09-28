#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

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
        }
        for (int i = 0; i < ind; i++) {
            lis->push_front(tlis->front());
            tlis->pop_front();
        }
        return element;
    }
    void setElement(int ind, int element) {   
        list<int>* tlis = new list<int>();
        for (int i = 0; i < ind; i++) {
            tlis->push_front(lis->front());
            lis->pop_front();
        }
        lis->pop_front();
        tlis->push_front(element);
        ind++;
        for (int i = 0; i < ind; i++) {
            lis->push_front(tlis->front());
            tlis->pop_front();
        }
    }
};



//list<int> genData(int n) {
//
//    srand(unsigned(time(nullptr)));
//    list<int> arr(n);
//    generate(arr.begin(), arr.end(), rand);
//    return arr;
//}
//
//unsigned int bubbleSort(list<int> arr, int n)
//{
//    unsigned int nop = 0;
//    int i, j;
//    bool swapped;
//    for (i = 0; i < n - 1; i++) {
//        swapped = false; nop++; // 1
//        for (j = 0; j < n - i - 1; j++) {
//            nop++; //1
//            if (arr[j] > arr[j + 1]) {
//                swap(arr[j], arr[j + 1]);  nop++; nop++;//2
//                swapped = true; nop++;//1
//            }
//        }
//        // If no two elements were swapped
//        // by inner loop, then break
//        if (swapped == false)  nop++; //1
//            break;
//    }
//    return nop;
//}

int main()
{
    list<int> arr;
    
    //printArray(arr); //Проверка генерации чисел
    cout <<  endl;
    vector<int> presets = { 500, 1000, 3000, 5000, 8000, 10000, 20000, 30000 };
    

    Adapter4List *a = new Adapter4List();
    a->push(1);
    a->push(2);
    a->push(3);
    a->push(4);
    a->push(5);
    a->display();
    cout << "\n" << a->getElement(0);
    a->setElement(3, 777);
    a->setElement(4, 888);
    a->setElement(0, 111);
    cout << "\n";
    a->display();

    //for (int i = 0; i < presets.size(); i++)
    //{
    //    int N = presets[i];
    //    cout << "N = " << N;
    //    arr = genData(N);
    //    unsigned int nop = bubbleSort(arr, N);
    //    cout << " nop = " << nop << endl;
    //}

    return 0;
}

