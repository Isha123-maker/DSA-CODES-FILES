#include <iostream>
using namespace std;

 void fiboSeries (int n) {
    int a=0 ,b=1;
     while (a <= n) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
 
   

}



int main() {

     fiboSeries(6);
    
    return 0;
}