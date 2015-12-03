#include <iostream>
#include <list>

#define DIGITS 3

using namespace std;

bool is_palindromic_number(long number){
    // Reverse the number by extracting the digits one by one.
    long reversedNumber = 0;
    long tempNumber = number;
    bool firstPass = true;
    while (tempNumber > 0){
        long rightMostDigit = tempNumber % 10;

        // If the rightmost digit is 0, there is no way for the number to be palindromic, since numbers cannot begin
        // with 0.
        if (rightMostDigit == 0 && firstPass){
            break;
        }else if (firstPass){
            firstPass = false;
        }

        reversedNumber = reversedNumber * 10 + rightMostDigit;

        // Remove the rightmost digit through truncation.
        tempNumber /= 10;
    }

    // If the reversed number is the same as the original number, then it is palindromic.
    return number == reversedNumber;
}

long get_max_number_given_digits(int digits){
    if (digits == 0){
        return 0;
    }

    long number = 0;
    for (int i = 0; i < digits; i++){
        number = number * 10 + 9;
    }

    return number;
}

bool compare_descending(const long& a, const long& b){
    return a > b;
}

int main() {
    // First, build up a sorted list of all of the products. This solution will take more up front memory, but will allow
    // us to sort the list and find the max palindrome.
    long max_factor = get_max_number_given_digits(DIGITS);
    long min_factor = max_factor / 10;

    list<long> products;
    list<long>::iterator products_iterator;

    for (int i = max_factor; i > min_factor; i--){
        for (int j = max_factor; j > min_factor; j--){
            products.push_front(i * j);
        }
    }

    products.sort(compare_descending);

    for (products_iterator = products.begin(); products_iterator != products.end(); products_iterator++){
        long val = *products_iterator;
        if (is_palindromic_number(val)){
            cout << val << endl;
            break;
        }
    }

    return 0;
}