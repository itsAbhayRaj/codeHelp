#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>>adj;
    for(auto p : g){
        int u = p.first.first;
        int v = p.first.second;
        int w = p.second;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> key(n+1);
    vector<bool> MST(n+1);
    vector<int> p(n+1);
    for(int i =1;i<=n;i++){
        key[i]=INT_MAX;
        MST[i]=false;
        p[i] = -1;
    }
    
    key[1] = 0;
    for(int i = 1;i<=n;i++){
        int mini = INT_MAX;
        int u;
        for(int v = 1;v<=n;v++){
            if(!MST[v] && key[v]<mini){
                mini = key[v];
                u = v;
            }
        }
        MST[u] = true;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(!MST[v] && w<key[v]){
                key[v] = w;
                p[v] = u;
            }
        }

    }
    vector<pair<pair<int,int>,int>> res;
    
    for(int i =2;i<=n;i++){
      res.push_back({{p[i],i},key[i]});
    }
return res;
}
