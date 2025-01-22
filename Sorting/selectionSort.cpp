#include <iostream>
using namespace std;
void sort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int minIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        swap(arr[minIdx],arr[i]);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
   int n;
   int arr[100];
   cin>>n;
   for(int i =0 ;i<n;i++){
    cin>>arr[i];
   }
   sort(arr,n);
   printArray(arr,n);
}