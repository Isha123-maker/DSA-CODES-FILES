#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubArraySum(const vector<int>& nums) {
    int currSum = 0 , maxSum = INT_MIN;

    for(int val : nums){
        currSum += val;
        maxSum = max( currSum , maxSum);

        if(currSum < 0){
        currSum = 0;
        }
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = maxSubArraySum(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
