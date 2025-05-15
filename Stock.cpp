#include <iostream>
#include <vector>
#include <algorithm> // For the max and min functions

using namespace std;

int buyAndSell(vector<int>& nums) {
    int maxProfit = 0, bestBuy = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // Update the bestBuy to the minimum price seen so far
        bestBuy = min(nums[i], bestBuy);
        // Calculate the potential profit and update maxProfit
        maxProfit = max(maxProfit, nums[i] - bestBuy);
    }
    return maxProfit;
}

int main() {
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit is: " << buyAndSell(nums) << endl;

    return 0;
}
