#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

unsigned int nop = 0;

void printArray(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
}

vector<int> genData(int n) {

    srand(unsigned(time(nullptr)));
    vector<int> arr(n);
    generate(arr.begin(), arr.end(), rand);
    return arr;
}

vector<int> selectionSort(vector<int> arr)
{
    int i, j, min_idx;
    int n = arr.size();

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {
        nop++;//1
        // Find the minimum element in
        // unsorted array
        min_idx = i;  nop++;//1
        for (j = i + 1; j < n; j++) {
            nop++;//1
            if (arr[j] < arr[min_idx])
                nop++;//1
                min_idx = j;
                nop++;//1
        }

        // Swap the found minimum element
        // with the first element
        nop++;//1
        if (min_idx != i){
            swap(arr[min_idx], arr[i]);
            nop+=3;//3
        }
    }
    return arr;
}

int main()
{
    vector<int> arr;

    //printArray(arr); //Проверка генерации чисел
    cout << endl;
    vector<int> presets = { 500, 1000, 3000, 5000, 8000, 10000, 20000, 30000 };

    //arr = genData(10);
    //printArray(arr);
    //arr = selectionSort(arr);
    //cout << endl;
    //printArray(arr);
    
    for (int i = 0; i < presets.size(); i++)
    {
        int N = presets[i];
        cout << "N = " << N;
        arr = genData(N);
        nop = 0;
        selectionSort(arr);
        cout << " nop = " << nop << endl;
    }

    return 0;
}
