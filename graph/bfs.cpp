vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int>ans;
    queue<int>q;
    unordered_map<int,bool>visited;

    q.push(0);
    visited[0] =true;
    while(!q.empty()){
        int n = q.front();
        ans.push_back(n);
        q.pop();
        for(int i=0;i<adj[n].size();i++){
            int padosi = adj[n][i];
            if(visited[padosi]==false){
                q.push(padosi);
                visited[padosi]=true;
            }
        }

    }
    return ans;
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int>ans;
    queue<int>q;
    unordered_map<int,bool>visited;

    q.push(0);
    visited[0] =true;
    while(!q.empty()){
        int n = q.front();
        ans.push_back(n);
        q.pop();
        for(int i=0;i<adj[n].size();i++){
            int padosi = adj[n][i];
            if(visited[padosi]==false){
                q.push(padosi);
                visited[padosi]=true;
            }
        }

    }
 return ans;
}