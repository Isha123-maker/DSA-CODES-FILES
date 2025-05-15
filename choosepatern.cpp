#include <iostream>
using namespace std;

// Function to print a pyramid pattern
void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "; // Print spaces
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*"; // Print stars
        }
        cout << endl; // Move to the next line
    }
}

// Function to print an inverted pyramid pattern
void printInvertedPyramid(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "; // Print spaces
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*"; // Print stars
        }
        cout << endl; // Move to the next line
    }
}

// Function to print a hollow square pattern
void printHollowSquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "*"; // Print borders
            } else {
                cout << " "; // Print spaces inside
            }
        }
        cout << endl; // Move to the next line
    }
}

// Function to print a diamond pattern
void printDiamond(int n) {
    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "; // Print spaces
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*"; // Print stars
        }
        cout << endl; // Move to the next line
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "; // Print spaces
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*"; // Print stars
        }
        cout << endl; // Move to the next line
    }
}

// Function to print a right triangle pattern

void starRightTriangle(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to print inverted right triangle pattern

void invertedStarRightTriangle(int n) {
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to print a butterfly pattern

void butterflyPattern(int n) {
    // Upper half
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        for (int j = 1; j <= 2 * (n - i); ++j) {
            cout << " ";
        }
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower half
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        for (int j = 1; j <= 2 * (n - i); ++j) {
            cout << " ";
        }
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}




int main() {
    int choice, n;
    char another;

    do {
        cout << "Select a pattern to print:" << endl;
        cout << "1. Pyramid Pattern" << endl;
        cout << "2. Inverted Pyramid Pattern" << endl;
        cout << "3. Hollow Square Pattern" << endl;
        cout << "4. Diamond Pattern" << endl;
        cout << "5. Right triangle Pattern" << endl;
        cout << "6. Inverted right triangle Pattern" << endl;
        cout << "7. Butterfly Pattern" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        cout << "Enter the number of rows: ";
        cin >> n;

        switch (choice) {
            case 1:
                printPyramid(n);
                break;
            case 2:
                printInvertedPyramid(n);
                break;
            case 3:
                printHollowSquare(n);
                break;
            case 4:
                printDiamond(n);
                break;
            case 5:
                starRightTriangle(n);
                break;
            case 6:
                invertedStarRightTriangle(n);
                break;
            case 7:
                butterflyPattern(n);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "Do you want to print another pattern? (y/n): ";
        cin >> another;

    } while (another == 'y' || another == 'Y'); // Repeat if user inputs 'y' or 'Y'

    return 0;
}
