#include <iostream>
using namespace std;
int main()
{
    int count1;
    cin>>count1;
    char *str= new char[count1];
    for(int i=0;i<count1;i++){
        cin>>str[i];
    }
    char target;
    cin>>target;
    int count=0;
    for (int i=0;i<count1;i++)
    {
        if(*(str+i)!=target)
        {
            count++;
        }
    }
    cout<<count;
}