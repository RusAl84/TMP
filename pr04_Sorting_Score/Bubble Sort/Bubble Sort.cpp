#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// An optimized version of Bubble Sort
vector<int> bubbleSort(vector<int> arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
    return arr;
}

// Function to print an array
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


int main()
{
    
    vector<int> arr;
    arr = genData(300);
    printArray(arr); //Проверка генерации чисел

    int N = 300;

    arr=bubbleSort(arr, N);
    cout << endl << endl;
    printArray(arr); //Проверка генерации чисел

    
    return 0;
}

