#include <iostream>
using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void sort(int arr[],int n){
    for(int i =1;i<n;i++){
        int key = arr[i];
        int j =i-1;
        for(;j>=0;j--){
            if(key<arr[j]){
                arr[j+1] = arr[j];
                printArray(arr,n);
            }else{
                break;
            }
        }
        arr[j+1]=key;
    }
}

int main()
{
   int n=6;
   int arr[100]={6,2,3,1,4,5};
//    cin>>n;
//    for(int i =0 ;i<n;i++){
//     cin>>arr[i];
//    }
   sort(arr,n);
   printArray(arr,n);
}