#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr){
    for(auto i:arr)
    cout<<i<<" ";
}
void merge(vector<int> &arr1,int m,vector<int> &arr2,int n){
    int i=0,j=0;
    vector<int> temp;
    while(i<m && j<n){
        if(arr1[i]<arr2[j])
        temp.push_back(arr1[i++]);
        else
        temp.push_back(arr2[j++]);
    }
    while(i<m){
        temp.push_back(arr1[i++]);
    }
    while(j<n){
        temp.push_back(arr2[j++]);
    }
    
    for(int k=0;k<n+m;k++){
        arr1[k] = temp[k];
    }
}
int main()
{
  vector<int> arr1 = {1,4,7,8,0,0,0,0};
  vector<int> arr2 = {2,3,4,6,7};
  merge(arr1,4,arr2,4);
  print(arr1);
}