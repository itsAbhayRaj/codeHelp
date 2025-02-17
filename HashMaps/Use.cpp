#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    unordered_map<string,int>umap;
    // insertion

    // 1
    pair<string,int> p1 = {"abhay",1};
    umap.insert(p1);

    // 2
    umap["Raj"] = 2;

    umap["Raj"] = 1; // value will change
    
    // Search
    cout<<umap["Raj"]<<endl;
    cout<<umap.at("abhay") <<endl;

    cout<<umap["unknownKey"]<<endl; // automatically assign 0 to key
    cout<<umap.at("unknownKey")<<endl; // does not assign gives error
    cout<<umap.size()<<endl;

    // check presence
    cout<<umap.count("hello")<<endl; // 0 if absent 
    cout<<umap.count("Raj")<<endl; // 1 if present

    // erase
    umap.erase("Raj");
    cout<<umap.size()<<endl;

    // traverse
    for(auto i: umap){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    // iterator
    unordered_map<string,int> :: iterator it = umap.begin();
    while(it!=umap.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    // in case of map order is preserved O(log n) 
    map<string,int> m;
    m.insert({"Raj",1});
    m.insert({"Abhay",2});
    cout<<m["AAunknown"]<<endl;
    for(auto i: m){
        cout<<i.first<<" "<<i.second<<endl;
    }
}