#include<iostream>
using namespace std;

int main() {
    int n;
    int sum=0;
    cout <<"enter number for calculating sum:" << endl;
    cin>>n;
    for(int i=0;i<=n;i++) {
        sum+=i;
    }
    cout<<"Your sum is ="<<sum <<endl;
    return 0;

}