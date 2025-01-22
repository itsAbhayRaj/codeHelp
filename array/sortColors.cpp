#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
        int start=0;
        int i =0;
        int end = nums.size()-1;
        while(i<=end){
            if(nums[i]==0)
                swap(nums[i++],nums[start++]);
            else if(nums[i]==1)
                i++;
            else
                swap(nums[i],nums[end--]);

        }
}

int main(){
    vector<int> arr={0,1,2,0,1,2,0,1,2,0,1,2};
    sortColors(arr);
    for(auto i:arr)
        cout<<i<<" ";
    return 0;
}