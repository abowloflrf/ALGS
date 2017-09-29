#include <iostream>
using namespace std;
int main()
{
    int data[3];
    for(int i=0;i<3;i++){
        cin>>data[i];
    }
    int result=data[0]+data[1]+data[2];
    cout<<result;

    return 0;
}