#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

unsigned int nop;

void printArray(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
}

vector<int> genData(int n) {

    srand(unsigned(time(nullptr)));
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand() * 100*100;
    //generate(arr.begin(), arr.end(), rand);
    return arr;
}

vector<int> countSort(vector<int>& inputArray)
{
    int N = inputArray.size(); nop++;  //1

    // Finding the maximum element of array inputArray[].
    int M = 0; nop++;  //1

    for (int i = 0; i < N; i++) {
        M = max(M, inputArray[i]); nop += 3;  //3
    }
    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0); nop += 3;  //3

    // Mapping each element of inputArray[] as an index
    // of countArray[] array

    for (int i = 0; i < N; i++) {
        countArray[inputArray[i]]++; nop += 3;  //3
    }
    // Calculating prefix sum at every index
    // of array countArray[]

    for (int i = 1; i <= M; i++) {
        countArray[i] += countArray[i - 1]; nop += 3;  //3
    }
    // Creating outputArray[] from countArray[] array
    nop++;  //1
    vector<int> outputArray(N);
    nop++;  //1
    for (int i = N - 1; i >= 0; i--)

    {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];
        nop += 3;  //3

        countArray[inputArray[i]]--;
        nop += 3;  //3
    }

    return outputArray;
}


int main()
{
    vector<int> arr;

    //printArray(arr); //Проверка генерации чисел
    cout << endl;
    vector<int> presets = { 500, 1000, 3000, 5000, 8000, 10000, 20000, 30000 };

    for (int i = 0; i < presets.size(); i++)
    {
        int N = presets[i];
        cout << "N = " << N;
        arr = genData(N);
        nop = 0;
        const clock_t begin_time = clock();
        countSort(arr);
        cout << " nop = " << nop << " time = ";
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;
    }

    return 0;
}

