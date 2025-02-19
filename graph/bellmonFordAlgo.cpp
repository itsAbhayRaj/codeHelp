vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    
    vector<int> distances(n+1,100000000);
    distances[src] = 0;
    for(int i =0;i<n-1;i++){
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            if(distances[u] + w < distances[v]){
                distances[v] = distances[u] + w;
            }
        }
    }
   
    return distances;
}