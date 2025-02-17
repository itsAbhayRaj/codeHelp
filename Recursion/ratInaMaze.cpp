#include <iostream>
#include <vector>
using namespace std;
void print(vector<string> arr){
for(auto i: arr){
    cout<<i<<" ";
}
}
bool isAllowed(vector<vector<int>> isVisited,int x,int y,vector<vector<int>> m,int n ){
    if((x>=0&&x<n)&&(y>=0 && y<n)&& isVisited[x][y]==0 && m[x][y]==1){
        return true;
    }
    else{
        return false;
    }
}
void solve( vector<string> &ans,int x, int y, string path,vector<vector<int>> isVisited,vector<vector<int>> m,int n ){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    isVisited[x][y]=1;
    //Down
    int newX = x+1;
    int newY = y;
    if(isAllowed(isVisited,newX,newY,m,n)){
        path.push_back('D');
        solve(ans,newX,newY,path,isVisited,m,n);
        path.pop_back();
    }
    //UP
     newX = x-1;
     newY = y;
    if(isAllowed(isVisited,newX,newY,m,n)){
        path.push_back('U');
        solve(ans,newX,newY,path,isVisited,m,n);
        path.pop_back();
    }
    //Left
     newX = x;
     newY = y-1;
    if(isAllowed(isVisited,newX,newY,m,n)){
        path.push_back('L');
        solve(ans,newX,newY,path,isVisited,m,n);
        path.pop_back();
    }
    //Right
     newX = x;
     newY = y+1;
    if(isAllowed(isVisited,newX,newY,m,n)){
        path.push_back('R');
        solve(ans,newX,newY,path,isVisited,m,n);
        path.pop_back();
    }
}

vector<string> findPaths(vector<vector<int>> m,int n){

    vector<string> ans;
    if(m[0][0]==0){
        return ans;
    }
    string path="";
    vector<vector<int>> isVisited= m;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            isVisited[i][j] = 0;
        }
    }
    int x = 0;
    int y = 0;
    solve(ans,x,y,path,isVisited,m,n);
    return ans;
}
int main()
{
    int n =4;
    vector<vector<int>> m ={{1,0,1,1},
                            {1,1,1,0},
                            {1,1,1,0},
                            {1,0,1,1}};
    vector<string> ans = findPaths(m,n);
   print(ans);
}





#include <bits/stdc++.h> 
bool isSafe(int newX,int newY ,vector<vector<int>> &m,
vector<vector<bool>> &vis,int n ){
if((newX >=0 && newX < n) && (newY >=0 && newY < n) && m[newX][newY]==1 && vis[newX][newY]==0){
    return true;
}
return false;
}
void solve(int x, int y , vector<string> &res,string path,
vector<vector<bool>> &vis,vector<vector<int>> &m,int n ){
    if(x==n-1 && y==n-1){
        res.push_back(path);
        return;
    }
    vis[x][y] = true;
    int dx[] = {1,0,0,-1};
    int dy[] = {0,-1,1,0};
    char dir[] = {'D','L','R','U'};
    
    for(int i =0 ;i<4;i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(isSafe(newX,newY,m,vis,n))
        solve(newX,newY,res,path+dir[i],vis,m,n);
    }
    vis[x][y] = false;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    if(!arr[0][0]){return {""};}
    vector<string> result;
    string path = "";
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    solve(0,0,result,path,visited,arr,n);
    return result;
}


