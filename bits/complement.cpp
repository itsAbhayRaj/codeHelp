#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int orig=n;
    int mask=0;
    while(n!=0){
        mask=(mask<<1)|1;
        n=n>>1;
    }
    orig = (~orig)& mask;
    cout<<mask;
}