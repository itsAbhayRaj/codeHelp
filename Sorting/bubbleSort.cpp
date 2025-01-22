#include <iostream>
using namespace std;
void sort(int arr[],int n){
    for(int i =1;i<n;i++){
        bool swapped = false;
        for(int j=0;j<n-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                swapped = true;
            }
        }
        if(!swapped)
        break;
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