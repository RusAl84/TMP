#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Adapter4List {
private:
    list<int> *lis;
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
            cout<<
        }
    }
    int getElement(int ind) {
        return 0;
    }

};



list<int> genData(int n) {

    srand(unsigned(time(nullptr)));
    list<int> arr(n);
    generate(arr.begin(), arr.end(), rand);
    return arr;
}

unsigned int bubbleSort(list<int> arr, int n)
{
    unsigned int nop = 0;
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false; nop++; // 1
        for (j = 0; j < n - i - 1; j++) {
            nop++; //1
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);  nop++; nop++;//2
                swapped = true; nop++;//1
            }
        }
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)  nop++; //1
            break;
    }
    return nop;
}

int main()
{
    list<int> arr;
    
    //printArray(arr); //Проверка генерации чисел
    cout <<  endl;
    vector<int> presets = { 500, 1000, 3000, 5000, 8000, 10000, 20000, 30000 };
    
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

