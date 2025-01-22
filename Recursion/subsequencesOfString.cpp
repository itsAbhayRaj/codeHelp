#include <iostream>
#include <vector>
using namespace std;

void print(vector<string>arr){
    for(auto i:arr){
        cout<<"[ ";
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"],";
    }
}
void solve(string str,int index,string output,vector<string> &ans){
    if(index>=str.length()){
        if(output.length()>0)
        ans.push_back(output);
        return;
    }
    //exclude
    solve(str,index+1,output,ans);
    //include
    char ele = str[index];
    output.push_back(ele);
    solve(str,index+1,output,ans);
}
vector<string> subsequence(string str){
    int index =0;
    string output;
    vector<string> ans;
    solve(str,index,output,ans);
    return ans;
}


int main()
{
   string str = "cba";
   vector<string> arr = subsequence(str);
   print(arr);
}