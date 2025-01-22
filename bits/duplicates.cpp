#include <iostream>
using namespace std;
void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int duplicate(int arr[],int s){
    int ans =0 ;
    for(int i =0;i<s;i++){
        ans = ans ^ i ^ arr[i];
    }
    return ans;
}
int main()
{
    int s;
   cin>>s;
   int arr[100];
   for(int i =0 ;i<s;i++){
    cin>>arr[i];
   }
   cout<<duplicate(arr,s);
}