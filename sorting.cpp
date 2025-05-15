#include<iostream>

using namespace std;

void bubbleSort(int arr[] , int n){
    
    for (int i = 0; i < n-1; i++){
        bool isSwap = false;
        for(int j = 0; j< n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;  //if array is already sorted
        }
    }
    
}

void selectionSort(int A[] , int n){
    for(int i = 0; i < n-1; i++){
        int smallestIndex = i;
        for(int j = i+1; j <n; j++){
            if(A[j] < A[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(A[i] , A[smallestIndex]);
    }
}

void insertionSort(int Arr[] , int n){
    for(int i = 1;i<n; i++){
        int current = Arr[i];
        int previous = i-1;
        while(previous >= 0 && Arr[previous] > current){
            Arr[previous + 1] = Arr[previous];
            previous--;
        }
        Arr[previous + 1] = current;
    }
}

void printArray(int arr[] , int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr1[] ={4, 1, 5, 2, 3};
    int arr2[] ={6, 8, 3, 7, 2, 1};
    int arr3[] ={17, 91, 10};
    int n1 = 5 , n2 = 6 , n3 = 3;
    bubbleSort(arr1 , n1);
    printArray(arr1 , n1);
    selectionSort(arr2 , n2);
    printArray(arr2 , n2);
    insertionSort(arr3 , n3);
    printArray(arr3 , n3);

    return 0;
}