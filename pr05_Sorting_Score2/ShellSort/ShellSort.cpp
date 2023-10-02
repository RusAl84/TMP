#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stack>
#include <queue>

using namespace std;
// Function to swap two elements

unsigned int nop = 0;

vector<int> bubbleSort(vector<int> arr)
{
    int i, j;
    int n = arr.size() - 1;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        //swapped = false; 
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
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

vector<int> genData(int n) {

    srand(unsigned(time(nullptr)));
    vector<int> arr(n);
    //for (int i = 0; i < n; i++)
    //    arr[i] = abs(rand()) * 1000;
    generate(arr.begin(), arr.end(), rand);
    //Сортировка
    //sort(arr.begin(), arr.end());
    return arr;
}
void printArray(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
}


/* function to sort arr using shellSort */
vector<int> shellSort(vector<int> arr)
{
    int n = arr.size();
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        nop++;  //1
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            nop++;  //1
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i]; nop++;  //1


            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j; 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                nop++;  //1
                nop++;  //1
                arr[j] = arr[j - gap];
            }
                

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp; nop++;  //1
        }
    }
    return arr;
}


int main()
{
    vector<int> arr;

    //printArray(arr); //Проверка генерации чисел
    cout << endl;
    vector<int> presets = { 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 100000 };
    //arr = genData(30);
    ////arr = bubbleSort(arr);
    //arr = shellSort(arr);
    //printArray(arr);

    for (int i = 0; i < presets.size(); i++)
    {
        int N = presets[i];
        cout << "N = " << N;
        arr = genData(N);
        nop = 0;
        //arr = bubbleSort(arr);
        const clock_t begin_time = clock();
        shellSort(arr);
        cout << " nop = " << nop << " time = ";
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;
    }
    return 0;
}

