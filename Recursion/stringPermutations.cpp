#include <iostream>
#include <vector>
using namespace std;
void print(vector<string> arr){
for(auto i: arr){
    cout<<i<<" ";
}
}
void solve( vector<string> &ans, int index,string str){
    if(index>=str.length()){
        ans.push_back(str);
        return;
    }
    for(int i =index;i<str.size();i++){
        swap(str[i],str[index]);
        solve(ans,index+1,str);
        swap(str[i],str[index]);
    }
}

vector<string> permutations(string str){
    int index = 0;
    vector<string> ans;
    solve(ans,index,str);
    return ans;
}
int main()
{
    string str = "abcd";
    vector<string> ans = permutations(str);
    cout<<ans.size()<<endl;
   print(ans);
}
