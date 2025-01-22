#include <iostream>
#include <vector>
using namespace std;

void shiftNegative(vector<int> &arr){
    int c=0;
    for(int i =0;i<arr.size();i++ ){
        if(arr[i]<0){
            swap(arr[c++],arr[i]);
            
        }

    }
}

int main()
{
    vector<int> arr={23,-7,12,-10,-11,40,60};
    shiftNegative(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}