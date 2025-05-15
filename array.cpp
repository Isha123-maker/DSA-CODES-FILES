#include <iostream>
using namespace std;

void commonValue(int arr1[] , int arr2[] , int size) {
    for(int i=0; i<size; i++) {
        for(int j=0;j<size;j++) {
            if(arr1[i]==arr2[j]){
                cout<< arr1[i] << " ";
            }
        }
    }
}

int main() {
    int arr1[] = {2, 3, 4, 6, 7, 9};
    int arr2[] = {6, 5, 2, 4, 8, 9};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    commonValue(arr1 , arr2 , size);

    return 0;
}
