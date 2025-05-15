#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(prices.size(), 0);
    stack<int> st;

    // Compute stock span for each day
    for (size_t i = 0; i < prices.size(); i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // If stack is empty, it means all previous prices were smaller
        if (st.empty()) {
            ans[i] = i + 1;
        } else {
            ans[i] = i - st.top();
        }

        // Push current index onto the stack
        st.push(i);
    }

    // Print the stock span values
    cout << "Stock span values: ";
    for (int span : ans) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}
