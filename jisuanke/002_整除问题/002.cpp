#include <iostream>
using namespace std;
int main(){
    int input_a,input_b;
    cin>>input_a;
    cin>>input_b;
    if(input_a%input_b==0){
        cout<<"YES";
    }else
        cout<<"NO";
    return 0;
}