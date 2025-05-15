#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& arr, int st, int mid, int end){
    vector<int> temp;
    int i = st , j = mid+1;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){ //change sighn here for sorting in descending order
            temp.push_back(arr[i++]);
        } else{
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(arr[i++]);
    }

    while(j <= end){
        temp.push_back(arr[j++]);
    }

    for(int idx=0; idx<temp.size(); idx++){
       arr[idx+st] = temp[idx];
    }
}

void mergeSort(vector<int>& arr , int st , int end){
    if(st<end){
        int mid = st + (end - st)/2;
        mergeSort(arr,st,mid); //right half
        mergeSort(arr,mid+1,end);//left half

        merge(arr,st,mid,end);
    }
}

int main(){
    vector<int> arr = {12 , 1 , 35 , 18 , 32 , 7};
    int n =arr.size()-1;

    mergeSort(arr,0,n);

    for(int val : arr){
        cout<< val << " ";
    }
    cout<<endl;
    return 0;
}