#include <iostream>
#include <vector>
using namespace std;

bool search(int *arr,int n,int size){
  if(size==0) return false;
  if(arr[0]==n){
    return true;
  }else{
    return search(arr+1,n,size-1);
  }
}

int main()
{
   int  n = 7;
   int arr[] = {1,2,3,4,5,6,7};
   int num = 4;
   string ans = search(arr,num,n) ? "Present ":"Not Present";
   cout<<ans;
}