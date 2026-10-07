#include <iostream>

using namespace std;

int main()
{
    long long nop = 0;  // number of operations
    for (int n = 1; n <= 64; n++) {
        const clock_t begin_time = clock();
        nop++;
        int s = 0; nop++;
        nop += 4;
        for (int i = n; i < 2 * n * n; i++)
        {
            nop += 5;
            nop += 5;
            for (int j = 2 * n; j < n * n + 1; j++)
            {
                nop += 5;
                int k = 13; nop++;
                nop += 2;
                while (k + 3 < 42) {
                    nop += 2;
                    k += 7; nop += 2;
                    s++; nop += 2;
                }
            }
        }
        nop++;
        cout << float(clock() - begin_time) / CLOCKS_PER_SEC << endl;
        //cout << nop << endl;
    }
}

