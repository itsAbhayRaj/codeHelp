#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void APUtil(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, int &time, int u, int parent, vector<bool> &AP)
{
    int child = 0;
    visited[u] = true;

    disc[u] = ++time;
    low[u] = time;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            child++;
            APUtil(adj, visited, disc, low, time, v, u, AP);

            low[u] = min(low[u], low[v]);

            if (low[v] >= disc[u] && parent != -1)
                AP[u] = true;
        }

        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }

    if (parent == -1 && child > 1)
        AP[u] = true;
}

void AP(vector<vector<int>> &adj, int V)
{
    vector<int> disc(V);
    vector<int> low(V);
    vector<bool> visited(V, false);
    vector<bool> AP(V, false); 
    int time = 0;
    int par = -1;

    for (int u = 0; u < V; ++u){
         if (!visited[u])
             APUtil(adj, visited, disc, low, time, u, par, AP);
    }

    for (int i = 0; i < V; i++){
        if (AP[i] == true)
            cout << i << " ";
    }
}

int main()
{
    cout << "Articulation points: ";
    int V = 5;
    int E = 6;
    vector<vector<int>> adj(V);
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    AP(adj, V);
    return 0;
}