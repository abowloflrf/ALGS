#include <iostream>

using namespace std;

int fib(int index);

int main() {
    int input_N;
    cin>>input_N;
    cout<<fib(input_N);
    return 0;
}

int fib(int index){
    if(index == 0) {
        return 0;
    }

    if(index == 1) {
        return 1;
    }

    return fib(index-1) + fib(index-2);
}