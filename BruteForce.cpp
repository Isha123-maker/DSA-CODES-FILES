#include<iostream> 
#include<vector>
using namespace std;


int main(){
   int size = 5;
   int arr[] = {1 , -2 , 3, -4, 5};

   int maxSum = INT_MIN;

   for(int st = 0; st<size; st++){

      int currSum = 0;

       for(int end = st; end<size; end++){
           currSum += arr[end];
           maxSum = max(currSum , maxSum);
       }
   }
    cout << "Sum of max subarray is:" << maxSum;
    
   
    
    return 0;

}