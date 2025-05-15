/*
    This program implements a solution to count inversions in an array using a modified merge sort algorithm.
    An inversion in an array occurs when two elements are out of their natural order, i.e., arr[i] > arr[j] 
    where i < j.

    Approach:
    - The program uses a divide-and-conquer strategy (merge sort) to count inversions efficiently.
    - During the merge step, we count the inversions by identifying how many elements from the left subarray 
      are greater than elements from the right subarray.

    Time Complexity: O(n log n)
    Space Complexity: O(n) (for the temporary array used during merging)

    How to find inversion count:
    - For every element in the left subarray that is greater than an element in the right subarray, 
      the number of inversions is incremented by the number of remaining elements in the left subarray.
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted subarrays and count inversions
int merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp; // Temporary array to store the sorted elements
    int i = st, j = mid + 1; // Pointers for left and right subarrays
    int invCount = 0; // Variable to store the count of inversions

    // Merge process
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            // If the current element in the left subarray is smaller or equal, no inversion
            temp.push_back(arr[i]);
            i++;
        } else {
            // If the current element in the right subarray is smaller, all remaining elements
            // in the left subarray form an inversion
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1); // Count all inversions with the remaining elements in the left subarray
        }
    }

    // Copy remaining elements of the left subarray
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements of the right subarray
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy the sorted elements back to the original array
    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }

    return invCount;
}

// Function to perform merge sort and count inversions
int mergeSort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2; // Find the middle index
        // Recursively sort the left half and count inversions
        int leftInvCount = mergeSort(arr, st, mid);
        // Recursively sort the right half and count inversions
        int rightInvCount = mergeSort(arr, mid + 1, end);
        // Merge the two halves and count inversions during merging
        int invCount = merge(arr, st, mid, end);
        return leftInvCount + rightInvCount + invCount;
    }
    return 0; // Base case: No inversions in a single-element array
}

int main() {
    // Example array to test the program
    vector<int> arr = {1, 3, 5, 10, 2, 6, 8, 9};

    // Call mergeSort to count inversions
    int ans = mergeSort(arr, 0, arr.size() - 1);

    // Output the inversion count
    cout << "Inversion count: " << ans << endl;

    return 0;
}
