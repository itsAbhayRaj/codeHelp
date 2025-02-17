// ---------undirected graph----------//
// bfs
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, 
    int s , int t){
        vector<vector<int>> adj(n+1);
        for(auto &[u,v] : edges){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool> vis;
        vector<int> parent(n+1) ;
        queue<int> q;
        q.push(s);
        vis[s] = true;
        parent[s] = -1;
        while(!q.empty()){
            int t = q.front();q.pop();
            for(int i : adj[t]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = true;
                    parent[i] = t;
                }
            }
        }
        vector<int> path;
        int d = t;
        path.push_back(d);
    while(d!=s){
        d = parent[d];
        path.push_back(d);
    }
    reverse(path.begin(),path.end());
        return path;
    }
    