#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr){
    for(auto i:arr)
    cout<<i<<" ";
}
void rotate(vector<int> &nums,int k){
    vector<int> temp(nums.size());
    for(int i=0;i<nums.size();i++){
        temp[(i+k)%nums.size()]=nums[i];
    }
    nums=temp;
}

int main()
{
  vector<int> arr1 = {1,2,3,4,5,6,7,8};
  rotate(arr1,4);
  print(arr1);
}
