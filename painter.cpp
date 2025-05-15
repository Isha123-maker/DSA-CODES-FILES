#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int>& arr , int m , int n , int maxAllowedTime){
    int painter = 1 , time = 0;

    for(int i =0; i < n; i++){
        if(time + arr[i] <= maxAllowedTime){
          time += arr[i];
        }else{
            painter++;
            time = arr[i];
        }
    }
    return painter <= m;
}

int painterPartition(vector<int>& arr , int m , int n){
    int sum = 0 , maxValue = INT_MIN;
    for(int i =0; i<n; i++){
        sum += arr[i];
        maxValue=max(maxValue , arr[i]);

    }
    int st = maxValue , end = sum , ans = -1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(isPossible(arr , m , n , mid)){
            ans = mid;
            end =  mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {40, 30, 10, 20};
    int n= 4 , m= 2;
    cout << painterPartition(arr , m , n);
    return 0;
}