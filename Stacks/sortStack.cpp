#include <iostream>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &s, int num){
    if(s.empty() || s.top() < num){
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortedInsert(s,num);
    s.push(n);
}
void sort(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    sort(s);
    sortedInsert(s,num);
}
int main(){
    stack<int> s;
    int numbers[] = {3,1,4,3,6,5};
    for(int n: numbers){
        s.push(n);
    }
    sort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}