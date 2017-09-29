#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int input_N;
    cin>>input_N;

    bool isPrime= true;

    if(input_N==1)
        isPrime= false;
    else if(input_N==2)
        isPrime= true;
    else{
        for (int i = 2; i <= int(sqrt(input_N)); i++) {
            if(input_N%i==0)
                isPrime= false;
        }
    }

    if(isPrime)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;

}