void dfs(unordered_map<int,list<int>> &adj,int s,
    unordered_map<int,bool> &vis,vector<int>& ans){
    ans.push_back(s);
    vis[s]  = true;
    for(auto i : adj[s]){
        if(!vis[i])
        dfs(adj,i,vis,ans);
    }
    }
    vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
    {
        unordered_map<int,list<int>> adj;
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> res;
        vector<int> ans;
        unordered_map<int,bool> vis;
        
        for(int i =0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,vis,ans);
                res.push_back(ans);
                ans.clear();
            }
           
        }
        return res;
    }