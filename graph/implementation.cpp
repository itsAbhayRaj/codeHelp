#include <iostream>
#include <map>
#include <list>
using namespace std;
template<typename T>
class graph
{
private:

    map<T,list<T>> adj;
public:
    void add(T u , T v,bool directed){
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }
    }
    void printAdjancyList(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(int j : i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    
};

int main(){
    int n , m, u, v;
    cin >> n >> m;
    graph<int> g;
    for(int i = 0;i<n;i++){
        int u,v;
        cin>>u>>v;
        // undirected
        g.add(u,v,0);
    }
    g.printAdjancyList();
}