#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;
// Function to swap two elements

unsigned int nop = 0;

// Partition the array using the last element as the pivot
int partition(vector<int> arr, int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
    nop++; //1
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
    nop++; //1
    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than the pivot
        nop++; //1
        if (arr[j] < pivot) {

            // Increment index of smaller element
            nop++; //1
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            nop+=3; //3
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    nop += 3; //3
    return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void  quickSort(vector<int> arr, int low, int high)
{
    nop++; //1
    if (low < high) {

        // pi is partitioning index, arr[p]
        // is now at right place
        nop++; //1
        int pi = partition(arr, low, high);

        // Separately sort lements before
        // partition and after partition
        nop++; //1
        quickSort(arr, low, pi - 1);
        nop++; //1
        quickSort(arr, pi + 1, high);
    }
}
void printArray(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
}

vector<int> genData(int n) {

    srand(unsigned(time(nullptr)));
    vector<int> arr(n);
    //for (int i = 0; i < n; i++)
    //    arr[i] = abs(rand()) * 1000;
    generate(arr.begin(), arr.end(), rand);
    sort(arr.begin(), arr.end());
    return arr;
}

vector<int> bubbleSort(vector<int> arr)
{
    int i, j;
    int n = arr.size()-1;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        //swapped = false; 
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] >  arr[j + 1]) {
                swap(arr[j], arr[j + 1]);  
                //swapped = true; 
            }
        }
        // If no two elements were swapped
        // by inner loop, then break
        //if (swapped == false)  nop++; //1
        //break;
    }
    return arr;
}


int main()
{
    vector<int> arr;

    //printArray(arr); //Проверка генерации чисел
    cout << endl;
    vector<int> presets = { 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 3000 };

    //arr = genData(3000);
    //arr = bubbleSort(arr);
    //printArray(arr);

    for (int i = 0; i < presets.size(); i++)
    {
        int N = presets[i];
        cout << "N = " << N;
        arr = genData(N);
        nop = 0;
        //arr = bubbleSort(arr);
        const clock_t begin_time = clock();
        quickSort(arr, 0, N-1);
        cout << " nop = " << nop << " time = ";
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;
    }
    return 0;
}

