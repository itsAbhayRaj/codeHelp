#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>> > adj;
    for(auto i : vec){
        int u = i[0];
        int v = i[1];
        int w = i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int> distances;
    for(int i =0;i<vertices;i++){
        distances.push_back(INT_MAX);
    }
    distances[source] = 0;
    set<pair<int,int>> s;
    s.insert({0,source});
    while(!s.empty()){
        auto t = *(s.begin());
        s.erase(s.begin());
        int nodeDistance = t.first;
        int node = t.second;
        for(auto i: adj[node]){
            int n = i.first;
            int w = i.second;
            if(nodeDistance+w < distances[n]){
                
                if(s.find({distances[n],n})!=s.end()){
s.erase({distances[n],n});
                }
                distances[n] = nodeDistance + w;
                s.insert({ distances[n],n});
            }
        }
    }
    return distances;
}
