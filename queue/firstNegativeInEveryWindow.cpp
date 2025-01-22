#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        queue<int>q;
        vector<int> result;
        for(int i =0;i<k;i++){
            if(arr[i]<0)
            q.push(i);
        }
        if(q.empty()){
            result.push_back(0);
        }else{
           result.push_back(arr[q.front()]);
        }
        
        for(int i =k;i<arr.size();i++){
            if(!q.empty() && i-q.front()>=k){
                q.pop();
            }
            if(arr[i]<0)q.push(i);
            if(q.empty()){
                result.push_back(0);
            }else{
                result.push_back(arr[q.front()]);
            }
           
            
           
        } return result;
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
