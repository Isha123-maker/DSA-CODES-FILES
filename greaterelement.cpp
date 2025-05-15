#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Function to find the next greater element for each element in the array
vector<int> nextGreaterElement(vector<int> &arr) {
    stack<int> s;
    vector<int> ans(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    return ans;
}

// Function to find the previous smaller element for each element in the array
vector<int> prevSmallerElement(vector<int> &arr) {
    stack<int> s;
    vector<int> ans(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }

    return ans;
}


// Function to find the next greater element for each element in the circular array
vector<int> nextGreaterElement2(vector<int> &arr) {
    int n = arr.size();
    stack<int> s;
    vector<int> ans(n);

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i%n]) {
            s.pop();
        }

        ans[i%n] = s.empty() ? -1 : s.top();
        s.push(arr[i%n]);
    }

    return ans;
}

int main() {
    vector<int> arr = {1 , 2, 3, 4, 3};

    // Get the next greater elements
    vector<int> nextGreater = nextGreaterElement(arr);

    // Get the previous smaller elements
    vector<int> prevSmaller = prevSmallerElement(arr);

    // Get the next greater elements2
    vector<int> nextGreater2 = nextGreaterElement2(arr);

    // Print results
    cout << "Next Greater Elements: ";
    for (int val : nextGreater) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Previous Smaller Elements: ";
    for (int val : prevSmaller) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Next Greater Elements2: ";
    for (int val : nextGreater2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
