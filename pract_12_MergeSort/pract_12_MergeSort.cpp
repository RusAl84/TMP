#include <vector>
#include "iostream"
#include <algorithm>
#include <ctime>

using namespace std;

unsigned int nop = 0;

void printArray(vector<int> arr)
{
    cout << endl;
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


// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left,
    int mid, int right)    //15n + 7
{  
    int n1 = mid - left + 1;  nop+=3;  // 3
    int n2 = right - mid; nop += 2;  // 2

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++){  // 2*N
        L[i] = arr[left + i]; nop += 2; // 2
    }
    for (int j = 0; j < n2; j++){ // 3*N
        R[j] = arr[mid + 1 + j]; nop += 3; // 3
    }
    int i = 0, j = 0; nop += 2; // 2
    int k = left; nop++; // 1

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        nop ++;                     //4 N
        if (L[i] <= R[j]) {
            arr[k] = L[i]; nop++;
            i++; nop++;
        }
        else {
            arr[k] = R[j]; nop++;
            j++; nop++;
        }
        k++; nop++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    nop++;
    while (i < n1) {   // 3*N
        arr[k] = L[i]; nop++;
        i++; nop++;
        k++; nop++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    nop++;
    while (j < n2) { // 3*N
        arr[k] = R[j]; nop++;
        j++; nop++;
        k++; nop++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>  & arr, int left, int right)
{   //log(N)(15n + 7)
    nop++;
    if (left >= right)
        return;

    int mid = left + (right - left) / 2; nop+=4;
    mergeSort(arr, left, mid); nop++;
    mergeSort(arr, mid + 1, right); nop+=2;
    merge(arr, left, mid, right); nop++;
}

// Function to print a vector
void printVector(vector<int>  arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    //vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    //int n = arr.size();

    //cout << "Given vector is \n";
    //printVector(arr);

    //mergeSort(arr, 0, n - 1);

    //cout << "\nSorted vector is \n";
    //printVector(arr);

    vector<int> arr;

    //printArray(arr); //Проверка генерации чисел
    cout << endl;
    //vector<int> presets = { 500, 600, 700, 800, 900, 1000, 1100, 1200 };
    vector<int> presets = { 5000, 6000, 7000, 8000, 9000, 10000, 11000, 30000 };
    //vector<int> presets = { 10 };

    for (int i = 0; i < presets.size(); i++)
    {
        int N = presets[i];
        cout << "N = " << N;
        arr = genData(N);
        //mergeSort(arr, 0, n - 1);
        nop = 0;
        //printArray(arr); 
        mergeSort(arr, 0, N - 1);
        //printArray(arr);
        //unsigned int nop = bubbleSort(arr, N);
        cout << " nop = " << nop << endl;
    }

    return 0;
}