#include <iostream>
#include <vector>
using namespace std;
void reverseArray(vector<int> &arr,int m){
    int s=m;int e=arr.size()-1;
    while(s<=e){
        swap(arr[s],arr[e]);
        s++;e--;
}
}
int main()
{
  vector<int> arr;
  int m,n;
  cout<<"Number of elements --> ";
  cin>>n;
  for(int i =0;i<n;i++ ){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  cout<<"Position From which array has to be reversed --> ";
  cin>>m;
  reverseArray(arr,m);
  for(auto I:arr){
    cout<<I<<" ";
  }
}