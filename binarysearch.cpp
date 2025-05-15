#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& nums , int target){
    int n = nums.size();
    int start = 0 , end = n-1;

    while(start <= end){
        int midPoint = start + (end-start)/2;

        if(target > nums[midPoint]){
            start = midPoint + 1;
        }else if(target < nums[midPoint]){
            end = midPoint - 1;
        }else{
            return midPoint;
        }
    }
    return -1;

}

int main(){
    vector<int> nums = {-1, 0, 3, 5, 7, 10};
    int target =3;

    cout << binarySearch(nums , target) << endl;
    return 0;
}