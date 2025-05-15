#include <iostream>
using namespace std;

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already sorted, so the inner loop goes until n - i - 1
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the element is greater than the next element
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 6, 2};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    bubbleSort(arr, n);  // Call the sorting function

    // Print the sorted array
    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
