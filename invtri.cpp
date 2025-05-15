#include<iostream>
using namespace std;

int main(){
    int n=5;
    char ch = 'A'; //for maintaining value
    for(int i=0; i<n; i++){  //outer loop for spaces
        for(int j=0;j<i;j++){
            cout<< " ";
        }
        for(int j=0;j<(n-i);j++){
                cout<< ch;
            }
            ch=ch+1;   //for incrementing value
            cout<< endl;
    }
    return 0;
}