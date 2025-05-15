#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int getMaxSum(int mat[][3] , int row , int cols){
    int maxRowSum = 0;

    for(int i = 0; i<row; i++){
        int rowSumI = 0;
        for(int j = 0; j < cols; j++){
            rowSumI += mat[i][j];
                
       }
       maxRowSum = max(maxRowSum, rowSumI);
    }
    return maxRowSum;
}

bool linearsearch(int mat[][3] , int row , int cols , int key){
     for(int i = 0; i < row; i++){
         for(int j = 0; j < cols; j++){
             if(mat[i][j] == key){
                 return true;
             }
         }
     }
     return false;
}

pair<int, int> linearSearch(int mat[][3], int row, int cols, int key) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == key) {
                // Return the row and column indices as a pair
                return make_pair(i, j);
            }
        }
    }
    // If not found, return (-1, -1)
    return make_pair(-1, -1);
}

int diagnalSum(int mat[][3], int n){
    int sum = 0;
    for(int i=0; i < n; i++){
        sum += mat[i][i];
    

    if(i != n-i-1 ){
        sum += mat[i][n-i-1];
    }
    }
    return sum;
}

int main(){
    int mat[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    int rows = 3;
    int cols = 3;
    int n = 3;
    cout << getMaxSum(mat, rows, cols) << endl;
    int key = 5;
    cout << linearsearch(mat, rows, cols , key) << endl;
    pair<int, int> result = linearSearch(mat, rows, cols, key);

    if (result.first != -1) {
        cout << "Element " << key << " found at index: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "Element " << key << " not found in the matrix." << endl;
    }
}