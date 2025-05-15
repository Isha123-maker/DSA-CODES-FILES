#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& arr){
    int n = arr.size();
    int mid = 0 , low = 0 , high = n-1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low++] , arr[mid++]);
        } else if(arr[mid] == 1){
            mid++;
        } else{
            swap(arr[high] , arr[mid]);
            high--;
        }
    }
}

int main(){
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    int n = arr.size();
    sortColors(arr);

    for(int i = 0; i < n; i++){
       cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}