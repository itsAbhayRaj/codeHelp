#include <iostream>
#include <vector>
using namespace std;
void print(vector<string> arr){
for(auto i: arr){
    cout<<i<<" ";
}
}
void solve( vector<string> &ans,vector<string> mapping, int index, string output,string str){
    if(index>=str.length()){
        ans.push_back(output);
        return;
    }
    char num = str[index]-'0';
    string value = mapping[num];
    for(int i =0;i<value.length();i++){
        output.push_back(value[i]);
        solve(ans,mapping,index+1,output,str);
        output.pop_back();
    }

}

vector<string> letterCombinations(string str){
    int index = 0;
    string output;
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    solve(ans,mapping,index,output,str);
    return ans;
}
int main()
{
    string str = "23";
    vector<string> ans = letterCombinations(str);
   print(ans);
}
