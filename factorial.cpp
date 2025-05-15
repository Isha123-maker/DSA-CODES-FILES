#include<iostream>
using namespace std;

int main(){
    int n , f=1;
    cout<<"Enter Number\n";
    cin>>n;
    for(int i=1;i<=n;i++){   // loop for finding factorial of given num
        f*=i;
    }
    cout<<"Your factorial is:"<< f;
    return 0;
}