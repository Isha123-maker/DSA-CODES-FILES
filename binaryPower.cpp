#include<iostream>
#include<vector>

using namespace std;

double myPower(double x , int n){
    long binaryForm = n;
    if(n<0){
        x = 1/x;
        binaryForm = -binaryForm;
    }

    double ans = 1;

    while(binaryForm > 0){
         if(binaryForm % 2 == 1){
            ans *= x;
         }

         x *= x;
         binaryForm /= 2;
         
    }
    return ans;
}

int main(){

    double x;
    int n;
    cout <<" \n WRITE BASE";
    cin >> x;
    cout << " \n WRITE POWER";
    cin >> n;
    cout << x <<" raise to the power " << n << " is: "  <<myPower(x , n) << endl;
    return 0;
}