#include <iostream>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    int prdt =1;
    int sum=0 ;
    while (n!=0)
    {
        int digit = n%10;
        sum += digit;
        prdt*=digit;
        n/=10;
    }
    cout<<prdt-sum;
}