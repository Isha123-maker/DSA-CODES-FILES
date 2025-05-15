#include<iostream>
using namespace std;

void changeA(int *a){  //pass by reference using pointer
    *a=20;
}

void changeB(int &a){  //pass by reference using alias
    a=20;
}

int main(){
    int ptr = 10;
    int *ptr1 =&ptr;
    int **ptr2 = &ptr1;
    int a = 5;
    changeA(&a);
    ChangeB(a);
    int *p = &a;
    int **q = &p;


   cout<< a << endl;
    cout << ptr << endl;
     cout << *ptr1 << endl;
      cout << **ptr2 << endl;
       cout << *p << endl;
        cout << **q << endl;
         cout << p << endl;
          cout << *q << endl;

    return 0;
}