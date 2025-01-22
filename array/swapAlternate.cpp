#include <iostream>
using namespace std;
void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n=9;
    int arr[9]={1,2,3,4,5,6,7,8,9};
    int k=2;
    for(int i=0;i<n;i++){
        if((i+1)<n)
        swap(arr[i++],arr[i+1]); 
        printArray(arr,n);
    }

   
}
