
#include <bits/stdc++.h>
using namespace std;
class Solution { //solution1
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        return q;
    }
};
/// recurion
class Solution {
  public:
  void solve(queue<int>&q){
      if(q.empty()){
          return;
      }
      int n = q.front();
      q.pop();
      solve(q);
      q.push(n);
      
  }
    queue<int> reverseQueue(queue<int> &q) {
        solve(q);
        return q;
    }
};
