#include <iostream>
#include <stack>
using namespace std;

bool isReduntant(string s){
   stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='/' ||ch=='*'){
            st.push(ch);
        }else if(ch==')'){
             bool isReduntant = true;
            while(st.top()!='('){
                st.pop();
                isReduntant = false;
            }
            st.pop();
            if(isReduntant)return true;
        }
    }
return false;
}
int main(){
// (a+b)
// (a+c*b)+(c))
// (a*b+(c/d))
// ((a/b))
    string s = "(a*b+(d))";
   string res = isReduntant(s)?"yes":"no";
   cout<<res<<endl;
}
