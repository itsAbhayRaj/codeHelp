#include <bits/stdc++.h> 
// ----------------------------using dfs --------------------------//
void tSort(int node,stack<int> &st,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){
    vis[node] = true;
    for(int i : adj[node]){
        if(!vis[i]){
            tSort(i,st,vis,adj);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   unordered_map<int,list<int>> adj;
   for(int i =0;i<e;i++){
       int u = edges[i][0];
       int v = edges[i][1];
       adj[u].push_back(v);
   }
   unordered_map<int,bool> vis;
   stack<int> st;
   for(int i =0;i<v;i++)if(!vis[i]){tSort(i,st,vis,adj);}
   vector<int> res;
   while(!st.empty()){
       res.push_back(st.top());
       st.pop();
   }
   return res;
}

// ----------------------------using bfs (Kahn's Algo)--------------------------//
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   unordered_map<int,list<int>> adj;
   for(int i =0;i<e;i++){
       int u = edges[i][0];
       int v = edges[i][1];
       adj[u].push_back(v);
   }

   vector<int> inDegree(v);
    for(auto i : adj){
        for(int j : i.second){
            inDegree[j]++;
        }
    }
 vector<int> res;
  queue<int> q;
   for(int i =0;i<v;i++){
       if(inDegree[i]==0)
       q.push(i);
   }
   while(!q.empty()){
       int t = q.front();q.pop();
       res.push_back(t);
       for(int i:adj[t]){
           inDegree[i]--;
           if(inDegree[i]==0)
           q.push(i);
   }
   }
   
   
   return res;
}
