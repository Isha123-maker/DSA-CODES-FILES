#include<iostream>
using namespace std;

int main(){
    int n=5;
    char ch='A';  //for maintaining ch value
    for(int i=0; i<n; i++){
        for(int j=0; j<(i+1); j++){  //(i+1)=>execution one more time than i
            cout<< ch << " ";
            ch = ch+1;   //for incrementing ch
        }
        cout<< endl;
    }
}