//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
        string str="";
        unordered_map<char,int> count;
        queue<char> q;

        for(int i =0;i<s.length();i++){
            char ch = s[i];
            count[ch]++;
            q.push(ch);
            while(!q.empty()){
                if(count[q.front()]>1){
                    q.pop();
                }else{
                    str.push_back(q.front());
                    break;
                }
            }
            if(q.empty()){
                str.push_back('#');
            }
        }
        return str;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends