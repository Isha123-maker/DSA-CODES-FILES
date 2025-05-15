#include<iostream>
#include<vector>

using namespace std;

bool isPossible(vector<int>& arr , int m , int n , int minAllowedtime){
      int cows = 1 , lastAllPossible = arr[0];
      for(int i = 0; i < n; i++){
        if((arr[i] - lastAllPossible) >= minAllowedtime){
            cows++;
            lastAllPossible = arr[i];
        }
        if(cows == c){ return true; }
      }
      return false;
}

 int getDistance(vector<int>& arr , int m , int n){
    sort(arr.begin() , arr.end());
    
    int st = 1 , end = arr[n-1] - arr[0] , ans = -1;

    while(st <= end){
        int mid = st + (end - st) / 2;

        if(isPossible(arr , m, n, mid)){
            ans = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }  
    }
    return ans;


 }

 int main(){
    vector<int> arr = {1, 2, 8, 4, 9};
    int c = 3 , n = 5;
    cout << getDistance(arr , c , n ) << endl;
    return 0;
 }