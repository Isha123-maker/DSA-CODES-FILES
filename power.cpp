#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is a power of 2 and print the power if true
void checkPowerOfTwo(int num) {
    if ((num > 0) && ((num & (num - 1)) == 0)) {
        // Calculate the power using logarithm base 2
        int power = log2(num);
        cout << num << " is a power of 2 (2^" << power << ")." << endl;
    } else {
        cout << num << " is not a power of 2." << endl;
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    checkPowerOfTwo(number);

    return 0;
}
