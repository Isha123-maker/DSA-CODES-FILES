#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& arr, int st, int end){
    int idx = st-1 , pivot = arr[end];

    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){ //change sign here for sorting in descending order 
            idx++;
            swap(arr[idx],arr[j]);
        }
    }

    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}

void quickSort(vector<int>& arr,int st,int end){
    if(st < end){
        int pivotIdx = partition(arr,st,end);
        quickSort(arr,st,pivotIdx-1);
        quickSort(arr,pivotIdx+1,end);
    }
}

int main(){
    vector<int> arr = {10,2,3,14,5,36,7,18};
    int n =arr.size()-1;
    quickSort(arr,0,n);

    for(int val : arr){
        cout<< val << " ";
    }
    cout<<endl;
    return 0;
}