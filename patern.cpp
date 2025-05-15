#include <iostream>
using namespace std;

int main() {
    int n=4;
    // Upper half of butterfly
    for(int i=1;i<=n; i++){
        // Print left stars
        for(int j=1;j<= i;j++){
            cout<< "*";
        }
        // Print spaces in middle
        for(int j=1; j<=(2*(n-i)); j++ ){
            cout<< " ";
        }
        // Print right stars
        for(int j=1; j<= i; j++){
            cout<< "*";
        }
        cout<< endl;
    }
    // Lower half of the butterfly
    for (int i = n; i >= 1; --i) {
        // Print the left stars
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        // Print the spaces in the middle
        for (int j = 1; j <= 2 * (n - i); ++j) {
            cout << " ";
        }
        // Print the right stars
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    
    
    return 0;
}
    
    

