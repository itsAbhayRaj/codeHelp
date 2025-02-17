#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int, list<pair<int, int>>> adj;

public:
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
    }
    void printAdj()
    {

        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st)
    {
        vis[node] = true;
        for (auto i : adj[node])
        {
            if (!vis[i.first])
            {
                dfs(i.first, vis, st);
            }
        }
        st.push(node);
    }
    void getShortestPath(vector<int> &distances,int n,stack<int> st ){
        
        while (!st.empty())
        {
            int top = st.top();st.pop();
            if(distances[top]!=INT_MAX)
            for(auto i : adj[top]){
                if(distances[i.first]>i.second+distances[top]){
                    distances[i.first] = i.second+distances[top];
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    // g.printAdj();
    int n = 6;
    unordered_map<int, bool> vis;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            g.dfs(i, vis, st);
        }
    }
    vector<int> distances;
    for (int i = 0; i < n; i++)
        {
            distances.push_back(INT_MAX);
        }
        distances[1] = 0; // src = 0
    g.getShortestPath(distances,n,st);
    for(int i : distances){
         cout<<i<<" ";
    }
}