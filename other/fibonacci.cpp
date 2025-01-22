#include <iostream>
using namespace std;

int main()
{
    int a=0;
    int b=1;
    int temp;
    int n;
    cin>>n;
    cout<<a<<" ,"<<b<<" ,";
    for(int i =0;i<=n;i++)
    {
        temp = a+b;
        cout<<temp<<" ,";
        a=b;
        b=temp;
    }
}