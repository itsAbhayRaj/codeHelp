#include <iostream>
#include <vector>

using namespace std;
void print(vector<vector<int>> arr){
    cout<<"{ ";
    for(int i =0 ;i<arr.size();i++){
        cout<<"[ ";
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"] , ";
    }
    cout<<"}";
}
void solve(vector<int> arr,vector<int> output,int index,vector<vector<int>> &ans){
    if(index>=arr.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(arr,output,index+1,ans);
    //include
    int element = arr[index];
    output.push_back(element);
    solve(arr,output,index+1,ans);

}
vector<vector<int>> powerSet(vector<int> &arr){
    int index = 0;
    vector<vector<int> > ans;
    vector<int> output;

    solve(arr,output,index,ans);
    return ans;

}
int main()
{
   vector<int> arr = {1,2,3};
   vector<vector<int>> result = powerSet(arr);
   print(result);
}