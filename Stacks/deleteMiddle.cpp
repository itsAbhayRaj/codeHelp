#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int count,int size){
    if(count==size/2 ){
        s.pop();
        return ;
    }
    int num = s.top();
    s.pop();
    solve(s,count+1,size);
    s.push(num);
}
void getMiddle(stack<int> &s){
     solve(s,0,s.size());
}
int main(){
    stack<int> s;
    int numbers[] = {1,2,3,4,5,6};
    for(int n: numbers){
        s.push(n);
    }
    getMiddle(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}