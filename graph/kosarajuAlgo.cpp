#include<bits/stdc++.h>
void dfs(int node,stack<int> &topo,vector<bool> &vis,
unordered_map<int,list<int>> &adj,int & components){
	vis[node] = true;
	for(int i : adj[node]){
		if(!vis[i]){
			dfs(i,topo,vis,adj,components);
		}
	}
	components++;
	topo.push(node);
}
void reverseDfs(int node, vector<bool> &vis, unordered_map<int, list<int>> &transposedAdj) {
    vis[node] = true;
    for (int i : transposedAdj[node]) {
        if (!vis[i]) {
            reverseDfs(i, vis, transposedAdj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adj;
	for(auto &i : edges){
		adj[i[0]].push_back(i[1]);
	}
	stack<int> topo;
	vector<bool> vis(v);
	int components = 0;
	for(int i =0;i<v;i++){
		if(!vis[i]){
			dfs(i,topo,vis,adj,components);
		}
	}
	// transpose
	unordered_map<int,list<int>> transposedAdj;
	for(auto & i : adj){
		for(int j : i.second){
			transposedAdj[j].push_back(i.first);
		} 
	}
	components = 0;
	vis.assign(vis.size(),false);
	while (!topo.empty()) {
        int node = topo.top();
        topo.pop();
        if (!vis[node]) {
            components++;
            reverseDfs(node, vis, transposedAdj);
        }
    }
	return components;
}