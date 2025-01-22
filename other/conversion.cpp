#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n=1010
    ;
    int result =0;
    int i =0;
    while(n>0){
        if(n%2){
            result+=pow(2,i);
        };
        n/=10;
        i++;
    }
    cout<<result;
}