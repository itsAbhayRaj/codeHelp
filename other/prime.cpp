#include <iostream>
using namespace std;
int main()
{
int m;
cin>>m;
bool prime=true;
for(int n =2;n<=m;n++)
{
for(int i =2;i<=n/2;i++)
{
    if(n%i==0){
        prime = false;
        break;
    }
}
    if(prime){
        cout<<"Prime"<<" = "<<n<<endl;
    }
prime = true;
}
}