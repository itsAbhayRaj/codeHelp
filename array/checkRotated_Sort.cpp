#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums){
    int pair=0;
    for(int i =1;i<nums.size();i++){
        if(nums[i]<nums[i-1]){
            pair++;
        }
    }
    if(nums[nums.size()-1]>nums[0])
    pair++;
    return pair<=1;//for same elements 
}
int main()
{
  vector<int> arr1 = {5,6,7,7,8,1,2,3};
  cout<<check(arr1);
  cout<<"io";
}