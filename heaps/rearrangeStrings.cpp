class Solution {
    public:
    
        string reorganizeString(string s) {
          map<char,int> cnt;
          for(char c : s){
            cnt[c] ++;
          }  
          priority_queue<pair<int,char>> pq;
          for(auto&[k,v]:cnt){
            pq.push({v,k});
          }
          string res = "";
          pair<int,char> prev = {-1,'#'};
          while(!pq.empty()){
            auto [freq,ch]= pq.top();pq.pop();
            res+=ch;
            if(prev.first>0){
                pq.push(prev);
            }
            prev = {freq-1,ch};
          }
          if(res.size()==s.size())return res;
          else return "";
    
        }
    };