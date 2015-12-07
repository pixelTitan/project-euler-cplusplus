#include <iostream>

#define RANGE 20

using namespace std;

bool is_factor_redundant(long factor, long range){
    // Determine if the factor is actually redundant within the range. What this means is, for example, if the factor
    // being tested is 2, and the range is 4, 4 is evenly divisible by 2, and is also within the range, so the factor
    // of 2 is redundant.
    for (int i = factor + 1; i <= range; i++) {
        if (i % factor == 0) {
            return true;
        }
    }

    return false;
}

bool can_remove_one_instance_of_factor(long factor, long range, long long product) {
    // If we can successfully remove an instance of a factor while having the resulting product still be
    // divisible by every number in the range, return true, otherwise false.
    long long modifiedProduct = product / factor;
    if (product % factor == 0 && modifiedProduct % factor == 0){
        for (long i = range; i > 0; i--){
            if (modifiedProduct % i != 0){
                return false;
            }
        }

        return true;
    }

    return false;
}

int main() {
    long long product = 1;

    for (long i = 1; i <= RANGE; i++) {
        if (is_factor_redundant(i, RANGE) || product % i == 0){
            continue;
        }

        cout << i << endl;

        product *= i;
    }

    for (long i = RANGE; i > 1; i--){
        while (can_remove_one_instance_of_factor(i, RANGE, product)){
            product /= i;
        }
    }

    cout << product << endl;

    return 0;
}