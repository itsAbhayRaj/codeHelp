#include <iostream>
using namespace std;
int findUnique(int arr[],int s){
    int ans =0;
    for( int i=0;i<s;i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int n;
   cout<<"array size "<<endl;cin>>n;cout<<"Array Elements "<<endl;
   int arr[100];
   for(int i = 0 ;i<n;i++){
    cin>>arr[i];
   } 
    cout<<findUnique(arr,n);
}