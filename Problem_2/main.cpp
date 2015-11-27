#include <iostream>

#define UPPER_BOUND 4000000

using namespace std;

int main() {
    int i = 1;
    int j = 2;
    int sum = 0;

    while (i <= UPPER_BOUND) {
        if (i % 2 == 0)
        {
            sum += i;
        }

        int temp = j;
        j = i + j;
        i = temp;
    }

    cout << sum << endl;
    return 0;
}