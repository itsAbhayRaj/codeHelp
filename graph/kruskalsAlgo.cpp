#include<algorithm>
int findParent(vector<int> & parent,int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node] = findParent(parent,parent[node]);
}
void unionSet(int u,int v,vector<int> & parent,vector<int> &rank){
 u = findParent(parent,u);
   v = findParent(parent,v);
  if(rank[u]==rank[v]){
    parent[v] = u;
    rank[u  ] ++;
  }else if(rank[u]>rank[v]){
    parent[v] = u;
  }else{
    parent[u] = v;
  }
}
bool cmp(vector<int>&a,vector<int>&b){
  return a[2] < b[2];
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
sort(edges.begin(),edges.end(),cmp);
 vector<int> parent;for(int i =0;i<n;i++){parent.push_back(i);}
 vector<int> rank(n,0);
 int cost = 0;
 for(auto i : edges){
   if(findParent(parent,i[0])==findParent(parent,i[1])){
     continue;
   }
   cost+=i[2];
   unionSet(i[0],i[1],parent,rank);

 }
return cost;
}