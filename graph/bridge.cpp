#include<list>
void dfs(int node,int &timer,vector<int> &disc,vector<int> &low,
vector<int> &parent,vector<bool> &vis,unordered_map<int,list<int>> &adj,
vector<vector<int>>&res){
    disc[node] = timer;
    low[node] = timer;
    vis[node] = true;
    timer++;
    for(int i : adj[node] ){
        if(i==parent[node])continue;
        if(!vis[i]){
            parent[i] = node;
            dfs(i,timer,disc,low,parent,vis,adj,res);
            low[node] = min(low[i],low[node]);
            // check if bridge
            if(low[i]>disc[node]){
               vector<int> ans;
               ans.push_back(i);
               ans.push_back(node);
               res.push_back(ans);
            }
        }else{
            // backedge
            low[node] = min(low[node],disc[i]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adj;
    for(auto i : edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
   vector<int> disc;
   vector<int> low;
   vector<int> parent;
   vector<bool> vis;
   for(int i =0;i<v;i++){
       disc.push_back(-1);
       low.push_back(-1);
       vis.push_back(false);
       parent.push_back(-1);
   }
   int timer =0;
   vector<vector<int>> res;
   for(int i =0;i<v;i++){
       if(!vis[i]){
       dfs(i,timer,disc,low,parent,vis,adj,res);
    }
    }
    return res;

}