#include <iostream>

using namespace std;

int main() {
    long long factor = 600851475143;
    long long divisor = 2;
    long long max_prime_divisor = -1;

    while (true) {
        // Once we reach the point where the divisor is the same as the current factor, the current factor
        // will not be able to be factored anymore, and may implicitly be determined as a prime, and in fact
        // the largest prime.
        if (divisor >= factor){
            max_prime_divisor = factor;

            break;
        }

        // If the current factor is divisible by the divisor, we do the division and come up with the next factor.
        if (factor % divisor == 0) {
            factor = factor / divisor;
        }

        // Increment to the next possible divisor.
        divisor++;
    }

    cout << max_prime_divisor << endl;

    return 0;
}