#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

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

unsigned int insertionSort(vector<int> arr)
{
    unsigned int nop = 0;
    int i, key, j;
    int n = arr.size();
    for (i = 1; i < n; i++) {
        key = arr[i]; nop++; //1
        j = i - 1; nop++; //1
        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; nop++; //1
            j = j - 1; nop++; //1
        }
        arr[j + 1] = key; nop++; //1
    }
    return nop;
}

int main()
{
    vector<int> arr;

    //printArray(arr); //Проверка генерации чисел
    cout << endl;
    vector<int> presets = { 500, 1000, 3000, 5000, 8000, 10000, 20000, 30000, 40000, 50000 };

    for (int i = 0; i < presets.size(); i++)
    {
        int N = presets[i];
        cout << "N = " << N;
        arr = genData(N);
        const clock_t begin_time = clock();
        unsigned int nop = insertionSort(arr);
        cout << " nop = " << nop << " time = ";
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;
    }

    return 0;
}
