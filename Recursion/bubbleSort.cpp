#include <iostream>
#include <vector>
using namespace std;
void print(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void Sort(int arr[],int n ){
    if(n==0){
        return ;
    }
    int i =0;
    while(i<n){
        if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
        }
        i++;
    }
    Sort(arr,n-1);
}
int main()
{
   int arr[] = {1,6,7,5,3,4,2};
    Sort(arr,7);
    print(arr,7);
}