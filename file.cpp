#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Please enter number\n";
    cin>>n;
    for(int i=0;i<n;i++){
       char ch ='A'; //for reseting character every time
       for(int j=0;j<n;j++){
        cout<< ch << " ";
        ch=ch+1;  // for incrementing ch
       }
       cout<< endl;
    }
    return 0;
}