#include <iostream>
using namespace std;
int firstOccurence(int arr[],int n,int key){
    int left = 0;int right =n-1;int ans;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid] == key){
            right = mid-1;ans = mid;}
        else if(arr[mid]<key){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return ans;
}
int lastOccurence(int arr[],int n,int key){
    int left = 0;int right =n-1;int ans;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid] == key){
            left = mid+1;ans = mid;}
        else if(arr[mid]<key){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return ans;
}
int noOfOccurence(int arr[],int n,int key){
    return lastOccurence(arr,n,key)-firstOccurence(arr,n,key)+1;
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}
void sortArray(int arr[],int n){

    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx= j;;
            }
        }
        swap(arr[min_idx],arr[i]);
    }
    printArray(arr,n);
}
int main()
{
   int n;
   cin>>n;
   int arr[100];
   for(int i =0;i<n;i++){
    cin>>arr[i];
   }
   sortArray(arr,n);
   cout<<"Key ";
   int key;
   cin>>key;
   cout<<"No of Occurence of "<<key<<" is "<<noOfOccurence(arr,n,key);
}