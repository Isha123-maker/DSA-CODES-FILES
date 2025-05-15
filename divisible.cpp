
#include <iostream>
using namespace std;

// Function to check if a number is a power of 2
bool isPowerOfTwo(int num) {
    // A number is a power of 2 if it is greater than 0 and has only one '1' bit in its binary representation.
    return (num > 0) && ((num & (num - 1)) == 0);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPowerOfTwo(number)) {
        cout << number << " is a power of 2." << endl;
    } else {
        cout << number << " is not a power of 2." << endl;
    }

    return 0;
}
