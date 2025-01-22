#include <iostream>
#include <vector>
using namespace std;
inline int series(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans = series(n-1)+series(n-2);
    return ans;

}
int main()
{
   int  n = 7;
   for(int i =0;i<n;i++)
    cout<<series(i)<<" ";
}