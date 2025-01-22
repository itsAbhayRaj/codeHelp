#include <iostream>
using namespace std;
int pivot(int arr[],int n){
    int left=0;
    int right=n-1;
    int mid = left + (right-left)/2;
    while (left<right)
    {
        if(arr[mid]<=arr[0]){
            right = mid-1;
        }else{
            left = mid;
        }
        mid = left + (right-left)/2;
    }
    
    return right;
    
}
int main()
{
   int arr[] = {6,7,8,9,2,5,6};
   int n = sizeof(arr)/sizeof(arr[0]);
   int index = pivot(arr,n);
   cout<<"Pivot element "<<arr[index]<<" is at "<<index;
}