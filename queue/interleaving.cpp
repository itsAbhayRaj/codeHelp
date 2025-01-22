#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleave(queue<int>&q){ //using stack
    stack<int>s;
    stack<int>st;
    int n = q.size();
    for(int i= 0;i<n/2;i++){
        int val = q.front();
        q.push(val);
        q.pop();
    }
    for(int i= 0;i<n/2;i++){
        int val = q.front();
        s.push(val);
        q.pop();
    }
    while(!s.empty()){
        st.push(s.top());
        s.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        int val = q.front();
        q.pop();
        q.push(val);
    }
}
// void interleave(queue<int>& q){
//     queue<int> firstHalf;
//     int n =q.size();
//     for(int i =0;i<n/2;i++){
//         firstHalf.push(q.front());
//         q.pop();
//     }
//     while(!firstHalf.empty()){
//         q.push(firstHalf.front());
//         firstHalf.pop();
//         int val = q.front();
//         q.pop();
//         q.push(val);

//     }
// }
int main(){
    queue<int> q;
    for(int i =11;i<=14;i++){
        q.push(i);
    }
    for(int i =1;i<=4;i++){
        q.push(i);
    }
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    interleave(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}