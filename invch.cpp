#include<iostream>
using namespace std;

int main(){
    int n=5;
    for(int i=0; i<n;i++){
        for(int j=(i+1); j>0;j--){ //
            cout << char('A' + j - 1); //('A' +j-1)=>offset of A.
        }
        cout << endl;
    }
    return 0;
}