#include <iostream>
using namespace std;
int peak(int arr[],int n ){
    int s = 0;int e = n-1;
    while(s<e){
        int mid = (s+e)/2;
        if(arr[mid]<=arr[mid+1]){
            s = mid+1;
        }else{
            e = mid;
        }
    }
    return s;
}
int main()
{
   int arr[] = {1,2,4,3,2};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<"Peak element "<<arr[peak(arr,n)]<<" is at "<<peak(arr,n);
}