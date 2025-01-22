#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<char> &s,char element){
    if(s.empty()){
        s.push(element);
        return;
    }
    char n = s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(n);
}
void reverse(stack<char> &s){
    if(s.empty()){
        return;
    }
    char topElement = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,topElement);
}
int main(){
    stack<char> s;
    string str;
    getline(cin,str);
    for(char ch: str){
        s.push(ch);
    }
    // reverse(s);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}