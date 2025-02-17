//--------------------undirected using BFS------------------------//
#include <list>
#include <unordered_map>
#include <queue>
bool isCycle(unordered_map<int,list<int>> &adj,int node,
unordered_map<int,bool> &vis){
    queue<int> q;
    unordered_map<int,int> parent;
    q.push(node);
    vis[node] = true;
    parent[node] = -1;
    while(!q.empty()){
        int n = q.front();q.pop();
        for(int i : adj[n]){
            if(!vis[i]){
                q.push(i);
                vis[i] = true;
                parent[i] = n;
            }else if(vis[i] && parent[n]!=i){
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i =0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    unordered_map<int,bool> parent;
    for(int i =0;i<n;i++){
        if(!vis[i]){
            if(isCycle(adj,i,vis)){
                return "Yes";
            }
        }
    }
    
    return "No";
}
//--------------------undirected using DFS--------------------------------//

#include <list>
#include <unordered_map>
#include <queue>
bool isCycle(unordered_map<int,list<int>> &adj,int node,int parent,
unordered_map<int,bool> &vis){
    vis[node] = true;
    for(int i : adj[node]){
        if(!vis[i]){

            if(isCycle(adj,i,node,vis)){
                return true;
            }
        }
         else if(vis[i] && parent!=i){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i =0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> vis;
    unordered_map<int,bool> parent;
    for(int i =0;i<n;i++){
        if(!vis[i]){
            if(isCycle(adj,i,-1,vis)){
                return "Yes";
            }
        }
    }
    
    return "No";
}
//---------------------directed using DFS-----------------------//
#include <list>
#include <unordered_map>
bool isCycle(int node,unordered_map<int,list<int>> &adj,
unordered_map<int,bool> &vis,unordered_map<int,bool> &inCall){
inCall[node] = true;
vis[node] = true;
for(int i :adj[node]){
  if(!vis[i]){
    if(isCycle(i,adj,vis,inCall)){
return true;
    }
  }else if(inCall[i]){
    return true;
  }
 
} inCall[node] = false;
return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>>adj;
  for(auto &[u,v] : edges){
    adj[u].push_back(v);
  }
  unordered_map<int,bool> vis;

  
  unordered_map<int,bool> inCall;  
  for(int i =0;i<n;i++){if(!vis[i]){if(isCycle(i,adj,vis,inCall)){
    return 1;
  }}}
  return 0;
}
//----------------------directed using BFS-----------------------//
#include <list>
#include <unordered_map>
#include <queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>>adj;
  for(auto &[u,v] : edges){
    adj[u-1].push_back(v-1);
  }
  vector<int> inDegree(n+1);
  for(auto i : adj){
    for(int j : i.second)
    inDegree[j]++;
  }

  queue<int> q;
  for(int i =0;i<n;i++){
    if(inDegree[i]==0)
    q.push(i);
  }
  int cnt =0;
  while(!q.empty()){
    int t = q.front();q.pop();
    cnt++;
    for(int neighbour : adj[t]){
      inDegree[neighbour]--;
      
      if(inDegree[neighbour]==0){
        q.push(neighbour);
      }
    }
  }
  return cnt==n ? 0 : 1;
}