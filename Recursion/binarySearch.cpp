#include <iostream>
#include <vector>
using namespace std;

bool search(int *arr,int s,int e,int n){
    if(s>e){
        return 0;
    }
    int mid = s+(e-s) / 2;
    if( arr[mid]==n)
    return 1;
    else if(arr[mid]<n){
        return search(arr,mid+1,e,n);
    }else{
        return search(arr,s,mid-1,n);
    }
}

int main()
{
   int  n = 7;
   int arr[] = {1,2,3,4,5,6,7};
   int num = 1;
   string ans = search(arr,0,n,num) ? "Present ":"Not Present";
   cout<<ans;
}