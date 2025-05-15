#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int freq = 0 , ans =0;

    for(int i=0; i<nums.size(); i++){
        if(freq == 0){
            ans = nums[i];
        }

        if(ans == nums[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
}

int main(){

    vector<int> nums = {2, 2, 2, 2, 4, 6, 4, 7};
    cout << "Majority Element is " << majorityElement(nums) << endl;
    
    return 0;
}