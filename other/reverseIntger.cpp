#include <iostream>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int answer =0;
    int digit;
    while(n!=0){
        digit = n%10;
        n/=10;
        answer = answer*10+digit;
    }
    cout<<answer;
}