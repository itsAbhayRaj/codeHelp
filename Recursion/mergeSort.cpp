#include <iostream>
#include <vector>

using namespace std;
void print(int arr[],int n ){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void merge(int *arr,int s ,int e){
    int mid = (s+e)/2;int len1 = mid-s+1;int len2 = e-mid;
    int *first = new int[len1];
    int *second = new int[len2];
    int k=s;
    for(int i =0;i<len1;i++){
        first[i]=arr[k++];
    }
    for(int i =0;i<len2;i++){
        second[i]=arr[k++];
    }
    int i =0;int j=0;k=s;
    while(i<len1 && j<len2){
        if(first[i]<second[j]){
            arr[k++]=first[i++];
        }else {
            arr[k++]=second[j++];
        }
    }
    while(i<len1){
       arr[k++] = first[i++];
    }
    while(j<len2){
       arr[k++] = second[j++];
    }
    delete [] first;
    delete [] second;
}

void mergeSort(int arr[],int s,int e){
    if(s>=e)return;
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}
int main()
{
   int  n = 8;
   int  arr[] = {8,3,3,4,1,4,2,8};
   mergeSort(arr,0,n);
   print(arr,n);
}