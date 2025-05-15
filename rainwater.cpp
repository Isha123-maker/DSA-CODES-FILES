#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the amount of rainwater that can be trapped with TC O(n) and SC O(n).
int trapRainWater(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    vector<int> left(n, 0), right(n, 0);

    left[0] = height[0];
    right[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - height[i];
    }

    return ans;
}

// Function to calculate the amount of rainwater that can be trapped with TC O(n) and SC O(1).

int trapRainWaterOptimized(vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;

    int left = 0, right = n - 1, ans = 0, maxLeft = 0, maxRight = 0;

    while (left < right)
    {
        maxLeft = max(maxLeft, height[left]);
        maxRight = max(maxRight, height[right]);

        if (maxLeft < maxRight)
        {
            ans += maxLeft - height[left];
            left++;
        }
        else
        {
            ans += maxRight - height[right];
            right--;
        }
    }

    return ans;
}

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  //6
    cout << trapRainWater(height) << endl;
    cout << trapRainWaterOptimized(height) << endl;
    
    return 0;
}