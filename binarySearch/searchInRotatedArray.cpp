#include <iostream>
using namespace std;
int binarySearch(int arr[],int s,int e,int key){
    int start = s ; int end = e;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}
    int getPivot(int arr[],int n){
    int left = 0;int right = n-1;
    while(left<right){
        int mid = left + (right-left)/2 ;
        if(arr[mid]>=arr[0]){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return right;
}
    int search(int nums[],int n, int target) {
        int pivot = getPivot(nums,n);
        if(target>=nums[pivot] && target<=nums[n-1]){
            return binarySearch(nums,pivot,n,target);
        }else {
            return binarySearch(nums,0,pivot-1,target);
        }
        return -1;
    }
int main(){
    int arr[] = {11,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<search(arr,n,3);
}