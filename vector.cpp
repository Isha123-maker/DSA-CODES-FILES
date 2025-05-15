#include<iostream>
#include<vector>

using namespace std;

vector<int> pairSum(vector<int>& nums , int target){
    vector<int> ans;
    int n = nums.size();

    int i = 0 , j = n-1;
    while(i < j){
        int pairSum = nums[i] + nums[j];
        if(pairSum > target){
            j--;
        }else if (pairSum < target){
            i++;
        }else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1};
    int target = 5;

    cout << "pair sum of target is  " << pairSum(nums , target) << endl;

    return 0;
}