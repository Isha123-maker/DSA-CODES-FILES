#include<iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;

        // Calculate right boundaries
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Clear the stack
        while (!s.empty()) {
            s.pop();
        }

        // Calculate left boundaries
        for (int i = 0; i < n; i++) {  // Fixed loop condition
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Compute the maximum area
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int curArea = heights[i] * width;
            ans = max(ans, curArea);
        }

        return ans;
    }
};


int main(){
    Solution s;
    vector<int> heights = {2,1,5,6,2,3};
    int ans = s.largestRectangleArea(heights);

    cout << "The largest rectangle area is: " << ans << endl;


    return 0;
}